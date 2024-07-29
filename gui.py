import sys
import os
from PyQt5.QtWidgets import (
    QApplication,
    QMainWindow,
    QTextEdit,
    QVBoxLayout,
    QWidget,
    QPushButton,
    QFileDialog,
    QPlainTextEdit,
    QTextBrowser,
    QFrame,
    QHBoxLayout,
    QSizePolicy,
)
from PyQt5.QtCore import Qt, QRect, QSize
from PyQt5.QtGui import QPainter


class LineNumberArea(QWidget):
    def __init__(self, editor):
        super().__init__(editor)
        self.code_editor = editor

    def sizeHint(self):
        return QSize(self.code_editor.lineNumberAreaWidth(), 0)

    def paintEvent(self, event):
        self.code_editor.lineNumberAreaPaintEvent(event)


class CodeEditor(QPlainTextEdit):
    def __init__(self):
        super().__init__()
        self.lineNumberArea = LineNumberArea(self)
        self.verticalScrollBar().valueChanged.connect(self.updateLineNumberArea)
        self.updateRequest.connect(self.updateLineNumberAreaWidth)
        self.updateLineNumberAreaWidth(0)

    def lineNumberAreaWidth(self):
        digits = 1
        count = max(1, self.blockCount())
        while count >= 10:
            count /= 10
            digits += 1
        space = 3 + self.fontMetrics().width('9') * digits
        return space

    def updateLineNumberAreaWidth(self, _):
        width = self.lineNumberAreaWidth()
        self.setViewportMargins(width, 0, 0, 0)

    def updateLineNumberArea(self, _):
        rect = self.viewport().geometry()
        self.lineNumberArea.update(0, rect.y(), self.lineNumberArea.width(), rect.height())

        if self.verticalScrollBar().isVisible():
            width = self.lineNumberArea.width()
            left = self.viewport().geometry().left() - width
            self.lineNumberArea.setGeometry(
                QRect(
                    left,
                    self.viewport().geometry().top(),
                    width,
                    self.viewport().geometry().height(),
                )
            )

    def resizeEvent(self, event):
        super().resizeEvent(event)
        cr = self.contentsRect()
        self.lineNumberArea.setGeometry(
            QRect(cr.left(), cr.top(), self.lineNumberAreaWidth(), cr.height())
        )

    def lineNumberAreaPaintEvent(self, event):
        painter = QPainter(self.lineNumberArea)
        painter.fillRect(event.rect(), Qt.lightGray)

        block = self.firstVisibleBlock()
        block_number = block.blockNumber()
        top = int(self.blockBoundingGeometry(block).translated(self.contentOffset()).top())
        bottom = top + int(self.blockBoundingRect(block).height())

        while block.isValid() and top <= event.rect().bottom():
            if block.isVisible() and bottom >= event.rect().top():
                number = str(block_number + 1)
                painter.drawText(
                    QRect(0, top, self.lineNumberArea.width(), self.fontMetrics().height()),
                    Qt.AlignRight,
                    number
                )
            block = block.next()
            top = bottom
            bottom = top + int(self.blockBoundingRect(block).height())
            block_number += 1



class CompilerGUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.display_mode = "Quadruples"
        self.init_window()

    def init_window(self):
        self.setWindowTitle("Compiler")
        self.setStyleSheet("background-color: #9B89B3;")
        self.setGeometry(100, 100, 1700, 800)

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        layout = QVBoxLayout(self.central_widget)

        self.create_editor_frame(layout)
        self.create_output_frame(layout)

    def create_editor_frame(self, layout):
        editor_frame = QFrame()
        editor_layout = QHBoxLayout(editor_frame)

        self.code_text = CodeEditor()
        self.code_text.setStyleSheet(
            "background-color: #FFF6FF; color: #845EC2; border: 2px ridge #9B89B3; font-size: 12px;"
        )
        self.code_text.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        editor_layout.addWidget(self.code_text)

        self.line_number_area = LineNumberArea(self.code_text)
        self.line_number_area.setStyleSheet(
            "background-color: #E8E8E8; color: #000000; border: 2px ridge #9B89B3; font-size: 12px;"
        )
        editor_layout.addWidget(self.line_number_area)

        layout.addWidget(editor_frame)

    def create_output_frame(self, layout):
        output_frame = QFrame()
        output_layout = QHBoxLayout(output_frame)

        self.errors_text = QTextEdit()
        self.errors_text.setStyleSheet(
            "background-color: #FFF6FF; color: #845EC2; border: 2px ridge #9B89B3; font-size: 12px;"
        )
        self.errors_text.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        output_layout.addWidget(self.errors_text)

        self.quadruples_text = QTextBrowser()
        self.quadruples_text.setStyleSheet(
            "background-color: #FFF6FF; color: #845EC2; border: 2px ridge #9B89B3; font-size: 12px;"
        )
        self.quadruples_text.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)  # Adjusted size policy
        self.quadruples_text.setFontFamily("Courier")  # Set the font family to Courier
        output_layout.addWidget(self.quadruples_text)

        button_layout = QVBoxLayout()  # Vertical layout for buttons

        compile_button = QPushButton("Compile")
        compile_button.setStyleSheet("background-color: #845EC2; color: #ffffff; border: none; font-size: 12px;")
        compile_button.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        compile_button.setFixedSize(80, 40)  # Decreased width
        compile_button.clicked.connect(self.code_compilation)
        button_layout.addWidget(compile_button)

        select_file_button = QPushButton("Select File")
        select_file_button.setStyleSheet("background-color: #845EC2; color: #ffffff; border: none; font-size: 12px;")
        select_file_button.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        select_file_button.setFixedSize(80, 40)  # Decreased width
        select_file_button.clicked.connect(self.select_file)
        button_layout.addWidget(select_file_button)

        self.switch_button = QPushButton(self.display_mode)
        self.switch_button.setStyleSheet("background-color: #845EC2; color: #ffffff; border: none; font-size: 12px;")
        self.switch_button.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        self.switch_button.setFixedSize(80, 40)  # Decreased width
        self.switch_button.clicked.connect(self.switch_mode)
        button_layout.addWidget(self.switch_button)

        output_layout.addLayout(button_layout)  # Add button layout to the horizontal layout

        layout.addWidget(output_frame)


    def code_compilation(self):
        self.remove_files()

        code = self.code_text.toPlainText()

        with open("code.txt", "w") as file:
            file.write(code)

        os.system('"my_parser" < code.txt')

        self.display_results()

    def remove_files(self):
        files = ['./errors.txt', './quadruples.txt', './symbol_table.txt']
        for file_path in files:
            if os.path.isfile(file_path):
                os.remove(file_path)

    def display_results(self):
        try:
            if self.display_mode == "Symbol Table":
                with open("quadruples.txt", "r") as file:
                    symbol_table = file.read()
                self.quadruples_text.setPlainText(symbol_table)
            else:
                with open("symbol_table.txt", "r") as file:
                    quadruples = file.read()
                self.quadruples_text.setPlainText(quadruples)
        except FileNotFoundError:
            if self.display_mode == "Symbol Table":
                self.quadruples_text.setPlainText("quadruples file not found")
            else:
                self.quadruples_text.setPlainText("symbol table file not found")

        try:
            with open("errors.txt", "r") as file:
                errors = file.read()
            self.errors_text.setPlainText(errors)
        except FileNotFoundError:
            self.errors_text.setPlainText("Errors file not found")

    def select_file(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "Select file", "", "All Files (*);;Text Files (*.txt)")
        if file_name:
            with open(file_name, "r") as file:
                self.code_text.setPlainText(file.read())

    def switch_mode(self):
        if self.display_mode == "Symbol Table":
            self.display_mode = "Quadruples"
        else:
            self.display_mode = "Symbol Table"
        self.switch_button.setText(self.display_mode)
        self.display_results()


def main():
    app = QApplication(sys.argv)
    window = CompilerGUI()
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()

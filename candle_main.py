from PyQt5 import QtCore, QtGui, QtWidgets
from candle import *

def signals(self):
    self.pushButton_value.clicked.connect(lambda : self.stackedWidget.setCurrentIndex(0))
    self.pushButton_set.clicked.connect(lambda : self.stackedWidget.setCurrentIndex(1))
    self.pushButton_graph.clicked.connect(lambda : self.stackedWidget.setCurrentIndex(2))

Ui_MainWindow.signals = signals

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    ui.signals()

    MainWindow.show()
    sys.exit(app.exec_())
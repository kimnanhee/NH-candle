# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '.\candle.ui'
#
# Created by: PyQt5 UI code generator 5.15.1
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 500)
        MainWindow.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.pushButton_value = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_value.setGeometry(QtCore.QRect(690, 20, 90, 50))
        self.pushButton_value.setStyleSheet("font: 75 12pt \"Arial\";\n"
"background-color: rgb(156, 156, 156);")
        self.pushButton_value.setObjectName("pushButton_value")
        self.pushButton_graph = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_graph.setGeometry(QtCore.QRect(690, 90, 90, 50))
        self.pushButton_graph.setStyleSheet("font: 75 12pt \"Arial\";\n"
"background-color: rgb(156, 156, 156);")
        self.pushButton_graph.setObjectName("pushButton_graph")
        self.pushButton_set = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_set.setGeometry(QtCore.QRect(690, 160, 90, 50))
        self.pushButton_set.setStyleSheet("font: 75 12pt \"Arial\";\n"
"background-color: rgb(156, 156, 156);")
        self.pushButton_set.setObjectName("pushButton_set")
        self.stackedWidget = QtWidgets.QStackedWidget(self.centralwidget)
        self.stackedWidget.setGeometry(QtCore.QRect(20, 20, 620, 460))
        self.stackedWidget.setObjectName("stackedWidget")
        self.page_value = QtWidgets.QWidget()
        self.page_value.setObjectName("page_value")
        self.label_temp = QtWidgets.QLabel(self.page_value)
        self.label_temp.setGeometry(QtCore.QRect(100, 100, 120, 50))
        self.label_temp.setStyleSheet("background-color: rgb(211, 211, 211);\n"
"font: 12pt \"Arial\";")
        self.label_temp.setAlignment(QtCore.Qt.AlignCenter)
        self.label_temp.setObjectName("label_temp")
        self.label_humi = QtWidgets.QLabel(self.page_value)
        self.label_humi.setGeometry(QtCore.QRect(260, 100, 120, 50))
        self.label_humi.setStyleSheet("background-color: rgb(211, 211, 211);\n"
"font: 12pt \"Arial\";")
        self.label_humi.setAlignment(QtCore.Qt.AlignCenter)
        self.label_humi.setObjectName("label_humi")
        self.label_temp_value = QtWidgets.QLabel(self.page_value)
        self.label_temp_value.setGeometry(QtCore.QRect(100, 170, 120, 30))
        self.label_temp_value.setAlignment(QtCore.Qt.AlignCenter)
        self.label_temp_value.setObjectName("label_temp_value")
        self.label_humi_value = QtWidgets.QLabel(self.page_value)
        self.label_humi_value.setGeometry(QtCore.QRect(260, 170, 120, 30))
        self.label_humi_value.setAlignment(QtCore.Qt.AlignCenter)
        self.label_humi_value.setObjectName("label_humi_value")
        self.label_cds = QtWidgets.QLabel(self.page_value)
        self.label_cds.setGeometry(QtCore.QRect(420, 100, 120, 50))
        self.label_cds.setStyleSheet("background-color: rgb(211, 211, 211);\n"
"font: 12pt \"Arial\";")
        self.label_cds.setAlignment(QtCore.Qt.AlignCenter)
        self.label_cds.setObjectName("label_cds")
        self.label_cds_value = QtWidgets.QLabel(self.page_value)
        self.label_cds_value.setGeometry(QtCore.QRect(420, 170, 120, 30))
        self.label_cds_value.setAlignment(QtCore.Qt.AlignCenter)
        self.label_cds_value.setObjectName("label_cds_value")
        self.stackedWidget.addWidget(self.page_value)
        self.page_set = QtWidgets.QWidget()
        self.page_set.setObjectName("page_set")
        self.textEdit_R = QtWidgets.QTextEdit(self.page_set)
        self.textEdit_R.setGeometry(QtCore.QRect(110, 170, 100, 50))
        self.textEdit_R.setObjectName("textEdit_R")
        self.textEdit_G = QtWidgets.QTextEdit(self.page_set)
        self.textEdit_G.setGeometry(QtCore.QRect(270, 170, 100, 50))
        self.textEdit_G.setObjectName("textEdit_G")
        self.textEdit_B = QtWidgets.QTextEdit(self.page_set)
        self.textEdit_B.setGeometry(QtCore.QRect(430, 170, 100, 50))
        self.textEdit_B.setObjectName("textEdit_B")
        self.pushButton_set_2 = QtWidgets.QPushButton(self.page_set)
        self.pushButton_set_2.setGeometry(QtCore.QRect(260, 290, 120, 40))
        self.pushButton_set_2.setStyleSheet("font: 75 12pt \"Arial\";\n"
"background-color: rgb(156, 156, 156);")
        self.pushButton_set_2.setObjectName("pushButton_set_2")
        self.pushButton_R = QtWidgets.QPushButton(self.page_set)
        self.pushButton_R.setGeometry(QtCore.QRect(100, 100, 120, 50))
        self.pushButton_R.setStyleSheet("background-color: rgb(211, 211, 211);\n"
"font: 10pt \"Arial\";")
        self.pushButton_R.setObjectName("pushButton_R")
        self.pushButton_G = QtWidgets.QPushButton(self.page_set)
        self.pushButton_G.setGeometry(QtCore.QRect(260, 100, 120, 50))
        self.pushButton_G.setStyleSheet("background-color: rgb(211, 211, 211);\n"
"font: 10pt \"Arial\";")
        self.pushButton_G.setObjectName("pushButton_G")
        self.pushButton_B = QtWidgets.QPushButton(self.page_set)
        self.pushButton_B.setGeometry(QtCore.QRect(420, 100, 120, 50))
        self.pushButton_B.setStyleSheet("background-color: rgb(211, 211, 211);\n"
"font: 10pt \"Arial\";")
        self.pushButton_B.setObjectName("pushButton_B")
        self.stackedWidget.addWidget(self.page_set)
        self.page_graph = QtWidgets.QWidget()
        self.page_graph.setObjectName("page_graph")
        self.graphicsView = QtWidgets.QGraphicsView(self.page_graph)
        self.graphicsView.setGeometry(QtCore.QRect(0, 0, 620, 450))
        self.graphicsView.setObjectName("graphicsView")
        self.stackedWidget.addWidget(self.page_graph)
        self.line = QtWidgets.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(670, 20, 3, 460))
        self.line.setFrameShape(QtWidgets.QFrame.VLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.stackedWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.pushButton_value.setText(_translate("MainWindow", "Value"))
        self.pushButton_graph.setText(_translate("MainWindow", "Graph"))
        self.pushButton_set.setText(_translate("MainWindow", "Set"))
        self.label_temp.setText(_translate("MainWindow", "Temperature"))
        self.label_humi.setText(_translate("MainWindow", "Humidity"))
        self.label_temp_value.setText(_translate("MainWindow", "TextLabel"))
        self.label_humi_value.setText(_translate("MainWindow", "TextLabel"))
        self.label_cds.setText(_translate("MainWindow", "CDS"))
        self.label_cds_value.setText(_translate("MainWindow", "TextLabel"))
        self.pushButton_set_2.setText(_translate("MainWindow", "Set"))
        self.pushButton_R.setText(_translate("MainWindow", "R"))
        self.pushButton_G.setText(_translate("MainWindow", "G"))
        self.pushButton_B.setText(_translate("MainWindow", "B"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

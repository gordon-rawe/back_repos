/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created: Tue Jun 3 11:58:16 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QLabel *label;
    QGraphicsView *graphicsView;
    QSlider *slider;
    QPushButton *pushButton;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(800, 480);
        label = new QLabel(MyWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 480));
        graphicsView = new QGraphicsView(MyWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(50, 30, 700, 400));
        slider = new QSlider(MyWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(20, 25, 20, 410));
        slider->setPageStep(1);
        slider->setValue(50);
        slider->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 440, 100, 30));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QApplication::translate("MyWidget", "\345\233\236\345\210\260\344\270\273\351\241\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H

/********************************************************************************
** Form generated from reading UI file 'window2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW2_H
#define UI_WINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Window2
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *Window2)
    {
        if (Window2->objectName().isEmpty())
            Window2->setObjectName(QStringLiteral("Window2"));
        Window2->resize(400, 300);
        pushButton = new QPushButton(Window2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 70, 80, 25));

        retranslateUi(Window2);

        QMetaObject::connectSlotsByName(Window2);
    } // setupUi

    void retranslateUi(QDialog *Window2)
    {
        Window2->setWindowTitle(QApplication::translate("Window2", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Window2", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window2: public Ui_Window2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW2_H

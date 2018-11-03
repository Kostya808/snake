/********************************************************************************
** Form generated from reading UI file 'window3.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW3_H
#define UI_WINDOW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Window3
{
public:

    void setupUi(QDialog *Window3)
    {
        if (Window3->objectName().isEmpty())
            Window3->setObjectName(QStringLiteral("Window3"));
        Window3->resize(400, 300);

        retranslateUi(Window3);

        QMetaObject::connectSlotsByName(Window3);
    } // setupUi

    void retranslateUi(QDialog *Window3)
    {
        Window3->setWindowTitle(QApplication::translate("Window3", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window3: public Ui_Window3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW3_H

/********************************************************************************
** Form generated from reading UI file 'kwarningwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KWARNINGWINDOW_H
#define UI_KWARNINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kWarningWindow
{
public:

    void setupUi(QWidget *kWarningWindow)
    {
        if (kWarningWindow->objectName().isEmpty())
            kWarningWindow->setObjectName(QStringLiteral("kWarningWindow"));
        kWarningWindow->resize(400, 300);

        retranslateUi(kWarningWindow);

        QMetaObject::connectSlotsByName(kWarningWindow);
    } // setupUi

    void retranslateUi(QWidget *kWarningWindow)
    {
        kWarningWindow->setWindowTitle(QApplication::translate("kWarningWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class kWarningWindow: public Ui_kWarningWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KWARNINGWINDOW_H

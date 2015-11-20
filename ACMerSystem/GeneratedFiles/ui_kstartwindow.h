/********************************************************************************
** Form generated from reading UI file 'kstartwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KSTARTWINDOW_H
#define UI_KSTARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kStartWindow
{
public:

    void setupUi(QWidget *kStartWindow)
    {
        if (kStartWindow->objectName().isEmpty())
            kStartWindow->setObjectName(QStringLiteral("kStartWindow"));
        kStartWindow->resize(400, 300);

        retranslateUi(kStartWindow);

        QMetaObject::connectSlotsByName(kStartWindow);
    } // setupUi

    void retranslateUi(QWidget *kStartWindow)
    {
        kStartWindow->setWindowTitle(QApplication::translate("kStartWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class kStartWindow: public Ui_kStartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KSTARTWINDOW_H

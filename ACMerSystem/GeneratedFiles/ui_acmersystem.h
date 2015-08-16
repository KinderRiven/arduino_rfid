/********************************************************************************
** Form generated from reading UI file 'acmersystem.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACMERSYSTEM_H
#define UI_ACMERSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ACMerSystemClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ACMerSystemClass)
    {
        if (ACMerSystemClass->objectName().isEmpty())
            ACMerSystemClass->setObjectName(QStringLiteral("ACMerSystemClass"));
        ACMerSystemClass->resize(600, 400);
        menuBar = new QMenuBar(ACMerSystemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ACMerSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ACMerSystemClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ACMerSystemClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ACMerSystemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ACMerSystemClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ACMerSystemClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ACMerSystemClass->setStatusBar(statusBar);

        retranslateUi(ACMerSystemClass);

        QMetaObject::connectSlotsByName(ACMerSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *ACMerSystemClass)
    {
        ACMerSystemClass->setWindowTitle(QApplication::translate("ACMerSystemClass", "ACMerSystem", 0));
    } // retranslateUi

};

namespace Ui {
    class ACMerSystemClass: public Ui_ACMerSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACMERSYSTEM_H

/********************************************************************************
** Form generated from reading UI file 'project.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETFINALECHEC_H
#define UI_PROJETFINALECHEC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjetFinalEchecClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjetFinalEchecClass)
    {
        if (ProjetFinalEchecClass->objectName().isEmpty())
            ProjetFinalEchecClass->setObjectName("ProjetFinalEchecClass");
        ProjetFinalEchecClass->resize(600, 400);
        menuBar = new QMenuBar(ProjetFinalEchecClass);
        menuBar->setObjectName("menuBar");
        ProjetFinalEchecClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjetFinalEchecClass);
        mainToolBar->setObjectName("mainToolBar");
        ProjetFinalEchecClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProjetFinalEchecClass);
        centralWidget->setObjectName("centralWidget");
        ProjetFinalEchecClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProjetFinalEchecClass);
        statusBar->setObjectName("statusBar");
        ProjetFinalEchecClass->setStatusBar(statusBar);

        retranslateUi(ProjetFinalEchecClass);

        QMetaObject::connectSlotsByName(ProjetFinalEchecClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjetFinalEchecClass)
    {
        ProjetFinalEchecClass->setWindowTitle(QCoreApplication::translate("ProjetFinalEchecClass", "Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjetFinalEchecClass: public Ui_ProjetFinalEchecClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETFINALECHEC_H

/********************************************************************************
** Form generated from reading ui file 'AboutDialog.ui'
**
** Created: Fri Dec 25 10:28:09 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tabAbout;
    QLabel *labelAbout;
    QWidget *tabCredicts;
    QLabel *labelCredicts;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 381, 241));
        tabAbout = new QWidget();
        tabAbout->setObjectName(QString::fromUtf8("tabAbout"));
        labelAbout = new QLabel(tabAbout);
        labelAbout->setObjectName(QString::fromUtf8("labelAbout"));
        labelAbout->setGeometry(QRect(30, 60, 301, 101));
        tabWidget->addTab(tabAbout, QString());
        tabCredicts = new QWidget();
        tabCredicts->setObjectName(QString::fromUtf8("tabCredicts"));
        labelCredicts = new QLabel(tabCredicts);
        labelCredicts->setObjectName(QString::fromUtf8("labelCredits"));
        labelCredicts->setGeometry(QRect(50, 80, 261, 71));
        tabWidget->addTab(tabCredicts, QString());

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        labelAbout->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabAbout), QApplication::translate("Dialog", "About", 0, QApplication::UnicodeUTF8));
        labelCredicts->setText(QApplication::translate("Dialog", "jingwenlai@163.com", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCredicts), QApplication::translate("Dialog", "Credicts", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H

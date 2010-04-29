/********************************************************************************
** Form generated from reading ui file 'plugin_dialog.ui'
**
** Created: Thu Apr 29 14:30:45 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PLUGINDIALOG_H
#define UI_PLUGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_pluginDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *pluginDialog)
    {
        if (pluginDialog->objectName().isEmpty())
            pluginDialog->setObjectName(QString::fromUtf8("pluginDialog"));
        pluginDialog->resize(402, 303);
        buttonBox = new QDialogButtonBox(pluginDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(pluginDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 381, 221));

        retranslateUi(pluginDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), pluginDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pluginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(pluginDialog);
    } // setupUi

    void retranslateUi(QDialog *pluginDialog)
    {
        pluginDialog->setWindowTitle(QApplication::translate("pluginDialog", "Show Plugins", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(pluginDialog);
    } // retranslateUi

};

namespace Ui {
    class pluginDialog: public Ui_pluginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINDIALOG_H

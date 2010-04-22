#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "ui_AboutDialog.hpp"
#include "../Common/globals.hpp"
#include <QString>


class AboutDialog : public QDialog,public Ui_Dialog
{
public:
  AboutDialog(QWidget* parent = 0,Qt::WindowFlags f=0)
    : QDialog(parent,f)
  {
    setupUi(this);
    setVersion(MAIN_VERSION,MAJOR_VERSION,MINOR_VERSION);
    setWindowTitle("Mesh Deformer");
  }
  ~AboutDialog()
  {}
  void setVersion(int main,int major,int minor)
  {
    QString aboutString;
    QTextStream(&aboutString)<<"\t MeshDeformer: version: "<<main<<"."<<major<<"."<<minor<<"\n";
    QDate date = QDate::currentDate();
    QTextStream(&aboutString)<<"\t\t Build Date: "<<date.year()<<":"<<date.month()<<":"<<date.day()<<"\n";

    labelAbout->setText(aboutString);
  }
  
};

#endif

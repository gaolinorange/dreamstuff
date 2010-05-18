#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "ui_AboutDialog.hpp"
#include "../Common/globals.hpp"
#include <QString>
#include <QTextStream>
#include <QDateTime>

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
    QTextStream(&aboutString)<<"MeshDeformer: version: "<<main<<"."<<major<<"."<<minor<<"\n";
    QDateTime date_time = QDateTime::currentDateTime(  );
    QTextStream( &aboutString )<<date_time.toString( );

    labelAbout->setText(aboutString);
  }
  
};

#endif

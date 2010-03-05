/**
   MeshDeformer
   An experimental environment for mesh deformation
   author: jingwenlai@163.com
   links: blog.csdn.net/jingwenlai_scut
 */

#ifndef MESHDEFORMER_COMMON_LOGGERWIDGET_H
#define MESHDEFORMER_COMMON_LOGGERWIDGET_H

#include <QListWidget>


/**
   LoggerWidget
   @brief:
   A widget for displaying Logging messages 
   @details: an singleton instance of logger
 */
class LoggerWidget : public QListWidget
{
public:
  LoggerWidget(QWidget * parent = 0)
    : QListWidget(parent)
  {
  }
  ~LoggerWidget()
  {
  }
public:
  /**
     appendMessage:
     @param: message, the message append to the logger
   */
  void appendMessage(const QString& message)
  {
	addItem(message);
  }
};


#endif /* MESHDEFORMER_COMMON_QOUTPUTLOGGER_H */


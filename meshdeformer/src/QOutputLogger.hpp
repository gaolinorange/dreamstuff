/**
   MeshDeformer
   An experimental environment for mesh deformation
   author: jingwenlai@163.com
   links: blog.csdn.net/jingwenlai_scut
 */

#ifndef MESHDEFORMER_COMMON_QOUTPUTLOGGER_H
#define MESHDEFORMER_COMMON_QOUTPUTLOGGER_H

#include <QListWidget>
#include <QDockWidget>

/**
   QOutputLogger
   @brief: Logger for displaying messages
   @details: an singleton instance of logger
 */
class QOutputLogger : public QDockWidget
{
public:
  static QOutputLogger* getInstance()
  {
	  Q_ASSERT(logger != NULL);
	  return logger;
  }
public:
  static QOutputLogger* logger;
public:
  QOutputLogger(QString title = QString(QObject::tr("Logger")),QWidget * parent = 0)
    : QDockWidget(title,parent)
  {
	  listWidget = new QListWidget(this);
	  setWidget(listWidget);
  }
  virtual ~QOutputLogger()
  {
	  delete listWidget; listWidget = 0;
  }

public:
  /**
     appendMessage:
     @param: message, the message append to the logger
   */
	void appendMessage(const QString& message)
	{
		listWidget->addItem(message);
	}
private:
	QListWidget* listWidget;
};





#endif /* MESHDEFORMER_COMMON_QOUTPUTLOGGER_H */


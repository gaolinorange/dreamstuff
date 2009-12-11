#ifndef MESHDEFORMER_COMMON_QOUTPUTLOGGER_H
#define MESHDEFORMER_COMMON_QOUTPUTLOGGER_H

#include <QListWidget>
#include <QDockWidget>

class QOutputLogger : public QDockWidget
{
public:
  static QOutputLogger* getInstance()
  {
    /*if(NULL == logger)
      {
	logger = new QOutputLogger();
      }
	  */
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
	void appendMessage(const QString& message)
	{
		listWidget->addItem(message);
	}
private:
	QListWidget* listWidget;
};





#endif /* MESHDEFORMER_COMMON_QOUTPUTLOGGER_H */


#ifndef MESHDEFORMER_COMMON_QOUTPUTLOGGER_H
#define MESHDEFORMER_COMMON_QOUTPUTLOGGER_H

#include <QTextEdit>
#include <QDockWidget>

class QOutputLogger : public QTextEdit , public QDockWidget
{
public:
  static QOutputLogger* getInstance()
  {
    if(NULL == logger)
      {
	logger = new QOutputLogger();
      }
    return logger;
  }
private:
  static QOutputLogger* logger;
  
private:
  QOutputLogger(QString title = QString(QObject::tr("Logger")),QWidget * parent = 0);
  virtual ~QOutputLogger();
};

QOutputLogger* QOutputLogger::logger = NULL;



#endif /* MESHDEFORMER_COMMON_QOUTPUTLOGGER_H */


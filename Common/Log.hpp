#ifndef _LOG_H_
#define _LOG_H_

#include <string>
#include <iostream>
#include <stdarg.h>
#include <fstream>
using namespace std;


class Log
{
public:
  static Log * getInstance()
  {
    if(m_Log == NULL)
      {
	m_Log = new Log();
      }
    return m_Log;
  }
public:
  void logString(string message)
  {
    if(!outFile.is_open())
      {
	outFile.open("log.txt",ios::out);
      }
    outFile<<message<<std::endl;
    outFile.close();
  }
  void logString(char * message)
  {
    if(!outFile.is_open())
      outFile.open("log.txt",ios::out);
    outFile<<message<<std::endl;
    outFile.close();
  }
private:
  Log()
  {
    outFile.open("log.txt",ios::out);
    if(!outFile.is_open())
      {
	std::cerr<<"can not create log.txt file"<<std::endl;
      }
  }
  virtual ~Log()
  {}
private:
  static Log* m_Log;
  ofstream outFile;
};


Log* Log::m_Log = NULL;



#endif /* _LOG_H_ */

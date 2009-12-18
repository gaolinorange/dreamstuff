#ifndef GLOBALS_H
#define GLOBALS_H



//#define RUNNING_AT_TEST_MODE true
extern bool RUNNING_AT_TEST_MODE;


/*
//Some facility for debugging, defined in global mode
class AppSettings
{
public:
	static AppSettings getSingleton()
	{
		return settings;
	}
	static AppSettings* getSingletonPtr()
	{
		return &settings;
	}
public:
	AppSettings()
	{
		RUNNING_AT_TEST_MODE = false;
	}
	~AppSettings()
	{
	}


public:
	void setRunningAtTestMode(bool flag)
	{
		RUNNING_AT_TEST_MODE = flag;
	}
private:
	bool RUNNING_AT_TEST_MODE;
private:
	static AppSettings settings;
};
*/


#endif

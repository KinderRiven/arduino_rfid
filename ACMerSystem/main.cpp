#include "acmersystem.h"
#include <QtWidgets/QApplication>
#include "kUserData.h"
#include "kwarningwindow.h"
#include "kHead.h"
#include "computerSystem.h"
#include "kstartwindow.h"

/*
	userData
*/
string kUserData::dataBase = "rfid";
string kUserData::IP = "127.0.0.1";
string kUserData::Port	= "21";
string kUserData::UserName = "NULL";
string kUserData::PassWord = "";
string kUserData::SavePath = "data/";
string kUserData::UserFile = "user";
string kUserData::TimeFile = "time";

string kUserData::config_path	= "mysqlServer\\config";
string kUserData::userdata_path = "mysqlServer\\data\\";
string kUserData::image_path	= "Resources\\image\\";
string kUserData::user_record	= "mysqlServer\\user";
string kUserData::time_record   = "mysqlServer\\time";

bool kUserData::isLogin = false;
/*
	
*/
int ComputerSystem::screenHeight;
int ComputerSystem::screenWidth;

int main(int argc, char *argv[])
{

	/*
		run
	*/
	QApplication a(argc, argv);

	/*
		获取电脑屏幕大小
	*/

	ComputerSystem::getScren();
	/*
		start
	*/
	kStartWindow k;
	k.kShow();

	return a.exec();

}

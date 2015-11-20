#ifndef KUSERDATA_H
#define KUSERDATA_H
#include "kHead.h"

namespace kSource{

};
class kUserData{
public:
	static string IP;
	static string Port;
	static string UserName;
	static string PassWord;
	static string dataBase;
	static string SavePath;
	static string UserFile;
	static string TimeFile;
	static bool isLogin;

	static string userdata_path;
	static string config_path;
	static string image_path;
	static string user_record;
	static string time_record;

public:
	static void LoadData();
	static void SaveData();
};
/*
	userData
*/
#endif;
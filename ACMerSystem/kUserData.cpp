#include "kUserData.h"

void kUserData::LoadData(){
	string path = config_path;
	fstream fstr(path);
	char str[128];
	int Case = 0;
	while (fstr.getline(str, sizeof(str))){

		if (Case == 0)
			dataBase = string(str);
		else if (Case == 1)
			IP = string(str);
		else if (Case == 2)
			Port = string(str);
		else if (Case == 3)
			SavePath = string(str);
		else if (Case == 4)
			UserFile = string(str);
		else if (Case == 5)
			TimeFile = string(str);
		else if (Case == 6)
			UserName = string(str);
		else if (Case == 7)
			PassWord = string(str);
		Case++;

	}
	fstr.close();
}

void kUserData::SaveData(){

	fstream fstr;
	string path = config_path;
	fstr.open(path, ios::out);
	fstr << dataBase << endl;
	fstr << IP << endl;
	fstr << Port << endl;
	fstr << SavePath << endl;
	fstr << UserFile << endl;
	fstr << TimeFile << endl;
	fstr << UserName << endl;
	fstr << PassWord;
	fstr.close();

}

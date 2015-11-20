#include "kMusicData.h"
void kMusicData::errorSound(){
	QSound::play("Resources\\music\\exit.wav");
}

void kMusicData::successSound(){
	QSound::play("Resources\\music\\welcome.wav");
}

void kMusicData::systemSound(){
	QSound::play("Resources\\music\\system.wav");
}

void kMusicData::menuSound(){
	QSound::play("Resources\\music\\menu.wav");
}

void kMusicData::settingSound(){
	QSound::play("Resources\\music\\setting.wav");
}
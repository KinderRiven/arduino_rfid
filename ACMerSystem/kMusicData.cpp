#include "kMusicData.h"
void kMusicData::errorSound(){
	QSound::play("Resources\\music\\exit.wav");
}

void kMusicData::successSound(){
	QSound::play("Resources\\music\\welcome.wav");
}
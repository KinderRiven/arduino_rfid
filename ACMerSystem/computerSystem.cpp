#include "computerSystem.h"
void ComputerSystem::getScren(){

	QDesktopWidget* desktop = QApplication::desktop();
	QRect qrect= desktop->screenGeometry();
	ComputerSystem::screenWidth  = qrect.width();
	ComputerSystem::screenHeight = qrect.height();
}


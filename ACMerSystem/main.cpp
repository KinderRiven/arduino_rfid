#include "acmersystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ACMerSystem w;
	w.show();
	return a.exec();
}

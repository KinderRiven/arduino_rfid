#ifndef KSTARTWINDOW_H
#define KSTARTWINDOW_H

#include <QWidget>
#include "kHead.h"
#include "acmersystem.h"

namespace Ui {
class kStartWindow;
}

class kStartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit kStartWindow(QWidget *parent = 0);
    ~kStartWindow();
	void kShow();
protected:
	void paintEvent(QPaintEvent*);						//»æÍ¼
	void timerEvent(QTimerEvent *event);
private:
    Ui::kStartWindow *ui;
	QPixmap windowImage;
	ACMerSystem mainWindow;
	int timeid;
	double cost;
};

#endif // KSTARTWINDOW_H

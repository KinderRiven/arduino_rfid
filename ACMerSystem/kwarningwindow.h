#ifndef KWARNINGWINDOW_H
#define KWARNINGWINDOW_H

#include <QWidget>
#include <kHead.h>
#include "kMusicData.h"

namespace Ui {
class kWarningWindow;
}

class kWarningWindow : public QWidget
{
    Q_OBJECT

public:
    explicit kWarningWindow(QWidget *parent = 0);
    ~kWarningWindow();
	void kShow(int type = 0);
protected:
	void paintEvent(QPaintEvent*);
	void timerEvent(QTimerEvent *event);
private:
    Ui::kWarningWindow *ui;
	QPixmap windowImage;
	int timeid;
};

#endif // KWARNINGWINDOW_H

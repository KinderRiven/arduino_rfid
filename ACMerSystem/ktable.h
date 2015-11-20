#ifndef KTABLE_H
#define KTABLE_H

#include <QWidget>
#include "kHead.h"
#include "computerSystem.h"
#include "kshowdata.h"
#include "kUserData.h"
#include "kMusicData.h"

namespace Ui {
class kTable;
}
/*
	280 740
*/
class kTable : public QWidget
{
    Q_OBJECT
public slots:
	void slotRowDoubleClicked(QModelIndex indx);
	void closeButton();
	void updateButton();
public:
    explicit kTable(QWidget *parent = 0);
    ~kTable();
	void kShow();
	void addColumn(QStandardItemModel *model, int row, int col, QString qstr);
	void update();
protected:
	void mousePressEvent(QMouseEvent *event);			//重写鼠标点击事件
	void mouseMoveEvent(QMouseEvent *event);			//重写鼠标移动事件
	void timerEvent(QTimerEvent *event);
private:

    Ui::kTable *ui;
	QPoint  mousePrepos;								//记录鼠标之前的位置

	kShowData* showdata_list[1024];
	int showdata_num;
	
	string path;
	int timeid;
	int max_height;
	int max_width;

	QStandardItemModel *cid_model;
};

#endif // KTABLE_H

#include "ktable.h"
#include "ui_ktable.h"

kTable::kTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kTable){

    ui->setupUi(this);

	path = kUserData::user_record;


	/*
		隐藏
	*/
	setWindowFlags(Qt::FramelessWindowHint);
	
	//
	max_width  = 280;
	max_height = 740;

	/*
		设置表头
	*/
	cid_model = new QStandardItemModel();
	cid_model -> setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Card ID")));

	ui -> tableView -> horizontalHeader() -> hide();
	ui -> tableView -> setModel(cid_model);

	/*
		双击信号
	*/
	connect(ui -> tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(slotRowDoubleClicked(const QModelIndex &)));
	connect(ui -> button_close, SIGNAL(clicked()), this, SLOT(closeButton()));
	connect(ui -> button_update, SIGNAL(clicked()), this, SLOT(updateButton()));
}
void kTable::closeButton(){
	hide();
}
void kTable::updateButton(){
	update();
}
void kTable::slotRowDoubleClicked(QModelIndex indx){

	showdata_list[indx.row()]->kShow();
}
/*
	row hang
	col lie		
*/
void kTable::addColumn(QStandardItemModel *model, int row, int col, QString qstr){

	QIcon icon("Resources\\image\\user");
	QStandardItem *qstand = new QStandardItem(icon, "    " + qstr);
	model->setItem(row, col, qstand);
}

kTable::~kTable(){

    delete ui;
}

void kTable::update(){

	cid_model->clear();

	showdata_num = 0;

	fstream fs(path);
	char str[128];
	int num = 0;
	while (fs.getline(str, sizeof(str))){

		addColumn(cid_model, num++, 0, QString(str));
		kShowData* tmp = new kShowData();
		tmp -> cid = string(str);
		showdata_list[showdata_num++] = tmp;

	}
}

void kTable::kShow(){

	update();

	resize(QSize(0, ComputerSystem::screenHeight));

	setWindowOpacity(0.3);

	move(QPoint(0, max_height / 4));

	timeid = startTimer(10);

	kMusicData::settingSound();

	show();

	//ui->tableView->setColumnWidth(0, 250);
}

/*
	Mouse move
*/
void kTable::mousePressEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		mousePrepos = cursor().pos();
		update();
	}
}

void kTable::mouseMoveEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		QPoint mousePos = cursor().pos();

		//窗口移动公式
		int posX = pos().x() + mousePos.x() - mousePrepos.x();
		int posY = pos().y() + mousePos.y() - mousePrepos.y();

		if (posX < 0) posX = 0;
		if (posY < 0) posY = 0;

		if (posX + width() > ComputerSystem::screenWidth)
			posX = ComputerSystem::screenWidth - width();
		if (posY + height() > ComputerSystem::screenHeight)
			posY = ComputerSystem::screenHeight - height();

		move(QPoint(posX, posY));
		mousePrepos = mousePos;
	}
}

void kTable::timerEvent(QTimerEvent *event){

	if (event->timerId() == timeid){
		int now_width = width();
		double op = windowOpacity();

		if (op + 0.1 <= 0.8){

			setWindowOpacity(op + 0.1);
		}

		if (now_width + 28 <= 280){
			resize(now_width + 28, max_height);
		}
		else{
			ui->tableView->setColumnWidth(0, max_width - 25);
			killTimer(timeid);
		}
	}
}
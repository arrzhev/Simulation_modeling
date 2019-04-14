#include "Settings.h"

Settings::Settings(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Settings::setWindowFlags(Qt::WindowStaysOnTopHint);
	this->setFixedSize(this->geometry().width(), this->geometry().height());

	warning = new QMessageBox(QMessageBox::Critical, "ERROR", "Some fields are empty or have invalid value");
	warning->setWindowFlags(Qt::WindowStaysOnTopHint);

	saveError = new QMessageBox(QMessageBox::Critical, "ERROR", "Settings cannot be saved");
	saveError->setWindowFlags(Qt::WindowStaysOnTopHint);

	loadError = new QMessageBox(QMessageBox::Critical, "ERROR", "Settings cannot be loaded");
	loadError->setWindowFlags(Qt::WindowStaysOnTopHint);

	wrongPassword = new QMessageBox(QMessageBox::Critical, "ERROR", "Wrong Password");
	wrongPassword->setWindowFlags(Qt::WindowStaysOnTopHint);

	moneyWarning = new QMessageBox(QMessageBox::Critical, "ERROR", "Not enough money");
	moneyWarning->setWindowFlags(Qt::WindowStaysOnTopHint);

	connect(ui.nextButton, SIGNAL(clicked()), this, SLOT(nextBtnClicked()));
	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(backBtnClicked()));
	connect(ui.finishButton, SIGNAL(clicked()), this, SLOT(finishBtnClicked()));
	connect(ui.saveAndFinishButton, SIGNAL(clicked()), this, SLOT(saveAndFinishBtnClicked()));
	connect(ui.loadButton, SIGNAL(clicked()), this, SLOT(loadBtnClicked()));
	connect(ui.repairButton, SIGNAL(clicked()), this, SLOT(repairBtnClicked()));

	showZeroSetList();
}

Settings::Settings(const Settings& set, QWidget *parent)
	: Settings(parent)
{
	setSettings(set);
}

void Settings::showZeroSetList()
{
	this->setWindowTitle(QString::fromLocal8Bit("Создание симуляции"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(true);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(false);
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::fromLocal8Bit("Введите пароль"));
	ui.lineEdit11->setReadOnly(false);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);


	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showFirstSetList()
{
	QRegExp rx("^[0-9]{3}$");
	QValidator *validator = new QRegExpValidator(rx, this);

	this->setWindowTitle(QString::fromLocal8Bit("Настройка партий бревен"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Кол-во бревен в партии"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(true);
	ui.label15->setText(QString::fromLocal8Bit("Стоимость пропуска партии"));
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Дефект влажности"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Дефект кол-ва сучков"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Дефект диаметра"));
	ui.label19->setVisible(true);
	ui.label19->setText(QString::fromLocal8Bit("Дефект длины"));
	ui.label20->setVisible(true);
	ui.label20->setText(QString::fromLocal8Bit("Дефект гнили"));
	ui.label21->setVisible(true);
	ui.label21->setText(QString::fromLocal8Bit("Дефект трещин"));

	ui.label1->setText(QString::fromLocal8Bit("1 партия"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setValidator(validator);
	ui.lineEdit11->setText(QString::number(firstSetList.batch[0].count));
	ui.lineEdit11->setReadOnly(false);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(true);
	ui.lineEdit14->setValidator(validator);
	ui.lineEdit14->setText(QString::number(firstSetList.batch[0].skipCost));
	ui.lineEdit14->setReadOnly(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(firstSetList.batch[0].hymidity);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(firstSetList.batch[0].knotCount);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(firstSetList.batch[0].diametr);
	ui.checkBox14->setVisible(true);
	ui.checkBox14->setChecked(firstSetList.batch[0].length);
	ui.checkBox15->setVisible(true);
	ui.checkBox15->setChecked(firstSetList.batch[0].mould);
	ui.checkBox16->setVisible(true);
	ui.checkBox16->setChecked(firstSetList.batch[0].crack);

	ui.label2->setText(QString::fromLocal8Bit("2 партия"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setValidator(validator);
	ui.lineEdit21->setText(QString::number(firstSetList.batch[1].count));
	ui.lineEdit21->setReadOnly(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(true);
	ui.lineEdit24->setValidator(validator);
	ui.lineEdit24->setText(QString::number(firstSetList.batch[1].skipCost));
	ui.lineEdit24->setReadOnly(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(firstSetList.batch[1].hymidity);
	ui.checkBox22->setVisible(true);
	ui.checkBox22->setChecked(firstSetList.batch[1].knotCount);
	ui.checkBox23->setVisible(true);
	ui.checkBox23->setChecked(firstSetList.batch[1].diametr);
	ui.checkBox24->setVisible(true);
	ui.checkBox24->setChecked(firstSetList.batch[1].length);
	ui.checkBox25->setVisible(true);
	ui.checkBox25->setChecked(firstSetList.batch[1].mould);
	ui.checkBox26->setVisible(true);
	ui.checkBox26->setChecked(firstSetList.batch[1].crack);

	ui.label3->setText(QString::fromLocal8Bit("3 партия"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setValidator(validator);
	ui.lineEdit31->setText(QString::number(firstSetList.batch[2].count));
	ui.lineEdit31->setReadOnly(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(true);
	ui.lineEdit34->setValidator(validator);
	ui.lineEdit34->setText(QString::number(firstSetList.batch[2].skipCost));
	ui.lineEdit34->setReadOnly(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(firstSetList.batch[2].hymidity);
	ui.checkBox32->setVisible(true);
	ui.checkBox32->setChecked(firstSetList.batch[2].knotCount);
	ui.checkBox33->setVisible(true);
	ui.checkBox33->setChecked(firstSetList.batch[2].diametr);
	ui.checkBox34->setVisible(true);
	ui.checkBox34->setChecked(firstSetList.batch[2].length);
	ui.checkBox35->setVisible(true);
	ui.checkBox35->setChecked(firstSetList.batch[2].mould);
	ui.checkBox36->setVisible(true);
	ui.checkBox36->setChecked(firstSetList.batch[2].crack);

	ui.label4->setText(QString::fromLocal8Bit("4 партия"));
	ui.label4->setVisible(true);
	ui.lineEdit41->setVisible(true);
	ui.lineEdit41->setValidator(validator);
	ui.lineEdit41->setText(QString::number(firstSetList.batch[3].count));
	ui.lineEdit41->setReadOnly(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(true);
	ui.lineEdit44->setValidator(validator);
	ui.lineEdit44->setText(QString::number(firstSetList.batch[3].skipCost));
	ui.lineEdit44->setReadOnly(false);
	ui.checkBox41->setVisible(true);
	ui.checkBox41->setChecked(firstSetList.batch[3].hymidity);
	ui.checkBox42->setVisible(true);
	ui.checkBox42->setChecked(firstSetList.batch[3].knotCount);
	ui.checkBox43->setVisible(true);
	ui.checkBox43->setChecked(firstSetList.batch[3].diametr);
	ui.checkBox44->setVisible(true);
	ui.checkBox44->setChecked(firstSetList.batch[3].length);
	ui.checkBox45->setVisible(true);
	ui.checkBox45->setChecked(firstSetList.batch[3].mould);
	ui.checkBox46->setVisible(true);
	ui.checkBox46->setChecked(firstSetList.batch[3].crack);

	ui.label5->setText(QString::fromLocal8Bit("5 партия"));
	ui.label5->setVisible(true);
	ui.lineEdit51->setVisible(true);
	ui.lineEdit51->setValidator(validator);
	ui.lineEdit51->setText(QString::number(firstSetList.batch[4].count));
	ui.lineEdit51->setReadOnly(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(true);
	ui.lineEdit54->setValidator(validator);
	ui.lineEdit54->setText(QString::number(firstSetList.batch[4].skipCost));
	ui.lineEdit54->setReadOnly(false);
	ui.checkBox51->setVisible(true);
	ui.checkBox51->setChecked(firstSetList.batch[4].hymidity);
	ui.checkBox52->setVisible(true);
	ui.checkBox52->setChecked(firstSetList.batch[4].knotCount);
	ui.checkBox53->setVisible(true);
	ui.checkBox53->setChecked(firstSetList.batch[4].diametr);
	ui.checkBox54->setVisible(true);
	ui.checkBox54->setChecked(firstSetList.batch[4].length);
	ui.checkBox55->setVisible(true);
	ui.checkBox55->setChecked(firstSetList.batch[4].mould);
	ui.checkBox56->setVisible(true);
	ui.checkBox56->setChecked(firstSetList.batch[4].crack);

	ui.label6->setText(QString::fromLocal8Bit("6 партия"));
	ui.label6->setVisible(true);
	ui.lineEdit61->setVisible(true);
	ui.lineEdit61->setValidator(validator);
	ui.lineEdit61->setText(QString::number(firstSetList.batch[5].count));
	ui.lineEdit61->setReadOnly(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(true);
	ui.lineEdit64->setValidator(validator);
	ui.lineEdit64->setText(QString::number(firstSetList.batch[5].skipCost));
	ui.lineEdit64->setReadOnly(false);
	ui.checkBox61->setVisible(true);
	ui.checkBox61->setChecked(firstSetList.batch[5].hymidity);
	ui.checkBox62->setVisible(true);
	ui.checkBox62->setChecked(firstSetList.batch[5].knotCount);
	ui.checkBox63->setVisible(true);
	ui.checkBox63->setChecked(firstSetList.batch[5].diametr);
	ui.checkBox64->setVisible(true);
	ui.checkBox64->setChecked(firstSetList.batch[5].length);
	ui.checkBox65->setVisible(true);
	ui.checkBox65->setChecked(firstSetList.batch[5].mould);
	ui.checkBox66->setVisible(true);
	ui.checkBox66->setChecked(firstSetList.batch[5].crack);

	ui.label7->setText(QString::fromLocal8Bit("7 партия"));
	ui.label7->setVisible(true);
	ui.lineEdit71->setVisible(true);
	ui.lineEdit71->setValidator(validator);
	ui.lineEdit71->setText(QString::number(firstSetList.batch[6].count));
	ui.lineEdit71->setReadOnly(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(true);
	ui.lineEdit74->setValidator(validator);
	ui.lineEdit74->setText(QString::number(firstSetList.batch[6].skipCost));
	ui.lineEdit74->setReadOnly(false);
	ui.checkBox71->setVisible(true);
	ui.checkBox71->setChecked(firstSetList.batch[6].hymidity);
	ui.checkBox72->setVisible(true);
	ui.checkBox72->setChecked(firstSetList.batch[6].knotCount);
	ui.checkBox73->setVisible(true);
	ui.checkBox73->setChecked(firstSetList.batch[6].diametr);
	ui.checkBox74->setVisible(true);
	ui.checkBox74->setChecked(firstSetList.batch[6].length);
	ui.checkBox75->setVisible(true);
	ui.checkBox75->setChecked(firstSetList.batch[6].mould);
	ui.checkBox76->setVisible(true);
	ui.checkBox76->setChecked(firstSetList.batch[6].crack);

	ui.label8->setText(QString::fromLocal8Bit("8 партия"));
	ui.label8->setVisible(true);
	ui.lineEdit81->setVisible(true);
	ui.lineEdit81->setValidator(validator);
	ui.lineEdit81->setText(QString::number(firstSetList.batch[7].count));
	ui.lineEdit81->setReadOnly(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(true);
	ui.lineEdit84->setValidator(validator);
	ui.lineEdit84->setText(QString::number(firstSetList.batch[7].skipCost));
	ui.lineEdit84->setReadOnly(false);
	ui.checkBox81->setVisible(true);
	ui.checkBox81->setChecked(firstSetList.batch[7].hymidity);
	ui.checkBox82->setVisible(true);
	ui.checkBox82->setChecked(firstSetList.batch[7].knotCount);
	ui.checkBox83->setVisible(true);
	ui.checkBox83->setChecked(firstSetList.batch[7].diametr);
	ui.checkBox84->setVisible(true);
	ui.checkBox84->setChecked(firstSetList.batch[7].length);
	ui.checkBox85->setVisible(true);
	ui.checkBox85->setChecked(firstSetList.batch[7].mould);
	ui.checkBox86->setVisible(true);
	ui.checkBox86->setChecked(firstSetList.batch[7].crack);

	ui.label9->setText(QString::fromLocal8Bit("9 партия"));
	ui.label9->setVisible(true);
	ui.lineEdit91->setVisible(true);
	ui.lineEdit91->setValidator(validator);
	ui.lineEdit91->setText(QString::number(firstSetList.batch[8].count));
	ui.lineEdit91->setReadOnly(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(true);
	ui.lineEdit94->setValidator(validator);
	ui.lineEdit94->setText(QString::number(firstSetList.batch[8].skipCost));
	ui.lineEdit94->setReadOnly(false);
	ui.checkBox91->setVisible(true);
	ui.checkBox91->setChecked(firstSetList.batch[8].hymidity);
	ui.checkBox92->setVisible(true);
	ui.checkBox92->setChecked(firstSetList.batch[8].knotCount);
	ui.checkBox93->setVisible(true);
	ui.checkBox93->setChecked(firstSetList.batch[8].diametr);
	ui.checkBox94->setVisible(true);
	ui.checkBox94->setChecked(firstSetList.batch[8].length);
	ui.checkBox95->setVisible(true);
	ui.checkBox95->setChecked(firstSetList.batch[8].mould);
	ui.checkBox96->setVisible(true);
	ui.checkBox96->setChecked(firstSetList.batch[8].crack);

	ui.label10->setText(QString::fromLocal8Bit("10 партия"));
	ui.label10->setVisible(true);
	ui.lineEdit101->setVisible(true);
	ui.lineEdit101->setValidator(validator);
	ui.lineEdit101->setText(QString::number(firstSetList.batch[9].count));
	ui.lineEdit101->setReadOnly(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(true);
	ui.lineEdit104->setValidator(validator);
	ui.lineEdit104->setText(QString::number(firstSetList.batch[9].skipCost));
	ui.lineEdit104->setReadOnly(false);
	ui.checkBox101->setVisible(true);
	ui.checkBox101->setChecked(firstSetList.batch[9].hymidity);
	ui.checkBox102->setVisible(true);
	ui.checkBox102->setChecked(firstSetList.batch[9].knotCount);
	ui.checkBox103->setVisible(true);
	ui.checkBox103->setChecked(firstSetList.batch[9].diametr);
	ui.checkBox104->setVisible(true);
	ui.checkBox104->setChecked(firstSetList.batch[9].length);
	ui.checkBox105->setVisible(true);
	ui.checkBox105->setChecked(firstSetList.batch[9].mould);
	ui.checkBox106->setVisible(true);
	ui.checkBox106->setChecked(firstSetList.batch[9].crack);

	ui.label11->setVisible(true);
	ui.label11->setText(QString::fromLocal8Bit("Общее кол-во денег"));
	ui.lineEdit111->setVisible(true);
	ui.lineEdit111->setValidator(validator);
	ui.lineEdit111->setText(QString::number(firstSetList.money));
	
}

void Settings::showSecondSetList()
{
	QRegExp rx("^[0-9]{3}$");
	QValidator *validator = new QRegExpValidator(rx, this);

	this->setWindowTitle(QString::fromLocal8Bit("Настройка параметров станков"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(true);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Деталей до 1 поломки"));
	ui.label13->setVisible(true);
	ui.label13->setText(QString::fromLocal8Bit("Деталей до 2 поломки"));
	ui.label14->setVisible(true);
	ui.label14->setText(QString::fromLocal8Bit("Деталей до 3 поломки"));
	ui.label15->setVisible(true);
	ui.label15->setText(QString::fromLocal8Bit("Стоимость ремонта"));
	ui.label16->setVisible(false);
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("Пилорама"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setValidator(validator);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[0].toFirstBreakdown));
	ui.lineEdit11->setReadOnly(false);
	ui.lineEdit12->setVisible(true);
	ui.lineEdit12->setValidator(validator);
	ui.lineEdit12->setText(QString::number(secondSetList.bench[0].toSecondBreakdown));
	ui.lineEdit12->setReadOnly(false);
	ui.lineEdit13->setVisible(true);
	ui.lineEdit13->setValidator(validator);
	ui.lineEdit13->setText(QString::number(secondSetList.bench[0].toThirdBreakdown));
	ui.lineEdit13->setReadOnly(false);
	ui.lineEdit14->setVisible(true);
	ui.lineEdit14->setValidator(validator);
	ui.lineEdit14->setText(QString::number(secondSetList.bench[0].repairCost));
	ui.lineEdit14->setReadOnly(false);
	ui.checkBox11->setVisible(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("Сушильная камера"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setValidator(validator);
	ui.lineEdit21->setText(QString::number(secondSetList.bench[1].toFirstBreakdown));
	ui.lineEdit21->setReadOnly(false);
	ui.lineEdit22->setVisible(true);
	ui.lineEdit22->setValidator(validator);
	ui.lineEdit22->setText(QString::number(secondSetList.bench[1].toSecondBreakdown));
	ui.lineEdit22->setReadOnly(false);
	ui.lineEdit23->setVisible(true);
	ui.lineEdit23->setValidator(validator);
	ui.lineEdit23->setText(QString::number(secondSetList.bench[1].toThirdBreakdown));
	ui.lineEdit23->setReadOnly(false);
	ui.lineEdit24->setVisible(true);
	ui.lineEdit24->setValidator(validator);
	ui.lineEdit24->setText(QString::number(secondSetList.bench[1].repairCost));
	ui.lineEdit24->setReadOnly(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("Сортировочный станок"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setValidator(validator);
	ui.lineEdit31->setText(QString::number(secondSetList.bench[2].toFirstBreakdown));
	ui.lineEdit31->setReadOnly(false);
	ui.lineEdit32->setVisible(true);
	ui.lineEdit32->setValidator(validator);
	ui.lineEdit32->setText(QString::number(secondSetList.bench[2].toSecondBreakdown));
	ui.lineEdit32->setReadOnly(false);
	ui.lineEdit33->setVisible(true);
	ui.lineEdit33->setValidator(validator);
	ui.lineEdit33->setText(QString::number(secondSetList.bench[2].toThirdBreakdown));
	ui.lineEdit33->setReadOnly(false);
	ui.lineEdit34->setVisible(true);
	ui.lineEdit34->setValidator(validator);
	ui.lineEdit34->setText(QString::number(secondSetList.bench[2].repairCost));
	ui.lineEdit34->setReadOnly(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setText(QString::fromLocal8Bit("Фрезерный станок для досок 1 сорта"));
	ui.label4->setVisible(true);
	ui.lineEdit41->setVisible(true);
	ui.lineEdit41->setValidator(validator);
	ui.lineEdit41->setText(QString::number(secondSetList.bench[3].toFirstBreakdown));
	ui.lineEdit41->setReadOnly(false);
	ui.lineEdit42->setVisible(true);
	ui.lineEdit42->setValidator(validator);
	ui.lineEdit42->setText(QString::number(secondSetList.bench[3].toSecondBreakdown));
	ui.lineEdit42->setReadOnly(false);
	ui.lineEdit43->setVisible(true);
	ui.lineEdit43->setValidator(validator);
	ui.lineEdit43->setText(QString::number(secondSetList.bench[3].toThirdBreakdown));
	ui.lineEdit43->setReadOnly(false);
	ui.lineEdit44->setVisible(true);
	ui.lineEdit44->setValidator(validator);
	ui.lineEdit44->setText(QString::number(secondSetList.bench[3].repairCost));
	ui.lineEdit44->setReadOnly(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setText(QString::fromLocal8Bit("Фрезерный станок для досок 2 сорта"));
	ui.label5->setVisible(true);
	ui.lineEdit51->setVisible(true);
	ui.lineEdit51->setValidator(validator);
	ui.lineEdit51->setText(QString::number(secondSetList.bench[4].toFirstBreakdown));
	ui.lineEdit51->setReadOnly(false);
	ui.lineEdit52->setVisible(true);
	ui.lineEdit52->setValidator(validator);
	ui.lineEdit52->setText(QString::number(secondSetList.bench[4].toSecondBreakdown));
	ui.lineEdit52->setReadOnly(false);
	ui.lineEdit53->setVisible(true);
	ui.lineEdit53->setValidator(validator);
	ui.lineEdit53->setText(QString::number(secondSetList.bench[4].toThirdBreakdown));
	ui.lineEdit53->setReadOnly(false);
	ui.lineEdit54->setVisible(true);
	ui.lineEdit54->setValidator(validator);
	ui.lineEdit54->setText(QString::number(secondSetList.bench[4].repairCost));
	ui.lineEdit54->setReadOnly(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setText(QString::fromLocal8Bit("Фрезерный станок для досок 3 сорта"));
	ui.label6->setVisible(true);
	ui.lineEdit61->setVisible(true);
	ui.lineEdit61->setValidator(validator);
	ui.lineEdit61->setText(QString::number(secondSetList.bench[5].toFirstBreakdown));
	ui.lineEdit61->setReadOnly(false);
	ui.lineEdit62->setVisible(true);
	ui.lineEdit62->setValidator(validator);
	ui.lineEdit62->setText(QString::number(secondSetList.bench[5].toSecondBreakdown));
	ui.lineEdit62->setReadOnly(false);
	ui.lineEdit63->setVisible(true);
	ui.lineEdit63->setValidator(validator);
	ui.lineEdit63->setText(QString::number(secondSetList.bench[5].toThirdBreakdown));
	ui.lineEdit63->setReadOnly(false);
	ui.lineEdit64->setVisible(true);
	ui.lineEdit64->setValidator(validator);
	ui.lineEdit64->setText(QString::number(secondSetList.bench[5].repairCost));
	ui.lineEdit64->setReadOnly(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setText(QString::fromLocal8Bit("Сборочный станок для дверей 1 сорта"));
	ui.label7->setVisible(true);
	ui.lineEdit71->setVisible(true);
	ui.lineEdit71->setValidator(validator);
	ui.lineEdit71->setText(QString::number(secondSetList.bench[6].toFirstBreakdown));
	ui.lineEdit71->setReadOnly(false);
	ui.lineEdit72->setVisible(true);
	ui.lineEdit72->setValidator(validator);
	ui.lineEdit72->setText(QString::number(secondSetList.bench[6].toSecondBreakdown));
	ui.lineEdit72->setReadOnly(false);
	ui.lineEdit73->setVisible(true);
	ui.lineEdit73->setValidator(validator);
	ui.lineEdit73->setText(QString::number(secondSetList.bench[6].toThirdBreakdown));
	ui.lineEdit73->setReadOnly(false);
	ui.lineEdit74->setVisible(true);
	ui.lineEdit74->setValidator(validator);
	ui.lineEdit74->setText(QString::number(secondSetList.bench[6].repairCost));
	ui.lineEdit74->setReadOnly(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setText(QString::fromLocal8Bit("Сборочный станок для дверей 2 сорта"));
	ui.label8->setVisible(true);
	ui.lineEdit81->setVisible(true);
	ui.lineEdit81->setValidator(validator);
	ui.lineEdit81->setText(QString::number(secondSetList.bench[7].toFirstBreakdown));
	ui.lineEdit81->setReadOnly(false);
	ui.lineEdit82->setVisible(true);
	ui.lineEdit82->setValidator(validator);
	ui.lineEdit82->setText(QString::number(secondSetList.bench[7].toSecondBreakdown));
	ui.lineEdit82->setReadOnly(false);
	ui.lineEdit83->setVisible(true);
	ui.lineEdit83->setValidator(validator);
	ui.lineEdit83->setText(QString::number(secondSetList.bench[7].toThirdBreakdown));
	ui.lineEdit83->setReadOnly(false);
	ui.lineEdit84->setVisible(true);
	ui.lineEdit84->setValidator(validator);
	ui.lineEdit84->setText(QString::number(secondSetList.bench[7].repairCost));
	ui.lineEdit84->setReadOnly(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setText(QString::fromLocal8Bit("Сборочный станок для дверей 3 сорта"));
	ui.label9->setVisible(true);
	ui.lineEdit91->setVisible(true);
	ui.lineEdit91->setValidator(validator);
	ui.lineEdit91->setText(QString::number(secondSetList.bench[8].toFirstBreakdown));
	ui.lineEdit91->setReadOnly(false);
	ui.lineEdit92->setVisible(true);
	ui.lineEdit92->setValidator(validator);
	ui.lineEdit92->setText(QString::number(secondSetList.bench[8].toSecondBreakdown));
	ui.lineEdit92->setReadOnly(false);
	ui.lineEdit93->setVisible(true);
	ui.lineEdit93->setValidator(validator);
	ui.lineEdit93->setText(QString::number(secondSetList.bench[8].toThirdBreakdown));
	ui.lineEdit93->setReadOnly(false);
	ui.lineEdit94->setVisible(true);
	ui.lineEdit94->setValidator(validator);
	ui.lineEdit94->setText(QString::number(secondSetList.bench[8].repairCost));
	ui.lineEdit94->setReadOnly(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setText(QString::fromLocal8Bit("Покрасочная камера"));
	ui.label10->setVisible(true);
	ui.lineEdit101->setVisible(true);
	ui.lineEdit101->setValidator(validator);
	ui.lineEdit101->setText(QString::number(secondSetList.bench[9].toFirstBreakdown));
	ui.lineEdit101->setReadOnly(false);
	ui.lineEdit102->setVisible(true);
	ui.lineEdit102->setValidator(validator);
	ui.lineEdit102->setText(QString::number(secondSetList.bench[9].toSecondBreakdown));
	ui.lineEdit102->setReadOnly(false);
	ui.lineEdit103->setVisible(true);
	ui.lineEdit103->setValidator(validator);
	ui.lineEdit103->setText(QString::number(secondSetList.bench[9].toThirdBreakdown));
	ui.lineEdit103->setReadOnly(false);
	ui.lineEdit104->setVisible(true);
	ui.lineEdit104->setValidator(validator);
	ui.lineEdit104->setText(QString::number(secondSetList.bench[9].repairCost));
	ui.lineEdit104->setReadOnly(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showThirdSetList()
{
	this->setWindowTitle(QString::fromLocal8Bit("Параметры поломки пилорамы"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(true);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Длинна"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Ширина"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("1 поломка"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(false);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(thirdSetList.breakdown[0].length);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(thirdSetList.breakdown[0].width);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(thirdSetList.breakdown[0].crack);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("2 поломка"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(thirdSetList.breakdown[1].length);
	ui.checkBox22->setVisible(true);
	ui.checkBox22->setChecked(thirdSetList.breakdown[1].width);
	ui.checkBox23->setVisible(true);
	ui.checkBox23->setChecked(thirdSetList.breakdown[1].crack);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("3 поломка"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(thirdSetList.breakdown[2].length);
	ui.checkBox32->setVisible(true);
	ui.checkBox32->setChecked(thirdSetList.breakdown[2].width);
	ui.checkBox33->setVisible(true);
	ui.checkBox33->setChecked(thirdSetList.breakdown[2].crack);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showFourthSetList()
{
	this->setWindowTitle(QString::fromLocal8Bit("Параметры поломки сушильной камеры"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(true);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Влажность"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Трещины"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Деформация"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("1 поломка"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(false);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(fourthSetList.breakdown[0].humidity);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(fourthSetList.breakdown[0].crack);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(fourthSetList.breakdown[0].deformation);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("2 поломка"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(fourthSetList.breakdown[1].humidity);
	ui.checkBox22->setVisible(true);
	ui.checkBox22->setChecked(fourthSetList.breakdown[1].crack);
	ui.checkBox23->setVisible(true);
	ui.checkBox23->setChecked(fourthSetList.breakdown[1].deformation);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("3 поломка"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(fourthSetList.breakdown[2].humidity);
	ui.checkBox32->setVisible(true);
	ui.checkBox32->setChecked(fourthSetList.breakdown[2].crack);
	ui.checkBox33->setVisible(true);
	ui.checkBox33->setChecked(fourthSetList.breakdown[2].deformation);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showFifthSetList()
{
	this->setWindowTitle(QString::fromLocal8Bit("Параметры поломки сортировочного станка"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(true);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Влажность"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Кол-во сучков"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Гниль"));
	ui.label19->setVisible(true);
	ui.label19->setText(QString::fromLocal8Bit("Трещены"));
	ui.label20->setVisible(true);
	ui.label20->setText(QString::fromLocal8Bit("Деформация"));
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("1 поломка для досок 1 сорта"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(false);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(fifthSetList.grade[0].breakdown[0].humidity);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(fifthSetList.grade[0].breakdown[0].knotCount);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(fifthSetList.grade[0].breakdown[0].mould);
	ui.checkBox14->setVisible(true);
	ui.checkBox14->setChecked(fifthSetList.grade[0].breakdown[0].crack);
	ui.checkBox15->setVisible(true);
	ui.checkBox15->setChecked(fifthSetList.grade[0].breakdown[0].deformation);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("2 поломка для досок 1 сорта"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(fifthSetList.grade[0].breakdown[1].humidity);
	ui.checkBox22->setVisible(true);
	ui.checkBox22->setChecked(fifthSetList.grade[0].breakdown[1].knotCount);
	ui.checkBox23->setVisible(true);
	ui.checkBox23->setChecked(fifthSetList.grade[0].breakdown[1].mould);
	ui.checkBox24->setVisible(true);
	ui.checkBox24->setChecked(fifthSetList.grade[0].breakdown[1].crack);
	ui.checkBox25->setVisible(true);
	ui.checkBox25->setChecked(fifthSetList.grade[0].breakdown[1].deformation);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("3 поломка для досок 1 сорта"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(fifthSetList.grade[0].breakdown[2].humidity);
	ui.checkBox32->setVisible(true);
	ui.checkBox32->setChecked(fifthSetList.grade[0].breakdown[2].knotCount);
	ui.checkBox33->setVisible(true);
	ui.checkBox33->setChecked(fifthSetList.grade[0].breakdown[2].mould);
	ui.checkBox34->setVisible(true);
	ui.checkBox34->setChecked(fifthSetList.grade[0].breakdown[2].crack);
	ui.checkBox35->setVisible(true);
	ui.checkBox35->setChecked(fifthSetList.grade[0].breakdown[2].deformation);
	ui.checkBox36->setVisible(false);

	ui.label4->setText(QString::fromLocal8Bit("1 поломка для досок 2 сорта"));
	ui.label4->setVisible(true);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(true);
	ui.checkBox41->setChecked(fifthSetList.grade[1].breakdown[0].humidity);
	ui.checkBox42->setVisible(true);
	ui.checkBox42->setChecked(fifthSetList.grade[1].breakdown[0].knotCount);
	ui.checkBox43->setVisible(true);
	ui.checkBox43->setChecked(fifthSetList.grade[1].breakdown[0].mould);
	ui.checkBox44->setVisible(true);
	ui.checkBox44->setChecked(fifthSetList.grade[1].breakdown[0].crack);
	ui.checkBox45->setVisible(true);
	ui.checkBox45->setChecked(fifthSetList.grade[1].breakdown[0].deformation);
	ui.checkBox46->setVisible(false);

	ui.label5->setText(QString::fromLocal8Bit("2 поломка для досок 2 сорта"));
	ui.label5->setVisible(true);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(true);
	ui.checkBox51->setChecked(fifthSetList.grade[1].breakdown[1].humidity);
	ui.checkBox52->setVisible(true);
	ui.checkBox52->setChecked(fifthSetList.grade[1].breakdown[1].knotCount);
	ui.checkBox53->setVisible(true);
	ui.checkBox53->setChecked(fifthSetList.grade[1].breakdown[1].mould);
	ui.checkBox54->setVisible(true);
	ui.checkBox54->setChecked(fifthSetList.grade[1].breakdown[1].crack);
	ui.checkBox55->setVisible(true);
	ui.checkBox55->setChecked(fifthSetList.grade[1].breakdown[1].deformation);
	ui.checkBox56->setVisible(false);

	ui.label6->setText(QString::fromLocal8Bit("3 поломка для досок 2 сорта"));
	ui.label6->setVisible(true);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(true);
	ui.checkBox61->setChecked(fifthSetList.grade[1].breakdown[2].humidity);
	ui.checkBox62->setVisible(true);
	ui.checkBox62->setChecked(fifthSetList.grade[1].breakdown[2].knotCount);
	ui.checkBox63->setVisible(true);
	ui.checkBox63->setChecked(fifthSetList.grade[1].breakdown[2].mould);
	ui.checkBox64->setVisible(true);
	ui.checkBox64->setChecked(fifthSetList.grade[1].breakdown[2].crack);
	ui.checkBox65->setVisible(true);
	ui.checkBox65->setChecked(fifthSetList.grade[1].breakdown[2].deformation);
	ui.checkBox66->setVisible(false);

	ui.label7->setText(QString::fromLocal8Bit("1 поломка для досок 3 сорта"));
	ui.label7->setVisible(true);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(true);
	ui.checkBox71->setChecked(fifthSetList.grade[2].breakdown[0].humidity);
	ui.checkBox72->setVisible(true);
	ui.checkBox72->setChecked(fifthSetList.grade[2].breakdown[0].knotCount);
	ui.checkBox73->setVisible(true);
	ui.checkBox73->setChecked(fifthSetList.grade[2].breakdown[0].mould);
	ui.checkBox74->setVisible(true);
	ui.checkBox74->setChecked(fifthSetList.grade[2].breakdown[0].crack);
	ui.checkBox75->setVisible(true);
	ui.checkBox75->setChecked(fifthSetList.grade[2].breakdown[0].deformation);
	ui.checkBox76->setVisible(false);

	ui.label8->setText(QString::fromLocal8Bit("2 поломка для досок 3 сорта"));
	ui.label8->setVisible(true);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(true);
	ui.checkBox81->setChecked(fifthSetList.grade[2].breakdown[1].humidity);
	ui.checkBox82->setVisible(true);
	ui.checkBox82->setChecked(fifthSetList.grade[2].breakdown[1].knotCount);
	ui.checkBox83->setVisible(true);
	ui.checkBox83->setChecked(fifthSetList.grade[2].breakdown[1].mould);
	ui.checkBox84->setVisible(true);
	ui.checkBox84->setChecked(fifthSetList.grade[2].breakdown[1].crack);
	ui.checkBox85->setVisible(true);
	ui.checkBox85->setChecked(fifthSetList.grade[2].breakdown[1].deformation);
	ui.checkBox86->setVisible(false);

	ui.label9->setText(QString::fromLocal8Bit("3 поломка для досок 3 сорта"));
	ui.label9->setVisible(true);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(true);
	ui.checkBox91->setChecked(fifthSetList.grade[2].breakdown[2].humidity);
	ui.checkBox92->setVisible(true);
	ui.checkBox92->setChecked(fifthSetList.grade[2].breakdown[2].knotCount);
	ui.checkBox93->setVisible(true);
	ui.checkBox93->setChecked(fifthSetList.grade[2].breakdown[2].mould);
	ui.checkBox94->setVisible(true);
	ui.checkBox94->setChecked(fifthSetList.grade[2].breakdown[2].crack);
	ui.checkBox95->setVisible(true);
	ui.checkBox95->setChecked(fifthSetList.grade[2].breakdown[2].deformation);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showSixthSetList()
{
	this->setWindowTitle(QString::fromLocal8Bit("Параметры поломки фрезерных станков"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(true);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Длина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Ширина"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("1 поломка для 1 фрезерного станка"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(false);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(sixthSetList.grade[0].breakdown[0].length);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(sixthSetList.grade[0].breakdown[0].width);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(sixthSetList.grade[0].breakdown[0].crack);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("2 поломка для 1 фрезерного станка"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(sixthSetList.grade[0].breakdown[1].length);
	ui.checkBox22->setVisible(true);
	ui.checkBox22->setChecked(sixthSetList.grade[0].breakdown[1].width);
	ui.checkBox23->setVisible(true);
	ui.checkBox23->setChecked(sixthSetList.grade[0].breakdown[1].crack);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("3 поломка для 1 фрезерного станка"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(sixthSetList.grade[0].breakdown[2].length);
	ui.checkBox32->setVisible(true);
	ui.checkBox32->setChecked(sixthSetList.grade[0].breakdown[2].width);
	ui.checkBox33->setVisible(true);
	ui.checkBox33->setChecked(sixthSetList.grade[0].breakdown[2].crack);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setText(QString::fromLocal8Bit("1 поломка для 2 фрезерного станка"));
	ui.label4->setVisible(true);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(true);
	ui.checkBox41->setChecked(sixthSetList.grade[1].breakdown[0].length);
	ui.checkBox42->setVisible(true);
	ui.checkBox42->setChecked(sixthSetList.grade[1].breakdown[0].width);
	ui.checkBox43->setVisible(true);
	ui.checkBox43->setChecked(sixthSetList.grade[1].breakdown[0].crack);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setText(QString::fromLocal8Bit("2 поломка для 2 фрезерного станка"));
	ui.label5->setVisible(true);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(true);
	ui.checkBox51->setChecked(sixthSetList.grade[1].breakdown[1].length);
	ui.checkBox52->setVisible(true);
	ui.checkBox52->setChecked(sixthSetList.grade[1].breakdown[1].width);
	ui.checkBox53->setVisible(true);
	ui.checkBox53->setChecked(sixthSetList.grade[1].breakdown[1].crack);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setText(QString::fromLocal8Bit("3 поломка для 2 фрезерного станка"));
	ui.label6->setVisible(true);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(true);
	ui.checkBox61->setChecked(sixthSetList.grade[1].breakdown[2].length);
	ui.checkBox62->setVisible(true);
	ui.checkBox62->setChecked(sixthSetList.grade[1].breakdown[2].width);
	ui.checkBox63->setVisible(true);
	ui.checkBox63->setChecked(sixthSetList.grade[1].breakdown[2].crack);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setText(QString::fromLocal8Bit("1 поломка для 3 фрезерного станка"));
	ui.label7->setVisible(true);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(true);
	ui.checkBox71->setChecked(sixthSetList.grade[2].breakdown[0].length);
	ui.checkBox72->setVisible(true);
	ui.checkBox72->setChecked(sixthSetList.grade[2].breakdown[0].width);
	ui.checkBox73->setVisible(true);
	ui.checkBox73->setChecked(sixthSetList.grade[2].breakdown[0].crack);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setText(QString::fromLocal8Bit("2 поломка для 3 фрезерного станка"));
	ui.label8->setVisible(true);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(true);
	ui.checkBox81->setChecked(sixthSetList.grade[2].breakdown[1].length);
	ui.checkBox82->setVisible(true);
	ui.checkBox82->setChecked(sixthSetList.grade[2].breakdown[1].width);
	ui.checkBox83->setVisible(true);
	ui.checkBox83->setChecked(sixthSetList.grade[2].breakdown[1].crack);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setText(QString::fromLocal8Bit("3 поломка для 3 фрезерного станка"));
	ui.label9->setVisible(true);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(true);
	ui.checkBox91->setChecked(sixthSetList.grade[2].breakdown[2].length);
	ui.checkBox92->setVisible(true);
	ui.checkBox92->setChecked(sixthSetList.grade[2].breakdown[2].width);
	ui.checkBox93->setVisible(true);
	ui.checkBox93->setChecked(sixthSetList.grade[2].breakdown[2].crack);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showSeventhSetList()
{
	this->setWindowTitle(QString::fromLocal8Bit("Параметры поломки сборочных станков"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(true);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Ширина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Высота"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("1 поломка для 1 сборочного станка"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(false);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(seventhSetList.grade[0].breakdown[0].width);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(seventhSetList.grade[0].breakdown[0].height);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(seventhSetList.grade[0].breakdown[0].crack);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("2 поломка для 1 сборочного станка"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(seventhSetList.grade[0].breakdown[1].width);
	ui.checkBox22->setVisible(true);
	ui.checkBox22->setChecked(seventhSetList.grade[0].breakdown[1].height);
	ui.checkBox23->setVisible(true);
	ui.checkBox23->setChecked(seventhSetList.grade[0].breakdown[1].crack);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("3 поломка для 1 сборочного станка"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(seventhSetList.grade[0].breakdown[2].width);
	ui.checkBox32->setVisible(true);
	ui.checkBox32->setChecked(seventhSetList.grade[0].breakdown[2].height);
	ui.checkBox33->setVisible(true);
	ui.checkBox33->setChecked(seventhSetList.grade[0].breakdown[2].crack);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setText(QString::fromLocal8Bit("1 поломка для 2 сборочного станка"));
	ui.label4->setVisible(true);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(true);
	ui.checkBox41->setChecked(seventhSetList.grade[1].breakdown[0].width);
	ui.checkBox42->setVisible(true);
	ui.checkBox42->setChecked(seventhSetList.grade[1].breakdown[0].height);
	ui.checkBox43->setVisible(true);
	ui.checkBox43->setChecked(seventhSetList.grade[1].breakdown[0].crack);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setText(QString::fromLocal8Bit("2 поломка для 2 сборочного станка"));
	ui.label5->setVisible(true);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(true);
	ui.checkBox51->setChecked(seventhSetList.grade[1].breakdown[1].width);
	ui.checkBox52->setVisible(true);
	ui.checkBox52->setChecked(seventhSetList.grade[1].breakdown[1].height);
	ui.checkBox53->setVisible(true);
	ui.checkBox53->setChecked(seventhSetList.grade[1].breakdown[1].crack);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setText(QString::fromLocal8Bit("3 поломка для 2 сборочного станка"));
	ui.label6->setVisible(true);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(true);
	ui.checkBox61->setChecked(seventhSetList.grade[1].breakdown[2].width);
	ui.checkBox62->setVisible(true);
	ui.checkBox62->setChecked(seventhSetList.grade[1].breakdown[2].height);
	ui.checkBox63->setVisible(true);
	ui.checkBox63->setChecked(seventhSetList.grade[1].breakdown[2].crack);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setText(QString::fromLocal8Bit("1 поломка для 3 сборочного станка"));
	ui.label7->setVisible(true);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(true);
	ui.checkBox71->setChecked(seventhSetList.grade[2].breakdown[0].width);
	ui.checkBox72->setVisible(true);
	ui.checkBox72->setChecked(seventhSetList.grade[2].breakdown[0].height);
	ui.checkBox73->setVisible(true);
	ui.checkBox73->setChecked(seventhSetList.grade[2].breakdown[0].crack);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setText(QString::fromLocal8Bit("2 поломка для 3 сборочного станка"));
	ui.label8->setVisible(true);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(true);
	ui.checkBox81->setChecked(seventhSetList.grade[2].breakdown[1].width);
	ui.checkBox82->setVisible(true);
	ui.checkBox82->setChecked(seventhSetList.grade[2].breakdown[1].height);
	ui.checkBox83->setVisible(true);
	ui.checkBox83->setChecked(seventhSetList.grade[2].breakdown[1].crack);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setText(QString::fromLocal8Bit("3 поломка для 3 сборочного станка"));
	ui.label9->setVisible(true);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(true);
	ui.checkBox91->setChecked(seventhSetList.grade[2].breakdown[2].width);
	ui.checkBox92->setVisible(true);
	ui.checkBox92->setChecked(seventhSetList.grade[2].breakdown[2].height);
	ui.checkBox93->setVisible(true);
	ui.checkBox93->setChecked(seventhSetList.grade[2].breakdown[2].crack);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showEighthSetList()
{
	this->setWindowTitle(QString::fromLocal8Bit("Параметры поломки покрасочных камер"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(true);
	ui.backButton->setVisible(true);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Дефект покраски"));
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("1 поломка для 1 покрасочной камеры"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(false);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(eighthSetList.grade[0].breakdown[0].paintingDefect);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("2 поломка для 1 покрасочной камеры"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(eighthSetList.grade[0].breakdown[1].paintingDefect);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("3 поломка для 1 покрасочной камеры"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(eighthSetList.grade[0].breakdown[2].paintingDefect);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setText(QString::fromLocal8Bit("1 поломка для 2 покрасочной камеры"));
	ui.label4->setVisible(true);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(true);
	ui.checkBox41->setChecked(eighthSetList.grade[1].breakdown[0].paintingDefect);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setText(QString::fromLocal8Bit("2 поломка для 2 покрасочной камеры"));
	ui.label5->setVisible(true);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(true);
	ui.checkBox51->setChecked(eighthSetList.grade[1].breakdown[1].paintingDefect);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setText(QString::fromLocal8Bit("3 поломка для 2 покрасочной камеры"));
	ui.label6->setVisible(true);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(true);
	ui.checkBox61->setChecked(eighthSetList.grade[1].breakdown[2].paintingDefect);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setText(QString::fromLocal8Bit("1 поломка для 3 покрасочной камеры"));
	ui.label7->setVisible(true);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(true);
	ui.checkBox71->setChecked(eighthSetList.grade[2].breakdown[0].paintingDefect);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setText(QString::fromLocal8Bit("2 поломка для 3 покрасочной камеры"));
	ui.label8->setVisible(true);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(true);
	ui.checkBox81->setChecked(eighthSetList.grade[2].breakdown[1].paintingDefect);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setText(QString::fromLocal8Bit("3 поломка для 3 покрасочной камеры"));
	ui.label9->setVisible(true);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(true);
	ui.checkBox91->setChecked(eighthSetList.grade[2].breakdown[2].paintingDefect);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showNinthSetList()
{
	QRegExp rx1("^[1-3]{1}[.]{1}[0-9]{5}$");
	QRegExp rx2("^[0-9]{3}$");
	QValidator *validator1 = new QRegExpValidator(rx1, this);
	QValidator *validator2 = new QRegExpValidator(rx2, this);

	this->setWindowTitle(QString::fromLocal8Bit("Параметры рабочих бригад"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(true);
	ui.saveAndFinishButton->setVisible(true);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(true);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Коэфициент эффективности бригады"));
	ui.label13->setVisible(true);
	ui.label13->setText(QString::fromLocal8Bit("Стоимость тренинга"));
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(false);
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("1 бригада"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setValidator(validator1);
	ui.lineEdit11->setText(QString::number(ninthSetList.brigade[0].effectiveCoef));
	ui.lineEdit11->setReadOnly(false);
	ui.lineEdit12->setVisible(true);
	ui.lineEdit12->setValidator(validator2);
	ui.lineEdit12->setText(QString::number(ninthSetList.brigade[0].trainCost));
	ui.lineEdit12->setReadOnly(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("2 бригада"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setValidator(validator1);
	ui.lineEdit21->setText(QString::number(ninthSetList.brigade[1].effectiveCoef));
	ui.lineEdit21->setReadOnly(false);
	ui.lineEdit22->setVisible(true);
	ui.lineEdit22->setValidator(validator2);
	ui.lineEdit22->setText(QString::number(ninthSetList.brigade[1].trainCost));
	ui.lineEdit22->setReadOnly(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("3 бригада"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setValidator(validator1);
	ui.lineEdit31->setText(QString::number(ninthSetList.brigade[0].effectiveCoef));
	ui.lineEdit31->setReadOnly(false);
	ui.lineEdit32->setVisible(true);
	ui.lineEdit32->setValidator(validator2);
	ui.lineEdit32->setText(QString::number(ninthSetList.brigade[0].trainCost));
	ui.lineEdit32->setReadOnly(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showTimbersBatshSkipSet(std::vector<UINT> lastInBatches)
{
	this->setWindowTitle(QString::fromLocal8Bit("Пропуск партий бревен"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Пропустить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Осталось в партии"));
	ui.label13->setVisible(true);
	ui.label13->setText(QString::fromLocal8Bit("Всего в партии"));
	ui.label14->setVisible(true);
	ui.label14->setText(QString::fromLocal8Bit("Стоимость пропуска"));
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Пропуск"));
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setText(QString::fromLocal8Bit("1 партия"));
	ui.label1->setVisible(true);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(lastInBatches[0]));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(true);
	ui.lineEdit12->setText(QString::number(firstSetList.batch[0].count));
	ui.lineEdit12->setReadOnly(true);
	ui.lineEdit13->setVisible(true);
	ui.lineEdit13->setText(QString::number(firstSetList.batch[0].skipCost));
	ui.lineEdit13->setReadOnly(true);
	ui.lineEdit14->setVisible(false);
	lastInBatches[0] != 0 ? ui.checkBox11->setVisible(true) : ui.checkBox11->setVisible(false);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setText(QString::fromLocal8Bit("2 партия"));
	ui.label2->setVisible(true);
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setText(QString::number(lastInBatches[1]));
	ui.lineEdit21->setReadOnly(true);
	ui.lineEdit22->setVisible(true);
	ui.lineEdit22->setText(QString::number(firstSetList.batch[1].count));
	ui.lineEdit22->setReadOnly(true);
	ui.lineEdit23->setVisible(true);
	ui.lineEdit23->setText(QString::number(firstSetList.batch[1].skipCost));
	ui.lineEdit23->setReadOnly(true);
	ui.lineEdit24->setVisible(false);
	lastInBatches[1] != 0 ? ui.checkBox21->setVisible(true) : ui.checkBox21->setVisible(false);
	ui.checkBox21->setChecked(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setText(QString::fromLocal8Bit("3 партия"));
	ui.label3->setVisible(true);
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setText(QString::number(lastInBatches[2]));
	ui.lineEdit31->setReadOnly(true);
	ui.lineEdit32->setVisible(true);
	ui.lineEdit32->setText(QString::number(firstSetList.batch[2].count));
	ui.lineEdit32->setReadOnly(true);
	ui.lineEdit33->setVisible(true);
	ui.lineEdit33->setText(QString::number(firstSetList.batch[2].skipCost));
	ui.lineEdit33->setReadOnly(true);
	ui.lineEdit34->setVisible(false);
	lastInBatches[2] != 0 ? ui.checkBox31->setVisible(true) : ui.checkBox31->setVisible(false);
	ui.checkBox31->setChecked(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setText(QString::fromLocal8Bit("4 партия"));
	ui.label4->setVisible(true);
	ui.lineEdit41->setVisible(true);
	ui.lineEdit41->setText(QString::number(lastInBatches[3]));
	ui.lineEdit41->setReadOnly(true);
	ui.lineEdit42->setVisible(true);
	ui.lineEdit42->setText(QString::number(firstSetList.batch[3].count));
	ui.lineEdit42->setReadOnly(true);
	ui.lineEdit43->setVisible(true);
	ui.lineEdit43->setText(QString::number(firstSetList.batch[3].skipCost));
	ui.lineEdit43->setReadOnly(true);
	ui.lineEdit44->setVisible(false);
	lastInBatches[3] != 0 ? ui.checkBox41->setVisible(true) : ui.checkBox41->setVisible(false);
	ui.checkBox41->setChecked(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setText(QString::fromLocal8Bit("5 партия"));
	ui.label5->setVisible(true);
	ui.lineEdit51->setVisible(true);
	ui.lineEdit51->setText(QString::number(lastInBatches[4]));
	ui.lineEdit51->setReadOnly(true);
	ui.lineEdit52->setVisible(true);
	ui.lineEdit52->setText(QString::number(firstSetList.batch[4].count));
	ui.lineEdit52->setReadOnly(true);
	ui.lineEdit53->setVisible(true);
	ui.lineEdit53->setText(QString::number(firstSetList.batch[4].skipCost));
	ui.lineEdit53->setReadOnly(true);
	ui.lineEdit54->setVisible(false);
	lastInBatches[4] != 0 ? ui.checkBox51->setVisible(true) : ui.checkBox51->setVisible(false);
	ui.checkBox51->setChecked(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setText(QString::fromLocal8Bit("6 партия"));
	ui.label6->setVisible(true);
	ui.lineEdit61->setVisible(true);
	ui.lineEdit61->setText(QString::number(lastInBatches[5]));
	ui.lineEdit61->setReadOnly(true);
	ui.lineEdit62->setVisible(true);
	ui.lineEdit62->setText(QString::number(firstSetList.batch[5].count));
	ui.lineEdit62->setReadOnly(true);
	ui.lineEdit63->setVisible(true);
	ui.lineEdit63->setText(QString::number(firstSetList.batch[5].skipCost));
	ui.lineEdit63->setReadOnly(true);
	ui.lineEdit64->setVisible(false);
	lastInBatches[5] != 0 ? ui.checkBox61->setVisible(true) : ui.checkBox61->setVisible(false);
	ui.checkBox61->setChecked(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setText(QString::fromLocal8Bit("7 партия"));
	ui.label7->setVisible(true);
	ui.lineEdit71->setVisible(true);
	ui.lineEdit71->setText(QString::number(lastInBatches[6]));
	ui.lineEdit71->setReadOnly(true);
	ui.lineEdit72->setVisible(true);
	ui.lineEdit72->setText(QString::number(firstSetList.batch[6].count));
	ui.lineEdit72->setReadOnly(true);
	ui.lineEdit73->setVisible(true);
	ui.lineEdit73->setText(QString::number(firstSetList.batch[6].skipCost));
	ui.lineEdit73->setReadOnly(true);
	ui.lineEdit74->setVisible(false);
	lastInBatches[6] != 0 ? ui.checkBox71->setVisible(true) : ui.checkBox71->setVisible(false);
	ui.checkBox71->setChecked(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setText(QString::fromLocal8Bit("8 партия"));
	ui.label8->setVisible(true);
	ui.lineEdit81->setVisible(true);
	ui.lineEdit81->setText(QString::number(lastInBatches[7]));
	ui.lineEdit81->setReadOnly(true);
	ui.lineEdit82->setVisible(true);
	ui.lineEdit82->setText(QString::number(firstSetList.batch[7].count));
	ui.lineEdit82->setReadOnly(true);
	ui.lineEdit83->setVisible(true);
	ui.lineEdit83->setText(QString::number(firstSetList.batch[7].skipCost));
	ui.lineEdit83->setReadOnly(true);
	ui.lineEdit84->setVisible(false);
	lastInBatches[7] != 0 ? ui.checkBox81->setVisible(true) : ui.checkBox81->setVisible(false);
	ui.checkBox81->setChecked(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setText(QString::fromLocal8Bit("9 партия"));
	ui.label9->setVisible(true);
	ui.lineEdit91->setVisible(true);
	ui.lineEdit91->setText(QString::number(lastInBatches[8]));
	ui.lineEdit91->setReadOnly(true);
	ui.lineEdit92->setVisible(true);
	ui.lineEdit92->setText(QString::number(firstSetList.batch[8].count));
	ui.lineEdit92->setReadOnly(true);
	ui.lineEdit93->setVisible(true);
	ui.lineEdit93->setText(QString::number(firstSetList.batch[8].skipCost));
	ui.lineEdit93->setReadOnly(true);
	ui.lineEdit94->setVisible(false);
	lastInBatches[8] != 0 ? ui.checkBox91->setVisible(true) : ui.checkBox91->setVisible(false);
	ui.checkBox91->setChecked(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setText(QString::fromLocal8Bit("10 партия"));
	ui.label10->setVisible(true);
	ui.lineEdit101->setVisible(true);
	ui.lineEdit101->setText(QString::number(lastInBatches[9]));
	ui.lineEdit101->setReadOnly(true);
	ui.lineEdit102->setVisible(true);
	ui.lineEdit102->setText(QString::number(firstSetList.batch[9].count));
	ui.lineEdit102->setReadOnly(true);
	ui.lineEdit103->setVisible(true);
	ui.lineEdit103->setText(QString::number(firstSetList.batch[9].skipCost));
	ui.lineEdit103->setReadOnly(true);
	ui.lineEdit104->setVisible(false);
	lastInBatches[9] != 0 ? ui.checkBox101->setVisible(true) : ui.checkBox101->setVisible(false);
	ui.checkBox101->setChecked(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showPSBenchRepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт пилорамы"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Длина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Ширина"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[0].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showDryingBenchRepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт сушильной камеры"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Влажность"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Трещены"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Деформация"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[1].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showSortingBenchRepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт сортировочного станка"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Влажность"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Кол-во сучков"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Гниль"));
	ui.label19->setVisible(true);
	ui.label19->setText(QString::fromLocal8Bit("Трещены"));
	ui.label20->setVisible(true);
	ui.label20->setText(QString::fromLocal8Bit("Деформация"));
	ui.label21->setVisible(false);

	ui.label1->setVisible(true);
	ui.label1->setText(QString::fromLocal8Bit("Доски 1 сорта"));
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[2].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(true);
	ui.checkBox14->setChecked(false);
	ui.checkBox15->setVisible(true);
	ui.checkBox15->setChecked(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(true);
	ui.label2->setText(QString::fromLocal8Bit("Доски 2 сорта"));
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setText(QString::number(secondSetList.bench[2].repairCost));
	ui.lineEdit21->setReadOnly(true);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(false);
	ui.checkBox22->setVisible(true);
	ui.checkBox22->setChecked(false);
	ui.checkBox23->setVisible(true);
	ui.checkBox23->setChecked(false);
	ui.checkBox24->setVisible(true);
	ui.checkBox24->setChecked(false);
	ui.checkBox25->setVisible(true);
	ui.checkBox25->setChecked(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(true);
	ui.label3->setText(QString::fromLocal8Bit("Доски 3 сорта"));
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setText(QString::number(secondSetList.bench[2].repairCost));
	ui.lineEdit31->setReadOnly(true);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(false);
	ui.checkBox32->setVisible(true);
	ui.checkBox32->setChecked(false);
	ui.checkBox33->setVisible(true);
	ui.checkBox33->setChecked(false);
	ui.checkBox34->setVisible(true);
	ui.checkBox34->setChecked(false);
	ui.checkBox35->setVisible(true);
	ui.checkBox35->setChecked(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showMillingBench1RepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт фрезерного станка для досок 1 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Длина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Ширина"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[3].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showMillingBench2RepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт фрезерного станка для досок 2 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Длина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Ширина"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[4].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showMillingBench3RepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт фрезерного станка для досок 3 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Длина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Ширина"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[5].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showAssemblingBench1RepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт сборочного станка для досок 1 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Ширина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Высота"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[6].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showAssemblingBench2RepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт сборочного станка для досок 2 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Ширина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Высота"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[7].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showAssemblingBench3RepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт сборочного станка для досок 3 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта 1 компоненты"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Ширина"));
	ui.label17->setVisible(true);
	ui.label17->setText(QString::fromLocal8Bit("Высота"));
	ui.label18->setVisible(true);
	ui.label18->setText(QString::fromLocal8Bit("Трещены"));
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(false);
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[8].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(true);
	ui.checkBox12->setChecked(false);
	ui.checkBox13->setVisible(true);
	ui.checkBox13->setChecked(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(false);
	ui.lineEdit21->setVisible(false);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(false);
	ui.lineEdit31->setVisible(false);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showPaintingBenchRepairSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Ремонт покрасочных камер"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Починить"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость ремонта"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Дефекты покраски"));
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(true);
	ui.label1->setText(QString::fromLocal8Bit("Камера для дверей 1 сорта"));
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(secondSetList.bench[9].repairCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(true);
	ui.label2->setText(QString::fromLocal8Bit("Камера для дверей 2 сорта"));
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setText(QString::number(secondSetList.bench[9].repairCost));
	ui.lineEdit21->setReadOnly(true);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(true);
	ui.label3->setText(QString::fromLocal8Bit("Камера для дверей 3 сорта"));
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setText(QString::number(secondSetList.bench[9].repairCost));
	ui.lineEdit31->setReadOnly(true);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showBrigadesTrainSet()
{
	this->setWindowTitle(QString::fromLocal8Bit("Тренировка бригад"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(true);
	ui.repairButton->setText(QString::fromLocal8Bit("Тренировать"));

	ui.label12->setVisible(true);
	ui.label12->setText(QString::fromLocal8Bit("Стоимость тренировки"));
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(true);
	ui.label16->setText(QString::fromLocal8Bit("Коэффициент эффективности"));
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(true);
	ui.label1->setText(QString::fromLocal8Bit("1 бригада"));
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(ninthSetList.brigade[0].trainCost));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(true);
	ui.checkBox11->setChecked(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(true);
	ui.label2->setText(QString::fromLocal8Bit("2 бригада"));
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setText(QString::number(ninthSetList.brigade[1].trainCost));
	ui.lineEdit21->setReadOnly(true);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(true);
	ui.checkBox21->setChecked(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(true);
	ui.label3->setText(QString::fromLocal8Bit("3 бригада"));
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setText(QString::number(ninthSetList.brigade[2].trainCost));
	ui.lineEdit31->setReadOnly(true);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(true);
	ui.checkBox31->setChecked(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(false);
	ui.lineEdit41->setVisible(false);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(false);
	ui.lineEdit51->setVisible(false);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(false);
	ui.lineEdit61->setVisible(false);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(false);
	ui.lineEdit71->setVisible(false);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(false);
	ui.lineEdit81->setVisible(false);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(false);
	ui.lineEdit91->setVisible(false);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showFirstGradeDoorsStat(UINT doorsCount, vector<UINT> deffectsCount)
{
	if (deffectsCount.size() != 8)
		return;
	this->show();

	this->setWindowTitle(QString::fromLocal8Bit("Двери 1 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(false);
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(true);
	ui.label1->setText(QString::fromLocal8Bit("Всего выпущено дверей"));
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(doorsCount));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(true);
	ui.label2->setText(QString::fromLocal8Bit("С черезмерной влажностью"));
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setText(QString::number(deffectsCount[0]));
	ui.lineEdit21->setReadOnly(true);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(true);
	ui.label3->setText(QString::fromLocal8Bit("Со слишком большим количеством сучков"));
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setText(QString::number(deffectsCount[1]));
	ui.lineEdit31->setReadOnly(true);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(true);
	ui.label4->setText(QString::fromLocal8Bit("Неверной ширины"));
	ui.lineEdit41->setVisible(true);
	ui.lineEdit41->setText(QString::number(deffectsCount[2]));
	ui.lineEdit41->setReadOnly(true);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(true);
	ui.label5->setText(QString::fromLocal8Bit("Неверной высоты"));
	ui.lineEdit51->setVisible(true);
	ui.lineEdit51->setText(QString::number(deffectsCount[3]));
	ui.lineEdit51->setReadOnly(true);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(true);
	ui.label6->setText(QString::fromLocal8Bit("С наличием гнили"));
	ui.lineEdit61->setVisible(true);
	ui.lineEdit61->setText(QString::number(deffectsCount[4]));
	ui.lineEdit61->setReadOnly(true);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(true);
	ui.label7->setText(QString::fromLocal8Bit("С наличием трещин"));
	ui.lineEdit71->setVisible(true);
	ui.lineEdit71->setText(QString::number(deffectsCount[5]));
	ui.lineEdit71->setReadOnly(true);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(true);
	ui.label8->setText(QString::fromLocal8Bit("Деформированных"));
	ui.lineEdit81->setVisible(true);
	ui.lineEdit81->setText(QString::number(deffectsCount[6]));
	ui.lineEdit81->setReadOnly(true);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(true);
	ui.label9->setText(QString::fromLocal8Bit("С дефектами покраски"));
	ui.lineEdit91->setVisible(true);
	ui.lineEdit91->setText(QString::number(deffectsCount[7]));
	ui.lineEdit91->setReadOnly(true);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showSecondGradeDoorsStat(UINT doorsCount, vector<UINT> deffectsCount)
{
	if (deffectsCount.size() != 8)
		return;
	this->show();

	this->setWindowTitle(QString::fromLocal8Bit("Двери 2 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(false);
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(true);
	ui.label1->setText(QString::fromLocal8Bit("Всего выпущено дверей"));
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(doorsCount));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(true);
	ui.label2->setText(QString::fromLocal8Bit("С черезмерной влажностью"));
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setText(QString::number(deffectsCount[0]));
	ui.lineEdit21->setReadOnly(true);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(true);
	ui.label3->setText(QString::fromLocal8Bit("Со слишком большим количеством сучков"));
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setText(QString::number(deffectsCount[1]));
	ui.lineEdit31->setReadOnly(true);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(true);
	ui.label4->setText(QString::fromLocal8Bit("Неверной ширины"));
	ui.lineEdit41->setVisible(true);
	ui.lineEdit41->setText(QString::number(deffectsCount[2]));
	ui.lineEdit41->setReadOnly(true);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(true);
	ui.label5->setText(QString::fromLocal8Bit("Неверной высоты"));
	ui.lineEdit51->setVisible(true);
	ui.lineEdit51->setText(QString::number(deffectsCount[3]));
	ui.lineEdit51->setReadOnly(true);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(true);
	ui.label6->setText(QString::fromLocal8Bit("С наличием гнили"));
	ui.lineEdit61->setVisible(true);
	ui.lineEdit61->setText(QString::number(deffectsCount[4]));
	ui.lineEdit61->setReadOnly(true);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(true);
	ui.label7->setText(QString::fromLocal8Bit("С наличием трещин"));
	ui.lineEdit71->setVisible(true);
	ui.lineEdit71->setText(QString::number(deffectsCount[5]));
	ui.lineEdit71->setReadOnly(true);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(true);
	ui.label8->setText(QString::fromLocal8Bit("Деформированных"));
	ui.lineEdit81->setVisible(true);
	ui.lineEdit81->setText(QString::number(deffectsCount[6]));
	ui.lineEdit81->setReadOnly(true);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(true);
	ui.label9->setText(QString::fromLocal8Bit("С дефектами покраски"));
	ui.lineEdit91->setVisible(true);
	ui.lineEdit91->setText(QString::number(deffectsCount[7]));
	ui.lineEdit91->setReadOnly(true);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

void Settings::showThirdGradeDoorsStat(UINT doorsCount, vector<UINT> deffectsCount)
{
	if (deffectsCount.size() != 8)
		return;
	this->show();

	this->setWindowTitle(QString::fromLocal8Bit("Двери 3 сорта"));

	ui.labelpct->setVisible(false);

	ui.finishButton->setVisible(false);
	ui.saveAndFinishButton->setVisible(false);
	ui.loadButton->setVisible(false);
	ui.nextButton->setVisible(false);
	ui.backButton->setVisible(false);
	ui.repairButton->setVisible(false);

	ui.label12->setVisible(false);
	ui.label13->setVisible(false);
	ui.label14->setVisible(false);
	ui.label15->setVisible(false);
	ui.label16->setVisible(false);
	ui.label17->setVisible(false);
	ui.label18->setVisible(false);
	ui.label19->setVisible(false);
	ui.label20->setVisible(false);
	ui.label21->setVisible(false);

	ui.label1->setVisible(true);
	ui.label1->setText(QString::fromLocal8Bit("Всего выпущено дверей"));
	ui.lineEdit11->setVisible(true);
	ui.lineEdit11->setText(QString::number(doorsCount));
	ui.lineEdit11->setReadOnly(true);
	ui.lineEdit12->setVisible(false);
	ui.lineEdit13->setVisible(false);
	ui.lineEdit14->setVisible(false);
	ui.checkBox11->setVisible(false);
	ui.checkBox12->setVisible(false);
	ui.checkBox13->setVisible(false);
	ui.checkBox14->setVisible(false);
	ui.checkBox15->setVisible(false);
	ui.checkBox16->setVisible(false);

	ui.label2->setVisible(true);
	ui.label2->setText(QString::fromLocal8Bit("С черезмерной влажностью"));
	ui.lineEdit21->setVisible(true);
	ui.lineEdit21->setText(QString::number(deffectsCount[0]));
	ui.lineEdit21->setReadOnly(true);
	ui.lineEdit22->setVisible(false);
	ui.lineEdit23->setVisible(false);
	ui.lineEdit24->setVisible(false);
	ui.checkBox21->setVisible(false);
	ui.checkBox22->setVisible(false);
	ui.checkBox23->setVisible(false);
	ui.checkBox24->setVisible(false);
	ui.checkBox25->setVisible(false);
	ui.checkBox26->setVisible(false);

	ui.label3->setVisible(true);
	ui.label3->setText(QString::fromLocal8Bit("Со слишком большим количеством сучков"));
	ui.lineEdit31->setVisible(true);
	ui.lineEdit31->setText(QString::number(deffectsCount[1]));
	ui.lineEdit31->setReadOnly(true);
	ui.lineEdit32->setVisible(false);
	ui.lineEdit33->setVisible(false);
	ui.lineEdit34->setVisible(false);
	ui.checkBox31->setVisible(false);
	ui.checkBox32->setVisible(false);
	ui.checkBox33->setVisible(false);
	ui.checkBox34->setVisible(false);
	ui.checkBox35->setVisible(false);
	ui.checkBox36->setVisible(false);

	ui.label4->setVisible(true);
	ui.label4->setText(QString::fromLocal8Bit("Неверной ширины"));
	ui.lineEdit41->setVisible(true);
	ui.lineEdit41->setText(QString::number(deffectsCount[2]));
	ui.lineEdit41->setReadOnly(true);
	ui.lineEdit42->setVisible(false);
	ui.lineEdit43->setVisible(false);
	ui.lineEdit44->setVisible(false);
	ui.checkBox41->setVisible(false);
	ui.checkBox42->setVisible(false);
	ui.checkBox43->setVisible(false);
	ui.checkBox44->setVisible(false);
	ui.checkBox45->setVisible(false);
	ui.checkBox46->setVisible(false);

	ui.label5->setVisible(true);
	ui.label5->setText(QString::fromLocal8Bit("Неверной высоты"));
	ui.lineEdit51->setVisible(true);
	ui.lineEdit51->setText(QString::number(deffectsCount[3]));
	ui.lineEdit51->setReadOnly(true);
	ui.lineEdit52->setVisible(false);
	ui.lineEdit53->setVisible(false);
	ui.lineEdit54->setVisible(false);
	ui.checkBox51->setVisible(false);
	ui.checkBox52->setVisible(false);
	ui.checkBox53->setVisible(false);
	ui.checkBox54->setVisible(false);
	ui.checkBox55->setVisible(false);
	ui.checkBox56->setVisible(false);

	ui.label6->setVisible(true);
	ui.label6->setText(QString::fromLocal8Bit("С наличием гнили"));
	ui.lineEdit61->setVisible(true);
	ui.lineEdit61->setText(QString::number(deffectsCount[4]));
	ui.lineEdit61->setReadOnly(true);
	ui.lineEdit62->setVisible(false);
	ui.lineEdit63->setVisible(false);
	ui.lineEdit64->setVisible(false);
	ui.checkBox61->setVisible(false);
	ui.checkBox62->setVisible(false);
	ui.checkBox63->setVisible(false);
	ui.checkBox64->setVisible(false);
	ui.checkBox65->setVisible(false);
	ui.checkBox66->setVisible(false);

	ui.label7->setVisible(true);
	ui.label7->setText(QString::fromLocal8Bit("С наличием трещин"));
	ui.lineEdit71->setVisible(true);
	ui.lineEdit71->setText(QString::number(deffectsCount[5]));
	ui.lineEdit71->setReadOnly(true);
	ui.lineEdit72->setVisible(false);
	ui.lineEdit73->setVisible(false);
	ui.lineEdit74->setVisible(false);
	ui.checkBox71->setVisible(false);
	ui.checkBox72->setVisible(false);
	ui.checkBox73->setVisible(false);
	ui.checkBox74->setVisible(false);
	ui.checkBox75->setVisible(false);
	ui.checkBox76->setVisible(false);

	ui.label8->setVisible(true);
	ui.label8->setText(QString::fromLocal8Bit("Деформированных"));
	ui.lineEdit81->setVisible(true);
	ui.lineEdit81->setText(QString::number(deffectsCount[6]));
	ui.lineEdit81->setReadOnly(true);
	ui.lineEdit82->setVisible(false);
	ui.lineEdit83->setVisible(false);
	ui.lineEdit84->setVisible(false);
	ui.checkBox81->setVisible(false);
	ui.checkBox82->setVisible(false);
	ui.checkBox83->setVisible(false);
	ui.checkBox84->setVisible(false);
	ui.checkBox85->setVisible(false);
	ui.checkBox86->setVisible(false);

	ui.label9->setVisible(true);
	ui.label9->setText(QString::fromLocal8Bit("С дефектами покраски"));
	ui.lineEdit91->setVisible(true);
	ui.lineEdit91->setText(QString::number(deffectsCount[7]));
	ui.lineEdit91->setReadOnly(true);
	ui.lineEdit92->setVisible(false);
	ui.lineEdit93->setVisible(false);
	ui.lineEdit94->setVisible(false);
	ui.checkBox91->setVisible(false);
	ui.checkBox92->setVisible(false);
	ui.checkBox93->setVisible(false);
	ui.checkBox94->setVisible(false);
	ui.checkBox95->setVisible(false);
	ui.checkBox96->setVisible(false);

	ui.label10->setVisible(false);
	ui.lineEdit101->setVisible(false);
	ui.lineEdit102->setVisible(false);
	ui.lineEdit103->setVisible(false);
	ui.lineEdit104->setVisible(false);
	ui.checkBox101->setVisible(false);
	ui.checkBox102->setVisible(false);
	ui.checkBox103->setVisible(false);
	ui.checkBox104->setVisible(false);
	ui.checkBox105->setVisible(false);
	ui.checkBox106->setVisible(false);

	ui.label11->setVisible(false);
	ui.lineEdit111->setVisible(false);
}

bool Settings::readFirstSetList()
{
	if (ui.lineEdit11->text().isEmpty() || ui.lineEdit14->text().isEmpty()
		|| ui.lineEdit21->text().isEmpty() || ui.lineEdit24->text().isEmpty()
		|| ui.lineEdit31->text().isEmpty() || ui.lineEdit34->text().isEmpty()
		|| ui.lineEdit41->text().isEmpty() || ui.lineEdit44->text().isEmpty()
		|| ui.lineEdit51->text().isEmpty() || ui.lineEdit54->text().isEmpty()
		|| ui.lineEdit61->text().isEmpty() || ui.lineEdit64->text().isEmpty()
		|| ui.lineEdit71->text().isEmpty() || ui.lineEdit74->text().isEmpty()
		|| ui.lineEdit81->text().isEmpty() || ui.lineEdit84->text().isEmpty()
		|| ui.lineEdit91->text().isEmpty() || ui.lineEdit94->text().isEmpty()
		|| ui.lineEdit101->text().isEmpty() || ui.lineEdit104->text().isEmpty()
		|| ui.lineEdit111->text().isEmpty())
	{
		warning->exec();
		return false;
	}

	firstSetList.batch[0].count		= ui.lineEdit11->text().toInt();
	firstSetList.batch[0].skipCost	= ui.lineEdit14->text().toInt();
	firstSetList.batch[0].hymidity	= ui.checkBox11->isChecked();
	firstSetList.batch[0].knotCount = ui.checkBox12->isChecked();
	firstSetList.batch[0].diametr	= ui.checkBox13->isChecked();
	firstSetList.batch[0].length	= ui.checkBox14->isChecked();
	firstSetList.batch[0].mould		= ui.checkBox15->isChecked();
	firstSetList.batch[0].crack		= ui.checkBox16->isChecked();

	firstSetList.batch[1].count		= ui.lineEdit21->text().toInt();
	firstSetList.batch[1].skipCost	= ui.lineEdit24->text().toInt();
	firstSetList.batch[1].hymidity	= ui.checkBox21->isChecked();
	firstSetList.batch[1].knotCount = ui.checkBox22->isChecked();
	firstSetList.batch[1].diametr	= ui.checkBox23->isChecked();
	firstSetList.batch[1].length	= ui.checkBox24->isChecked();
	firstSetList.batch[1].mould		= ui.checkBox25->isChecked();
	firstSetList.batch[1].crack		= ui.checkBox26->isChecked();

	firstSetList.batch[2].count		= ui.lineEdit31->text().toInt();
	firstSetList.batch[2].skipCost	= ui.lineEdit34->text().toInt();
	firstSetList.batch[2].hymidity	= ui.checkBox31->isChecked();
	firstSetList.batch[2].knotCount	= ui.checkBox32->isChecked();
	firstSetList.batch[2].diametr	= ui.checkBox33->isChecked();
	firstSetList.batch[2].length	= ui.checkBox34->isChecked();
	firstSetList.batch[2].mould		= ui.checkBox35->isChecked();
	firstSetList.batch[2].crack		= ui.checkBox36->isChecked();

	firstSetList.batch[3].count		= ui.lineEdit41->text().toInt();
	firstSetList.batch[3].skipCost	= ui.lineEdit44->text().toInt();
	firstSetList.batch[3].hymidity	= ui.checkBox41->isChecked();
	firstSetList.batch[3].knotCount = ui.checkBox42->isChecked();
	firstSetList.batch[3].diametr	= ui.checkBox43->isChecked();
	firstSetList.batch[3].length	= ui.checkBox44->isChecked();
	firstSetList.batch[3].mould		= ui.checkBox45->isChecked();
	firstSetList.batch[3].crack		= ui.checkBox46->isChecked();

	firstSetList.batch[4].count		= ui.lineEdit51->text().toInt();
	firstSetList.batch[4].skipCost	= ui.lineEdit54->text().toInt();
	firstSetList.batch[4].hymidity	= ui.checkBox51->isChecked();
	firstSetList.batch[4].knotCount = ui.checkBox52->isChecked();
	firstSetList.batch[4].diametr	= ui.checkBox53->isChecked();
	firstSetList.batch[4].length	= ui.checkBox54->isChecked();
	firstSetList.batch[4].mould		= ui.checkBox55->isChecked();
	firstSetList.batch[4].crack		= ui.checkBox56->isChecked();

	firstSetList.batch[5].count		= ui.lineEdit61->text().toInt();
	firstSetList.batch[5].skipCost	= ui.lineEdit64->text().toInt();
	firstSetList.batch[5].hymidity	= ui.checkBox61->isChecked();
	firstSetList.batch[5].knotCount = ui.checkBox62->isChecked();
	firstSetList.batch[5].diametr	= ui.checkBox63->isChecked();
	firstSetList.batch[5].length	= ui.checkBox64->isChecked();
	firstSetList.batch[5].mould		= ui.checkBox65->isChecked();
	firstSetList.batch[5].crack		= ui.checkBox66->isChecked();

	firstSetList.batch[6].count		= ui.lineEdit71->text().toInt();
	firstSetList.batch[6].skipCost	= ui.lineEdit74->text().toInt();
	firstSetList.batch[6].hymidity	= ui.checkBox71->isChecked();
	firstSetList.batch[6].knotCount = ui.checkBox72->isChecked();
	firstSetList.batch[6].diametr	= ui.checkBox73->isChecked();
	firstSetList.batch[6].length	= ui.checkBox74->isChecked();
	firstSetList.batch[6].mould		= ui.checkBox75->isChecked();
	firstSetList.batch[6].crack		= ui.checkBox76->isChecked();

	firstSetList.batch[7].count		= ui.lineEdit81->text().toInt();
	firstSetList.batch[7].skipCost	= ui.lineEdit84->text().toInt();
	firstSetList.batch[7].hymidity	= ui.checkBox81->isChecked();
	firstSetList.batch[7].knotCount = ui.checkBox82->isChecked();
	firstSetList.batch[7].diametr	= ui.checkBox83->isChecked();
	firstSetList.batch[7].length	= ui.checkBox84->isChecked();
	firstSetList.batch[7].mould		= ui.checkBox85->isChecked();
	firstSetList.batch[7].crack		= ui.checkBox86->isChecked();

	firstSetList.batch[8].count		= ui.lineEdit91->text().toInt();
	firstSetList.batch[8].skipCost	= ui.lineEdit94->text().toInt();
	firstSetList.batch[8].hymidity	= ui.checkBox91->isChecked();
	firstSetList.batch[8].knotCount = ui.checkBox92->isChecked();
	firstSetList.batch[8].diametr	= ui.checkBox93->isChecked();
	firstSetList.batch[8].length	= ui.checkBox94->isChecked();
	firstSetList.batch[8].mould		= ui.checkBox95->isChecked();
	firstSetList.batch[8].crack		= ui.checkBox96->isChecked();

	firstSetList.batch[9].count		= ui.lineEdit101->text().toInt();
	firstSetList.batch[9].skipCost	= ui.lineEdit104->text().toInt();
	firstSetList.batch[9].hymidity	= ui.checkBox101->isChecked();
	firstSetList.batch[9].knotCount = ui.checkBox102->isChecked();
	firstSetList.batch[9].diametr	= ui.checkBox103->isChecked();
	firstSetList.batch[9].length	= ui.checkBox104->isChecked();
	firstSetList.batch[9].mould		= ui.checkBox105->isChecked();
	firstSetList.batch[9].crack		= ui.checkBox106->isChecked();

	firstSetList.money				= ui.lineEdit111->text().toInt();

	return true;
}

bool Settings::readSecondSetList()
{
	if (ui.lineEdit11->text().isEmpty() || ui.lineEdit12->text().isEmpty() || ui.lineEdit13->text().isEmpty() || ui.lineEdit14->text().isEmpty()
		|| ui.lineEdit21->text().isEmpty() || ui.lineEdit22->text().isEmpty() || ui.lineEdit23->text().isEmpty() || ui.lineEdit24->text().isEmpty()
		|| ui.lineEdit31->text().isEmpty() || ui.lineEdit32->text().isEmpty() || ui.lineEdit33->text().isEmpty() || ui.lineEdit34->text().isEmpty()
		|| ui.lineEdit41->text().isEmpty() || ui.lineEdit42->text().isEmpty() || ui.lineEdit43->text().isEmpty() || ui.lineEdit44->text().isEmpty()
		|| ui.lineEdit51->text().isEmpty() || ui.lineEdit52->text().isEmpty() || ui.lineEdit53->text().isEmpty() || ui.lineEdit54->text().isEmpty()
		|| ui.lineEdit61->text().isEmpty() || ui.lineEdit62->text().isEmpty() || ui.lineEdit63->text().isEmpty() || ui.lineEdit64->text().isEmpty()
		|| ui.lineEdit71->text().isEmpty() || ui.lineEdit72->text().isEmpty() || ui.lineEdit73->text().isEmpty() || ui.lineEdit74->text().isEmpty()
		|| ui.lineEdit81->text().isEmpty() || ui.lineEdit82->text().isEmpty() || ui.lineEdit83->text().isEmpty() || ui.lineEdit84->text().isEmpty()
		|| ui.lineEdit91->text().isEmpty() || ui.lineEdit92->text().isEmpty() || ui.lineEdit93->text().isEmpty() || ui.lineEdit94->text().isEmpty()
		|| ui.lineEdit101->text().isEmpty() || ui.lineEdit102->text().isEmpty() || ui.lineEdit103->text().isEmpty() || ui.lineEdit104->text().isEmpty())
	{
		warning->exec();
		return false;
	}

	secondSetList.bench[0].toFirstBreakdown		= ui.lineEdit11->text().toInt();
	secondSetList.bench[0].toSecondBreakdown	= ui.lineEdit12->text().toInt();
	secondSetList.bench[0].toThirdBreakdown		= ui.lineEdit13->text().toInt();
	secondSetList.bench[0].repairCost			= ui.lineEdit14->text().toInt();

	secondSetList.bench[1].toFirstBreakdown		= ui.lineEdit21->text().toInt();
	secondSetList.bench[1].toSecondBreakdown	= ui.lineEdit22->text().toInt();
	secondSetList.bench[1].toThirdBreakdown		= ui.lineEdit23->text().toInt();
	secondSetList.bench[1].repairCost			= ui.lineEdit24->text().toInt();

	secondSetList.bench[2].toFirstBreakdown		= ui.lineEdit31->text().toInt();
	secondSetList.bench[2].toSecondBreakdown	= ui.lineEdit32->text().toInt();
	secondSetList.bench[2].toThirdBreakdown		= ui.lineEdit33->text().toInt();
	secondSetList.bench[2].repairCost			= ui.lineEdit34->text().toInt();

	secondSetList.bench[3].toFirstBreakdown		= ui.lineEdit41->text().toInt();
	secondSetList.bench[3].toSecondBreakdown	= ui.lineEdit42->text().toInt();
	secondSetList.bench[3].toThirdBreakdown		= ui.lineEdit43->text().toInt();
	secondSetList.bench[3].repairCost			= ui.lineEdit44->text().toInt();

	secondSetList.bench[4].toFirstBreakdown		= ui.lineEdit51->text().toInt();
	secondSetList.bench[4].toSecondBreakdown	= ui.lineEdit52->text().toInt();
	secondSetList.bench[4].toThirdBreakdown		= ui.lineEdit53->text().toInt();
	secondSetList.bench[4].repairCost			= ui.lineEdit54->text().toInt();

	secondSetList.bench[5].toFirstBreakdown		= ui.lineEdit61->text().toInt();
	secondSetList.bench[5].toSecondBreakdown	= ui.lineEdit62->text().toInt();
	secondSetList.bench[5].toThirdBreakdown		= ui.lineEdit63->text().toInt();
	secondSetList.bench[5].repairCost			= ui.lineEdit64->text().toInt();

	secondSetList.bench[6].toFirstBreakdown		= ui.lineEdit71->text().toInt();
	secondSetList.bench[6].toSecondBreakdown	= ui.lineEdit72->text().toInt();
	secondSetList.bench[6].toThirdBreakdown		= ui.lineEdit73->text().toInt();
	secondSetList.bench[6].repairCost			= ui.lineEdit74->text().toInt();

	secondSetList.bench[7].toFirstBreakdown		= ui.lineEdit81->text().toInt();
	secondSetList.bench[7].toSecondBreakdown	= ui.lineEdit82->text().toInt();
	secondSetList.bench[7].toThirdBreakdown		= ui.lineEdit83->text().toInt();
	secondSetList.bench[7].repairCost			= ui.lineEdit84->text().toInt();

	secondSetList.bench[8].toFirstBreakdown		= ui.lineEdit91->text().toInt();
	secondSetList.bench[8].toSecondBreakdown	= ui.lineEdit92->text().toInt();
	secondSetList.bench[8].toThirdBreakdown		= ui.lineEdit93->text().toInt();
	secondSetList.bench[8].repairCost			= ui.lineEdit94->text().toInt();

	secondSetList.bench[9].toFirstBreakdown		= ui.lineEdit101->text().toInt();
	secondSetList.bench[9].toSecondBreakdown	= ui.lineEdit102->text().toInt();
	secondSetList.bench[9].toThirdBreakdown		= ui.lineEdit103->text().toInt();
	secondSetList.bench[9].repairCost			= ui.lineEdit104->text().toInt();

	return true;
}

bool Settings::readThirdSetList()
{

	thirdSetList.breakdown[0].length = ui.checkBox11->isChecked();
	thirdSetList.breakdown[0].width = ui.checkBox12->isChecked();
	thirdSetList.breakdown[0].crack = ui.checkBox13->isChecked();

	thirdSetList.breakdown[1].length = ui.checkBox21->isChecked();
	thirdSetList.breakdown[1].width = ui.checkBox22->isChecked();
	thirdSetList.breakdown[1].crack = ui.checkBox23->isChecked();

	thirdSetList.breakdown[2].length = ui.checkBox31->isChecked();
	thirdSetList.breakdown[2].width = ui.checkBox32->isChecked();
	thirdSetList.breakdown[2].crack = ui.checkBox33->isChecked();

	return true;
}

bool Settings::readFourthSetList()
{

	fourthSetList.breakdown[0].humidity = ui.checkBox11->isChecked();
	fourthSetList.breakdown[0].crack = ui.checkBox12->isChecked();
	fourthSetList.breakdown[0].deformation = ui.checkBox13->isChecked();

	fourthSetList.breakdown[1].humidity = ui.checkBox21->isChecked();
	fourthSetList.breakdown[1].crack = ui.checkBox22->isChecked();
	fourthSetList.breakdown[1].deformation = ui.checkBox23->isChecked();

	fourthSetList.breakdown[2].humidity = ui.checkBox31->isChecked();
	fourthSetList.breakdown[2].crack = ui.checkBox32->isChecked();
	fourthSetList.breakdown[2].deformation = ui.checkBox33->isChecked();

	return true;
}

bool Settings::readFifthSetList()
{

	fifthSetList.grade[0].breakdown[0].humidity		= ui.checkBox11->isChecked();
	fifthSetList.grade[0].breakdown[0].knotCount	= ui.checkBox12->isChecked();
	fifthSetList.grade[0].breakdown[0].mould		= ui.checkBox13->isChecked();
	fifthSetList.grade[0].breakdown[0].crack		= ui.checkBox14->isChecked();
	fifthSetList.grade[0].breakdown[0].deformation	= ui.checkBox15->isChecked();


	fifthSetList.grade[0].breakdown[1].humidity		= ui.checkBox21->isChecked();
	fifthSetList.grade[0].breakdown[1].knotCount	= ui.checkBox22->isChecked();
	fifthSetList.grade[0].breakdown[1].mould		= ui.checkBox23->isChecked();
	fifthSetList.grade[0].breakdown[1].crack		= ui.checkBox24->isChecked();
	fifthSetList.grade[0].breakdown[1].deformation  = ui.checkBox25->isChecked();

	fifthSetList.grade[0].breakdown[2].humidity		= ui.checkBox31->isChecked();
	fifthSetList.grade[0].breakdown[2].knotCount	= ui.checkBox32->isChecked();
	fifthSetList.grade[0].breakdown[2].mould		= ui.checkBox33->isChecked();
	fifthSetList.grade[0].breakdown[2].crack		= ui.checkBox34->isChecked();
	fifthSetList.grade[0].breakdown[2].deformation	= ui.checkBox35->isChecked();

	fifthSetList.grade[1].breakdown[0].humidity		= ui.checkBox41->isChecked();
	fifthSetList.grade[1].breakdown[0].knotCount	= ui.checkBox42->isChecked();
	fifthSetList.grade[1].breakdown[0].mould		= ui.checkBox43->isChecked();
	fifthSetList.grade[1].breakdown[0].crack		= ui.checkBox44->isChecked();
	fifthSetList.grade[1].breakdown[0].deformation	= ui.checkBox45->isChecked();

	fifthSetList.grade[1].breakdown[1].humidity		= ui.checkBox51->isChecked();
	fifthSetList.grade[1].breakdown[1].knotCount	= ui.checkBox52->isChecked();
	fifthSetList.grade[1].breakdown[1].mould		= ui.checkBox53->isChecked();
	fifthSetList.grade[1].breakdown[1].crack		= ui.checkBox54->isChecked();
	fifthSetList.grade[1].breakdown[1].deformation  = ui.checkBox55->isChecked();

	fifthSetList.grade[1].breakdown[2].humidity		= ui.checkBox61->isChecked();
	fifthSetList.grade[1].breakdown[2].knotCount	= ui.checkBox62->isChecked();
	fifthSetList.grade[1].breakdown[2].mould		= ui.checkBox63->isChecked();
	fifthSetList.grade[1].breakdown[2].crack		= ui.checkBox64->isChecked();
	fifthSetList.grade[1].breakdown[2].deformation  = ui.checkBox65->isChecked();

	fifthSetList.grade[2].breakdown[0].humidity		= ui.checkBox71->isChecked();
	fifthSetList.grade[2].breakdown[0].knotCount	= ui.checkBox72->isChecked();
	fifthSetList.grade[2].breakdown[0].mould		= ui.checkBox73->isChecked();
	fifthSetList.grade[2].breakdown[0].crack		= ui.checkBox74->isChecked();
	fifthSetList.grade[2].breakdown[0].deformation  = ui.checkBox75->isChecked();

	fifthSetList.grade[2].breakdown[1].humidity		= ui.checkBox81->isChecked();
	fifthSetList.grade[2].breakdown[1].knotCount	= ui.checkBox82->isChecked();
	fifthSetList.grade[2].breakdown[1].mould		= ui.checkBox83->isChecked();
	fifthSetList.grade[2].breakdown[1].crack		= ui.checkBox84->isChecked();
	fifthSetList.grade[2].breakdown[1].deformation  = ui.checkBox85->isChecked();

	fifthSetList.grade[2].breakdown[2].humidity		= ui.checkBox91->isChecked();
	fifthSetList.grade[2].breakdown[2].knotCount	= ui.checkBox92->isChecked();
	fifthSetList.grade[2].breakdown[2].mould		= ui.checkBox93->isChecked();
	fifthSetList.grade[2].breakdown[2].crack		= ui.checkBox94->isChecked();
	fifthSetList.grade[2].breakdown[2].deformation  = ui.checkBox95->isChecked();

	return true;
}

bool Settings::readSixthSetList()
{

	sixthSetList.grade[0].breakdown[0].length = ui.checkBox11->isChecked();
	sixthSetList.grade[0].breakdown[0].width = ui.checkBox12->isChecked();
	sixthSetList.grade[0].breakdown[0].crack = ui.checkBox13->isChecked();

	sixthSetList.grade[0].breakdown[1].length = ui.checkBox21->isChecked();
	sixthSetList.grade[0].breakdown[1].width = ui.checkBox22->isChecked();
	sixthSetList.grade[0].breakdown[1].crack = ui.checkBox23->isChecked();

	sixthSetList.grade[0].breakdown[2].length = ui.checkBox31->isChecked();
	sixthSetList.grade[0].breakdown[2].width = ui.checkBox32->isChecked();
	sixthSetList.grade[0].breakdown[2].crack = ui.checkBox33->isChecked();

	sixthSetList.grade[1].breakdown[0].length = ui.checkBox41->isChecked();
	sixthSetList.grade[1].breakdown[0].width = ui.checkBox42->isChecked();
	sixthSetList.grade[1].breakdown[0].crack = ui.checkBox43->isChecked();

	sixthSetList.grade[1].breakdown[1].length = ui.checkBox51->isChecked();
	sixthSetList.grade[1].breakdown[1].width = ui.checkBox52->isChecked();
	sixthSetList.grade[1].breakdown[1].crack = ui.checkBox53->isChecked();

	sixthSetList.grade[1].breakdown[2].length = ui.checkBox61->isChecked();
	sixthSetList.grade[1].breakdown[2].width = ui.checkBox62->isChecked();
	sixthSetList.grade[1].breakdown[2].crack = ui.checkBox63->isChecked();

	sixthSetList.grade[2].breakdown[0].length = ui.checkBox71->isChecked();
	sixthSetList.grade[2].breakdown[0].width = ui.checkBox72->isChecked();
	sixthSetList.grade[2].breakdown[0].crack = ui.checkBox73->isChecked();

	sixthSetList.grade[2].breakdown[1].length = ui.checkBox81->isChecked();
	sixthSetList.grade[2].breakdown[1].width = ui.checkBox82->isChecked();
	sixthSetList.grade[2].breakdown[1].crack = ui.checkBox83->isChecked();

	sixthSetList.grade[2].breakdown[2].length = ui.checkBox91->isChecked();
	sixthSetList.grade[2].breakdown[2].width = ui.checkBox92->isChecked();
	sixthSetList.grade[2].breakdown[2].crack = ui.checkBox93->isChecked();

	return true;
}

bool Settings::readSeventhSetList()
{

	seventhSetList.grade[0].breakdown[0].width = ui.checkBox11->isChecked();
	seventhSetList.grade[0].breakdown[0].height = ui.checkBox12->isChecked();
	seventhSetList.grade[0].breakdown[0].crack = ui.checkBox13->isChecked();

	seventhSetList.grade[0].breakdown[1].width = ui.checkBox21->isChecked();
	seventhSetList.grade[0].breakdown[1].height = ui.checkBox22->isChecked();
	seventhSetList.grade[0].breakdown[1].crack = ui.checkBox23->isChecked();

	seventhSetList.grade[0].breakdown[2].width = ui.checkBox31->isChecked();
	seventhSetList.grade[0].breakdown[2].height = ui.checkBox32->isChecked();
	seventhSetList.grade[0].breakdown[2].crack = ui.checkBox33->isChecked();

	seventhSetList.grade[1].breakdown[0].width = ui.checkBox41->isChecked();
	seventhSetList.grade[1].breakdown[0].height = ui.checkBox42->isChecked();
	seventhSetList.grade[1].breakdown[0].crack = ui.checkBox43->isChecked();

	seventhSetList.grade[1].breakdown[1].width = ui.checkBox51->isChecked();
	seventhSetList.grade[1].breakdown[1].height = ui.checkBox52->isChecked();
	seventhSetList.grade[1].breakdown[1].crack = ui.checkBox53->isChecked();

	seventhSetList.grade[1].breakdown[2].width = ui.checkBox61->isChecked();
	seventhSetList.grade[1].breakdown[2].height = ui.checkBox62->isChecked();
	seventhSetList.grade[1].breakdown[2].crack = ui.checkBox63->isChecked();

	seventhSetList.grade[2].breakdown[0].width = ui.checkBox71->isChecked();
	seventhSetList.grade[2].breakdown[0].height = ui.checkBox72->isChecked();
	seventhSetList.grade[2].breakdown[0].crack = ui.checkBox73->isChecked();

	seventhSetList.grade[2].breakdown[1].width = ui.checkBox81->isChecked();
	seventhSetList.grade[2].breakdown[1].height = ui.checkBox82->isChecked();
	seventhSetList.grade[2].breakdown[1].crack = ui.checkBox83->isChecked();

	seventhSetList.grade[2].breakdown[2].width = ui.checkBox91->isChecked();
	seventhSetList.grade[2].breakdown[2].height = ui.checkBox92->isChecked();
	seventhSetList.grade[2].breakdown[2].crack = ui.checkBox93->isChecked();

	return true;
}

bool Settings::readEighthSetList()
{

	eighthSetList.grade[0].breakdown[0].paintingDefect = ui.checkBox11->isChecked();
	eighthSetList.grade[0].breakdown[1].paintingDefect = ui.checkBox21->isChecked();
	eighthSetList.grade[0].breakdown[2].paintingDefect = ui.checkBox31->isChecked();

	eighthSetList.grade[1].breakdown[0].paintingDefect = ui.checkBox41->isChecked();
	eighthSetList.grade[1].breakdown[1].paintingDefect = ui.checkBox51->isChecked();
	eighthSetList.grade[1].breakdown[2].paintingDefect = ui.checkBox61->isChecked();

	eighthSetList.grade[2].breakdown[0].paintingDefect = ui.checkBox71->isChecked();
	eighthSetList.grade[2].breakdown[1].paintingDefect = ui.checkBox81->isChecked();
	eighthSetList.grade[2].breakdown[2].paintingDefect = ui.checkBox91->isChecked();

	return true;
}

bool Settings::readNinthSetList()
{
	if (ui.lineEdit11->text().isEmpty() || ui.lineEdit12->text().isEmpty()
		|| ui.lineEdit21->text().isEmpty() || ui.lineEdit22->text().isEmpty()
		|| ui.lineEdit31->text().isEmpty() || ui.lineEdit32->text().isEmpty())
	{
		warning->exec();
		return false;
	}

	ninthSetList.brigade[0].effectiveCoef = ui.lineEdit11->text().toInt();
	ninthSetList.brigade[0].trainCost = ui.lineEdit12->text().toInt();

	ninthSetList.brigade[1].effectiveCoef = ui.lineEdit21->text().toInt();
	ninthSetList.brigade[1].trainCost = ui.lineEdit22->text().toInt();

	ninthSetList.brigade[2].effectiveCoef = ui.lineEdit31->text().toInt();
	ninthSetList.brigade[2].trainCost = ui.lineEdit32->text().toInt();

	return true;
}

void Settings::nextBtnClicked()
{
	switch (setState)
	{
	case Zero:
		if (checkPassword())
		{
			setState = First;
			showFirstSetList();
		}
		else
			wrongPassword->exec();
		break;
	case First:
		if (readFirstSetList())
		{
			setState = Second;
			showSecondSetList();
		}
		break;
	case Second:
		if (readSecondSetList())
		{
			setState = Third;
			showThirdSetList();
		}
		break;
	case Third:
		if (readThirdSetList())
		{
			setState = Fourth;
			showFourthSetList();
		}
		break;
	case Fourth:
		if (readFourthSetList())
		{
			setState = Fifth;
			showFifthSetList();
		}
		break;
	case Fifth:
		if (readFifthSetList())
		{
			setState = Sixth;
			showSixthSetList();
		}
		break;
	case Sixth:
		if (readSixthSetList())
		{
			setState = Seventh;
			showSeventhSetList();
		}
		break;
	case Seventh:
		if (readSeventhSetList())
		{
			setState = Eighth;
			showEighthSetList();
		}
		break;
	case Eighth:
		if (readEighthSetList())
		{
			setState = Ninth;
			showNinthSetList();
		}
		break;
	}
}

void Settings::backBtnClicked()
{
	switch (setState)
	{
	case First:
		break;
	case Second:
		showFirstSetList();
		setState = First;
		break;
	case Third:
		showSecondSetList();
		setState = Second;
		break;
	case Fourth:
		showThirdSetList();
		setState = Third;
		break;
	case Fifth:
		showFourthSetList();
		setState = Fourth;
		break;
	case Sixth:
		showFifthSetList();
		setState = Fifth;
		break;
	case Seventh:
		showSixthSetList();
		setState = Sixth;
		break;
	case Eighth:
		showSeventhSetList();
		setState = Seventh;
		break;
	case Ninth:
		showEighthSetList();
		setState = Eighth;
		break;
	}
}

void Settings::finishBtnClicked()
{
	if (readNinthSetList())
	{
		setState = Finished;
		this->close();
		emit finishBtnPressed();
	}
}

void Settings::saveAndFinishBtnClicked()
{
	if (save())
	{
		if (readNinthSetList())
		{
			setState = Finished;
			this->close();
			emit finishBtnPressed();
		}
	}
	else
		saveError->exec();
}

void Settings::loadBtnClicked()
{
	if (checkPassword())
	{
		if (load())
		{
			setState = Finished;
			this->close();
			emit finishBtnPressed();
		}
		else
			loadError->exec();
	}
	else
		wrongPassword->exec();
}

void Settings::repairBtnClicked()
{
	UINT neededMoney = 0;

	switch (repairSet)
	{
	case Timbers:
	{
		std::vector<bool> needToSkip;
		ui.checkBox11->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox21->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox31->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox41->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox51->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox61->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox71->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox81->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox91->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);
		ui.checkBox101->isChecked() ? needToSkip.push_back(true) : needToSkip.push_back(false);

		for (int i = 0; i < needToSkip.size(); i++)
			if (needToSkip[i])
				neededMoney += firstSetList.batch[i].skipCost;

		if (neededMoney <= curMoney)
		{
			emit timbersSkip(neededMoney, needToSkip);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();
		break;
	}
	case PSBench:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[0].repairCost;

		if (neededMoney <= curMoney)
		{
			emit PSBenchRepair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case DryingBench:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[1].repairCost;

		if (neededMoney <= curMoney)
		{
			emit dryingBenchRepair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case SortingBench:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox14->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox15->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		ui.checkBox21->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox22->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox23->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox24->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox25->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		ui.checkBox31->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox32->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox33->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox34->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox35->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[2].repairCost;

		if (neededMoney <= curMoney)
		{
			emit sortingBenchRepair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case MillingBench1:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[3].repairCost;

		if (neededMoney <= curMoney)
		{
			emit millingBench1Repair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case MillingBench2:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[4].repairCost;

		if (neededMoney <= curMoney)
		{
			emit millingBench2Repair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case MillingBench3:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[5].repairCost;

		if (neededMoney <= curMoney)
		{
			emit millingBench3Repair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case AssemblingBench1:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[6].repairCost;

		if (neededMoney <= curMoney)
		{
			emit assemblingBench1Repair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case AssemblingBench2:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[7].repairCost;

		if (neededMoney <= curMoney)
		{
			emit assemblingBench2Repair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case AssemblingBench3:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox12->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox13->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[8].repairCost;

		if (neededMoney <= curMoney)
		{
			emit assemblingBench3Repair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case PaintingBench:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox21->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox31->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += secondSetList.bench[9].repairCost;

		if (neededMoney <= curMoney)
		{
			emit paintingBenchRepair(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	case Brigades:
	{
		std::vector<bool> needToRepair;
		ui.checkBox11->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox21->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);
		ui.checkBox31->isChecked() ? needToRepair.push_back(true) : needToRepair.push_back(false);

		for (int i = 0; i < needToRepair.size(); i++)
			if (needToRepair[i])
				neededMoney += ninthSetList.brigade[i].trainCost;

		if (neededMoney <= curMoney)
		{
			emit brigadesTrain(neededMoney, needToRepair);
			repairSet = NoRepair;
			this->close();
		}
		else
			moneyWarning->exec();

		break;
	}
	}


}

void Settings::skipTimbersBatch(UINT money, std::vector<UINT> lastInBetches)
{
	curMoney = money;
	repairSet = Timbers;
	if (this->isVisible())
		this->close();
	showTimbersBatshSkipSet(lastInBetches);
	this->show();
}

void Settings::repairPSBench(UINT money)
{
	curMoney = money;
	repairSet = PSBench;
	if (this->isVisible())
		this->close();
	showPSBenchRepairSet();
	this->show();
}

void Settings::repairDryingBench(UINT money)
{
	curMoney = money;
	repairSet = DryingBench;
	if (this->isVisible())
		this->close();
	showDryingBenchRepairSet();
	this->show();
}

void Settings::repairSortingBench(UINT money)
{
	curMoney = money;
	repairSet = SortingBench;
	if (this->isVisible())
		this->close();
	showSortingBenchRepairSet();
	this->show();
}

void Settings::repairMillingBench1(UINT money)
{
	curMoney = money;
	repairSet = MillingBench1;
	if (this->isVisible())
		this->close();
	showMillingBench1RepairSet();
	this->show();
}

void Settings::repairMillingBench2(UINT money)
{
	curMoney = money;
	repairSet = MillingBench2;
	if (this->isVisible())
		this->close();
	showMillingBench2RepairSet();
	this->show();
}

void Settings::repairMillingBench3(UINT money)
{
	curMoney = money;
	repairSet = MillingBench3;
	if (this->isVisible())
		this->close();
	showMillingBench3RepairSet();
	this->show();
}

void Settings::repairAssemblingBench1(UINT money)
{
	curMoney = money;
	repairSet = AssemblingBench1;
	if (this->isVisible())
		this->close();
	showAssemblingBench1RepairSet();
	this->show();
}

void Settings::repairAssemblingBench2(UINT money)
{
	curMoney = money;
	repairSet = AssemblingBench2;
	if (this->isVisible())
		this->close();
	showAssemblingBench2RepairSet();
	this->show();
}

void Settings::repairAssemblingBench3(UINT money)
{
	curMoney = money;
	repairSet = AssemblingBench3;
	if (this->isVisible())
		this->close();
	showAssemblingBench3RepairSet();
	this->show();
}

void Settings::repairPaintingBench(UINT money)
{
	curMoney = money;
	repairSet = PaintingBench;
	if (this->isVisible())
		this->close();
	showPaintingBenchRepairSet();
	this->show();
}

void Settings::trainBrigades(UINT money)
{
	curMoney = money;
	repairSet = Brigades;
	if (this->isVisible())
		this->close();
	showBrigadesTrainSet();
	this->show();
}

bool Settings::save()
{
	std::ofstream out("settings/settings.txt");

	if (out.is_open())
	{
		///////// firstSetList /////////
		for (int i = 0; i < 10; i++)
			out << firstSetList.batch[i].count << " " << firstSetList.batch[i].skipCost << " " << firstSetList.batch[i].hymidity << " " << firstSetList.batch[i].knotCount << " " << firstSetList.batch[i].diametr << " " << firstSetList.batch[i].length << " " << firstSetList.batch[i].mould << " " << firstSetList.batch[i].crack << std::endl;
		out << firstSetList.money << std::endl;

		///////// SecondSetList /////////
		for (int i = 0; i < 10; i++)
			out << secondSetList.bench[i].toFirstBreakdown << " " << secondSetList.bench[i].toSecondBreakdown << " " << secondSetList.bench[i].toThirdBreakdown << " " << secondSetList.bench[i].repairCost << std::endl;

		///////// ThirdSetList /////////
		for (int i = 0; i < 3; i++)
			out << thirdSetList.breakdown[i].length << " " << thirdSetList.breakdown[i].width << " " << thirdSetList.breakdown[i].crack << std::endl;

		///////// FourthSetList /////////
		for (int i = 0; i < 3; i++)
			out << fourthSetList.breakdown[i].humidity << " " << fourthSetList.breakdown[i].crack << " " << fourthSetList.breakdown[i].deformation << std::endl;

		///////// FifthSetList /////////
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				out << fifthSetList.grade[i].breakdown[j].humidity << " " << fifthSetList.grade[i].breakdown[j].knotCount << " " << fifthSetList.grade[i].breakdown[j].mould << " " << fifthSetList.grade[i].breakdown[j].crack << " " << fifthSetList.grade[i].breakdown[j].deformation << std::endl;

		///////// SixthSetList /////////
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				out << sixthSetList.grade[i].breakdown[j].length << " " << sixthSetList.grade[i].breakdown[j].width << " " << sixthSetList.grade[i].breakdown[j].crack << std::endl;

		///////// SeventhSetList /////////
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				out << seventhSetList.grade[i].breakdown[j].width << " " << seventhSetList.grade[i].breakdown[j].width << " " << seventhSetList.grade[i].breakdown[j].crack << std::endl;

		///////// EighthSetList /////////
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				out << eighthSetList.grade[i].breakdown[j].paintingDefect << std::endl;

		///////// NinthSetList /////////
		for (int i = 0; i < 3; i++)
		{
			if (i < 2)
				out << ninthSetList.brigade[i].effectiveCoef << " " << ninthSetList.brigade[i].trainCost << std::endl;
			else
				out << ninthSetList.brigade[i].effectiveCoef << " " << ninthSetList.brigade[i].trainCost;
		}

		out.close();

		return true;
	}

	out.close();

	return false;
}

bool Settings::load()
{
	std::ifstream in("settings/settings.txt");

	if (in.is_open())
	{
		///////// firstSetList /////////
		for (int i = 0; i < 10; i++)
			in >> firstSetList.batch[i].count >> firstSetList.batch[i].skipCost >> firstSetList.batch[i].hymidity >> firstSetList.batch[i].knotCount >> firstSetList.batch[i].diametr >> firstSetList.batch[i].length >> firstSetList.batch[i].mould >> firstSetList.batch[i].crack;
		in >> firstSetList.money;

		///////// SecondSetList /////////
		for (int i = 0; i < 10; i++)
			in >> secondSetList.bench[i].toFirstBreakdown >> secondSetList.bench[i].toSecondBreakdown >> secondSetList.bench[i].toThirdBreakdown >> secondSetList.bench[i].repairCost;

		///////// ThirdSetList /////////
		for (int i = 0; i < 3; i++)
			in >> thirdSetList.breakdown[i].length >> thirdSetList.breakdown[i].width >> thirdSetList.breakdown[i].crack;

		///////// FourthSetList /////////
		for (int i = 0; i < 3; i++)
			in >> fourthSetList.breakdown[i].humidity >> fourthSetList.breakdown[i].crack >> fourthSetList.breakdown[i].deformation;

		///////// FifthSetList /////////
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				in >> fifthSetList.grade[i].breakdown[j].humidity >> fifthSetList.grade[i].breakdown[j].knotCount >> fifthSetList.grade[i].breakdown[j].mould >> fifthSetList.grade[i].breakdown[j].crack >> fifthSetList.grade[i].breakdown[j].deformation;

		///////// SixthSetList /////////
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				in >> sixthSetList.grade[i].breakdown[j].length >> sixthSetList.grade[i].breakdown[j].width >> sixthSetList.grade[i].breakdown[j].crack;

		///////// SeventhSetList /////////
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				in >> seventhSetList.grade[i].breakdown[j].width >> seventhSetList.grade[i].breakdown[j].height >> seventhSetList.grade[i].breakdown[j].crack;

		///////// EighthSetList /////////
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				in >> eighthSetList.grade[i].breakdown[j].paintingDefect;

		///////// NinthSetList /////////
		for (int i = 0; i < 3; i++)
			in >> ninthSetList.brigade[i].effectiveCoef >> ninthSetList.brigade[i].trainCost;

		in.close();
		return true;
	}

	in.close();
	return false;
}

bool Settings::checkPassword()
{
	return ui.lineEdit11->text().toStdString() == password;
}

void Settings::setSettings(const Settings& set)
{
	this->firstSetList = set.firstSetList;
	this->secondSetList = set.secondSetList;
	this->thirdSetList = set.thirdSetList;
	this->fourthSetList = set.fourthSetList;
	this->fifthSetList = set.fifthSetList;
	this->sixthSetList = set.sixthSetList;
	this->seventhSetList = set.seventhSetList;
	this->eighthSetList = set.eighthSetList;
	this->ninthSetList = set.ninthSetList;
	this->setState = set.setState;
}


Settings::~Settings()
{
}


#include "stdafx.h"
#include "Window.h"

#include <QMessageBox>
#include <QSpinBox>
#include <QLabel>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QToolButton>
#include <QtWidgets/QApplication>
#include <QDesktopWidget.h>

Window::Window(QWidget *parent) : QMainWindow(parent)
{
	this->simulation = nullptr;
	this->newSettings = nullptr;
	this->ui.setupUi(this);

	QRect rect = QApplication::desktop()->screenGeometry();
	this->setGeometry(rect.x(),rect.y(), rect.width(), rect.height()-40);
	this->ui.display->window = this;

	QRect r = QApplication::desktop()->screenGeometry();

	QAction* act;

	act = new QAction(tr("&Start new simulation"), this);
	this->connect(act, &QAction::triggered, this, &Window::genNewSimulation);
	this->ui.mainToolBar->addAction(act);

	act = new QAction(tr("&Play"), this);
	act->setVisible(false);
	this->connect(act, &QAction::triggered, this, &Window::play);
	this->ui.mainToolBar->addAction(act);

	act = new QAction(tr("&<<"), this);
	act->setVisible(false);
	this->connect(act, &QAction::triggered, this, &Window::halveSpeed);
	this->ui.mainToolBar->addAction(act);

	act = new QAction(tr("&||"), this);
	act->setVisible(false);
	this->connect(act, &QAction::triggered, this, &Window::normalizeSpeed);
	this->ui.mainToolBar->addAction(act);

	act = new QAction(tr("&>>"), this);
	act->setVisible(false);
	this->connect(act, &QAction::triggered, this, &Window::doubleSpeed);
	this->ui.mainToolBar->addAction(act);

	QWidget *spacerWidget = new QWidget(this);
	spacerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	spacerWidget->setVisible(true);
	this->ui.mainToolBar->addWidget(spacerWidget);
	
	act = new QAction(tr("&Money:"), this);
	act->setObjectName("Money");
	act->setVisible(false);
	act->setDisabled(true);
	this->ui.mainToolBar->addAction(act);

	act = new QAction(tr("Exit"), this);
	this->connect(act, &QAction::triggered, this, &Window::exit);
	this->ui.mainToolBar->addAction(act);

}

void Window::genNewSimulation()
{
	if (newSettings)
		newSettings->close();
	newSettings = new Settings();

	QObject::connect(newSettings, SIGNAL(finishBtnPressed()), this, SLOT(finishSet()));

	newSettings->show();
}


void Window::exit()
{
	if (this->newSettings)
		this->newSettings->close();

	if (this->simulation)
	{
		if (this->simulation->settings.isVisible())
			this->simulation->settings.close();
		this->simulation->isPlayed = false;
		this->simulation->~Simulation();
	}

	this->close();
}

void Window::finishSet()
{
	if (simulation)
	{
		if (simulation->settings.isVisible())
			simulation->settings.close();
		this->simulation->isPlayed = false;
		simulation->~Simulation();
	}

	simulation = new Simulation(*newSettings);
	simulation->setWndParams(this->ui.display->width, this->ui.display->height);
	QObject::connect(&simulation->settings, SIGNAL(timbersSkip(UINT, std::vector<bool>)), this, SLOT(skipBatches(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(PSBenchRepair(UINT, std::vector<bool>)), this, SLOT(repairPSBench(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(dryingBenchRepair(UINT, std::vector<bool>)), this, SLOT(repairDryingBench(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(sortingBenchRepair(UINT, std::vector<bool>)), this, SLOT(repairSortingBench(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(millingBench1Repair(UINT, std::vector<bool>)), this, SLOT(repairMillingBench1(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(millingBench2Repair(UINT, std::vector<bool>)), this, SLOT(repairMillingBench2(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(millingBench3Repair(UINT, std::vector<bool>)), this, SLOT(repairMillingBench3(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(assemblingBench1Repair(UINT, std::vector<bool>)), this, SLOT(repairAssemblingBench1(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(assemblingBench2Repair(UINT, std::vector<bool>)), this, SLOT(repairAssemblingBench2(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(assemblingBench3Repair(UINT, std::vector<bool>)), this, SLOT(repairAssemblingBench3(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(paintingBenchRepair(UINT, std::vector<bool>)), this, SLOT(repairPaintingBench(UINT, std::vector<bool>)));
	QObject::connect(&simulation->settings, SIGNAL(brigadesTrain(UINT, std::vector<bool>)), this, SLOT(trainBrigades(UINT, std::vector<bool>)));

	delete newSettings;
	newSettings = nullptr;

	QList<QAction*> lst = ui.mainToolBar->actions();
	auto el = std::find_if(lst.begin(), lst.end(), [](QAction* QAct) { return QAct->text() == tr("&Play") || QAct->text() == tr("&Stop"); });
	(*el)->setVisible(true);
	(*el)->setText(tr("&Play"));

	el = std::find_if(lst.begin(), lst.end(), [](QAction* QAct) { return QAct->text() == tr("&<<"); });
	(*el)->setVisible(true);
	el = std::find_if(lst.begin(), lst.end(), [](QAction* QAct) { return QAct->text() == tr("&||"); });
	(*el)->setVisible(true);
	el = std::find_if(lst.begin(), lst.end(), [](QAction* QAct) { return QAct->text() == tr("&>>"); });
	(*el)->setVisible(true);

	setMoney(this->simulation->money);
}

void Window::play()
{
	this->simulation->isPlayed = !this->simulation->isPlayed;
	if (this->simulation->isPlayed)
	{

		QList<QAction*> lst = ui.mainToolBar->actions();
		auto el = std::find_if(lst.begin(), lst.end(), [](QAction* QAct) { return QAct->text() == tr("&Play"); });
		(*el)->setText(tr("&Stop"));
	}
	else
	{
		QList<QAction*> lst = ui.mainToolBar->actions();
		auto el = std::find_if(lst.begin(), lst.end(), [](QAction* QAct) { return QAct->text() == tr("&Stop"); });
		(*el)->setText(tr("&Play"));
	}

}

void Window::doubleSpeed()
{
	if (this->simulation)
		this->simulation->pps *= 2;
}
void Window::normalizeSpeed()
{
	if (this->simulation)
		this->simulation->pps = this->simulation->ppsNormal;
}
void Window::halveSpeed()
{
	if (this->simulation)
		this->simulation->pps /= 2;
}

void Window::skipBatches(UINT needToSpend, std::vector<bool> needToSkip)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	for (int i = 0; i < needToSkip.size(); i++)
	{
		if (needToSkip[i])
		{
			UINT beforSkip = 0;
			for (int j = 0; j < i; j++)
				beforSkip += this->simulation->settings.firstSetList.batch[j].count;
			for (int j = 0; j < this->simulation->settings.firstSetList.batch[i].count; j++)
			{
				if (this->simulation->timbers[beforSkip + j].isIdle())
					this->simulation->timbers[beforSkip + j].setSkiped();
			}
		}
	}
}

void Window::repairPSBench(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->pSBench.repairLength();
	if (needToDo[1])
		this->simulation->pSBench.repairWidth();
	if (needToDo[2])
		this->simulation->pSBench.repairCrack();
}

void Window::repairDryingBench(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->dryerBench.repairHumidity();
	if (needToDo[1])
		this->simulation->dryerBench.repairCrack();
	if (needToDo[2])
		this->simulation->dryerBench.repairDeformation();
}

void Window::repairSortingBench(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->sortingBench.repairHumidity1();
	if (needToDo[1])
		this->simulation->sortingBench.repairKnotCount1();
	if (needToDo[2])
		this->simulation->sortingBench.repairMould1();
	if (needToDo[3])
		this->simulation->sortingBench.repairCrack1();
	if (needToDo[4])
		this->simulation->sortingBench.repairDeformation1();

	if (needToDo[5])
		this->simulation->sortingBench.repairHumidity2();
	if (needToDo[6])
		this->simulation->sortingBench.repairKnotCount2();
	if (needToDo[7])
		this->simulation->sortingBench.repairMould2();
	if (needToDo[8])
		this->simulation->sortingBench.repairCrack2();
	if (needToDo[9])
		this->simulation->sortingBench.repairDeformation2();

	if (needToDo[10])
		this->simulation->sortingBench.repairHumidity3();
	if (needToDo[11])
		this->simulation->sortingBench.repairKnotCount3();
	if (needToDo[12])
		this->simulation->sortingBench.repairMould3();
	if (needToDo[13])
		this->simulation->sortingBench.repairCrack3();
	if (needToDo[14])
		this->simulation->sortingBench.repairDeformation3();
}

void Window::repairMillingBench1(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->millingBenchs[0].repairLength();
	if (needToDo[1])
		this->simulation->millingBenchs[0].repairWidth();
	if (needToDo[2])
		this->simulation->millingBenchs[0].repairCrack();
}

void Window::repairMillingBench2(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->millingBenchs[1].repairLength();
	if (needToDo[1])
		this->simulation->millingBenchs[1].repairWidth();
	if (needToDo[2])
		this->simulation->millingBenchs[1].repairCrack();
}

void Window::repairMillingBench3(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->millingBenchs[2].repairLength();
	if (needToDo[1])
		this->simulation->millingBenchs[2].repairWidth();
	if (needToDo[2])
		this->simulation->millingBenchs[2].repairCrack();
}

void Window::repairAssemblingBench1(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->assemblingBenchs[0].repairWidth();
	if (needToDo[1])
		this->simulation->assemblingBenchs[0].repairHeight();
	if (needToDo[2])
		this->simulation->assemblingBenchs[0].repairCrack();
}

void Window::repairAssemblingBench2(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->assemblingBenchs[1].repairWidth();
	if (needToDo[1])
		this->simulation->assemblingBenchs[1].repairHeight();
	if (needToDo[2])
		this->simulation->assemblingBenchs[1].repairCrack();
}

void Window::repairAssemblingBench3(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->assemblingBenchs[2].repairWidth();
	if (needToDo[1])
		this->simulation->assemblingBenchs[2].repairHeight();
	if (needToDo[2])
		this->simulation->assemblingBenchs[2].repairCrack();
}

void Window::repairPaintingBench(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->paintingBench.repairPainting1();
	if (needToDo[1])
		this->simulation->paintingBench.repairPainting2();
	if (needToDo[2])
		this->simulation->paintingBench.repairPainting3();
}

void Window::trainBrigades(UINT needToSpend, std::vector<bool> needToDo)
{
	this->simulation->money -= needToSpend;

	setMoney(this->simulation->money);

	if (needToDo[0])
		this->simulation->brigades[0].trianBrigade();
	if (needToDo[1])
		this->simulation->brigades[1].trianBrigade();
	if (needToDo[2])
		this->simulation->brigades[2].trianBrigade();
}

void Window::setMoney(UINT money)
{
	QList<QAction*> lst = ui.mainToolBar->actions();
	auto el = std::find_if(lst.begin(), lst.end(), [](QAction* QAct) { return QAct->objectName() == "Money"; });
	(*el)->setText(tr((std::string("Money: ") + std::to_string(money)).c_str()));
	(*el)->setVisible(true);
}
Window::~Window()
{
	this->simulation = nullptr;
}

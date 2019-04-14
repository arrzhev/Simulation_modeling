#pragma once

#ifndef _Window_H_
#define _Window_H_

#include <QtWidgets/QMainWindow>
#include "ui_Window.h"

#include "Display.h"
#include "Simulation.h"
#include "Settings.h"


class Window : public QMainWindow
{
	Q_OBJECT

public:
	Simulation* simulation;

	Window(QWidget *parent = Q_NULLPTR);

	virtual ~Window();

public slots:
	void finishSet();
	/// <param name="neededMoney">Number of money needed to pass selected batches</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.firstSetList"/></param>
	void skipBatches(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.thirdSetList"/></param>
	void repairPSBench(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.fourthSetList"/></param>
	void repairDryingBench(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.fifthSetList"/></param>
	void repairSortingBench(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.sixthSetList"/></param>
	void repairMillingBench1(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.sixthSetList"/></param>
	void repairMillingBench2(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.sixthSetList"/></param>
	void repairMillingBench3(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.seventhSetList"/></param>
	void repairAssemblingBench1(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.seventhSetList"/></param>
	void repairAssemblingBench2(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.seventhSetList"/></param>
	void repairAssemblingBench3(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.eighthSetList"/></param>
	void repairPaintingBench(UINT needToSpend, std::vector<bool> needToDo);
	/// <param name="neededMoney">Number of money needed to train selected brigades</param>
	/// <param name="itemsToDo">Array of possible train(true - train; false - not). Arrat size - 3(we got three brigades)</param>
	void trainBrigades(UINT needToSpend, std::vector<bool> needToDo);

private slots:
	void genNewSimulation();
	void play();
	void doubleSpeed();
	void normalizeSpeed();
	void halveSpeed();
	void exit();

private:
	Ui::WindowClass ui;
	
	Settings* newSettings;

	void setMoney(UINT money); // Set player's money
};

#endif; //_Window_H_
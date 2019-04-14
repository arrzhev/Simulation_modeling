#pragma once

#include <QWidget>
#include <QMessageBox>
#include "ui_Settings.h"
#include "stdafx.h"

/*
Widget with all simulation settings
*/
class Settings : public QWidget
{
	Q_OBJECT

public:

	// Set list with timbers batch settings and players money
	struct FirstSetList{
		struct Batch{
			unsigned int count = 0; // Number of timbers in the batch
			bool hymidity = false; // is humidity deffect
			bool knotCount = false; // is knot count deffect
			bool diametr = false; // is diametr deffect
			bool length = false; // is langth deffect
			bool mould = false; /// is mould deffect
			bool crack = false;// is crack deffect
			unsigned int skipCost = 0; // Batch pass price
		}batch[10];
		unsigned int money = 0; // Player's money
	}firstSetList;

	// Bench breakdown script
	struct SecondSetList{
		struct Bench{
			unsigned int toFirstBreakdown = 0;
			unsigned int toSecondBreakdown = 0;
			unsigned int toThirdBreakdown = 0;
			unsigned int repairCost = 0;
		}bench[10];
	}secondSetList;

	// Power-saw defects per breakdown
	struct ThirdSetList{
		struct Breakdown{
			bool length = false;
			bool width = false;
			bool crack = false;
		}breakdown[3];
	}thirdSetList;

	// Drying bench deffects per breakdown
	struct FourthSetList{
		struct Breakdown{
			bool humidity = false;
			bool crack = false;
			bool deformation = false;
		}breakdown[3];
	}fourthSetList;

	// Sorting bech deffects per  grade and breakdown
	struct FifthSetList{
		struct Grade{
			struct Breakdown{
				bool humidity = false;
				bool knotCount = false;
				bool mould = false;
				bool crack = false;
				bool deformation = false;
			}breakdown[3];
		}grade[3];
	}fifthSetList;

	// Milling bech deffects per grade and breakdown
	struct SixthSetList{
		struct Grade{
			struct Breakdown{
				bool length = false;
				bool width = false;
				bool crack = false;
			}breakdown[3];
		}grade[3];
	}sixthSetList;

	// Assembling bech deffects per grade and breakdown
	struct SeventhSetList{
		struct Grade{
			struct Breakdown{
				bool width = false;
				bool height = false;
				bool crack = false;
			}breakdown[3];
		}grade[3];
	}seventhSetList;

	// Painting bech deffects per grade and breakdown
	struct EighthSetList{
		struct Grade{
			struct Breakdown{
				bool paintingDefect = false;
			}breakdown[3];
		}grade[3];
	}eighthSetList;

	// Brigade set list
	struct NinthSetList{
		struct Brigade{
			double effectiveCoef = 1; // Brigade efficiency ratio(the higher the more likely the deffects)
			unsigned int trainCost = 0;
		}brigade[3];
	}ninthSetList;


	Settings(QWidget *parent = Q_NULLPTR);
	Settings(const Settings& set, QWidget *parent = Q_NULLPTR);

	void showZeroSetList();

	void showFirstSetList();
	bool readFirstSetList();

	void showSecondSetList();
	bool readSecondSetList();

	void showThirdSetList();
	bool readThirdSetList();

	void showFourthSetList();
	bool readFourthSetList();

	void showFifthSetList();
	bool readFifthSetList();

	void showSixthSetList(); 
	bool readSixthSetList();

	void showSeventhSetList();
	bool readSeventhSetList();

	void showEighthSetList();
	bool readEighthSetList();

	void showNinthSetList();
	bool readNinthSetList();

	/// <param name="lastInBatches">Array of the number of doors remaining in the Batch (size - 10)</param>
	void showTimbersBatshSkipSet(vector<UINT> lastInBatches);
	/// <param name="money">Curent payer's money</param>
	/// <param name="lastInBatches">Array of the number of doors remaining in the Batch (size - 10)</param>
	void skipTimbersBatch(UINT money, vector<UINT> lastInBatches);

	void showPSBenchRepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairPSBench(UINT money);

	void showDryingBenchRepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairDryingBench(UINT money);

	void showSortingBenchRepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairSortingBench(UINT money);

	void showMillingBench1RepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairMillingBench1(UINT money);

	void showMillingBench2RepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairMillingBench2(UINT money);

	void showMillingBench3RepairSet();
	/// <param name="money">Curent payer's money </param>
	void repairMillingBench3(UINT money);

	void showAssemblingBench1RepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairAssemblingBench1(UINT money);

	void showAssemblingBench2RepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairAssemblingBench2(UINT money);

	void showAssemblingBench3RepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairAssemblingBench3(UINT money);

	void showPaintingBenchRepairSet();
	/// <param name="money">Curent payer's money</param>
	void repairPaintingBench(UINT money);

	void showBrigadesTrainSet();
	/// <param name="money">Curent payer's money</param>
	void trainBrigades(UINT money);

	/// <param name="doorsCount">Number of already prodused 1 grade doors</param>
	/// <param name="deffectsCount">Array of the number of 1 grade doors which got the deffects (size - 8, 8 - number of door's deffects)</param>
	void showFirstGradeDoorsStat(UINT doorsCount, vector<UINT> deffectsCount);

	/// <param name="doorsCount">Number of already prodused 2 grade doors</param>
	/// <param name="deffectsCount">Array of the number of 2 grade doors which got the deffects (size - 8, 8 - number of door's deffects)</param>
	void showSecondGradeDoorsStat(UINT doorsCount, vector<UINT> deffectsCount);

	/// <param name="doorsCount">Number of already prodused 3 grade doors</param>
	/// <param name="deffectsCount" >Array of the number of 3 grade doors which got the deffects (size - 8, 8 - number of door's deffects)</param>
	void showThirdGradeDoorsStat(UINT doorsCount, vector<UINT> deffectsCount);

	/// <summary> Copy settings </summary>
	void setSettings(const Settings& set);

	~Settings();	

signals:
	void finishBtnPressed();
	/// <param name="neededMoney">Number of money needed to pass selected batches</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.firstSetList"/></param>
	void timbersSkip(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.thirdSetList"/></param>
	void PSBenchRepair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.fourthSetList"/></param>
	void dryingBenchRepair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.fifthSetList"/></param>
	void sortingBenchRepair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.sixthSetList"/></param>
	void millingBench1Repair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.sixthSetList"/></param>
	void millingBench2Repair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.sixthSetList"/></param>
	void millingBench3Repair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.seventhSetList"/></param>
	void assemblingBench1Repair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.seventhSetList"/></param>
	void assemblingBench2Repair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.seventhSetList"/></param>
	void assemblingBench3Repair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to repair selected defects</param>
	/// <param name="itemsToDo">Array of possible deffects(true - repair; flase - not)
	/// List of possible deffects see here <see cref="Settings.eighthSetList"/></param>
	void paintingBenchRepair(UINT neededMoney, std::vector<bool> itemsToDo);
	/// <param name="neededMoney">Number of money needed to train selected brigades</param>
	/// <param name="itemsToDo">Array of possible train(true - train; false - not). Arrat size - 3(we got three brigades)</param>
	void brigadesTrain(UINT neededMoney, std::vector<bool> itemsToDo);

private slots:
	void finishBtnClicked();
	void saveAndFinishBtnClicked();
	void loadBtnClicked();
	void repairBtnClicked();
	void nextBtnClicked();
	void backBtnClicked();


private:
	Ui::Settings ui;
	
	const std::string password = "123";

	QMessageBox* warning;
	QMessageBox* saveError;
	QMessageBox* loadError;
	QMessageBox* wrongPassword;
	QMessageBox* moneyWarning;
	enum {Zero, First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth, Ninth, Finished} setState = Zero; // State of UI, related to shown set list
	enum { NoRepair, Timbers, PSBench, DryingBench, SortingBench, MillingBench1, MillingBench2, MillingBench3, AssemblingBench1, AssemblingBench2, AssemblingBench3, PaintingBench, Brigades } repairSet = NoRepair; // State of UI, relayed to shown repair set list
	UINT curMoney = 0; // Curent player's money

	bool checkPassword();
	bool save();
	bool load();
};


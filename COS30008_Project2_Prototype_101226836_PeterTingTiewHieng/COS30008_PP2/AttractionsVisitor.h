#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class FerrisWheel;
class WaterPark;
class RollerCoaster;

class AttractionsVisitor
{
public:
	// Constructor and destructor
	AttractionsVisitor();
	virtual ~AttractionsVisitor();

	// visit different type of attractions
	virtual void visit(FerrisWheel* f) = 0;
	virtual void visit(WaterPark* w) = 0;
	virtual void visit(RollerCoaster* r) = 0;
};

class DecreaseTVisitor : public AttractionsVisitor
{
private:
	int increasedFame;
public:
	// Constructor and destructor
	DecreaseTVisitor();
	~DecreaseTVisitor();

	// getters
	int getIncreasedFame();

	// visit different type of attractions
	void visit(FerrisWheel* f);
	void visit(WaterPark* w);
	void visit(RollerCoaster* r);
};

class UpgradeVisitor : public AttractionsVisitor
{
private:
	int cost;
	int gold;

public:
	// Constructor and destructor
	UpgradeVisitor(int g);
	~UpgradeVisitor();

	// getters
	int getRemainder();

	// visit different type of attractions
	void visit(FerrisWheel* f);
	void visit(WaterPark* w);
	void visit(RollerCoaster* r);
};

class RefundVisitor : public AttractionsVisitor
{
private:
	int refunded;
public:
	// Constructor and destructor
	RefundVisitor();
	~RefundVisitor();

	// getters
	int getRefunded();

	// visit different type of attractions
	void visit(FerrisWheel* f);
	void visit(WaterPark* w);
	void visit(RollerCoaster* r);
};
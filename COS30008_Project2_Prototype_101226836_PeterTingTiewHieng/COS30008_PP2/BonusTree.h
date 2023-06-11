#pragma once
#include <iostream>
using namespace std;

class BonusTree
{
private:
	int bonusRate;
	int conditionDays;
	BonusTree* fLeft;
	BonusTree* fRight;

	BonusTree();

public:
	// Constructor and destructor
	BonusTree(int r, int c);
	~BonusTree();

	// Read node data
	int readRate();
	int readCondition();

	// check whether its the leaf of the tree
	bool lastNode();

	// Check whethter the node is empty
	bool isEmpty() const;

	// Get left node
	BonusTree* left();

	// Get right node
	BonusTree* right();

	// Attach node to left
	void attachLeft(BonusTree* r);

	// Attach node to right
	void attachRight(BonusTree* r);

	// Detach left node
	BonusTree* detachLeft();

	// Detach right node
	BonusTree* detachRight();
};
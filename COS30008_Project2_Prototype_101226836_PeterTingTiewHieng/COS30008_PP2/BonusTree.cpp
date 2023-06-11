#include "BonusTree.h"

BonusTree::BonusTree()
{
	bonusRate = int();
	conditionDays = int();
	fLeft = nullptr;
	fRight = nullptr;
}

BonusTree::BonusTree(int r, int c)
{
	bonusRate = r;
	conditionDays = c;
	fLeft = nullptr;
	fRight = nullptr;
}

BonusTree::~BonusTree()
{
	if (fLeft != nullptr)
	{
		delete fLeft;
	}
	if (fRight != nullptr)
	{
		delete fRight;
	}
}

int BonusTree::readRate() { return bonusRate; }

int BonusTree::readCondition() { return conditionDays; }

bool BonusTree::lastNode()
{
	if (fLeft == nullptr && fRight == nullptr)
	{
		return true;
	}
	else { 
		return false; 
	}
}

bool BonusTree::isEmpty() const { return this == NULL; }

BonusTree* BonusTree::left()
{
	if (isEmpty())
		throw std::domain_error("Empty node!");

	return fLeft;
}

BonusTree* BonusTree::right()
{
	if (isEmpty())
		throw std::domain_error("Empty node!");

	return fRight;
}

void BonusTree::attachLeft(BonusTree* r)
{
	if (isEmpty())
		throw std::domain_error("Empty Node");

	if (fLeft != nullptr)
		throw std::domain_error("Non-empty sub tree");

	fLeft = r;
}

void BonusTree::attachRight(BonusTree* r)
{
	if (isEmpty())
		throw std::domain_error("Empty Node");

	if (fRight != nullptr)
		throw std::domain_error("Non-empty sub tree");

	fRight = r;
}

BonusTree* BonusTree::detachLeft()
{
	if (isEmpty())
		throw std::domain_error("Empty Node");

	BonusTree* Result = fLeft;
	fLeft = nullptr;
	return Result;
}

BonusTree* BonusTree::detachRight()
{
	if (isEmpty())
		throw std::domain_error("Empty Node");

	BonusTree* Result = fRight;
	fRight = nullptr;
	return Result;
}
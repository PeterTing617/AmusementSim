#include "AmusementPark.h"

void AmusementPark::initTree()
{
	headT = new BonusTree(0, 10);
	headT->attachLeft(new BonusTree(0, 5));
	headT->attachRight(new BonusTree(0, 15));
	headT->left()->attachLeft(new BonusTree(1, 0));
	headT->left()->attachRight(new BonusTree(2, 0));
	headT->right()->attachLeft(new BonusTree(3, 0));
	headT->right()->attachRight(new BonusTree(4, 0));
}

AmusementPark::AmusementPark()
{
	maxAttractions = 2;
	initTree();
}

AmusementPark::~AmusementPark()
{
	for (size_t i = 0; i < attractions.size(); i++)
	{
		delete attractions[i];
	}
	delete headT;
}

int AmusementPark::parkSize() { return attractions.size(); }

int AmusementPark::limitAttractions() { return maxAttractions; }

void AmusementPark::increaseLimit(int i) { maxAttractions += i; }

void AmusementPark::addAttractions(string i) { attractions.push_back(atF.buildAttractions(i)); }

int AmusementPark::removeAttractions(string i)
{
	RefundVisitor r;
	attractions[stoi(i) - 1]->accept(r);
	delete attractions[stoi(i) - 1];
	attractions.erase(attractions.begin() + (stoi(i) - 1));
	cout << "Refunded " << r.getRefunded() << " gold\n" << endl;
	return r.getRefunded();
}

int AmusementPark::upgradeAttractions(string i, int g)
{
	UpgradeVisitor u(g);
	attractions[stoi(i) - 1]->accept(u);
	return u.getRemainder();
}

void AmusementPark::updateBonus()
{
	for (size_t i = 0; i < attractions.size(); i++)
	{
		BonusTree* check = headT;
		while (!check->lastNode())
		{
			if (attractions[i]->getOperatingDays() <= check->readCondition())
			{
				check = check->left();
			}
			else {
				check = check->right();
			}
		}
		attractions[i]->setBonus(check->readRate());
	}
}

void AmusementPark::readAttractionInfo()
{
	for (size_t i = 0; i < attractions.size(); i++)
	{
		cout << "[" << i + 1 << "] ";
		attractions[i]->showInformation();
	}
}

tuple<int, int> AmusementPark::proceedNextDay()
{
	int earned = 0;
	int famed = 0;
	for (size_t i = 0; i < attractions.size(); i++)
	{
		if (attractions[i]->getBuildingStatus() == "Completed")
		{
			earned += attractions[i]->getEarnings() * attractions[i]->getBonus();
			famed += attractions[i]->getFame() * attractions[i]->getBonus();
			attractions[i]->increaseOperatingDays();
		}
	}
	DecreaseTVisitor d;
	for (size_t i = 0; i < attractions.size(); i++)
	{
		attractions[i]->accept(d);
	}
	cout << endl;
	famed += d.getIncreasedFame();
	updateBonus();
	return { earned, famed };
}
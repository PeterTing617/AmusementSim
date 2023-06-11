#include "AttractionsVisitor.h"
#include "FerrisWheel.h"
#include "WaterPark.h"
#include "RollerCoaster.h"

AttractionsVisitor::AttractionsVisitor()
{
}

AttractionsVisitor::~AttractionsVisitor()
{
}

DecreaseTVisitor::DecreaseTVisitor()
{
	increasedFame = 0;
}

DecreaseTVisitor::~DecreaseTVisitor()
{
}

int DecreaseTVisitor::getIncreasedFame()
{
	return increasedFame;
}

void DecreaseTVisitor::visit(FerrisWheel* f)
{
	if (f->getBuildTime() != 0)
	{
		f->decreaseBuildingT();
		if (f->getBuildTime() == 0)
		{
			cout << "Ferris Wheel built" << endl;
			increasedFame += f->getFame() * 2;
		}
	}
	if (f->getUpgradeTime() != 0)
	{
		f->decreaseUpgradeT();
		if (f->getUpgradeTime() == 0)
		{
			cout << "Ferris Wheel level " << f->getLevel() << " upgrade done" << endl;
			increasedFame += f->getFame() * 2;
		}
	}
}

void DecreaseTVisitor::visit(WaterPark* w)
{
	if (w->getBuildTime() != 0)
	{
		w->decreaseBuildingT();
		if (w->getBuildTime() == 0)
		{
			cout << "Water Park built" << endl;
			increasedFame += w->getFame() * 2;
		}
	}
	if (w->getUpgradeTime() != 0)
	{
		w->decreaseUpgradeT();
		if (w->getUpgradeTime() == 0)
		{
			cout << "Water Park level " << w->getLevel() << " upgrade done" << endl;
			increasedFame += w->getFame() * 2;
		}
	}
}

void DecreaseTVisitor::visit(RollerCoaster* r)
{
	if (r->getBuildTime() != 0)
	{
		r->decreaseBuildingT();
		if (r->getBuildTime() == 0)
		{
			cout << "Roller Coaster built" << endl;
			increasedFame += r->getFame() * 2;
		}
	}
	if (r->getUpgradeTime() != 0)
	{
		r->decreaseUpgradeT();
		if (r->getUpgradeTime() == 0)
		{
			cout << "Roller Coaster level " << r->getLevel() << " upgrade done" << endl;
			increasedFame += r->getFame() * 2;
		}
	}
}

UpgradeVisitor::UpgradeVisitor(int g)
{
	cost = 0;
	gold = g;
}

UpgradeVisitor::~UpgradeVisitor()
{
}

int UpgradeVisitor::getRemainder()
{
	return gold - cost;
}

void UpgradeVisitor::visit(FerrisWheel* f)
{
	string userInput;
	if (f->getBuildingStatus() == "Completed")
	{
		if (f->getLevel() == 1)
		{
			cout << "Ferris Wheel Upgrade from level " << f->getLevel() << " to level " << f->getLevel() + 1 << endl;
			cout << "Earnings: " << f->getEarnings() << " -> " << 2 << endl;
			cout << "Fame: " << f->getFame() << " per day -> " << 3 << " per day" << endl;
			cout << "Upgrading Time: " << 3 << " days" << endl;
			cout << "Cost: " << 3 << " gold" << endl;
			cout << "[1] Confirm" << endl;
			cout << "[2] Cancel" << endl;
			cout << ">>";
			while (userInput != "1" && userInput != "2")
			{
				getline(cin, userInput);
				cout << endl;
				if (userInput == "1")
				{
					if (gold < 3)
					{
						cout << "Insufficient funds\n" << endl;
						userInput = "";
					}
					else {
						cost = 3;
						f->upgradeLvl();
						f->setEarnings(2);
						f->setFame(3);
						f->setUpgradeTime(3);
						cout << "Upgrading Ferris Wheel to level " << f->getLevel() << "\n" << endl;
					}
				}
			}
		}
		else if (f->getLevel() == 2)
		{
			cout << "Ferris Wheel Upgrade from level " << f->getLevel() << " to level " << f->getLevel() + 1 << endl;
			cout << "Earnings: " << f->getEarnings() << " -> " << 3 << endl;
			cout << "Fame: " << f->getFame() << " per day -> " << 5 << " per day" << endl;
			cout << "Upgrading Time: " << 5 << " days" << endl;
			cout << "Cost: " << 5 << " gold" << endl;
			cout << "[1] Confirm" << endl;
			cout << "[2] Cancel" << endl;
			cout << ">>";
			while (userInput != "1" && userInput != "2")
			{
				getline(cin, userInput);
				cout << endl;
				if (userInput == "1")
				{
					if (gold < 5)
					{
						cout << "Insufficient funds\n" << endl;
						userInput = "";
					}
					else {
						cost = 5;
						f->upgradeLvl();
						f->setEarnings(3);
						f->setFame(5);
						f->setUpgradeTime(5);
						cout << "Upgrading Ferris Wheel to level " << f->getLevel() << "\n" << endl;
					}
				}
			}
		}
		else {
			cout << "You have reached the max level for this attraction.\n" << endl;
		}
	}
	else {
		cout << "You cannot upgrade this attraction at this time\n" << endl;
	}
}

void UpgradeVisitor::visit(WaterPark* w)
{
	string userInput;
	if (w->getBuildingStatus() == "Completed")
	{
		if (w->getLevel() == 1)
		{
			cout << "Water Park Upgrade from level " << w->getLevel() << " to level " << w->getLevel() + 1 << endl;
			cout << "Earnings: " << w->getEarnings() << " -> " << 8 << endl;
			cout << "Fame: " << w->getFame() << " per day -> " << 15 << " per day" << endl;
			cout << "Upgrading Time: " << 8 << " days" << endl;
			cout << "Cost: " << 15 << " gold" << endl;
			cout << "[1] Confirm" << endl;
			cout << "[2] Cancel" << endl;
			cout << ">>";
			while (userInput != "1" && userInput != "2")
			{
				getline(cin, userInput);
				cout << endl;
				if (userInput == "1")
				{
					if (gold < 15)
					{
						cout << "Insufficient funds\n" << endl;
						userInput = "";
					}
					else {
						cost = 15;
						w->upgradeLvl();
						w->setEarnings(8);
						w->setFame(15);
						w->setUpgradeTime(8);
						cout << "Upgrading Water Park to level " << w->getLevel() << "\n" << endl;
					}
				}
			}
		}
		else if (w->getLevel() == 2)
		{
			cout << "Water Park Upgrade from level " << w->getLevel() << " to level " << w->getLevel() + 1 << endl;
			cout << "Earnings: " << w->getEarnings() << " -> " << 12 << endl;
			cout << "Fame: " << w->getFame() << " per day -> " << 23 << " per day" << endl;
			cout << "Upgrading Time: " << 12 << " days" << endl;
			cout << "Cost: " << 23 << " gold" << endl;
			cout << "[1] Confirm" << endl;
			cout << "[2] Cancel" << endl;
			cout << ">>";
			while (userInput != "1" && userInput != "2")
			{
				getline(cin, userInput);
				cout << endl;
				if (userInput == "1")
				{
					if (gold < 23)
					{
						cout << "Insufficient funds\n" << endl;
						userInput = "";
					}
					else {
						cost = 23;
						w->upgradeLvl();
						w->setEarnings(12);
						w->setFame(23);
						w->setUpgradeTime(12);
						cout << "Upgrading Water Park to level " << w->getLevel() << "\n" << endl;
					}
				}
			}
		}
		else {
			cout << "You have reached the max level for this attraction.\n" << endl;
		}
	}
	else {
		cout << "You cannot upgrade this attraction at this time\n" << endl;
	}
}

void UpgradeVisitor::visit(RollerCoaster* r)
{
	string userInput;
	if (r->getBuildingStatus() == "Completed")
	{
		if (r->getLevel() == 1)
		{
			cout << "Roller Coaster Upgrade from level " << r->getLevel() << " to level " << r->getLevel() + 1 << endl;
			cout << "Earnings: " << r->getEarnings() << " -> " << 15 << endl;
			cout << "Fame: " << r->getFame() << " per day -> " << 30 << " per day" << endl;
			cout << "Upgrading Time: " << 15 << " days" << endl;
			cout << "Cost: " << 30 << " gold" << endl;
			cout << "[1] Confirm" << endl;
			cout << "[2] Cancel" << endl;
			cout << ">>";
			while (userInput != "1" && userInput != "2")
			{
				getline(cin, userInput);
				cout << endl;
				if (userInput == "1")
				{
					if (gold <= 30)
					{
						cout << "Insufficient funds\n" << endl;
						userInput = "";
					}
					else {
						cost = 30;
						r->upgradeLvl();
						r->setEarnings(15);
						r->setFame(30);
						r->setUpgradeTime(15);
						cout << "Upgrading Roller Coaster to level " << r->getLevel() << "\n" << endl;
					}
				}
			}
		}
		else if (r->getLevel() == 2)
		{
			cout << "Roller Coaster Upgrade from level " << r->getLevel() << " to level " << r->getLevel() + 1 << endl;
			cout << "Earnings: " << r->getEarnings() << " -> " << 23 << endl;
			cout << "Fame: " << r->getFame() << " per day -> " << 45 << " per day" << endl;
			cout << "Upgrading Time: " << 23 << " days" << endl;
			cout << "Cost: " << 45 << " gold" << endl;
			cout << "[1] Confirm" << endl;
			cout << "[2] Cancel" << endl;
			cout << ">>";
			while (userInput != "1" && userInput != "2")
			{
				getline(cin, userInput);
				cout << endl;
				if (userInput == "1")
				{
					if (gold <= 45)
					{
						cout << "Insufficient funds\n" << endl;
						userInput = "";
					}
					else {
						cost = 45;
						r->upgradeLvl();
						r->setEarnings(23);
						r->setFame(45);
						r->setUpgradeTime(23);
						cout << "Upgrading Roller Coaster to level " << r->getLevel() << "\n" << endl;
					}
				}
			}
		}
		else {
			cout << "You have reached the max level for this attraction.\n" << endl;
		}
	}
	else {
		cout << "You cannot upgrade this attraction at this time\n" << endl;
	}
}

RefundVisitor::RefundVisitor()
{
	refunded = 0;
}

RefundVisitor::~RefundVisitor()
{
}

int RefundVisitor::getRefunded()
{
	return refunded;
}

void RefundVisitor::visit(FerrisWheel* f)
{
	if (f->getLevel() == 1) {
		refunded = 2;
	}
	else if (f->getLevel() == 2)
	{
		refunded = 2;
	}
	else if (f->getLevel() == 3)
	{
		refunded = 3;
	}
}

void RefundVisitor::visit(WaterPark* w)
{
	if (w->getLevel() == 1) {
		refunded = 5;
	}
	else if (w->getLevel() == 2)
	{
		refunded = 8;
	}
	else if (w->getLevel() == 3)
	{
		refunded = 12;
	}
}

void RefundVisitor::visit(RollerCoaster* r)
{
	if (r->getLevel() == 1) {
		refunded = 10;
	}
	else if (r->getLevel() == 2)
	{
		refunded = 15;
	}
	else if (r->getLevel() == 3)
	{
		refunded = 23;
	}
}

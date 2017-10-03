#pragma once

class MainHand;
class OffHand;
class Armour;

class Character
{
public:
	int level;
	int strength;
	int dexterity;
	int intellegence;
	int currentGold;
	int currentExp;
	int nextLevelExp;
	//int mainHandId;
	//int offHandID;
	//int armourID;
	double healthpoints;
	std::string name;
	std::string CharacterClass;
	std::list<std::string> backpack;
	MainHand * mainHand;
	OffHand * offHand;
	Armour * armour;
	void setcharvalues(std::string allstats);
};

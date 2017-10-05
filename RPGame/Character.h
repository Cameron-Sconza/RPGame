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
	double attack;
	double defence;
	double nextLevelExp;
	double currentHealthPoints;
	double maxHealthPoints;
	std::string name;
	std::string CharacterClass;
	std::vector<std::string> backpack;
	MainHand * mainHand;
	OffHand * offHand;
	Armour * armour;
	void setcharvalues(std::string allstats);
	Character Clear(Character character);
};

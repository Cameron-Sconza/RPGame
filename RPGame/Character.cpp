#include "stdafx.h"
#include "Character.h"

void Character::setcharvalues(std::string allstats) {
	std::stringstream ss(allstats);
	std::string temp;
	getline(ss, name, '\n');
	getline(ss, CharacterClass, '\n');
	(getline(ss, temp, '\n'));
	std::stringstream(temp) >> level;
	temp.clear();
	(getline(ss, temp, '\n'));
	std::stringstream(temp) >> strength;
	temp.clear();
	(getline(ss, temp, '\n'));
	std::stringstream(temp) >> dexterity;
	temp.clear();
	(getline(ss, temp, '\n'));
	std::stringstream(temp) >> intellegence;
	temp.clear();
	(getline(ss, temp, '\n'));
	std::stringstream(temp) >> currentGold;
	temp.clear();
	(getline(ss, temp, '\n'));
	std::stringstream(temp) >> currentExp;
	temp.clear();
	(getline(ss, temp, '\n'));
	std::stringstream(temp) >> nextLevelExp;
	do {
		temp.clear();
		getline(ss, temp, '\n');
		if (!temp.empty()) {
			backpack.push_back(temp);
		}
	} while (!temp.empty());
	healthpoints = ceil(((level*strength) / 2) + 20);
}

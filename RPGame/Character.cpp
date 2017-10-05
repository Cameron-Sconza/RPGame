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
	maxHealthPoints = std::ceil((((level*strength + (dexterity*level) / 3)) / 2) + 20);
	currentHealthPoints = maxHealthPoints;
	if (CharacterClass == "Wizard") {
		attack = std::ceil(((intellegence * 2) / 3) + 2);
	}
	else if (CharacterClass == "Warrior") {
		attack = std::ceil(((strength * 2) / 3) + (dexterity*0.5) + 3);
	}
	else if (CharacterClass == "Rogue") {
		attack = std::ceil(((dexterity * 2) / 3) + (strength*0.5) + 2);
	}
	defence = std::ceil((strength + dexterity) / 1.5);
}

Character Character::Clear(Character character) {
	Character c = character;
	c.name.clear();
	c.CharacterClass.clear();
	c.level = 0;
	c.strength = 0;
	c.dexterity = 0;
	c.intellegence = 0;
	c.currentGold = 0;
	c.currentExp = 0;
	c.nextLevelExp = 0;
	c.maxHealthPoints = 0;
	c.currentHealthPoints = 0;
	c.backpack.clear();
	return c;
}

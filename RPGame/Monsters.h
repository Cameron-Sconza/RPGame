#pragma once
class Monsters
{
public:
	int maxHealthPoints;
	int currentHealthPoints;
	int attack;
	int defence;
	std::string name;
	std::vector<Monsters> getAllMonsters();
};


#pragma once
class Monsters
{
public:
	double maxHealthPoints;
	double currentHealthPoints;
	int attack;
	int defence;
	std::string name;
	std::vector<Monsters> getAllMonsters();
};


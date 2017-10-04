#include "stdafx.h"
#include "Monsters.h"

std::vector<Monsters> Monsters::getAllMonsters()
{
	std::ifstream IO;
	std::string monsterStr;
	IO.open("C:\\Users\\Onshore\\Documents\\Visual Studio 2017\\Projects\\RPGame\\Monsters.txt");
	if (IO.is_open()) {
		std::ostringstream ss;
		ss << IO.rdbuf();
		monsterStr = ss.str();
		IO.clear();
		IO.close();
	}
	std::stringstream ss(monsterStr);
	std::vector<Monsters> monsterList;
	for (int i = 0; i < 3; i++)
	{
		Monsters mon;
		std::string temp;
		getline(ss, name, '\n');
		(getline(ss, temp, '\n'));
		std::stringstream(temp) >> maxHealthPoints;
		temp.clear();
		(getline(ss, temp, '\n'));
		std::stringstream(temp) >> attack;
		temp.clear();
		(getline(ss, temp, '\n'));
		std::stringstream(temp) >> defence;
		temp.clear();
		currentHealthPoints = maxHealthPoints;
		monsterList.push_back(mon);
	}
	return monsterList;
}

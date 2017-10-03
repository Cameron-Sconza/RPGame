// RPGTestGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "Console.h"
using namespace std;

void NewGame();
void LoadGame();
Console console;
int main() {
	int mainMenu = 0;
	do {
		string mainMenuStr;
		int attemptCount = 0;
		cout << "Please Select Numbered Option Below" << endl
			<< "1. New Game." << endl
			<< "2. Continue Game." << endl
			<< "3. Quit" << endl;
		cin >> mainMenuStr;
		stringstream(mainMenuStr) >> mainMenu;
		if (attemptCount > 3) {
			cout << "Use The Number To Select an Option." << endl;
		}
		attemptCount++;
	} while (!(mainMenu >= 1 && mainMenu <= 3) || mainMenu == 0);
	if (mainMenu == 1) {
		NewGame();
	}
	else if (mainMenu == 2) {
		LoadGame();
	}
	else {
		cout << "Closing Application." << endl;
		return 0;
	}
}

void PlayGame(Character player);

void NewGame() {
	Character c;
	c.level = 1;
	c.currentExp = 0;
	c.nextLevelExp = 10;
	c.backpack.clear();
	cout << "What is this adventures name?" << endl;
	cin >> c.name;
	int choice = 0;
	do {
		string choiceStr;
		int attemptCount = 0;
		cout << "What class is this Character?" << endl
			<< "1. Warrior" << endl
			<< "2. Rouge" << endl
			<< "3. Wizard" << endl;
		cin >> choiceStr;
		stringstream(choiceStr) >> choice;
		if (attemptCount > 4) {
			cout << "Please us the number." << endl;
		}
		attemptCount++;
	} while (!(choice >= 1 && choice <= 3) || choice == 0);
	if (choice == 1) {
		c.CharacterClass = "Warrior";
		c.strength = 6;
		c.dexterity = 5;
		c.intellegence = 2;
		c.currentGold = 10;
		c.backpack.push_back("Rusty Sword");
		c.backpack.push_back("Broken Shield");
		c.backpack.push_back("Rusted Metal Armour");
	}
	else if (choice == 2) {
		c.CharacterClass = "Rogue";
		c.strength = 4;
		c.dexterity = 6;
		c.intellegence = 3;
		c.currentGold = 15;
		c.backpack.push_back("Rusty Dagger");
		c.backpack.push_back("Rusty Dagger");
		c.backpack.push_back("Ragged Leather Armour");
	}
	else if (choice == 3) {
		c.CharacterClass = "Wizard";
		c.strength = 3;
		c.dexterity = 3;
		c.intellegence = 7;
		c.currentGold = 50;
		c.backpack.push_back("Broken Staff");
		c.backpack.push_back("Tattered Book");
		c.backpack.push_back("Simple Clothes");
	}
	ofstream IO;
	IO.open("C:\\Users\\Onshore\\Documents\\Visual Studio 2017\\Projects\\RPGame\\Save.txt");
	IO << c.name << endl
		<< c.CharacterClass << endl << c.level << endl
		<< c.strength << endl << c.dexterity << endl
		<< c.intellegence << endl << c.currentGold << endl
		<< c.currentExp << endl << c.nextLevelExp << endl;
	for each (string var in c.backpack)
	{
		IO << var << endl;
	}
	IO.clear();
	IO.close();
	PlayGame(c);
}

void LoadGame() {
	ifstream IO;
	IO.open("C:\\Users\\Onshore\\Documents\\Visual Studio 2017\\Projects\\RPGame\\Save.txt");
	if (IO.is_open()) {
		ostringstream ss;
		ss << IO.rdbuf();
		string str = ss.str();
		if (str.empty()) {
			cout << "No saves Availible, Returing to Main Menu." << endl;
			main();
		}
		Character c;
		c.setcharvalues(str);
		IO.clear();
		IO.close();
		PlayGame(c);
	}
}

void SaveGame(Character player);
Character Hunt(Character player);
Character Shop(Character player);
Character Rest(Character player);

void PlayGame(Character player) {
	bool playing;
	do {
		console.ClearScreen();
		playing = true;
		Character c = player;
		int choice = 0;
		do {
			string choiceStr;
			int attemptCount = 0;
			cout << "Please Select Numbered Option Below" << endl
				<< "1. Save Game." << endl
				<< "2. Hunt." << endl
				<< "3. Shop." << endl
				<< "4. Rest." << endl
				<< "5. Quit." << endl;
			cin >> choiceStr;
			stringstream(choiceStr) >> choice;
			if (attemptCount > 3) {
				cout << "Use The Number To Select an Option." << endl;
			}
			attemptCount++;
		} while (!(choice >= 1 && choice <= 5) || choice == 0);
		switch (choice)
		{
		case(1):
			SaveGame(c);
			break;
		case(2):
			c = Hunt(c);
			break;
		case(3):
			c = Shop(c);
			break;
		case(4):
			c = Rest(c);
			break;
		case(5):
			playing = false;
			break;
		}

	} while (playing);
	main();
}

void SaveGame(Character player) {
	Character c = player;
	ofstream IO;
	IO.open("C:\\Users\\Onshore\\Documents\\Visual Studio 2017\\Projects\\RPGame\\Save.txt");
	IO << c.name << endl
		<< c.CharacterClass << endl << c.level << endl
		<< c.strength << endl << c.dexterity << endl
		<< c.intellegence << endl << c.currentGold << endl
		<< c.currentExp << endl << c.nextLevelExp << endl;
	for each (string var in c.backpack)
	{
		IO << var << endl;
	}
	IO.clear();
	IO.close();
}

Character LevelUp(Character player);

Character Hunt(Character player) {
	Character c = player; 
	bool hunting;
	do {
		hunting = true;
		cout << "What would you like to hunt?" << endl
			<< "1. Small Game." << endl
			<< "2. Monsters." << endl
			<< "3. Back." << endl;
	} while (hunting);
	return c;
}

Character LevelUp(Character player) {
	Character c = player;
	cout << "You Leveled Up!" << endl;
	c.level++;
	c.currentExp = 0;
	c.nextLevelExp = ceil((c.nextLevelExp * 5) / 2);
	c.maxHealthPoints = ceil((((c.level*c.strength + (c.dexterity*c.level) / 2)) / 2) + 20);
	c.currentHealthPoints = c.maxHealthPoints;
	return c;
}

Character Shop(Character player) {
	Character c = player;
	bool shopping;
	do {
		shopping = true;
		cout << "Where would you like to Shop?" << endl
			<< "1. MainHand" << endl
			<< "2. OffHand" << endl
			<< "2. Armour" << endl;
	} while (shopping);
	return c;
}

Character Rest(Character player) {
	Character c = player;
	cout << "You rest at a nearby Shrine, and your wounds have time to heal." << endl;
	c.currentHealthPoints = c.maxHealthPoints;
	return c;
}


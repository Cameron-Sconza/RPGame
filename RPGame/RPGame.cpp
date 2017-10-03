// RPGTestGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
using namespace std;

void NewGame();
void LoadGame();

void main() {
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
	IO.open("C:\\Users\\Onshore\\source\\repos\\RPGTestGame\\Saves.txt");
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
	IO.open("C:\\Users\\Onshore\\source\\repos\\RPGTestGame\\Saves.txt");
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

bool SaveGame(Character player);
bool Hunt(Character player);
bool Shop(Character player);
bool Rest(Character player);

void PlayGame(Character player) {
	bool playing;
	do {
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
			playing = SaveGame(c);
		case(2):
			playing = Hunt(c);
		case(3):
			playing = Shop(c);
		case(4):
			playing = Rest(c);
		case(5):
			playing = false;
		default:
			cout << "Something Fucked Up." << endl;
			break;
		}
	} while (playing);
	main();
}

bool SaveGame(Character player) {
	Character c = player;
	ofstream IO;
	IO.open("C:\\Users\\Onshore\\source\\repos\\RPGTestGame\\Saves.txt");
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
	return true;
}

void LevelUp(Character player);

bool Hunt(Character player) {

}

void LevelUp(Character player) {
	cout << "" << endl;
}

bool Shop(Character player) {

}

bool Rest(Character player) {

}


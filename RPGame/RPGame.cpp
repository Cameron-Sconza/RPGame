// RPGTestGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "Console.h"
#include "Monsters.h"
using namespace std; //So I dont have to type std:: infront of most every fking call that uses it.....

void NewGame();
void LoadGame();
Console console;

int main() {
	int mainMenu = 0;
	do {
		string mainMenuStr;
		int attemptCount = 0;
		cout << "Please Select Numbered Option Below" << '\n'
			<< "1. New Game." << '\n'
			<< "2. Continue Game." << '\n'
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
		cout << "What class is this Character?" << '\n'
			<< "1. Warrior" << '\n'
			<< "2. Rouge" << '\n'
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
			cout << "Please Select Numbered Option Below" << '\n'
				<< "1. Save Game." << '\n'
				<< "2. Hunt." << '\n'
				<< "3. Shop." << '\n'
				<< "4. Rest." << '\n'
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
bool Death(int currentHealthPoints);
Character HuntSmallGame(Character character);
Character HuntMonsters(Character character);
Character Fight(Monsters monster, Character character);

Character Hunt(Character player) {
	Character c = player;
	bool hunting;
	do {
		console.ClearScreen();
		hunting = true;
		int choice = 0;
		do {
			string choiceStr;
			int fail = 0;
			cout << "What would you like to hunt?" << '\n'
				<< "1. Small Game." << '\n'
				<< "2. Monsters." << '\n'
				<< "3. Back." << endl;
			if (fail > 3) {
				cout << "Please Use the Number." << endl;
			}
			cin >> choiceStr;
			stringstream(choiceStr) >> choice;
			fail++;
		} while (!(choice >= 1 && choice <= 3) || choice == 0);
		if (choice == 1) {
			c = HuntSmallGame(c);
		}
		else if (choice == 2) {
			c = HuntMonsters(c);
		}
		else if (choice == 3) {
			hunting = false;
		}
	} while (hunting);
	return c;
}

Character HuntSmallGame(Character character) {
	Character c = character;
	int rand = console.RandomNumber();
	if (rand <= 40) {
		cout << "You managed to find hunt down some rabbits and birds, but nothing worth while." << endl;
		c.backpack.push_back("Raw Meat");
		console.Sleep(3);
		return c;
	}
	else if (rand > 40 && rand <= 70) {
		cout << "This was a good hunt. You managed to run into a small family of Deer." << endl;
		c.backpack.push_back("Raw Meat");
		c.backpack.push_back("Raw Meat");
		c.backpack.push_back("Raw Meat");
		c.backpack.push_back("Raw Meat");
		c.backpack.push_back("Raw Hide");
		c.backpack.push_back("Raw Hide");
		console.Sleep(3);
		return c;
	}
	else if (rand > 70 && rand <= 90) {
		cout << "You fail to find animals of any sorts." << endl;
		console.Sleep(3);
		return c;
	}
	else if (rand > 90 && rand > 100) {
		cout << "Something managed to hunt you instead." << '\n'
			<< "You lose 5 health." << endl;
		c.currentHealthPoints -= 5;
		Death(c.currentHealthPoints);
		return c;
	}
	else if (rand == 100) {
		cout << "You were seen by a Dragon." << endl;
		int newRand = console.RandomNumber();
		if (newRand <= 50) {
			cout << "You manage to hide in the bushes." << endl;
			return c;
		}
		else if (newRand > 50 && newRand <= 80) {
			cout << "It noticed you and tried to kill you." << endl;
			c.currentHealthPoints -= 25;
			if (Death(c.currentHealthPoints)) {
				main();
			}
			return c;
		}
		else {
			cout << "It Manages to get a direct hit on you." << endl;
			c.currentHealthPoints -= 50;
			if (Death(c.currentHealthPoints)) {
				main();
			}
			return c;
		}
	}
}

Character HuntMonsters(Character character) {
	Character c = character;
	int choice = 0;
	do {
		string choiceStr;
		int fail = 0;
		cout << "Which Monster would you like to hunt?" << '\n'
			<< "1. Goblin." << '\n'
			<< "2. Hobgoblin." << '\n'
			<< "3. Ogre." << '\n'
			<< "4. Back." << endl;
		if (fail > 3) {
			cout << "Please Use the Number." << endl;
		}
		cin >> choiceStr;
		stringstream(choiceStr) >> choice;
		fail++;
	} while (!(choice >= 1 && choice <= 4) || choice == 0);
	if (choice == 1) {
		Monsters mon;
		mon = mon.getAllMonsters()[0];
		return Fight(mon, c);
	}
	else if (choice == 2) {
		Monsters mon;
		mon = mon.getAllMonsters()[1];
		return Fight(mon, c);
	}
	else if (choice == 3) {
		Monsters mon;
		mon = mon.getAllMonsters()[2];
		return Fight(mon, c);
	}
	else if (choice == 4) {
		return c;
	}
}

Character Fight(Monsters monster, Character character) {
	bool fighting = true;
	Monsters mon = monster;
	Character c = character;
	int choice = 0;
	do {
		cout << "You managed to find a " << mon.name << "." << '\n'
			<< "1. Attack." << '\n'
			<< "2. Defend." << '\n'
			<< "3. Flee."<< endl;
	} while (mon.currentHealthPoints > 0 && c.currentHealthPoints > 0 || (fighting));
}

bool Death(int currentHealthPoints) {
	if (currentHealthPoints < 0) {
		cout << "You Have Died" << endl;
		console.Sleep(3);
		return true;
	}
	else {
		return false;
	}
}

Character LevelUp(Character player) {
	Character c = player;
	cout << "You Leveled Up!" << endl;
	c.level++;
	c.currentExp = 0;
	c.nextLevelExp = ceil((c.nextLevelExp * 5) / 2);
	c.maxHealthPoints = ceil((((c.level*c.strength + (c.dexterity*c.level) / 3)) / 2) + 20);
	c.currentHealthPoints = c.maxHealthPoints;
	return c;
}

Character Shop(Character player) {
	Character c = player;
	bool shopping;
	do {
		shopping = true;
		cout << "What would you like to shop for?" << '\n'
			<< "1. MainHand." << '\n'
			<< "2. OffHand." << '\n'
			<< "3. Armour." << '\n'
			<< "4. Back." << endl;
	} while (false);
	return c;
}

Character Rest(Character player) {
	console.ClearScreen();
	Character c = player;
	cout << "You rest at a nearby Shrine, and your wounds have time to heal." << '\n';
	c.currentHealthPoints = c.maxHealthPoints;
	console.Sleep(4);
	return c;
}


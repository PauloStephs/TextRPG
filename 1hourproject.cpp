#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

int playerHp = 150, rawHp = 150;
int playerStr = 8, rawStr = 8;

int dmg = rand() % 20 + playerStr;

bool welcome = false, inFight = false;

string currentClass;

char choice;

// ENEMIE STATS
int hp, str, level;
string type;
string types[] = { "Zumbi", "Humano", "Esqueleto" };
// ENEMIE STATS

void GenerateEnemie()
{
	type = types[rand() % 3];
	cout << "Voce encontra um " << type;
	level = (rand() % 10) + 1;
	hp = (rand() % 100) + 50;
	str = (rand() % (level * hp / 12)) + 1;
	cout << "\nStatus do inimigo -\n";
	cout << " Hp = " << hp << endl;
	cout << " Level = " << level << endl;
	cout << " Strenght = " << str << endl;
}
void welcomeMessage()
{
	cout << "Ola novo jogador!\n";
	delay(750ms);
	cout << "Hoje iremos participar de um rpg!!!\n";
	welcome = true;
}
void fight()
{
	if (inFight == false) {
		cout << "Voce enfrenta um inimigo\n";
		delay(750ms);
		GenerateEnemie();
	}
	else {
		system("sleep");
		clearConsole();
		cout << "O inimigo continua a atacar\n";
		delay(750ms);
	}
	cout << "---------------------------------------\n";
	cout << "O que fazer? \n";
	delay(750ms);
	cout << "---------------------------------------\n";
	cout << "Ataque basico (1)\nFugir (2)\n";
	cout << "---------------------------------------\n";
	delay(750ms);
	cout << "Escolha: ";
	cin >> choice;
	switch (choice)
	{
	case '1':
		cout << "Voce ataca e causa " << dmg << " de dano\n";
		delay(200ms);
		hp -= dmg;
		if (hp > 0) {
			cout << "O inimigo esta com " << hp << " de vida\n";
			delay(750ms);
			int dmgToken = str -= (rand() % 4);
			cout << "O inimigo ataca e causa " << dmgToken << " de dano\n";
			playerHp -= dmgToken;
			delay(200ms);
			cout << "Voce esta com " << playerHp << " de vida\n";
			delay(1000ms);
			inFight = true;
			fight();
		}
		else {
			cout << "O inimigo foi derrotado\n";
			cout << "Voce subiu de level!!!\n";
			playerHp = rawHp += 50;
			rawHp = playerHp;
			playerHp = rawStr += 3;
			rawStr = playerStr;
			cout << "Hp = " << playerHp << endl;
			cout << "Strenght = " << playerStr << endl;
			system("pause");
			clearConsole();
			inFight = false;
			fight();
			delay(750ms);
		}
		break;
	case '2':
		cout << "Voce foge :(";
		break;
	}
}
int main()
{
	if (welcome == false) {
		welcomeMessage();
		// CHOOSE CLASS LOGIC
		char classChoosen;
		cout << "Qual sera a sua classe?\n";
		delay(750ms);
		cout << " Guerreiro (1)\n Mago (2)\n Bardo (3)\n";
		delay(750ms);
		cout << "Escolha: ";
		cin >> classChoosen;
		cout << "Boa escolha!\n";
		// CHOOSE CLASS LOGIC
	}
	delay(750ms);
	system("pause");
	clearConsole();
	fight();
}
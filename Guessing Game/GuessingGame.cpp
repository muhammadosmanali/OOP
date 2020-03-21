#include <iostream>
#include <conio.h>
#include <string.h>
#include "GuessingGame.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	GuessGame players, guessNo;
    players.input();
    guessNo.guessno();
    players.output();
    return 0;
}

GuessGame::GuessGame() {
	srand(time(NULL));
	this->secret = rand() % 10 + 0;
}


GuessGame::GuessGame(int g1, int g2, int g3, char p1[20], char p2[20], char p3[20]) 
{
	guess1 = g1;
	guess2 = g2;
	guess3 = g3;
	strcpy(this->player1, p1);
	strcpy(this->player2, p2);
	strcpy(this->player3, p3);
}

GuessGame::~GuessGame() {
	//no-op
}

void GuessGame::input() {
	do {
		cout << "Player # 1: Please write your NAME & GUESS" << endl;
		cout << "Name: ";
		cin >> player1;
		cout << "Guess: ";
		cin >> guess1;
		validg1();
	} while(guess1 == -1);
	do {
		cout << "Player # 2: Please write your NAME & GUESS" << endl;
		cout << "Name: ";
		cin >> player2;
		cout << "Guess: ";
		cin >> guess2;
		validg2();
	} while(guess2 == -1);
	do {
		cout << "Player # 3: Please write your NAME & GUESS" << endl;
		cout << "Name: ";
		cin >> player3;
		cout << "Guess: ";
		cin >> guess3;
		validg3();
	} while(guess3 == -1);
}

void GuessGame::output() {
	cout << "---------------------------------------------------" << endl;
	if (guess1 == this->secret) {
		cout << player1 << ": You guessed a right number ...........YOU WIN!!!!! " << endl;
	}
	else {
		cout << player1 << ": Failed to guess right number........YOU LOSE-------- " << endl;
	}
    if (guess2 == this->secret) {
		cout << player2 << ": You guessed a right number ...........YOU WIN!!!!! " << endl;
	}
	else {
		cout << player2 << ": Failed to guess right number........YOU LOSE-------- " << endl;
	}
	if (guess3 == this->secret) {
		cout << player3 << ": You guessed a right number ...........YOU WIN!!!!! " << endl;
	}
	else {
		cout << player3 << ": Failed to guess right number........YOU LOSE-------- " << endl;
	}
	cout << "---------------------------------------------------" << endl;
}

void GuessGame::validg1() {
	if(guess1 < 0 || guess1 > 9) {
		guess1 = -1;
		cout << "Please write the number in range 0 - 9" << endl;
		cout << "Again write your NAME & GUESS" << endl;
	}
}

void GuessGame::validg2() {
	if(guess2 < 0 || guess2 > 9) {
		guess2 = -1;
		cout << "Please write the number in range 0 - 9" << endl;
		cout << "Again write your NAME & GUESS" << endl;
	}
	if(this->guess1 == this->guess2) {
		cout << '\b';
		guess2 = -1;
		cout << "This number is already used" << endl;
	}
}

void GuessGame::validg3() {
	if(guess3 < 0 || guess3 > 9) {
		guess3 = -1;
		cout << "Please write the number in range 0 - 9" << endl;
		cout << "Again write your NAME & GUESS" << endl;
	}
	if(this->guess3 == this->guess2 || this->guess3 == this->guess1) {
		guess3 = -1;
		cout << "This number is already used.Please enter any other number in range 0 - 9" << endl;
	}
}

void GuessGame::guessno() {
	cout << "-----------------------------------" << endl;
	cout << "The number that you guessed is " << this->secret << endl << endl;
	cout << "-----------------------------------" << endl;
	cout << "Result: " << endl;
}




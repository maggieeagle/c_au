#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int clubs = 0; // трефы
const int diamonds = 1; // бубны
const int hearts = 2; // червы
const int spades = 3; // пики
const int emptySuit = 4;
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
const int joker = 15;

struct card {
	int number;
	int suit;
};

card fiveCards[5];

void display(card i) {
	if (i.number >= 2 && i.number <= 10) cout << i.number;
	else {
		switch (i.number) {
			case jack: cout << 'J'; break;
			case queen: cout << 'Q'; break;
			case king: cout << 'K'; break;
			case ace: cout << 'A'; break;
			case joker: cout << "Joker"; break;
		}
	}
	switch (i.suit) {
		case clubs: cout << "clubs" << ' '; break;
		case diamonds: cout << "diamons" << ' '; break;
		case hearts: cout << "hearts" << ' '; break;
		case spades: cout << "spades" << ' '; break;
		case emptySuit: cout << ' '; break;
	}
}

void chooseCards() {
	card deck[54];

	for (int i = 0; i < 52; i++) {
		deck[i].number = i % 13 + 2;
		deck[i].suit = i / 13;
	}

	deck[52].number = 15;
	deck[52].suit = 4;
	deck[53].number = 15;
	deck[53].suit = 4;

	srand(time(NULL));

	for (int i = 0; i < 54; i++) {
		int k = rand() % 54;
		card tmp = deck[i];
		deck[i] = deck[k];
		deck[k] = tmp;
	}

	for (int i = 0; i < 5; i++) {
		fiveCards[i] = deck[i];
	}
}

void sortByNumber() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (fiveCards[j].number < fiveCards[j + 1].number) {
				card tmp = fiveCards[j];
				fiveCards[j] = fiveCards[j + 1];
				fiveCards[j + 1] = tmp;
			}
		}
	}
}

bool checkSameSuit() {
	for (int i = 1; i < 5; i++)
	{
		int prev = fiveCards[i - 1].suit;
		int cur = fiveCards[i].suit;
		if (cur != prev && cur != 4 && prev != 4) return false;
	} 
	return true;
}

bool checkRoyalFlush() {
	sortByNumber(); 

	if(checkSameSuit() && fiveCards[4].number >= 10) return true;
	return false;
}

int numOfJoker() {
	int first = fiveCards[0].number;
	int second = fiveCards[1].number;
	if (first == 15 && second == 15) return 2;
	if (first == 15 && second != 15) return 1;
	return 0;
}

bool checkStraightFlush() {
	sortByNumber();
	if (checkSameSuit()) {
		if (numOfJoker() == 2 && (fiveCards[2].number - fiveCards[4].number) <= 4) return true;
		if (numOfJoker() == 1 && (fiveCards[1].number - fiveCards[4].number) <= 4) return true;
		if ((fiveCards[0].number - fiveCards[4].number) <= 4) return true;
	}
	return false;
}

bool checkSameNumber(int first, int second) {
	for (int i = first + 1; i < second + 1; i++)
	{
		int prev = fiveCards[i - 1].number;
		int cur = fiveCards[i].number;
		if (cur != prev && cur != 15 && prev != 15) return false;
	}
	return true;
}

bool checkFourOfAKind() {
	sortByNumber();

	if (checkSameNumber(0, 3) || checkSameNumber(1, 4)) return true;
	return false;
}

bool checkFullHouse() {
	sortByNumber();

	if (checkSameNumber(0, 2) && checkSameNumber(3, 4)) return true;
	if (checkSameNumber(0, 1) && checkSameNumber(2, 4)) return true;
	return false;
}

bool checkFlush() {
	if (checkSameSuit()) return true;
	return false;
}

bool checkDifferentNumber() {
	for (int i = 1; i < 5; i++)
	{
		int prev = fiveCards[i - 1].number;
		int cur = fiveCards[i].number;
		if (cur == prev && cur != 15 && prev != 15) return false;
	}
	return true;
}

bool checkStraight() {
	sortByNumber();
	if (checkDifferentNumber()) {
		if (numOfJoker() == 2 && (fiveCards[2].number - fiveCards[4].number) <= 4) return true;
		if (numOfJoker() == 1 && (fiveCards[1].number - fiveCards[4].number) <= 4) return true;
		if ((fiveCards[0].number - fiveCards[4].number) <= 4) return true;
	}
	return false;
}

int findMaxOfSame() {
	int nums[14] = { 0 };
	for (int i = 0; i < 5; i++) {
		nums[fiveCards[i].number]++;
	}
	int max = 0;
	for (int i = 0; i < 14; ++i) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

bool checkThreeOfAKind() {
	sortByNumber();

	if (numOfJoker() == 2) return true;
	if (numOfJoker() == 1 && findMaxOfSame() == 2) return true;
	if (findMaxOfSame() == 3) return true;

	return false;
}


bool checkTwoPair() {
	int nums[14] = { 0 };
	for (int i = 0; i < 5; i++) {
		if(nums[fiveCards[i].number] < 2) nums[fiveCards[i].number]++;
	}
	int count = 0;
	for (int i = 0; i < 14; i++) {
		if (nums[i] == 2) count++;
	}
	if (count == 2) return true;
	return false;
}

bool checkOnePair() {
	if (findMaxOfSame() == 2 || numOfJoker() == 1) return true;
	return false;
}

void setCards() {
	fiveCards[0] = card{ 4, 1 };
	fiveCards[1] = card{ 6, 2 };
	fiveCards[2] = card{ 5, 3 };
	fiveCards[3] = card{ 2, 1 };
	fiveCards[4] = card{ 3, 2 };
}

string findResult() {
	if (checkRoyalFlush()) return "Royal Flush";
	if (checkStraightFlush()) return "Straight Flush";
	if (checkFourOfAKind()) return "Four of a Kind";
	if (checkFullHouse()) return "Full House";
	if (checkFlush()) return "Flush";
	if (checkStraight()) return "Straight";
	if (checkThreeOfAKind()) return "Three of a Kind";
	if (checkTwoPair()) return "Two-Pair";
	if (checkOnePair()) return "One-Pair";
	return "nothing";
}

int main() {

	//chooseCards();
	setCards();

	for (int i = 0; i < 5; i++) {
		display(fiveCards[i]);
	}

	cout << endl;
	cout << findResult();

	return 0;
}

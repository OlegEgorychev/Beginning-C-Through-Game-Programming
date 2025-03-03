#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>


using namespace std;

void task1()
{
	int randomNumber;
	int guesNumber = 0;
	int tryCounter = 0;


	/* it's old wayy to get random number
	______________________________________________________
	srand(time(0)); // Seeding the random number generator
	randomNumber = rand() % 100;
	cout << "Random number: " << randomNumber; //debug
	______________________________________________________*/

	random_device rd; //source of random numbers - object for seeding 
	uniform_int_distribution <int> dist(1, 9);

	randomNumber = dist(rd);

	cout << randomNumber << "- !!! This debug shows which random number choisen.\n";


	cout << "\nGuess number: ";

	while (randomNumber != guesNumber)
	{
		tryCounter++;
		cin >> guesNumber;

		if (randomNumber > guesNumber)
		{
			if ((randomNumber - guesNumber) <= 5)
			{
				cout << "So close";
			}
			cout << "\nNeed more: ";
			continue;
		}
		else if (randomNumber < guesNumber)
		{
			if ((guesNumber - randomNumber) <= 5)
			{
				cout << "So close";
			}
			cout << "\nNeed less: ";
			continue;
		}
	}

	cout << "\nYou're win! It took you " << tryCounter << " tries.\n";
}

void task2()
{
	cout << "\nDifficulty Levels\n";

	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";

	int choise;

	cout << "Choise: ";
	cin >> choise;

	switch (choise)
	{
	case 1: cout << "You picked Easy\n";
		break;
	case 2: cout << "You picked Normal\n";
		break;
	case 3: cout << "You picked Hard\n";
		break;

	default:
		cout << "You made illegal choise\n";
		break;
	}
}

int main()
{

	int choice;

	do
	{
		cout << "\tHello! This is program for practice while I reading the book <Beginning C++ Game Programming> ";
		cout << "\nMenu: ";
		cout << "\n1. Game: guess a number";
		cout << "\n2. Game: Menu Chooser";
		cout << "\n\nEnter number to chose game: ";

		cin >> choice;

		switch (choice)
		{
		case 1: task1();
			break;
		case 2: task2();

		case 0: cout << "\nExit\n\n";
			break;

		default: cout << "\nUnfortunately it's not correct, please try again\n\n";
			break;
		}
	} while (choice != 0);
	system("pause");

}
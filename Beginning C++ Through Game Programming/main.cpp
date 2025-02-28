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

int main()
{

	int choice;

	do
	{
		cout << "\tHello! This is program for practice while I reading the book <Beginning C++ Game Programming> ";
		cout << "\nMenu: ";
		cout << "\n1. Game: guess a number\n";
		cout << "\nEnter number to chose game: ";

		cin >> choice;

		switch (choice)
		{
		case 1: task1();
			break;

		case 0: cout << "\nExit";
			break;

		default: cout << "\nUnfortunately it's not correct, please try again\n\n";
			break;
		}
	} while (choice != 0);
	system("pause");

}
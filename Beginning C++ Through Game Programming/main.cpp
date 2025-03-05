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

	enum levels
	{
		Easy = 1,
		Normal = 2,
		Hard = 3
	};

	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";

	int choise;

	cout << "Choise: ";
	cin >> choise;

	switch (choise)
	{
	case Easy: cout << "You picked Easy\n";
		break;
	case Normal: cout << "You picked Normal\n";
		break;
	case Hard: cout << "You picked Hard\n";
		break;

	default:
		cout << "You made illegal choise\n";
		break;
	}
}

void task3() 
{
	int myNumber;
	int computerNumber;

	//Player answers for computer
	enum answers
	{
		less = 1,
		more = 2,
		correct = 3
	};

	//range of guess number
	int minValue = 0;
	int maxValue = 10;

	cout << "\nPlease, think of a number from 0 to 10 and I try to guess it: ";
	cin >> myNumber;

	while (myNumber < 0 || myNumber > 10)
	{
		cout << "You entered incorrect number, please try again: ";
		cin >> myNumber;
	}	

	//Initialize random device and set the range for guessing numbers
	random_device rd;
	mt19937 gen(rd());
	
	do
	{

		if (minValue > maxValue) 
		{
			cout << "\nSomething went wrong. Did you change your number?\n\n";
			return;
		}

		//Generated random number in current form
		uniform_int_distribution<int> dist(minValue, maxValue);

		computerNumber = dist(gen);

		cout << "\nI think it's: " << computerNumber << endl;

		cout << "\n1 - My Number less";
		cout << "\n2 - My Number more";
		cout << "\n3 - Correct!\n";

		int answer;
		cout << "enter your answer: ";
		cin >> answer;
		
		while (answer < 1 || answer > 3)
		{
			cout << "Invalid input! Please enter 1, 2 or 3: ";
			cin >> answer;
		}
		


		cout << "\n";

		switch (answer)
		{
		case less:
			maxValue = computerNumber - 1;
			break;
		case more:
			minValue = computerNumber + 1;
			break;
		case correct:
			cout << "The computer wins... The machine uprising is near!!!!\n\n";
			return;
		default:
			break;
		}
	} while (minValue <= maxValue);
		
			cout << "\nSomething went wrong. Did you change your number?\n\n";
}

void task4()
{
	cout << "\nCounting forward: \n";
		for (int i = 0; i < 10; ++i)
			{
				cout << i << " ";
			}

	cout << "\n\nCounting backward: \n";
		for (int i = 9; i >= 0; --i)
			{		
				cout << i << " ";
			}

	cout << "\n\nCounting by fives: \n";
		for (int i = 0; i <= 50; i += 5)
			{
				cout << i << " ";
			}
	cout << "\n\nCounting with null statements: \n";

		int count = 0;

		for (; count < 10;)
			{
				cout << count << " ";
				++count;
			}

	cout << "\n\nCounting with nested for loops: \n";
		int ROWS = 5;
		int COLUMNS = 3;

		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLUMNS; ++j)
			{
				cout << i << "." << j << " ";
			}
			cout << endl;
		}

		cout << endl;

		
}

int main()
{

	int choice;

	do
	{
		cout << "\tHello! This is program for practice while I reading the book <Beginning C++ Game Programming> ";
		cout << "\nMenu: ";
		cout << "\n1. Game: guess a number";
		cout << "\n2. Programm: Menu Chooser";
		cout << "\n3. Game: guess MY number";
		cout << "\n4. Programm: Counter";

		cout << "\n\nEnter number to chose game: ";

		cin >> choice;

		switch (choice)
		{
		case 1: task1();
			break;
		case 2: task2();
			break;
		case 3: task3();
			break;
		case 4: task4();
			break;

		case 0: cout << "\nExit\n\n";
			break;

		default: cout << "\nUnfortunately it's not correct, please try again\n\n";
			break;
		}
	} while (choice != 0);
	system("pause");

}
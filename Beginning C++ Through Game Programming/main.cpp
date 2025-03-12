#include <iostream>
#include <string>
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

	cout << "\nYou're win! It took you " << tryCounter << " tries.\n\n";
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

void task5()
{
	string word1 = "Game";
	string word2("Over");
	string word3(3, '!');
	string phrase = word1 + " " + word2 + word3;

	cout << "The phrase is: " << phrase << "\n\n";
	cout << "The phrase has: " << phrase.size() << " characters in it.\n\n";
	cout << "The character at position 0 is: " << phrase[0] << "\n\n";
	cout << "Changing the character at position 0.\n";

	phrase[0] = 'L';

	cout << "The phrase is now: " << phrase << "\n\n";

	for (unsigned int i = 0; i < phrase.size(); ++i)
	{
		cout << "Character at position " << i << " is: " << phrase[i] << endl;
	}

	cout << "\nThe sequence 'Over' begins at location ";
	cout << phrase.find("Over") << endl;

	if (phrase.find("eggplant") == string::npos)
	{
		cout << "'eggplant' is not in the phrase.\n\n";
	}

	phrase.erase(4, 5);
	cout << "The phrase is now: " << phrase << endl;
	
	phrase.erase(4);
	cout << "The phrase is now: " << phrase << endl;

	phrase.erase();
	cout << "The phrase is now: " << phrase << endl;

	if (phrase.empty())
	{
		cout << "\nThe phrase is no more.\n\n";
	}

}

void task6()

{
	const int MAX_ITEMS = 10;

	string inventory[MAX_ITEMS];

	int numItems = 0;

	inventory[numItems++] = "sword";
	inventory[numItems++] = "armor";
	inventory[numItems++] = "shield";

	cout << "Your items: \n";

	for (int i = 0; i < numItems; ++i)
	{
		cout << inventory[i] << endl;
	}

	cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";

	cout << "\nYour items: \n";

	for (int i = 0; i < numItems; ++i)
	{
		cout << inventory[i] << endl;
	}

	cout << "\nThe item name '" << inventory[0] << "' has ";
	cout << inventory[0].size() << " Letters in it.\n";
	cout << "\nYou find a healing potion.";

	if (numItems < MAX_ITEMS)
	{
		inventory[numItems++] = "healing potion";
	}
	else
	{
		cout << "You have too many items and can't carry another";
	}

	cout << "\nYour items: \n";

	for (int i = 0; i < numItems; ++i)
	{
		cout << inventory[i] << endl;
	}

	cout << endl;
}

void task7()

{
	//Tic-Tac-Toe Board
	// Demonstrates working with multidimensional arrays

	const int ROWS = 3;
	const int COLUMNS = 3;

	char board[ROWS][COLUMNS] =
	{
		{'0', 'X', '0'},
		{' ', 'X', 'X'},
		{'X', '0', '0'}
	};

	cout << "\nHere's the tic-tac-toe board:\n";

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}

	cout << "\n'X' moves to the empty location\n\n";


	board[1][0] = 'X';

	cout << "Now the tic-tac-toe board  is: \n";

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}

	cout << "\n'X' wins!\n\n";
}

void task8()

{
	//Game Word Jumble
	//A classic puzzle game in which the user guesses words, with or without hints

	

		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			{"ocean", "A vast body of water that covers most of the Earth"},
			{"guitar", "A musical instrument with six strings."},
			{"shadow", "A dark shape cast by an object blocking the light"},
			{"puzzle", "Something you solve by thinking carefully."},
			{"sun", " A bright star that gives us light and warmth."},
			{"train", " A long vehicle that moves on tracks."},
			{"forest", " A large area filled with trees and wildlife."},
			{"balloon", " A light object filled with air or gas that floats."},
			{"elephant", " A large animal with a trunk and big ears."},
			{"whisper", " Speaking very softly so only a few can hear."},

		};

		/*random_device rd;
		uniform_int_distribution<int> dist(1, 5);

		int choice = (rd() % NUM_WORDS);*/


		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);

		string theWord = WORDS[choice][WORD]; // word what player should guess
		string theHint = WORDS[choice][HINT]; // hint for word

		string jumble = theWord;
		int length = jumble.size();

		
		//Score
		int playerPoints = 0;
		int pointsForWord = 1;
		int pointsForHint = 5;

		// debug cout << jumble.size();
		// debug cout << length;

		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		cout << "\n\t\t\tWelcome to Word Jumble!\n\n";
		cout << "Uncramble the letters to make a word.\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'quit' to quit the game.\n\n";
		cout << "You have 5 rounds where you earn 2 points for each guessed character, but if you use a hint, you lose 5 points.\n\n";
		
		string guess;
		
		for(int i = 0; i < 5; ++i)
		{ 
		
		cout << "The jumble is: " << jumble;
		cout << "\n\nYour guess: ";
		cin >> guess;



		
		// Start game loop
		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << theHint;
				playerPoints = playerPoints - pointsForHint;
				cout << "\nYou lose 5 points for hint :( " << endl;
			}
			else
			{
				cout << "Sorry, that's not it.";
			}
			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		if (guess == theWord)
		{
			cout << "\nThat's it! You guessed it! + " << pointsForWord * jumble.size() << " points.\n";
			playerPoints += jumble.size() * pointsForWord;
		}

		}

		cout << "\nYour points: " << playerPoints << ".\n\n";
		cout << "\nThanks for playing.\n\n";
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
		cout << "\n5. Programm: String Tester";
		cout << "\n6. Programm: Hero's Inventory";
		cout << "\n7. Game: Tic-Tac-Toe Board";
		cout << "\n8. Game: Word Jumble";

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
		case 5: task5();
			break;
		case 6: task6();
			break;
		case 7: task7();
			break;
		case 8: task8();
			break;

		case 0: cout << "\nExit\n\n";
			break;

		default: cout << "\nUnfortunately it's not correct, please try again\n\n";
			break;
		}
	} while (choice != 0);
	system("pause");

}
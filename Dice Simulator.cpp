#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

//This program simulates the rolling of dice
//The user can specify the number of dice 2 <= num <= 50,
//the number of sides each die has (4, 6, 8, 10 or 20) and
//the number of rolls to be simulated (10 <= num <= 1000 )
//The program prints the sum of each of 
//the rolls of the dice
//User types data, data is read using cin
//Results are printed to the screen
 
 //Author:   Janice Regan
 //Date: Jan. 22 2017  modified Jan 2020

int main(void)
{
	//  Declare variables 
	unsigned int seed = 12345;
	unsigned int intsPerBucket = 0;
	unsigned int limit = 0;
	int numSides = 0;
	int numDice = 0;
	int numRolls = 0;
	int countGuesses = 1;
	int totalRoll = 0;
	int dieShows = 0;
	int tempRand = 0;
	bool numSidesOK = false;

	const int MAX_REREADS = 2;
	const int MIN_SEED = 2;
	const int MIN_NUM_DICE = 2;
	const int MAX_NUM_DICE = 50;
	const int FOUR_SIDED = 4;
	const int SIX_SIDED = 6;
	const int EIGHT_SIDED = 8;
	const int TEN_SIDED = 10;
	const int TWENTY_SIDED = 20;
	const int MIN_NUM_ROLLS = 10;
	const int MAX_NUM_ROLLS = 10000;



	//  Get seed value and interval limits.
	countGuesses = 0;
	do
	{		
		cout << "Enter a positive integer seed for "
			<< "random number generation: ";
		if( !(cin  >> seed) )
		{
			cout << "ERROR: seed read was not an integer";
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl << endl;
			// first argument is maximum number of characters to read
			// ignore stops reading when it encounters the character in 
			// the second argument
		}		
		else if ( seed < MIN_SEED || seed > RAND_MAX)
		{	
			cout << "ERROR: seed read was not in the acceptable range";
			cout << endl << MIN_SEED << " <= seed <= " << RAND_MAX;
			cout << endl<<endl;
		}
		else
		{
			break;
		}
		countGuesses++;
	}while ( countGuesses <= MAX_REREADS);
	if ( countGuesses > MAX_REREADS )
	{
		cout << "ERROR: Too many tries entering data";
		cout << endl;
		exit (1);
	}	


	countGuesses = 0;
	do
	{
		cout << "Enter the number of dice: ";
		if( ! (cin  >> numDice) )
		{
			cout << "number of dice read was not an integer";
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl << endl;
		} 
		else if( numDice < MIN_NUM_DICE || numDice > MAX_NUM_DICE)
		{
			cout << "ERROR: number of dice read was not in the acceptable range";
			cout << endl << MIN_NUM_DICE << "  <= number of dice <= " << MAX_NUM_DICE;
			cout << endl<<endl;
		}
		else
		{
			break;
		}
		countGuesses++;
	}while (countGuesses <= MAX_REREADS);
	
	if ( countGuesses > MAX_REREADS)
	{
		cout << "ERROR: Too many tries entering number of dice";
		cout << endl;
		exit (2);
	}


	countGuesses = 0;
	do 
	{		
		cout << "Enter the number of sides on each die: ";
		if( !(cin  >> numSides) )
		{
			cout << "number of sides on each die read was not an integer";
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl << endl;
			countGuesses++;
			continue;
		}
		else
		{
			switch( numSides )
			{	
				case FOUR_SIDED:
				case SIX_SIDED:
				case EIGHT_SIDED:
				case TEN_SIDED:
				case TWENTY_SIDED:
					numSidesOK = true;
					break;
				default:
					cout << "ERROR: number of sides did not have an acceptable value";
					cout << endl << "number of sides should be 4,6,8,10 or 20" ;
					cout << endl<<endl;
					countGuesses++;
					numSidesOK = false;
					break;
			}
		}
		if (numSidesOK)
		{
			break;
		}
	}while (countGuesses <= MAX_REREADS);
	if ( countGuesses > MAX_REREADS )
	{
		cout << "Too many tries entering data";
		cout << endl;
		exit (3);
	}



	countGuesses = 0;
	do 
	{		
		cout << "Enter the number of rolls of the dice: ";
		if( !(cin  >> numRolls) )
		{
			cout << "ERROR: number of random integers to use was not an integer";
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl << endl;
		}		
		else if ( numRolls < MIN_NUM_ROLLS || numRolls > MAX_NUM_ROLLS )
		{
			cout << "ERROR: number of rolls to use was not in the acceptable range";
			cout << endl << MIN_NUM_ROLLS << " <= number of rolls <= " << MAX_NUM_ROLLS;
			cout << endl<<endl;
		}
		else
		{
			break;
		}
	}while ( countGuesses <= MAX_REREADS );
	if ( countGuesses > MAX_REREADS )
	{
		cout << "Too many tries entering data";
		exit (4);
	}

	// initialize random number generater ready to roll dice
	srand(seed);
	cout << endl;
	cout << " The numbers rolled are: " << endl;

	//Create numSides equal size intsPerBucket 
	//Note that maxInteger - minInteger +1 = numSides -1 + 1 for a dice
	intsPerBucket = RAND_MAX / numSides;
	limit = intsPerBucket * numSides;

	// roll dice
	for (int countRolls = 0; countRolls < numRolls; countRolls++)
	{
		totalRoll = 0;
		for (int countDice = 0; countDice < numDice; countDice++)
		{
			//If you land off the end of the line of intsPerBucket, try again. 
			do
			{
				tempRand = rand();
			} while (tempRand >= limit);

			dieShows = 1 + (tempRand / intsPerBucket);
			totalRoll += dieShows;
		}
		
		cout << setw(5) << totalRoll << "  ";
		if( countRolls % 10 == 9 ) 
		{
			cout << endl;
		}
	}
	return 0;
}

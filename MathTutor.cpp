* Programmer: Chad Thornton
*
* Assigned Project Number: 4A
*
*
* Revision     Date                        Release Comment
* --------  ----------  -------------------------------------------------------
*   1.0     01/25/2016  Initial Release
*   1.1     01/28/2016  Added const min/max int, and fixed values to only get 10-50
*
*
* Program Inputs
* --------------
*  Device                              Description
* --------  -------------------------------------------------------------------
* Keyboard  Receive input from the user if they would like to run through the math tutor again or if they want to quit.
*
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  -------------------------------------------------------------------
* Monitor   Displays text on the console and waits for user input
*
*
* File Methods
* ------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
* main          Program entry point method
* **** Add name and description of any other methods defined in this file ****
*
*******************************************************************************
*/
// External Definition files
// The first inclusion file is required by the Visual Studio complier and
// MUST be first in the "include" files list
#include "stdafx.h"  // Defines IDE required "pre-compiled" definition files

#include <iostream>  // Defines objects and classes used for stream I/O

// Namespaces utilized in this program
using namespace std; // Announces to the compiler that members of the namespace
                     // "std" are utilized in this program

// Method Prototypes
// -----------------
void toUpper(string&);
char toUpper(char);
void toLower(string&);
char toLower(char);


/******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* ** The program displays text on the screen and asks if the user is ready to begin.
* ** It will then wait for user input and depending on the user response will either
* ** continue with the math tutor or ask if they want to exit the program.
* ** If they continue with the program they will answer a random addition problem.
* ** After they will be asked if they want to try again, and it will give a different 
* ** addition question if they decide to run through the program again.
*
*
* Preconditions
* -------------
* None
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  ----------------------------------------------------
*                        *** No Arguments supplied ***
*
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked Methods
* ---------------
*     Name                             Description
* ------------  ---------------------------------------------------------------
*                           *** No methods invoked ***
*
*******************************************************************************
*/
int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;  // Program Execution Status: No errors

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;  // Assume no program execution errors

	// Uninitialized Variable Declarations


	string exitProgram, tryAgain, userResponse;
	const int minNum = 10, maxNum = 50;

	cout << "Hello there!\nWelcome to the Thornton Bot Math Tutor" << endl;

	do
	{
		cout << "Let's begin with an addition problem.\nAre you ready to start? (Yes/No)" << endl;
		cin >> userResponse;
		toLower(userResponse);

		if (userResponse == "yes")
		{
			int randNum;
			randNum = time(NULL);
			srand(randNum);
			do
			{
				double randNum1, randNum2, getAnswer, answer;
				randNum1 = rand() % maxNum + minNum;
				randNum2 = rand() % maxNum + minNum;
				answer = randNum1 + randNum2;

				cout << "Perfect! Please type the sum of these two numbers:\n" << endl;
				cout << right << setw(12) << randNum1 << endl;
				if (randNum2 >= 10)
				{
					cout << right << setw(10) << "+" << randNum2 << endl;
				}
				else
				{
					cout << right << setw(11) << "+ " << randNum2 << endl;
				}
				cout << right << setw(12) << "__" << endl;
				cin >> getAnswer;
				if (getAnswer == answer)
				{
					cout << "Congratulations! That is the correct answer!\nWould you like to try another probelm? (Yes/No)" << endl;
				}
				else
				{
					cout << "Sorry the correct answer is " << answer << ". Would you like to try another problem? (Yes/No)" << endl;
				}
				cin >> tryAgain;
				toLower(tryAgain);
			} while (tryAgain == "yes");

			cout << "Would you like to exit the program now?" << endl;
			cin >> exitProgram;
			toLower(exitProgram);
		}
		else if (userResponse == "no")
		{
			cout << "Not a problem. Would you like to exit the program now? (Yes/No)" << endl;
			cin >> exitProgram;
			toLower(exitProgram);
		}
		else
		{
			cout << "Oops! Something went wrong." << endl;
		}
	} while (exitProgram != "yes");

	cout << "Thank you for using the Thornton Bot Math Tutor!\nHave a nice day!\n" << endl;


	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()


void toUpper(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toUpper(str[index]);
}

char toUpper(char chr)
{
	if (chr >= 'a' && chr <= 'z')
	{
		unsigned short excludeBit = 'a' - 'A';
		chr = chr ^ excludeBit;
	}

	return chr;
}

void toLower(string& str)
{
	for (int index = 0; index < str.length(); ++index)
		str[index] = toLower(str[index]);
}

char toLower(char chr)
{
	if (chr >= 'A' && chr <= 'Z')
	{
		unsigned short includeBit = 'a' - 'A';
		chr = chr | includeBit;
	}

	return chr;
}
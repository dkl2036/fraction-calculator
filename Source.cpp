/*
Name: Danielle Lamb
Date: April 16, 2019
Purpose: Asks user how they would like to calculate the sum of two fractions (add, subtract, multiply, divide).
		 When entering numerator and denominator, if 0 is entered for denominator program will prompt user to change it. 
		 This is especially so for division of denominators.
*/
#include <iostream> 

using namespace std;

// function declarations
void addFractions(int num1, int num2, int den1, int den2,
	int& numfrac, int& denfrac);
void subtractFractions(int num1, int num2, int den1, int den2,
	int& numfrac, int& denfrac);
void multiplyFractions(int num1, int num2, int den1, int den2,
	int& numfrac, int& denfrac);
void divideFractions(int num1, int num2, int den1, int den2,
	int& numfrac, int& denfrac);

void menu();
void getFraction(int choice, int fractNo, int& numerator, int& denominator);

void showResult(char operation, int num1, int num2, int den1, int den2,
	int numfrac, int denfrac);

int main()
{
	// variable declaration
	int numerator1, numerator2, denominator1, denominator2;
	int resultnum, resultdeno;

	int choice;

	// displays menu and prompts user to choose option then performs it
	menu();
	cin >> choice;

	// while statement; while choice does not equal exit
	while (choice != 9)
	{
		// Prompts user to enter numerator and denominator for fracton 1 and 2
		cout << "For fraction 1" << endl;
		getFraction(choice, 1, numerator1, denominator1);
		cout << endl;
		cout << "For fraction 2" << endl;
		getFraction(choice, 2, numerator2, denominator2);
		cout << endl;

		// nested while statement; if denomonator 1 or 2 equals 0
		while (denominator2 == 0 || denominator1 == 0) //cannot divide by 0
		{
			// if denominator 1 ia equal to zero
			if (denominator1 == 0)
			{
				cout << "Your first fraction cannot have a 0 in the denominator, what would" <<
					" you like to change it to?" << endl;
				cin >> denominator1;
			}// end if

							// if denominator 2 is equal to zero
			if (denominator2 == 0)
			{
				cout << "Your second fraction cannot have a 0 in the denominator, what would" <<
					" you like to change it to?" << endl;
				cin >> denominator2;
			}//end if

		}//end while

		// switch case statement when user selects certain method of calulation (add, subtract, multiply, divide)
		switch (choice)
		{
		case 1:
			addFractions(numerator1, numerator2,
				denominator1, denominator2,
				resultnum, resultdeno);
			showResult('+', numerator1, numerator2,
				denominator1, denominator2,
				resultnum, resultdeno);
			break;
		case 2:
			subtractFractions(numerator1, numerator2,
				denominator1, denominator2,
				resultnum, resultdeno);
			showResult('-', numerator1, numerator2,
				denominator1, denominator2,
				resultnum, resultdeno);
			break;
		case 3:
			multiplyFractions(numerator1, numerator2,
				denominator1, denominator2,
				resultnum, resultdeno);
			showResult('*', numerator1, numerator2,
				denominator1, denominator2,
				resultnum, resultdeno);
			break;
		case 4:
			divideFractions(numerator1, numerator2,
				denominator1, denominator2,
				resultnum, resultdeno);
			showResult('/', numerator1, numerator2,
				denominator1, denominator2,
				resultnum, resultdeno);
			break;
		default:
			cout << "Invalid selection." << endl;
		}

		// display menu after break 
		menu();
		cin >> choice;
	}// end of switch case

	return 0;
}// end of main

// fraction that adds numerators/denominators entered by user
void addFractions(int num1, int num2, int den1, int den2,
	int& numfrac, int& denfrac)
{
	numfrac = num1 * den2 + num2 * den1;
	denfrac = den1 * den2;
}//end of addFractions

// fraction that subtracts numerators/denominators entered by user
void subtractFractions(int num1, int num2, int den1, int den2,
	int& numfrac, int& denfrac)
{
	numfrac = num1 * den2 - num2 * den1;
	denfrac = den1 * den2;
}// end of subtractFractions

// fraction that multiplies numerators/denominators entered by user
void multiplyFractions(int num1, int num2, int den1, int den2,
	int& numfrac, int& denfrac)
{
	numfrac = num1 * num2;
	denfrac = den1 * den2;
}// end of multiplyFractions

// fraction that divides numerators/denominators entered by user
void divideFractions(int num1, int num2, int den1, int den2,
	int& numfrac, int& denfrac)
{
	numfrac = num1 * den2;
	denfrac = num2 * den1;
}// end of divideFractions

// function for navigation menu
void menu()
{
	cout << "This program performs operations on fraction. Enter"
		<< endl;
	cout << "1 : To add fraction" << endl;
	cout << "2 : To subtract fraction" << endl;
	cout << "3 : To multiply fraction" << endl;
	cout << "4 : To divide fraction" << endl;
	cout << "9 : To exit the program" << endl;
}// end of menu()

// fraction to get user's numerators and denominators
// if dividing, if statement checks if fractions are nonzero
void getFraction(int choice, int fractNo, int& numerator, int& denominator)
{
	cout << "Enter the numerator: ";
	cin >> numerator;
	cout << endl;

	if (choice == 4 && fractNo == 2 && numerator == 0 && denominator == 0)
	{
		cout << "To divide, the second fraction must be nonzero."
			<< endl;
		while (numerator == 0)
		{
			cout << "Enter a nonzero number for the numerator: ";
			cin >> numerator;
			cout << endl;
		}// end of while

		while (denominator == 0)
		{
			cout << "Enter a nonzero number for the denominator: ";
			cin >> denominator;
			cout << endl;
		}// end of while

	}// end of if

	cout << "Enter the denominator: ";
	cin >> denominator;
	cout << endl;
}//end of getFraction

// function to display result to user including calculaton performed
void showResult(char operation, int num1, int num2, int den1, int den2,
	int numfrac, int denfrac)
{
	cout << num1 << "/" << den1;

	switch (operation)
	{
	case '+':
		cout << " + ";
		break;
	case '-':
		cout << " - ";
		break;
	case '*':
		cout << " * ";
		break;
	case '/':
		cout << " / ";
		break;
	default:
		cout << "Invalid operation." << endl;
	}

	cout << num2 << "/" << den2 << " = " << numfrac << "/"
		<< denfrac << endl;
}// end of showResults

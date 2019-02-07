#include "Points.h"
#include <iostream>
#include <cstdlib>
#include "windows.h"
#include <conio.h>

using namespace std;

void placeCursorAt(Point coordinate) {
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord);
}

//default constructor
Points::Points() {
	mPointArray[MAXPOINTS];
	mNumberOfPoints = 0;
}

bool Points::add(const Point newPoint)
{
	//add newPoint to array of points
	if (mNumberOfPoints < MAXPOINTS) {
		mPointArray[mNumberOfPoints] = newPoint;
		mNumberOfPoints++;
		return true;
	}
	else return false;
}

void Points::sumExercise(Point givenPoint) {

	//generate 5 random points
	for (int i = 0; i < 5; i++) {
		const int newX = (rand() % 10) + 1;
		const int newY = (rand() % 10) + 1;
		Point newPoint(newX, newY);
		mPointArray[i] = newPoint;
	}

	int pointArrayIndex = 0;
	char play = 'y';
	while ((play == 'y' || play == 'Y') && pointArrayIndex < 5) {
		//place output under "plot"
		Point bottomOfConsole(20, 20);
		placeCursorAt(bottomOfConsole);

		//output points
		cout << "\nPoint A: ";
		//can't call display on const givenPoint
		givenPoint.display();

		cout << "\nPoint B: ";
		mPointArray[pointArrayIndex].display();

		//prompt user for sum
		cout << "\nGuess the sum of the two points: ";
		int guessX, guessY;
		cin >> guessX >> guessY;
		Point guessedPoint(guessX, guessY);

		//point for true sum
		Point sum = mPointArray[pointArrayIndex] + givenPoint;

		//output points at proper coordinates
		placeCursorAt(givenPoint);
		cout << "A";

		placeCursorAt(mPointArray[pointArrayIndex]);
		cout << "B";

		placeCursorAt(sum);
		cout << "C";

		placeCursorAt(guessedPoint);
		cout << "?";

		//place user prompts at bottom
		bottomOfConsole.setY(23);
		placeCursorAt(bottomOfConsole);

		//prompt user to play again
		cout << "\nWould you like to play again? Enter 'y' for yes: ";
		cin >> play;
		pointArrayIndex++;

		system("cls");
		if (pointArrayIndex == 5) cout << "Game over! You played five times.";
	}

}

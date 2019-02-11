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

void correctedPlaceCursorAt(Point coordinate) {
	COORD coord;
	coord.X = coordinate.getX() * 2;
	coord.Y = 15 - coordinate.getY();
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
		Point bottomOfConsole(20, 18);
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
		correctedPlaceCursorAt(givenPoint);
		cout << "A";

		correctedPlaceCursorAt(mPointArray[pointArrayIndex]);
		cout << "B";

		correctedPlaceCursorAt(sum);
		cout << "C";

		correctedPlaceCursorAt(guessedPoint);
		cout << "?";

		//draw x-axis increments
		Point xAxis(0, 16);
		for (int i = 1; i < 16; i++){
			placeCursorAt(xAxis);
			cout << "|";
			xAxis.setX(i * 2);
		}

		//number x-axis
		xAxis.setY(17), xAxis.setX(0);
		for (int i = 2; i < 16; i += 2) {
			placeCursorAt(xAxis);
			cout << (i - 2);
			xAxis.setX(i * 2);
		}

		//draw y-axis increments
		Point yAxis(0, 1);
		for (int i = 1; i < 16; i++) {
			placeCursorAt(yAxis);
			cout << "-";
			yAxis.setY(i);
		}

		//place user prompts at bottom
		bottomOfConsole.setY(17);
		placeCursorAt(bottomOfConsole);

		//prompt user to play again
		cout << "\nWould you like to play again? Enter 'y' for yes: ";
		cin >> play;
		pointArrayIndex++;

		system("cls");
		if (pointArrayIndex == 5) cout << "Game over! You played five times.";
	}

}

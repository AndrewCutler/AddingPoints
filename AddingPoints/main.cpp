#include <iostream>
#include "Point.h"
#include "Points.h"
#include <cstdlib>

using namespace std;

int main() {
	Points myPoints;

	//prompt user for point to start game with
	cout << "Enter a point: ";
	int newX, newY;
	cin >> newX >> newY;
	Point newPoint(newX, newY);

	myPoints.sumExercise(newPoint);

	//system("pause");
	return 0;
}
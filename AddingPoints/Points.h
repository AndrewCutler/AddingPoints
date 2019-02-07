#pragma once
#include "Point.h"

class Points {
public:
	Points();
	bool add(const Point);
	void sumExercise(Point givenPoint);

private:
	static const int MAXPOINTS = 10;
	Point mPointArray[MAXPOINTS];
	int mNumberOfPoints;
};


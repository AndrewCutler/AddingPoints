#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point() {
	mX = 0;
	mY = 0;
}

Point::Point(int inX, int inY) {
	mX = inX;
	mY = inY;
}

void Point::display() {
	cout << "(" << mX << "," << mY << ")";
}

double Point::distance(const Point otherPoint) const {
	return sqrt(pow((mX - otherPoint.mX),2) + pow((mY - otherPoint.mY),2));
}

void Point::setX(const int inX)
{
	mX = inX;
}

void Point::setY(const int inY)
{
	mY = inY;
}

int Point::getX() const
{
	return mX;
}

int Point::getY() const
{
	return mY;
}

Point Point::operator+(const Point otherPoint)
{
	return Point((mX + otherPoint.mX), (mY + otherPoint.mY));
}

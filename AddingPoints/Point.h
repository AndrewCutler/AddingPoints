#pragma once
class Point {
public:
	//constructors
	Point();
	Point(int, int);
	//formatted output
	void display();
	//calculate distance
	double distance(const Point) const;
	//setters
	void setX(const int);
	void setY(const int);
	//getters
	int getX() const;
	int getY() const;
	//operator overload
	Point operator+ (const Point);

private:
	int mX;
	int mY;
};


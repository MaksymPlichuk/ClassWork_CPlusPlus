#include "Point.h"
#include <iostream>

void Point::print() const
{
	cout << "X = " << x << "," << " Y = " << y << endl;
}

Point Point::operator--()
{
	this->x--;
	this->y--;
	return*this;
}

Point Point::operator++()
{
	this->x++;
	this->y++;
	return*this;
}

Point Point::operator>()
{
	if (this.x>this.y)
	{

	}
}

Point Point::operator<()
{
	return Point();
}

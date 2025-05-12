#include "Point.h"

Point::Point() : x(0.0f), y(0.0f), z(0.0f) {}

Point::Point(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0;
}

double Point::getX() { return x; }

double Point::getY() { return y; }

double Point::getZ() { return z; }

void Point::setX(double x) { this->x = x; }

void Point::setY(double y) { this->y = y; }

void Point::setZ(double z) { this->z = z; }

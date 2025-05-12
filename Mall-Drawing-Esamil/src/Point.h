// Point.h
#ifndef POINT_H
#define POINT_H

#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>
#include <cmath>

class Point {
public:
	float x, y, z;
    Point();
	Point(float x, float y);
    Point(GLfloat x, GLfloat y, GLfloat z);
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);

	static float distance(Point a, Point b)
	{
		return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
	};
};

#endif
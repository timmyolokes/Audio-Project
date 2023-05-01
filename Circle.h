#include <iostream>
#include <string>

#include <stdio.h>
#include <math.h>

using namespace std;

class Circle
{
public:
	float x;
	float y;
	float r;

	Circle();
	Circle(float x_in, float y_in, float r_in);

	void print(string label);
	void set(float x_in, float y_in, float r_in);
	float getArea();
	bool intersects(Circle other);
};
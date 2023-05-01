#include "Circle.h"

#define PI 3.14159

Circle::Circle()
{
	x = 0;
	y = 0;
	r = 1;
}

Circle::Circle(float x_in, float y_in, float r_in)
{
	x = x_in;
	y = y_in;
	r = r_in;
}

void Circle::print(string label)
{
	printf("\nCircle Object: ", label);
	printf("\n    x: %f", x);
	printf("\n    y: %f", y);
	printf("\n    r: %f", r);
}

void Circle::set(float x_in, float y_in, float r_in)
{
	x = x_in;
	y = y_in;
	r = r_in;
}

float Circle::getArea()
{
	float area;

	area = PI * r * r;

	return(area);
}

bool Circle::intersects(Circle other)
{
	float sum, dist;
	bool result;

	sum = (x - other.x)*(x - other.x) + (y - other.y)*(y - other.y);
	dist = sqrt(sum);

	if (dist < r + other.r) result = true;
	else result = false;
	return(result);
}
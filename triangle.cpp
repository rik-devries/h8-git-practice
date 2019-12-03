#include "triangle.h"
#include <algorithm>
#include <iostream>

#include <GL/glut.h>

using namespace std;

Triangle::Triangle() {
	_p1 = {-0.5, -0.5}; //Bottom left corner
	_p2 = {0.5, -0.5}; //Bottom right corner
	_p3 = {0, 0.5}; //Center top
}

Triangle::Triangle(point p1, point p2, point p3) {
	_p1 = p1;
	_p2 = p2;
	_p3 = p3;
}

Triangle::~Triangle() {}

void Triangle::move(float dx, float dy) {
	_p1.x += dx;
	_p2.x += dx;
	_p3.x += dx;
	
	_p1.y += dy;
	_p2.y += dy;
	_p3.y += dy;
}

void Triangle::zoom(float scale) {
	_p1.x *= scale;
	_p2.x *= scale;
	_p3.x *= scale;
	
	_p1.y *= scale;
	_p2.y *= scale;
	_p3.y *= scale;
}

float Triangle::area() {
	//Find most left corner of triangle along with most right
	//Do the same for top and bottom
	float xArr[3] = {_p1.x, _p2.x, _p3.x};
	float yArr[3] = {_p1.y, _p2.y, _p3.y};
	
	//Min and max element need to go all the way to the end, to the position of the new array
	float smallestX = *min_element(xArr, xArr+3);
	float largestX = *max_element(xArr, xArr+3);
	float smallestY = *min_element(yArr, yArr+3);
	float largestY = *max_element(yArr, yArr+3);
	
	//Calculate a square around the triangle and divide by 2 for triangle area
	return ((largestX - smallestX) * (largestY - smallestY))/2;
}

void Triangle::setColor(colorRGB color){
	_color = color;
}

void Triangle::draw(){
	glColor3f(_color.r, _color.g, _color.b); 
	
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(_p1.x, _p1.y); 
	glVertex2f(_p2.x, _p2.y);
	glVertex2f(_p3.x, _p3.y); 
	
	glEnd();
}

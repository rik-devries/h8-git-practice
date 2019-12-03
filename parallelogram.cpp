#include "parallelogram.h"
#include <algorithm>
#include <iostream>
#include <cmath>

#include <GL/glut.h>

using namespace std;

Parallelogram::Parallelogram() {
	_p1 = {-0.5, -0.5}; //Bottom left corner
	_p2 = {0.5, -0.5}; //Bottom right corner
	_p3 = {0, 0.5}; //Top left corner
	_p4 = {1, 0.5}; //Top right corner
}

Parallelogram::Parallelogram(point p1, point p2, point p3, point p4) {
	_p1 = p1;
	_p2 = p2;
	_p3 = p3;
	//p4 not really necessary, can be calculated based on other points. Including it for the sake of logic
	_p4 = p4;
}

Parallelogram::Parallelogram(point p1, float width, float height, float angle) {
	const float PI = 3.14159265;
	
	_p1 = p1;
	_p2 = {p1.x + width, p1.y};
	
	if(angle >= 360){
		angle = fmod(angle, 360);
	}		
	//AC = tilted side
	//BC = length
	//Alpha is the angle
	//AC = BC/Sin(alpha)
	
	float tiltedSideLength = height/sin((angle/180)*PI);
	point p3 = {p1.x + sqrt(pow(tiltedSideLength,(float)2) - pow(height, (float)2)), p1.y + height};
	_p3 = p3;
	
	_p4 = {p3.x + width, p3.y};
}

Parallelogram::~Parallelogram() {}

void Parallelogram::move(float dx, float dy) {
	_p1.x += dx;
	_p2.x += dx;
	_p3.x += dx;
	_p4.x += dx;
	
	_p1.y += dy;
	_p2.y += dy;
	_p3.y += dy;
	_p4.y += dy;
}

void Parallelogram::zoom(float scale) {
	_p1.x *= scale;
	_p2.x *= scale;
	_p3.x *= scale;
	_p4.x *= scale;
	
	_p1.y *= scale;
	_p2.y *= scale;
	_p3.y *= scale;
	_p4.y *= scale;
}

float Parallelogram::area() {
	//Doesn't work for tilted parallelograms
	float width = _p2.x - _p1.x;
	float height = _p3.y - _p1.y;
	
	return width*height;
}

void Parallelogram::setColor(colorRGB color){
	_color = color;
}

void Parallelogram::draw(){
	glColor3f(_color.r, _color.g, _color.b); 
	
	glBegin(GL_QUAD_STRIP);
	glVertex2f(_p1.x, _p1.y); 
	glVertex2f(_p2.x, _p2.y);
	glVertex2f(_p3.x, _p3.y); 
	glVertex2f(_p4.x, _p4.y); 
	
	glEnd();
}

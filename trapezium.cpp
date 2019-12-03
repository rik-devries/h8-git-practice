#include "trapezium.h"
#include <algorithm>
#include <iostream>
#include <cmath>

#include <GL/glut.h>

using namespace std;

Trapezium::Trapezium() {
	_p1 = {-0.5, -0.5}; //Bottom left corner
	_p2 = {0.5, -0.5}; //Bottom right corner
	_p3 = {-0.25, 0.5}; //Top left corner
	_p4 = {0.25, 0.5}; //Top right corner
}

Trapezium::Trapezium(point p1, point p2, point p3, point p4) {
	_p1 = p1;
	_p2 = p2;
	_p3 = p3;
	_p4 = p4;
}

Trapezium::~Trapezium() {}

void Trapezium::move(float dx, float dy) {
	_p1.x += dx;
	_p2.x += dx;
	_p3.x += dx;
	_p4.x += dx;
	
	_p1.y += dy;
	_p2.y += dy;
	_p3.y += dy;
	_p4.y += dy;
}

void Trapezium::zoom(float scale) {
	_p1.x *= scale;
	_p2.x *= scale;
	_p3.x *= scale;
	_p4.x *= scale;
	
	_p1.y *= scale;
	_p2.y *= scale;
	_p3.y *= scale;
	_p4.y *= scale;
}

float Trapezium::area() {
	//Doesn't work for tilted parallelograms
	float botWidth = _p2.x - _p1.x;
	float topWidth = _p4.x - _p3.x;
	float avgWidth = (topWidth + botWidth) / 2;
	float height = _p3.y - _p1.y;
	
	return avgWidth*height;
}

void Trapezium::setColor(colorRGB color){
	_color = color;
}

void Trapezium::draw(){
	glColor3f(_color.r, _color.g, _color.b); 
	
	glBegin(GL_QUAD_STRIP);
	glVertex2f(_p1.x, _p1.y); 
	glVertex2f(_p2.x, _p2.y);
	glVertex2f(_p3.x, _p3.y); 
	glVertex2f(_p4.x, _p4.y); 
	
	glEnd();
}

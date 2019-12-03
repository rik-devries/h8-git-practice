#include "circle.h"
#include "point.h"

#include <GL/glut.h>
#include <cmath>

static const float PI=3.1415926535;

Circle::Circle() {
	_center.x=_center.y=0.0;
	_radius = 1.0;
}

Circle::Circle(point center, float radius) {
	_center = center;
	_radius = radius;
}

Circle::~Circle() {}

void Circle::move(float dx, float dy) {
	_center.x += dx;
	_center.y += dy;
}

void Circle::zoom(float scale) {
	_radius *= scale;
	_center.x *= scale;
	_center.y *= scale;
}

float Circle::area() {
	return PI * _radius * _radius;
}

void Circle::setColor(colorRGB color){
	_color = color;
}

void Circle::draw(){
	point points[360];
	for (int i = 0; i < 360; i++){
		float radian = (PI * i) / 180;
		float x = _center.x + _radius * cos(radian);
		float y = _center.y + _radius * sin(radian);
		points[i] = {x,y};
	}

	glColor3f(_color.r, _color.g, _color.b);
	glBegin(GL_POLYGON);
	for(int i = 0; i < 360; i++){
		glVertex2f(points[i].x, points[i].y);
	}
	glEnd();
}

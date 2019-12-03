#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include "shape.h"

class Circle : public Shape {
	public:
		//Constructors and destructors
		Circle();
		Circle(point center, float radius);
		~Circle();

		//Class functions
		void move(float dx, float dy);
		void zoom(float scale);
		float area();
		void setColor(colorRGB color);
		void draw();
	private:
		point _center;
		float _radius;
		colorRGB _color = {0.5, 0.5, 0.5};
};

#endif

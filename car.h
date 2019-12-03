#ifndef CAR_H
#define CAR_H

#include "point.h"
#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "parallelogram.h"
#include "trapezium.h"

class Car {
	public:
		//Constructors/destructors
		Car(float width = 6, float height = 4, point anchor = {0, 0});
		~Car();

		//Functions
		void move(float dx, float dy);
		void zoom(float scale);
		float area();
		void setColor(colorRGB bodyColor, colorRGB roofColor, colorRGB tireColor);
		void draw();
	private:
		point _anchor;
		float _width, _height;
		colorRGB _bodyColor = {0, 0, 0}, _roofColor = {0, 0, 0}, _tireColor = {0, 0, 0};
		Shape** _shapes;
};

#endif

#include <iostream>

#include "assignment.h"
#include "circle.h"
#include "triangle.h"
#include "parallelogram.h"
#include "trapezium.h"

#include <GL/glut.h>
#include <ctime>

using namespace std;

void glDrawEx2();
void TimeStepEx2(int n);

void ex2(){
	int argc = 0;
	char** argv = NULL;
	srand(time(NULL));

	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Basic shapes");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(glDrawEx2);
	glutTimerFunc(1000, TimeStepEx2, 1000);
	glutMainLoop();
}

void glDrawEx2() {
	Circle circ1, circ2({0,0}, (float)3.1);
	Triangle tri1, tri2({-4,1}, {-1,1}, {-2,4});
	Parallelogram par1, par2({1,0}, {4,0}, {2,3}, {5,3}), par3({0,0}, 3.0, 2.0, 60.0);
	Trapezium trap1, trap2({1,1}, {8,1}, {3,3}, {6,3});

	//int amountOfShapes = 9;
	//Shape* allShapes[amountOfShapes] = {&circ1, &circ2, &tri1, &tri2, &par1, &par2, &par3, &trap1, &trap2};

	int amountOfShapes = 4;
	Shape* allShapes[4] = {&circ1, &tri2, &par2, &trap1};
	/*
	for(int i = 0; i < amountOfShapes; i++){
		cout << "area: " << allShapes[i]->area() << endl;
	}
	*/
	for(int i = 0; i < amountOfShapes; i++){
		allShapes[i]->zoom(0.2);
		//cout << "area: " << allShapes[i]->area() << endl;
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(int i = 0; i < amountOfShapes; i++){
		colorRGB color = {rand()/((float)RAND_MAX), rand()/((float)RAND_MAX), rand()/((float)RAND_MAX)};
		allShapes[i]->setColor(color);
		allShapes[i]->draw();
	}
	glutSwapBuffers();
	glFlush();
}

void TimeStepEx2(int n) {
	glutTimerFunc(n, TimeStepEx2, n);
	glutPostRedisplay();
}

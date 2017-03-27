
#define PROGRAM_TITLE "mulRotate"

#include <stdlib.h>
#include <stdio.h>    
#include <iostream>

#include <gl\freeglut.h>

int Window_ID;
int Window_Width = 600;
int Window_Height = 400;

float rot = 0.0f;
float cRot = 0.0f;
float pRot = 0.0f;

bool left = false;
bool right = false;

bool q = false;
bool a = false;
bool z = false;

void cube() {
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glColor3f(1.0f, 0.5f, 0.4f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
}

void pyramid()
{
	glBegin(GL_TRIANGLES);
	 glColor3f(1.0f, 1.0f, 0.0f);
	 glVertex3f(0.0f, 1.f, 0.0f);
	 glVertex3f(-1.0f, -1.0f, 1.0f);
	 glVertex3f(1.0f, -1.0f, 1.0f);
	 glColor3f(0.0f, 1.0f, 1.0f);
	 glVertex3f(0.0f, 1.0f, 0.0f);
	 glVertex3f(-1.0f, -1.0f, 1.0f);
	 glVertex3f(0.0f, -1.0f, -1.0f);
	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(0.0f, 1.0f, 0.0f);
	 glVertex3f(0.0f, -1.0f, -1.0f);
	 glVertex3f(1.0f, -1.0f, 1.0f);
	 glColor3f(1.0f, 0.5f, 0.0f);
	 glVertex3f(-1.0f, -1.0f, 1.0f);
	 glVertex3f(0.0f, -1.0f, -1.0f);
	 glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();
}

void CallBackRenderScene(void)
{
	if (!q) {
		rot += 0.06f;
		cRot = rot;
		pRot = rot;

		if (z)
			pRot = 0;

		if (a)
			cRot = 0;
	}


	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3, 3, -2, 2, -10.0f, 100.0f);

	if (left) 
		gluLookAt(-5.0, 5.0, 5.0, 0.0, 0.0, 0, 0.0, 1.0, 0.0);
	else if (right) 
		gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0, 0.0, 1.0, 0.0);
	else 
		gluLookAt(0, 0, 0, -1.0, 0.0, 0, 0.0, 1.0, 0.0);
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
		glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
		glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
	}
	glEnd();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 2.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(pRot, 0.0f, 0.0f, 1.0f);
	glutSolidTetrahedron();
	
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 1.0f);
	glRotatef(rot, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 1.0f, -3.0f);
	glutSolidSphere(0.5, 20, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(cRot, 0.0f, 0.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

	glutSwapBuffers();
}

void onKeyboardButton(unsigned char key, int m, int k) {
	if (key == 'z') {
		z = true;
		a = false;
	}
	if (key == 'a') {
		a = true;
		z = false;
	}
	if (key == 'q')
		q = true;
	if (key == 32) {
		q = false;
		a = false;
		z = false;
		q = false;
	}
}

void onMouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		right = true;
	else
		right = false;
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		left = true;
	else
		left = false;
}

void CallBackResizeScene(int Width, int Height)
{
	if (Height == 0)
		Height = 1;

	glViewport(0, 0, Width, Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(90.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);

	Window_Width = Width;
	Window_Height = Height;
}

void init(int Width, int Height)
{
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	glShadeModel(GL_SMOOTH);
	CallBackResizeScene(Width, Height);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(Window_Width, Window_Height);
	Window_ID = glutCreateWindow(PROGRAM_TITLE);
	glutDisplayFunc(&CallBackRenderScene);
	glutIdleFunc(&CallBackRenderScene);
	glutReshapeFunc(&CallBackResizeScene);

	GLfloat black[] = { 0.0, 0.0, 0.0, 0.6 };
	GLfloat yellow[] = { 1.0, 1.0, 0.0, 0.6 };
	GLfloat ambDef[] = { 1.0, 0.6, 1.0, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 0.35f };
	GLfloat direction[] = { 0.0, 5.0, 0.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ambDef);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);

	glLightfv(GL_LIGHT0, GL_AMBIENT, black);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, direction);

	glEnable(GL_LIGHTING);               
	glEnable(GL_LIGHT0);                  

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutMouseFunc(&onMouseButton);
	glutKeyboardFunc(&onKeyboardButton);
	init(Window_Width, Window_Height);

	glutMainLoop();

	return 1;
}

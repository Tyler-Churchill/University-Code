
#define PROGRAM_TITLE "tyler churchill"
#define DISPLAY_INFO "First OpenGL Program"

#include <gl\freeglut.h>

#include <stdlib.h>  
#include <stdio.h>    
#include <string.h>  
#include <iostream>
#include <sstream>

int Window_ID;
int Window_Width = 600;
int Window_Height = 600;
bool n;
float rot = 0.0f;
float x = 0, y = 0, z = 0;
float ex, ey, ez;

std::string info = "test";
std::string obj = "";
std::string eye = "";

static void PrintString(void *font, char *str)
{
	int i, len = strlen(str);

	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, *str++);
}

void drawObjInfo() {

	glViewport(0, 0, 150, 500);

	char inf[80];
	strcpy_s(inf, obj.c_str());
	int len = strlen(obj.c_str());

	char ey[80];
	strcpy_s(ey, eye.c_str());
	int el = strlen(eye.c_str());

	glColor3f(1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 300, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(0, 50);
	for (int i = 0; i < len; ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, inf[i]);
	}

	glRasterPos2i(0, 55);
	for (int i = 0; i < el; ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ey[i]);
	}
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}

void drawHelpInfo() {

	glViewport(150, 300, 450, 300);

	char inf[80];
	strcpy_s(inf, info.c_str());
	int len = strlen(info.c_str());

	glColor3f(1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 300, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(0, 50);
	for (int i = 0; i < len; ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, inf[i]);
	}
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}

void drawObject() {

	glViewport(150, 0, 450, 300);
	rot += 0.06f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3, 3, -2, 2, -10.0f, 100.0f);
	if (n) {
		gluLookAt(5.0, 5.0, 5.0 + z, 0.0, 0.0, z, 0.0, 1.0, 0.0);
		ex = 5;
		ey = 5;
		ez = 5 + z;
	}
	else {
		gluLookAt(0.0, 0.0, 5.0 + z, 0.0, 0.0, z, 0.0, 1.0, 0.0);
		ex = 0;
		ey = 0;
		ez = 5 + z;
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, z);
	glRotatef(rot, 0.0f, 1.0f, 0.0f);

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

void CallBackRenderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	drawObject();
	drawHelpInfo();
	drawObjInfo();

	glutSwapBuffers();
}

void onMouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		n = true;
	else
		n = false;
}

void init(int Width, int Height)
{
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	glShadeModel(GL_SMOOTH);
}

void onKeyboardButton(unsigned char key, int m, int k) {
	if (key == 'z')
	{
		z += 0.2f;
	}
	
	std::ostringstream o;
	o << "Position of Cube: " << x << ", " << y << ", " << z;
	obj = o.str();
	std::ostringstream e;
	e << "Eye position: " << ex << ", " << ey << ", " << ez;
	eye = e.str();
	std::ostringstream b;
	b << "Key hit: " << key;
	info = b.str();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(Window_Width, Window_Height);
	Window_ID = glutCreateWindow(PROGRAM_TITLE);
	glutDisplayFunc(&CallBackRenderScene);
	glutIdleFunc(&CallBackRenderScene);
	glEnable(GL_DEPTH_TEST);
	glutMouseFunc(&onMouseButton);
	glutKeyboardFunc(&onKeyboardButton);
	init(Window_Width, Window_Height);

	glutMainLoop();

	return 1;
}
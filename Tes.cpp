#include<stdio.h>
#include<GL/glut.h>


float w = 480, h = 480;
float sudut = 0, sx = 0, sy = 0, sz = 0;

void cube() {
glColor3d(0, 0, 1);
glutWireCube(10);
}
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0, 0, -40);
glRotatef(sudut, sx, sy, sz);
cube();
glutSwapBuffers();
}
 
void resize(int w1, int h1) {
glViewport(0, 0, w1, h1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45., (GLdouble)w1 / (GLdouble)h1, 1., 300.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void init() {
glClearColor(0.0, 0.0, 0.0, 1.0);
glEnable(GL_DEPTH_TEST);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45., (GLdouble)w / (GLdouble)h, 1., 300.);
glMatrixMode;
}
void mykeyboard(unsigned char key, int x, int y) {
if (key == 'x') {
sx = 1;
sy = 0;
sz = 0;
sudut += 10;
}
else if (key == 'y') {
sx = 0;
sy = 1;
sz = 0;
sudut += 10;
}
else if (key == 'z') {
sx = 0;
sy = 0;
sz = 1;
}
}

void update(int value) {
glutPostRedisplay();
glutTimerFunc(50, update, 0);
}
void main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
glutInitWindowPosition(200, 200);
glutInitWindowSize(480, 480);
glutCreateWindow("Draw By Maulana Akmal");;
glutDisplayFunc(display);
glutReshapeFunc(resize);
glutTimerFunc(50, update, 0);
init();
glutKeyboardFunc(mykeyboard);
glutMainLoop();
}

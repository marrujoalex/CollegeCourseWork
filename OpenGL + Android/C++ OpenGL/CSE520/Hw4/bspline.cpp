//bspline.cpp

#include <GL/glut.h>
#include <iostream>

const int dx = 0.3;
const int maxL = 10;

float p[maxL][3];

using namespace std;

void build(int m, int n, float knt[]) {
        if (n < m)
                return; //this means there isn't enough control points, so it returns
        for (int i = 0; i < n + m; ++i) {
                if (i < m)
                        knt[i] = 0.0;
                else if (i < n)
                        knt[i] = i - m + 1; 
                else
                        knt[i] = n - m + 1;
        }
}

float bSpline(int k, int s, float u, float knt[]) {
        float a;
        float b;
        float sum = 0.0;
        if (s == 1)
                return (knt[k] <= u && u <= knt[k + 1]);
        a = knt[k + s - 1] - knt[k];
        if (a != 0)
                sum = (u - knt[k]) * bSpline(k, s - 1, u, knt) / a;
        b = knt[k + s] - knt[k + 1];
        if (b != 0)
                sum += (knt[k + s] - u) * bSpline(k + 1, s - 1, u, knt) / b;
        return sum;
}

void display(void) {
        float knt[11];
        build(4, 8, knt);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glBegin(GL_LINE_STRIP);
        for (int i = 1; i < 4; i++) {
                for (float x = 0.0; x < 5.0; x += 0.01) {
                        float y = bSpline(i, 4, x, knt);
                        glVertex2f(x, y);
                }
        } 
        glEnd();
        glFlush(); //renderer
}

void setWindow(double left,double right, double bottom, double top) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(left, right, bottom, top);
} 

void init(void) {
        glClearColor(0.9, 0.9, 0.9, 1.0);
        glColor3f(0.0f, 0.0f, 0.0f); 
        glPointSize(4.0); 
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); 
        gluOrtho2D(-1.0, 5.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
        glutInitWindowSize(800, 800); //sets the window size on screen
        glutInitWindowPosition(100, 150); //sets the window position on screen
        glutCreateWindow(argv[0]); 
        init();
        glutDisplayFunc(display); //references the display function
        glutKeyboardFunc(keyboard); //used to exit the program with 'ESC'
        glutMainLoop(); 
        return 0;
}
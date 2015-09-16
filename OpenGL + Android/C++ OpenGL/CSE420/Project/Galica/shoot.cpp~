#include<iostream>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;

int state(0); //shield state
GLint x; GLint y; GLint d;

class Polygon {
public:
    Polygon();
    int getShip_x();
    int getShip_y();

protected:
    int Polygon_x;
    int Polygon_y;
};

class Ship : public Polygon {
public:
    //Ship();
    //Ship(Polygon ship, Polygon shield, Polygon bullet, Polygon missile);
    Polygon getBullet();
    Polygon getMissile();
    Polygon getShield();
    Polygon getShip();
    void sfire();
    void smissile();
    void cshield();
    void suicide();

protected:
    Polygon ship;
    Polygon shield;
    Polygon bullet;
    Polygon missile;
};

Polygon::Polygon() {
    int Polygon_x = x;
    int Polygon_y = y;
}


int Polygon::getShip_x() {
    return this->Polygon_x;
}
int Polygon::getShip_y() {
    return this->Polygon_y;
}

void fire();
void shield();
void blowup();
void missile();

void processNormalKeys (unsigned char key, int mx, int my) {
    switch(key) {
        case 'w':
        case 'W':
            y = (y+10);
            glutPostRedisplay();
            break;
        case 's':
        case 'S':
            y = (y-10);
            glutPostRedisplay();
            break;
        case 'a':
        case 'A':
            x = (x-10);
            glutPostRedisplay();
            break;
        case 'd':
        case 'D':
            x = (x+10);
            glutPostRedisplay();
            break;
        case 27:
        case 'E':
            exit(-1);
            break;
        case ' ':
            fire();
            glutPostRedisplay();
            break;
        case 'm':
        case 'M':
            missile();
            glutPostRedisplay();
            break;
        case 'f':
        case 'F':
            shield();
            glutPostRedisplay();
            break;
        case 'y':
        case 'Y':
            blowup();
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void processSpecialKeys (int key, int mx, int my) {
    switch(key) {
    case GLUT_KEY_LEFT :
        x = (x-10);
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT :
        x = (x+10);
        glutPostRedisplay();
        break;
    default: 
        break;
    }
}

void processMouseKeys(int button, int state, int x, int y) {
   switch(button) {
      case GLUT_LEFT_BUTTON:
         fire();
         glutPostRedisplay();
         break;
      case GLUT_RIGHT_BUTTON:
         shield();
         glutPostRedisplay();
         break;
      case GLUT_MIDDLE_BUTTON:
         blowup();
         glutPostRedisplay();
         break;
      default:
         break;
      }
}

void ship(void) {
    glBegin(GL_LINE_LOOP);      //head
        glVertex2i(x,y);
        glVertex2i(x+0.5*d, y);
        glVertex2i(x+0.5*d, y+0.5*d);
        glVertex2i(x-0.5*d, y+0.5*d);
        glVertex2i(x-0.5*d, y);
    glEnd();

    glBegin(GL_LINES); 
	glVertex2i(x-d, y);
        glVertex2i(x, y+d);
	glVertex2i(x+d,y);
	glVertex2i(x,y+d);   
    glEnd();
}

void display(void)
{ 
  glClear(GL_COLOR_BUFFER_BIT);
  ship();
  glFlush();
}

void init(void) 
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void fire(void) { 
}

void missile(void) {}

void blowup(void) {  // idea
    glColor3f(0,0,0);
    glutPostRedisplay();
}

void shield(void) { //shield idea
    if (state == 0) {
        glPushMatrix();
        glTranslatef(x, y, d);
        glColor4f(0,1,1,1);
        glutSolidSphere(0.4, 10, 10);
        glPopMatrix();
        state ++;
    }
    else {
        state--;
        glPushMatrix();
        glTranslatef(x, y, d);
        glColor4f(1,1,1,1);
        glutSolidSphere(0.4,10,10);
        glPopMatrix();
    }
}

int main(int argc, char** argv)
{
   x = 350;
   y = 10;
   d = 35;
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (640, 480); 
   glutInitWindowPosition (200, 100);
   glutCreateWindow ("Can't Touch This");
   glutDisplayFunc(display); 
   glutKeyboardFunc(processNormalKeys);
   glutSpecialFunc(processSpecialKeys);
   glutMouseFunc(processMouseKeys);
   glutPostRedisplay();
   init();
   glutMainLoop();
   return 0;
}

#include<bits/stdc++.h>
#define PI acos(-1.0)
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

GLfloat positionCloud1 = 0.0f;
GLfloat speedCloud1 = 0.002f;
GLfloat positionCloud2 = 0.0f;
GLfloat speedCloud2 = 0.0025f;
GLfloat positionCloud3 = 0.0f;
GLfloat speedCloud3 = 0.00209f;
GLfloat positionBoat1 = 0.0f;
GLfloat speedBoat1 = 0.008f;
GLfloat positionPlane = 0.0f;
GLfloat speedPlane = -0.0155f;
GLfloat positionBus = 0.0f;
GLfloat speedBus = -0.01f;

GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 5.0f;
float angle=45.0;
bool rainday=false;
float _rain=0.0f;
float sunintensity=1.0f;
float sunrayintensity=1.0f;
float sky_r=0.0f;
float sky_g=0.745f;
float sky_b=1.0f;


void update(int value) {
    positionCloud1 += speedCloud1;
    if(positionCloud1 > 1.8){
        positionCloud1 = -0.2f;
    }
    positionCloud2 += speedCloud2;
    if(positionCloud2 > 1.5){
        positionCloud2 = -0.4f;
    }
    positionCloud3 += speedCloud3;
    if(positionCloud3 > 1.0){
        positionCloud3 = -1.6f;
    }
    positionBoat1 += speedBoat1;
    if(positionBoat1 > 1.875){
        positionBoat1 = -1.0f;
    }
    positionPlane += speedPlane;
    if(positionPlane < -1.875){
        positionPlane = 0.8f;
    }
    positionBus += speedBus;
    if(positionBus < -1.875){
        positionBus = 0.5f;
    }

	glutPostRedisplay();

	glutTimerFunc(100, update, 0);
}



void init()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

///Rain Add
void Rain(int value)
{
    if(rainday)
    {
        _rain+=0.01f;
        glBegin(GL_POINTS);
        for(int i=1;i<=100;i++)
        {
            int x=rand(),y=rand();
            x%=820;
            y%=520;
            float tmpx=float(x)/820;
            float tmpy=float(y)/520;
            float mintmpx=(-1)*tmpx;
            float mintmpy=(-1)*tmpy;

            ///+ + AXIS RAIN
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(tmpx,tmpy);
            glVertex2d(tmpx+0.05,tmpy+0.05);
            glEnd();

            ///+ - AXIS RAIN
            glBegin(GL_LINES);
            glVertex2d(tmpx,mintmpy);
            glVertex2d(tmpx+0.05,mintmpy+0.05);
            glEnd();

            ///- + Axis Rain
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(mintmpx,tmpy);
            glVertex2d(mintmpx+0.05,tmpy+0.05);
            glEnd();
            ///- - Axis Rain
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(mintmpx,mintmpy);
            glVertex2d(mintmpx+0.05,mintmpy+0.05);
            glEnd();
        }
        glutPostRedisplay();
        glutTimerFunc(5,Rain,0);
        glFlush();
    }
}

void drawSun() //sun
{
    glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
	glEnd();
	glutPostRedisplay();
}


void drawCircle(float x,float y,float radius)
{
    glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
    int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

void drawCloud1(float x,float y,float radius) //cloud1
{
    //GLfloat  x=-.97f;GLfloat y=0.88; GLfloat radius =.035f;       //cloud1
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(61, 131, 231);
    int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	  x=-.92f; y=0.88;  radius =.055f;       //cloud1
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(61, 131, 231);
     i;
	 lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();


	 x=-.86f; y=0.88;  radius =.035f;       //cloud1
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(61, 131, 231);
     i;
	 lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
	glutPostRedisplay();
}

void drawCloud2(float x,float y,float radius) //cloud2
{
    //x=-.57f; y=0.88;  radius =.035f;       //cloud2
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
    int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();


	 x=-.52f; y=0.88;  radius =.055f;       //cloud2
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
     i;
	 lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	x=-.46f; y=0.88;  radius =.035f;       //cloud2
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
     i;
	 lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    glutPostRedisplay();

}

void drawCloud3(float x,float y,float radius) //cloud3
{
    //x=.46f; y=0.88;  radius =.035f;       //cloud3
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(61, 131, 231);
    int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();


	 x=.52f; y=0.88;  radius =.055f;       //cloud3
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(61, 131, 231);
     i;
	 lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	x=.57f; y=0.88;  radius =.035f;       //cloud3
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(61, 131, 231);
     i;
	 lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    glutPostRedisplay();

}

void drawBoat1() //boat1
{
    glBegin(GL_POLYGON);//boat2
    glColor3f(0.4,0.0 , 0.0);
    glVertex2f(-0.833f, -0.66f);
    glVertex2f(-0.33f, -0.66f);
     glVertex2f(-0.25f, -0.583f);
     glVertex2f(-0.916f, -0.583f);
     glEnd();
     glBegin(GL_POLYGON);
     glColor3f(1.0,1.0 , 0.4);
     glVertex2f(-0.833f, -0.583f);
     glVertex2f(-0.33f, -0.583f);
     glVertex2f(-0.416f, -0.5f);
     glVertex2f(-0.75f, -0.5f);
     glEnd();
     glBegin(GL_POLYGON);
     glColor3f(1.0,0.4 , 0.698);
     glVertex2f(-0.66f, -0.5f);
     glVertex2f(-0.5f, -0.5f);
     glVertex2f(-0.583f, -0.33f);
     glEnd();
     glBegin(GL_LINES);
     glColor3f(0.0,0.0 , 0.0);
     glVertex2f(-0.583f, -0.33f);
     glVertex2f(-0.583f, -0.166f);
     glEnd();
     glBegin(GL_POLYGON);
     glColor3f(1.0,0.0 , 0.0);
     glVertex2f(-0.583f, -0.283);
     glVertex2f(-0.55f, -0.25f);
     glVertex2f(-0.583f, -0.2166f);
     glEnd();

     ////Boatwindows//
     glBegin(GL_POLYGON);
     glColor3f(1.0,0.0 , 0.0);
     glVertex2f(-0.75f,-0.566f);
     glVertex2f(-0.7f,-0.566f);
     glVertex2f(-0.7,-0.516f);
     glVertex2f(-0.75f,-0.516f);
     glEnd();
          glBegin(GL_POLYGON);
     glColor3f(1.0,0.0 , 0.0);
     glVertex2f(-0.633f,-0.566f);
     glVertex2f(-0.583f,-0.566f);
     glVertex2f(-0.583,-0.516f);
     glVertex2f(-0.633f,-0.516f);
     glEnd();
          glBegin(GL_POLYGON);
     glColor3f(1.0,0.0 , 0.0);
     glVertex2f(-0.516f,-0.566f);
     glVertex2f(-0.46f,-0.566f);
     glVertex2f(-0.46f,-0.516f);
     glVertex2f(-0.516f,-0.516f);
     glEnd();
 glBegin(GL_POLYGON);
     glColor3f(0.0,0.56 , 0.698);
     glVertex2f(-0.833f,-0.6833f);
     glVertex2f(-0.33f,-0.6833f);
     glVertex2f(-0.33f,-0.66f);
     glVertex2f(-0.833f,-0.66f);
     glEnd();
}

void drawPlane() //plane
{
    glBegin(GL_TRIANGLES);//plane front
	glColor3ub(96,96,96);
	glVertex2f(.38,.65);
	glVertex2f(.40,.62);
	glVertex2f(.40,.68);
	glEnd();

	/*glBegin(GL_POLYGON);//plane body
	glColor3ub(0,153,153);
	glVertex2f(.40,.62);
	glVertex2f(.51,.62);
	glVertex2f(.54,.71);
	glVertex2f(.52,.71);
	glVertex2f(.51,.68);
	glVertex2f(.40,.68);
	glEnd();*/
	glBegin(GL_POLYGON);//plane body
	glColor3ub(0,153,153);
	glVertex2f(.40,.62);
	glVertex2f(.53,.62);
	glVertex2f(.56,.64);
	glVertex2f(.575,.66);
	glVertex2f(.575,.68);
	glVertex2f(.40,.68);
	glEnd();

	glBegin(GL_POLYGON);//plane body
	glColor3ub(0,153,153);
	glVertex2f(.57,.68);
	glVertex2f(.585,.73);
	glVertex2f(.57,.73);
	glVertex2f(.53,.68);
	glEnd();


	glBegin(GL_QUADS);//plane wing upper
	glColor3ub(0,153,153);
	glVertex2f(.44,.68);
	glVertex2f(.46,.68);
	glVertex2f(.47,.71);
	glVertex2f(.45,.71);
	glEnd();

	glBegin(GL_QUADS);//plane wing lower
	glColor3ub(0,153,153);
	glVertex2f(.44,.62);
	glVertex2f(.46,.62);
	glVertex2f(.47,.58);
	glVertex2f(.45,.58);
	glEnd();
}

void drawTree(float x,float y,float radius) //tree
{
    //x=.46f; y=0.88;  radius =.035f;       //tree
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 152, 49);
    int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

void drawBus1()
{
    glScalef(0.5,0.5,0.0);
//glTranslatef(position,0.0,0.0);
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(0.5f, -0.166f);
        glVertex2f(1.0f, -0.166f);
         glVertex2f(1.0f, 0.0f);
          glVertex2f(0.55f, 0.0f);
          glVertex2f(0.5f, -0.033f);
	glEnd();
	  glBegin(GL_POLYGON);
         glColor3f(1.0,1.0,0.0);
        glVertex2f(0.5f, -0.1f);
        glVertex2f(0.5166f, -0.1f);
         glVertex2f(0.5166f, -0.066f);
          glVertex2f(0.5f, -0.066f);
	glEnd();
	glBegin(GL_POLYGON);
         glColor3f(1.0,0.0,0.0);
        glVertex2f(0.55f, 0.0f);
        glVertex2f(1.0f, 0.0f);
         glVertex2f(1.0f, 0.116f);
          glVertex2f(0.55f, 0.116f);
	glEnd();

	////Buswindows///
	glBegin(GL_POLYGON);
         glColor3f(0.26,0.26,0.26);
        glVertex2f(0.5833f, 0.016f);
        glVertex2f(0.633f, 0.016f);
         glVertex2f(0.633f, 0.1f);
          glVertex2f(0.5833f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
         glColor3f(0.26,0.26,0.26);
        glVertex2f(0.65f, 0.016f);
        glVertex2f(0.7f, 0.016f);
         glVertex2f(0.7f, 0.1f);
          glVertex2f(0.65f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
         glColor3f(0.26,0.26,0.26);
        glVertex2f(0.716f, 0.016f);
        glVertex2f(0.766f, 0.016f);
         glVertex2f(0.766f, 0.1f);
          glVertex2f(0.716f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
         glColor3f(0.26,0.26,0.26);
        glVertex2f(0.783f, 0.016f);
        glVertex2f(0.833f, 0.016f);
         glVertex2f(0.833f, 0.1f);
          glVertex2f(0.783f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
         glColor3f(0.26,0.26,0.26);
        glVertex2f(0.85f, 0.016f);
        glVertex2f(0.9f, 0.016f);
         glVertex2f(0.9f, 0.1f);
          glVertex2f(0.85f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
         glColor3f(0.26,0.26,0.26);
        glVertex2f(0.916f, 0.016f);
        glVertex2f(0.966f, 0.016f);
         glVertex2f(0.966f, 0.1f);
          glVertex2f(0.916f, 0.1f);
	glEnd();

float x=.58f;float y=-0.18; float radius =.025f;       //first wheel
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 255);
    int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	x=.88f; y=-0.18;  radius =.025f;       //second wheel
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 204, 255);
     i;
	 lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();





//glLoadIdentity();

}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
    glClearColor(sky_r, sky_g, sky_b, 1.0f); // Set background color to black and opaque
	//glClear(GL_COLOR_BUFFER_BIT);
	//gluOrtho2D(-2.0,2.0,-2.0,2.0);

    glPushMatrix(); //Sun
        glTranslatef(0.8, 0.8, 0.0);
        glColor4f(1.0,1.0,0.0,sunintensity);
        drawSun();
	glPopMatrix();


	glBegin(GL_LINES); ////Sunrays////
	glColor4f(1.0,1.0,0.0,sunrayintensity);
	glVertex2f(0.8,0.8);
	glVertex2f(0.8,0.6);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(0.7,0.6);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(0.9,0.6);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(0.8,1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(0.9,1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(0.7,1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(1.2,1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(1.0,0.8);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(1.0,0.6);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(0.5,0.7);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(0.5,0.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.8,0.8);
	glVertex2f(0.5,0.9);
	glEnd();

	glBegin(GL_QUADS);//road
	glColor3f(0.698,0.745 , 0.7098);
	glVertex2f(-1.0,-.3);
	glVertex2f(1.0,-.3);
	glVertex2f(1.0,0.0);
	glVertex2f(-1.0,0.0);
	glEnd();
	glBegin(GL_QUADS);//road black
	glColor3ub(32,32,32);
	glVertex2f(-1.0,-0.0);
	glVertex2f(-1.0,-.15);
	glVertex2f(1.0,-.15);
	glVertex2f(1.0,-0.0);
	glEnd();

	glBegin(GL_QUADS);//road black
	glColor3ub(32,32,32);
	glVertex2f(-1.0,-0.18);
	glVertex2f(-1.0,-.35);
	glVertex2f(1.0,-.35);
	glVertex2f(1.0,-0.18);
	glEnd();

	 ////Border///

    glBegin(GL_POLYGON);
    glColor3f(0.2,0.098 , 0.0);
    glVertex2f(-1.0f, -0.33f);
    glVertex2f(1.0f, -0.33f);
    glVertex2f(1.0f, -0.416f);
    glVertex2f(-1.0f, -0.416f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0 , 0.0);
    glVertex2f(-1.0f, -0.35f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(1.0f, -0.33f);
    glVertex2f(-1.0f, -0.33f);
    glEnd();

	glBegin(GL_QUADS);//water
	glColor3ub(65, 108, 198);
	glVertex2f(-1.0,-1.0);
	glVertex2f(1.0,-1.0);
	glVertex2f(1.0,-.3);
	glVertex2f(-1.0,-.3);
	glEnd();

	glPushMatrix(); //plane
        glTranslatef(positionPlane, 0.0f, 0.0f);
        drawPlane();
	glPopMatrix();

	glBegin(GL_QUADS);// petronas tower lower left
	glColor3ub(163, 21, 21);
	glVertex2f(-.35,0.0);
	glVertex2f(-.30,0.0);
	glVertex2f(-.30,.30);
	glVertex2f(-.35,.30);
	glEnd();

	glBegin(GL_QUADS);// petronas tower lower left ,window
	glColor3ub(128, 128, 128);
	glVertex2f(-.335,0.10);
	glVertex2f(-.315,0.10);
	glVertex2f(-.315,.15);
	glVertex2f(-.335,.15);
	glEnd();

	glBegin(GL_QUADS);// petronas tower lower left ,window
	glColor3ub(128, 128, 128);
	glVertex2f(-.335,0.18);
	glVertex2f(-.315,0.18);
	glVertex2f(-.315,.23);
	glVertex2f(-.335,.23);
	glEnd();

	glBegin(GL_QUADS);// petronas tower lower right
	glColor3ub(163, 21, 21);
	glVertex2f(-.22,0.0);
	glVertex2f(-.17,0.0);
	glVertex2f(-.17,.30);
	glVertex2f(-.22,.30);
	glEnd();
	glBegin(GL_QUADS);// petronas tower lower right ,window
	glColor3ub(128, 128, 128);
	glVertex2f(-.205,0.10);
	glVertex2f(-.185,0.10);
	glVertex2f(-.185,.15);
	glVertex2f(-.205,.15);
	glEnd();
	glBegin(GL_QUADS);// petronas tower lower right ,window
	glColor3ub(128, 128, 128);
	glVertex2f(-.205,0.18);
	glVertex2f(-.185,0.18);
	glVertex2f(-.185,.23);
	glVertex2f(-.205,.23);
	glEnd();
	glBegin(GL_QUADS);// petronas tower lower middle
	glColor3ub(25,0,51);
	glVertex2f(-.30,.15);
	glVertex2f(-.22,0.15);
	glVertex2f(-.22,.20);
	glVertex2f(-.30,.20);
	glEnd();


	glBegin(GL_QUADS);// petronas tower upper left
	glColor3ub(163, 21, 21);
	glVertex2f(-.345,.30);
	glVertex2f(-.305,0.30);
	glVertex2f(-.305,.45);
	glVertex2f(-.345,.45);
	glEnd();

	glBegin(GL_QUADS);// petronas tower upper right
	glColor3ub(163, 21, 21);
	glVertex2f(-.215,.30);
	glVertex2f(-.175,0.30);
	glVertex2f(-.175,.45);
	glVertex2f(-.215,.45);
	glEnd();

	glBegin(GL_TRIANGLES);//petronas left triangle
	glColor3ub(25,0,51);
	glVertex2f(-.345,.45);
	glVertex2f(-.305,.45);
	glVertex2f(-.325,.75);
	glEnd();

	glBegin(GL_TRIANGLES);//petronas right triangle
	glColor3ub(25,0,51);
	glVertex2f(-.215,.45);
	glVertex2f(-.175,.45);
	glVertex2f(-.195,.75);
	glEnd();

	glBegin(GL_QUADS);//1st building
	glColor3ub(125, 7, 2);
	glVertex2f(-1.0,0.0);
	glVertex2f(-.92,0.0);
	glVertex2f(-.92,.2);
	glVertex2f(-1.0,.2);
	glEnd();

	glBegin(GL_QUADS);//1st building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.96,0.07);
	glVertex2f(-.94,0.07);
	glVertex2f(-.94,.1);
	glVertex2f(-.96,.1);
	glEnd();
	glBegin(GL_QUADS);//1st building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.96,0.12);
	glVertex2f(-.94,0.12);
	glVertex2f(-.94,.15);
	glVertex2f(-.96,.15);
	glEnd();

	glBegin(GL_QUADS);//2nd building
	glColor3ub(128, 5, 166);
	glVertex2f(-.91,0.0);
	glVertex2f(-.85,0.0);
	glVertex2f(-.85,.25);
	glVertex2f(-.91,.25);
	glEnd();

	glBegin(GL_QUADS);//2nd building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.89,0.07);
	glVertex2f(-.87,0.07);
	glVertex2f(-.87,.1);
	glVertex2f(-.89,.1);
	glEnd();

	glBegin(GL_QUADS);//2nd building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.89,0.12);
	glVertex2f(-.87,0.12);
	glVertex2f(-.87,.15);
	glVertex2f(-.89,.15);
	glEnd();

	glBegin(GL_QUADS);//2nd building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.89,0.18);
	glVertex2f(-.87,0.18);
	glVertex2f(-.87,.21);
	glVertex2f(-.89,.21);
	glEnd();

	glBegin(GL_QUADS);//watch tower
	glColor3ub(0,102,51);
	glVertex2f(-.83,0.0);
	glVertex2f(-.80,0.0);
	glVertex2f(-.80,.15);
	glVertex2f(-.83,.15);
	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3ub(64,64,64);
	glVertex2f(-.83,.15);
	glVertex2f(-.80,.15);
	glVertex2f(-.815,.25);
	glEnd();

	drawCircle(-.815f,0.12,0.013);

	glBegin(GL_QUADS);//3rd building
	glColor3ub(128, 4, 55);
	glVertex2f(-.79,0.0);
	glVertex2f(-.74,0.0);
	glVertex2f(-.74,.17);
	glVertex2f(-.79,.17);
	glEnd();

	glBegin(GL_QUADS);//3rd building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.77,0.05);
	glVertex2f(-.75,0.05);
	glVertex2f(-.75,.08);
	glVertex2f(-.77,.08);
	glEnd();

	glBegin(GL_QUADS);//3rd building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.77,0.09);
	glVertex2f(-.75,0.09);
	glVertex2f(-.75,.12);
	glVertex2f(-.77,.12);
	glEnd();

	glBegin(GL_QUADS);//  left 1st building
	glColor3ub(72, 112, 29);
	glVertex2f(-.42,0.0);
	glVertex2f(-.37,0.0);
	glVertex2f(-.37,.30);
	glVertex2f(-.42,.30);
	glEnd();
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(-.42,0.30);
	glVertex2f(-.37,0.30);
	glEnd();
	glBegin(GL_QUADS);//  left 1st building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.405,0.10);
	glVertex2f(-.385,0.10);
	glVertex2f(-.385,.15);
	glVertex2f(-.405,.15);
	glEnd();
	glBegin(GL_QUADS);//  left 1st building window
	glColor3ub(128, 128, 128);
	glVertex2f(-.405,0.18);
	glVertex2f(-.385,0.18);
	glVertex2f(-.385,.23);
	glVertex2f(-.405,.23);
	glEnd();

	glBegin(GL_TRIANGLES);//left triangle
	glColor3ub(64,64,64);
	glVertex2f(-.42,.30);
	glVertex2f(-.37,.30);
	glVertex2f(-.395,.48);
	glEnd();

	glBegin(GL_QUADS);//  left 2nd building(left)
	glColor3ub(148, 11, 212);
	glVertex2f(-.58,0.0);
	glVertex2f(-.53,0.0);
	glVertex2f(-.53,.30);
	glVertex2f(-.58,.28);
	glEnd();
	glBegin(GL_QUADS);//  left 2nd building(left) window
	glColor3ub(128, 128, 128);
	glVertex2f(-.565,0.10);
	glVertex2f(-.545,0.10);
	glVertex2f(-.545,.15);
	glVertex2f(-.565,.15);
	glEnd();
	glBegin(GL_QUADS);//  left 2nd building(left) window
	glColor3ub(128, 128, 128);
	glVertex2f(-.565,0.18);
	glVertex2f(-.545,0.18);
	glVertex2f(-.545,.23);
	glVertex2f(-.565,.23);
	glEnd();

	glBegin(GL_QUADS);//  left 2nd building(left)up
	glColor3ub(64,64,64);
	glVertex2f(-.57,0.284);
	glVertex2f(-.53,0.30);
	glVertex2f(-.53,.35);
	glVertex2f(-.57,.33);
	glEnd();

	glBegin(GL_QUADS);//  left 2nd building(right)
	glColor3ub(148, 11, 212);
	glVertex2f(-.53,0.0);
	glVertex2f(-.48,0.0);
	glVertex2f(-.48,.28);
	glVertex2f(-.53,.30);
	glEnd();
	glBegin(GL_QUADS);//  left 2nd building(right) window
	glColor3ub(128, 128, 128);
	glVertex2f(-.515,0.10);
	glVertex2f(-.495,0.10);
	glVertex2f(-.495,.15);
	glVertex2f(-.515,.15);
	glEnd();
	glBegin(GL_QUADS);//  left 2nd building(right) window
	glColor3ub(128, 128, 128);
	glVertex2f(-.515,0.18);
	glVertex2f(-.495,0.18);
	glVertex2f(-.495,.23);
	glVertex2f(-.515,.23);
	glEnd();
	glBegin(GL_QUADS);//  left 2nd building(right)up
	glColor3ub(64,64,64);
	glVertex2f(-.53,0.30);
	glVertex2f(-.49,0.284);
	glVertex2f(-.49,.33);
	glVertex2f(-.53,.35);
	glEnd();


	glBegin(GL_QUADS);//  right 1nd building
	glColor3ub(3, 37, 82);
	glVertex2f(0.0,0.0);
	glVertex2f(.05,0.0);
	glVertex2f(.05,.20);
	glVertex2f(0.0,.17);
	glEnd();
	glBegin(GL_QUADS);//  right 1nd building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.0205,0.10);
	glVertex2f(.045,0.10);
	glVertex2f(.045,.15);
	glVertex2f(0.0205,.15);
	glEnd();

    glBegin(GL_QUADS);//  right 1nd building
	glColor3ub(3, 65, 82);
	glVertex2f(0.05,0.0);
	glVertex2f(.10,0.0);
	glVertex2f(.10,.20);
	glVertex2f(0.05,.20);
	glEnd();
	glBegin(GL_QUADS);//  right 1nd building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.075,0.07);
	glVertex2f(.095,0.07);
	glVertex2f(.095,.12);
	glVertex2f(0.075,.12);
	glEnd();
	glBegin(GL_QUADS);//  right 1nd building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.075,0.15);
	glVertex2f(.095,0.15);
	glVertex2f(.095,.20);
	glVertex2f(0.075,.20);
	glEnd();

	glBegin(GL_QUADS);//  right 1nd building
	glColor3ub(3, 65, 82);
	glVertex2f(0.10,0.0);
	glVertex2f(.15,0.0);
	glVertex2f(.15,.20);
	glVertex2f(0.10,.20);
	glEnd();

	glBegin(GL_QUADS);//  right 1nd building
	glColor3ub(3, 37, 82);
	glVertex2f(0.15,0.0);
	glVertex2f(.20,0.0);
	glVertex2f(.20,.17);
	glVertex2f(0.15,.20);
	glEnd();

	glBegin(GL_QUADS);// upper right 1nd building
	glColor3ub(3, 65, 82);
	glVertex2f(0.05,0.20);
	glVertex2f(.10,0.20);
	glVertex2f(.10,.38);
	glVertex2f(0.05,.38);
	glEnd();

	glBegin(GL_QUADS);// upper right 1nd building
	glColor3ub(3, 65, 82);
	glVertex2f(0.10,0.20);
	glVertex2f(.15,0.20);
	glVertex2f(.15,.38);
	glVertex2f(0.10,.38);
	glEnd();
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(.10,0.20);
	glVertex2f(0.10,.38);
	glEnd();

    glBegin(GL_QUADS);//  right 3rd building
	glColor3ub(24, 82, 3);
	glVertex2f(0.25,0.0);
	glVertex2f(.30,0.0);
	glVertex2f(.30,.20);
	glVertex2f(0.25,.20);
	glEnd();
	glBegin(GL_QUADS);//  right 3rd building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.265,0.10);
	glVertex2f(.285,0.10);
	glVertex2f(.285,.15);
	glVertex2f(0.265,.15);
	glEnd();
	glBegin(GL_QUADS);//  right 3rd building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.265,0.05);
	glVertex2f(.285,0.05);
	glVertex2f(.285,.08);
	glVertex2f(0.265,.08);
	glEnd();

	glBegin(GL_QUADS);//  right 4th building
	glColor3ub(204, 0, 82);
	glVertex2f(0.35,0.0);
	glVertex2f(.40,0.0);
	glVertex2f(.40,.40);
	glVertex2f(0.35,.35);
	glEnd();
	glBegin(GL_QUADS);//  right 4th building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.365,0.10);
	glVertex2f(.385,0.10);
	glVertex2f(.385,.15);
	glVertex2f(0.365,.15);
	glEnd();
	glBegin(GL_QUADS);//  right 4th building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.365,0.18);
	glVertex2f(.385,0.18);
	glVertex2f(.385,.23);
	glVertex2f(0.365,.23);
	glEnd();

	glBegin(GL_QUADS);//  right 5th building
	glColor3ub(102, 0, 51);
	glVertex2f(0.45,0.0);
	glVertex2f(.50,0.0);
	glVertex2f(.50,.25);
	glVertex2f(0.45,.17);
	glEnd();
	glBegin(GL_QUADS);//  right 5th building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.465,0.10);
	glVertex2f(.485,0.10);
	glVertex2f(.485,.12);
	glVertex2f(0.465,.12);
	glEnd();
	glBegin(GL_QUADS);//  right 5th building window
	glColor3ub(128, 128, 128);
	glVertex2f(0.465,0.14);
	glVertex2f(.485,0.14);
	glVertex2f(.485,.16);
	glVertex2f(0.465,.16);
	glEnd();

	glBegin(GL_QUADS);//  tree 1
	glColor3ub(64,64,64);
	glVertex2f(0.80,0.0);
	glVertex2f(.81,0.0);
	glVertex2f(.81,.10);
	glVertex2f(0.80,.10);
	glEnd();
	drawTree(.805,0.11,0.03);

	glBegin(GL_QUADS);//  tree 2
	glColor3ub(64,64,64);
	glVertex2f(0.83,0.0);
	glVertex2f(.84,0.0);
	glVertex2f(.84,.07);
	glVertex2f(0.83,.07);
	glEnd();
	drawTree(.835,0.07,.02);

	glBegin(GL_QUADS);//  tree 3
	glColor3ub(64,64,64);
	glVertex2f(0.85,0.0);
	glVertex2f(.86,0.0);
	glVertex2f(.86,.07);
	glVertex2f(0.85,.07);
	glEnd();
	drawTree(.855f,0.08,0.02);

	glBegin(GL_QUADS);//  tree 4
	glColor3ub(64,64,64);
	glVertex2f(0.89,0.0);
	glVertex2f(.90,0.0);
	glVertex2f(.90,.07);
	glVertex2f(0.89,.07);
	glEnd();
	drawTree(.895,0.08,0.03);

	glBegin(GL_QUADS);//  tree 5
	glColor3ub(64,64,64);
	glVertex2f(0.92,0.0);
	glVertex2f(.93,0.0);
	glVertex2f(.93,.07);
	glVertex2f(0.92,.07);
	glEnd();
	drawTree(.925,0.08,0.03);

	glBegin(GL_QUADS);//  tree -1
	glColor3ub(64,64,64);
	glVertex2f(-0.72,0.0);
	glVertex2f(-.71,0.0);
	glVertex2f(-.71,.04);
	glVertex2f(-0.72,.04);
	glEnd();
	drawTree(-.7155,0.05,0.015);

	glBegin(GL_QUADS);//  tree -2
	glColor3ub(64,64,64);
	glVertex2f(-0.69,0.0);
	glVertex2f(-.68,0.0);
	glVertex2f(-.68,.04);
	glVertex2f(-0.69,.04);
	glEnd();
	drawTree(-.685,0.05,0.020);

	glBegin(GL_QUADS);//  tree -3
	glColor3ub(64,64,64);
	glVertex2f(-0.67,0.0);
	glVertex2f(-.66,0.0);
	glVertex2f(-.66,.06);
	glVertex2f(-0.67,.06);
	glEnd();
	drawTree(-.665,0.07,0.025);

	glBegin(GL_QUADS);//  tree -4
	glColor3ub(64,64,64);
	glVertex2f(-0.64,0.0);
	glVertex2f(-.63,0.0);
	glVertex2f(-.63,.04);
	glVertex2f(-0.64,.04);
	glEnd();
	drawTree(-.635,0.05,0.020);






	glPushMatrix();
        glTranslatef(positionBus, 0.0f, 0.0f);
        drawBus1();
    glPopMatrix();

	glPushMatrix(); //cloud1
        glTranslatef(positionCloud1, 0.0f, 0.0f);
        drawCloud1(-.97f,0.88,0.035);
	glPopMatrix();

	glPushMatrix(); //cloud2
        glTranslatef(positionCloud2, 0.0f, 0.0f);
        drawCloud2(-.57,0.88,0.035);
	glPopMatrix();

	glPushMatrix(); //cloud3
        glTranslatef(positionCloud3, 0.0f, 0.0f);
        drawCloud3(0.46,0.88,0.035);
	glPopMatrix();

	glPushMatrix(); //boat1
        glTranslatef(positionBoat1, 0.0f, 0.0f);
        drawBoat1();
	glPopMatrix();


    glFlush();
    glutSwapBuffers();
}


void handleKeypress(unsigned char key, int x, int y){
    if(key=='r'||key=='R')
    {
        rainday=true;
        PlaySound(TEXT("Others/rsound.WAV"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        Rain(_rain);
        sunintensity=0.20f;
        sunrayintensity=0.0f;
        sky_r=0.172;
        sky_g=0.219;
        sky_b=0.271;
        //cout<<"pressed"<<endl;
    }
    else if(key=='E'||key=='e')
    {
        PlaySound(TEXT("Others/city.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        rainday=false;
        sunintensity=1.0f;
        sunrayintensity=1.0f;
        sky_r=0.0f;
        sky_g=0.745f;
        sky_b=1.0f;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(820,520);
    glutCreateWindow("Test");
    glutDisplayFunc(display);
    PlaySound(TEXT("Others/city.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    init();
    glutTimerFunc(1000, update, 0);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}

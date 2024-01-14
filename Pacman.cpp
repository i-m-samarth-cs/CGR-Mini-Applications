#include <windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>

static double x1=0;
static double y1=-1;
static double a=0.0;
bool start=false;
bool eat=false;
bool left=false;
bool right=false;
bool up=false;
bool down=false;
bool pac=false;
float angle=0;
float point[][3]={{1,-0.6,1},{2,1.2,1},{-1,-1,1},{-2,-1,1},{1,1,1},{2,1,1},{-1,1,1},{-2,1,1},{-2,2,1},{-1.2,2,1},{0.8,2,1},{0,2,1},{2,2,1}  };
bool d[12];

void
stroke_output(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(-2.5, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}
void drawPacMan(){

	glPushMatrix();
//head
	glPushMatrix();
glScalef(1,1,0.2);
glutSolidSphere(0.5,20,20);
glPopMatrix();

//eye
	glPushMatrix();
glColor3f(1.0,0,1);
glScaled(1,1,0.5);
glTranslatef(0.15,0.2,0);
glutSolidSphere(0.2,20,20);
glPopMatrix();


if(eat){
glPushMatrix();
glColor3f(1.0,0,1);
glTranslatef(0.3,-0.08,0);
glScaled(0.5,0.2,0.5);
glutSolidSphere(0.4,20,20);
glPopMatrix();
}
 glPopMatrix();
}
void wall(float y1){
glPushMatrix();
glTranslatef(0,y1,0);
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,0.0);
glVertex3f(-4,-.3,-2);
glVertex3f(4,-.3,-2);
glVertex3f(4,.3,-2);
glVertex3f(-4,.3,-2);

glEnd();
glPopMatrix();

}

void blade(){

glPushMatrix();
glRotatef(angle,0,0,1);
glPushMatrix();
glScalef(1,0.1,0.1);
glutSolidSphere(0.5,20,20);
glPopMatrix();


glPushMatrix();
glScalef(0.1,1.0,0.1);
glutSolidSphere(0.5,20,20);
glPopMatrix();


glPopMatrix();
}



void pacMan() 
{ 


glClearColor(1.0,1.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
  glTranslatef(0.0f,0.0f,-13.0f);
//glRotated(x1,1.0,0.0,0.0);
 if(left)
x1-=0.003;
	
if(right)
x1+=0.003;
	
if(up)
y1+=0.003;
	
if(down)
y1-=0.003;

//   Main eating Condition 
for(int j=0;j<12;j++)
{
if(x1>=(point[j][0]-0.3) && x1<=(point[j][0]+0.3) && y1>=(point[j][1]-0.3) && y1<=(point[j][1]+0.3)){
d[j]=true;
}

}


// Destroying Condition
if(x1>=-0.5 && x1<=0.5  &&  y1>=-.5  && y1<=.5){
pac=true;
}
if(x1>=3.5-0.5 && x1<=3.5+0.5  &&  y1>=-2.5-0.5  && y1<=-2.5+0.5){
pac=true;
}

// border conditions

if(x1<=-4.2){
	
left=false;
right=true;
}
if(x1>=4.2){
left=true;
right=false;
}
if(y1<=-3.4){
up=true;
down=false;
	}
	
	
if(y1>=3.4){
	
up=false;
down=true;
}
 /**********   Border   *************/

glBegin(GL_POLYGON);

glColor3f(1.0,0.0,0.0);
glVertex3f(-5,-4,-2);
glVertex3f(5,-4,-2);
glVertex3f(5,4,-2);
glVertex3f(-5,4,-2);
  glEnd();


glBegin(GL_POLYGON);

glColor3f(0.0,0.0,0.0);
glVertex3f(-4.8,-3.8,-2);
glVertex3f(4.8,-3.8,-2);
glVertex3f(4.8,3.8,-2);
glVertex3f(-4.8,3.8,-2);
glEnd();

/*****************   WALLS   *****************/
wall(2.8);	
wall(1.5);
//rotate and scale
glPushMatrix();
glTranslatef(-3.6,-0.8,0);
glRotatef(90,0,0,1);
glScalef(0.28,1,1);
wall(0);
glPopMatrix();
//scale
glPushMatrix();
glTranslatef(0.7,0,0);
glScalef(0.8,1,1);
wall(0);
glPopMatrix();

//scale
glPushMatrix();
glTranslatef(0.7,0,0);
glScalef(0.8,1,1);
wall(-1.5);
glPopMatrix();
//Normal
wall(-2.8);


// blades
glPushMatrix();
glTranslatef(3.5,-2.5,0);
blade();
glPopMatrix();
blade();
// Create pacman and assign movement 
if(left){
glPushMatrix();
glTranslatef(x1,y1,0);
glRotatef(180,0,1,0);
drawPacMan();
glPopMatrix();
}
else if(right){
glPushMatrix();
glTranslatef(x1,y1,0);
drawPacMan();
glPopMatrix();
}
else if(down){
glPushMatrix();
glTranslatef(x1,y1,0);
glRotatef(-90,0,0,1);
drawPacMan();glPopMatrix();}

for(int i=0;i<12;i++)
{	glPushMatrix();
if(d[i])
{	glTranslatef(10,10,10);
}
else 
{	glTranslatef(point[i][0],point[i][1],0.1);
}	
glutSolidSphere(0.1,10,10);
glPopMatrix();
}
glFlush();
glutSwapBuffers();
}
void gameOver(){
glClearColor(1.3,1.3,1.3,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glTranslatef(0.0f,0.0f,-13.0f);
 glColor3f(1,1,0);
 stroke_output(0,0,"GAME  OVER  UR  DONE");
 stroke_output(0,-1,"Project By");
 glFlush();
glutSwapBuffers();
}

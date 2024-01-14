#include<conio.h>

#include<stdlib.h>

#include<math.h>

#include <graphics.h>

#include<dos.h>

void tree(float x, float y,float len, float a, float b) {

if (len<20)

{

delay(50);

setcolor(20);

circle(x,y,5);

setcolor(280);

circle(x,y,6);

return;

}

float x1,y1;

settextstyle(1,0,1);

setcolor(14);

outtextxy(150,5, "Created by :- Ak Grp"The Glowing Tree!!"); 

setcolor(28); 

x1=x+len*cos(3.1428*a/180);

y1-y-len*sin(3.1428*a/180);

line(x,y,x1,y1);

tree(x1,y1, len*0.75,a-b,b);
tree(x1,y1, len*0.75,a-b,-b);

}

void main()

{

int gd=0,gm,i,rd;

float x=320,y=550,t=120;

clrscr();

initgraph(&gd,&gm, for(i=0; i<=3; i++)

{

tree(x+i,y,t,90,30);

tree(x+i,y,t,90,-30);

}

getch();

closegraph();

}


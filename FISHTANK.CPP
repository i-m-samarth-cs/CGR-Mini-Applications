#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
void oxygen_bubbles(int i,int y)
{
if(y<100)
{
y=y+200;
if(y>200)
{
setfillstyle(SOLID_FILL,9);
circle(100,y+110-i,5);
floodfill(100,y+110-i,15);
}
}
else
{
setfillstyle(SOLID_FILL,9);
circle(100,y+110-i,5);
floodfill(100,y+110-i,15);
}
}
void main()
{
int i,y=200;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
for(i=0;i<300;i++)
{
setcolor(15);
//Right Fish
arc(400-i,150,50,320,30);
line(420-i,128,450-i,160);
line(420-i,173,450-i,130);
line(450-i,160,450-i,130);
circle(380-i,150,3);
arc(380-i,150,270,90,20);

//Left Fish
arc(150+i,200,220,150,30);
line(100+i,190,130+i,222);
line(125+i,184,100+i,220);
line(100+i,190,100+i,220);
circle(170+i,200,3);
arc(175+i,200,100,260,20);
arc(525,400,100,180,50);

//Plant
setfillstyle(SOLID_FILL,2);
ellipse(498,369,100,460,10,5);
floodfill(498,369,15);

arc(425,400,10,80,50);

setfillstyle(SOLID_FILL,2);
ellipse(459,375,100,460,10,5);
floodfill(459,375,15);

setfillstyle(SOLID_FILL,2);
ellipse(440,360,100,460,10,5);
floodfill(440,360,15);

setfillstyle(SOLID_FILL,2);
ellipse(470,360,100,460,10,5);
floodfill(470,360,15);

setfillstyle(SOLID_FILL,2);
ellipse(487,385,100,460,10,5);
floodfill(487,385,15);

setfillstyle(SOLID_FILL,2);
ellipse(519,350,100,460,10,5);
floodfill(519,350,15);

setfillstyle(SOLID_FILL,2);
ellipse(430,350,100,460,10,5);
floodfill(430,350,15);

//Oxygen Provider
setfillstyle(SOLID_FILL,4);
rectangle(50,300,80,370);
floodfill(51,301,15);

rectangle(80,305,95,310);
oxygen_bubbles(i,y);
y--;

//Aquarium

rectangle(50,100,560,400);
setfillstyle(SOLID_FILL,4);
rectangle(10,10,610,100);
floodfill(11,11,15);


//Pebbles
setfillstyle(SOLID_FILL,6);
ellipse(100,390,0,360,20,10);
floodfill(100,390,15);

setfillstyle(SOLID_FILL,6);
ellipse(125,373,0,360,25,10);
floodfill(125,373,15);

setfillstyle(SOLID_FILL,6);
ellipse(150,390,0,360,20,10);
floodfill(150,390,15);

setfillstyle(SOLID_FILL,6);
ellipse(170,375,0,360,20,5);
floodfill(170,375,15);

setfillstyle(SOLID_FILL,6);
circle(180,390,10);
floodfill(180,390,15);

setfillstyle(SOLID_FILL,6);
ellipse(200,380,0,360,10,15);
floodfill(200,380,15);

setfillstyle(SOLID_FILL,15);
circle(220,390,10);
floodfill(220,390,15);

setfillstyle(SOLID_FILL,7);
ellipse(250,380,0,360,20,15);
floodfill(250,380,15);

setfillstyle(SOLID_FILL,8);
ellipse(290,390,0,360,20,10);
floodfill(290,390,15);

setfillstyle(SOLID_FILL,7);
ellipse(315,370,0,360,25,10);
floodfill(315,370,15);

setfillstyle(SOLID_FILL,8);
ellipse(340,390,0,360,25,10);
floodfill(340,390,15);

setfillstyle(SOLID_FILL,7);
ellipse(360,375,0,360,15,5);
floodfill(360,375,15);

setfillstyle(SOLID_FILL,7);
circle(370,390,10);
floodfill(370,390,15);

setfillstyle(SOLID_FILL,7);
ellipse(390,380,0,360,10,15);
floodfill(390,380,15);

setfillstyle(SOLID_FILL,7);
circle(410,390,10);
floodfill(410,390,15);

setfillstyle(SOLID_FILL,8);
ellipse(530,390,0,360,21,10);
floodfill(530,390,15);
setfillstyle(SOLID_FILL,8);
ellipse(550,365,0,360,10,20);
floodfill(550,365,15);

outtextxy(250,50,"\n Fish tank \n");
setcolor(15);
outtextxy(100,20,"\nCreated by :-\n Samarth Shendre");
delay(10);
cleardevice();
}
getch();
closegraph();
}


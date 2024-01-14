#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void main()
{
  int gd=DETECT,gm,x;
  clrscr();
  initgraph(&gd,&gm,"C://TurboC3//BGI");

for( x=0;x<450; x++)
  {
 //body of car
   setfillstyle(1,4);
  line(50+x,370,90+x,370);
  arc(110+x,370,0,180,20);
  line(130+x,370,220+x,370);
  arc(240+x,370,0,180,20);
  line(260+x,370,300+x,370);
  line(300+x,370,300+x,350);
  line(300+x,350,240+x,330);
  line(240+x,330,200+x,300);
  line(200+x,300,110+x,300);
  line(110+x,300,80+x,330);
 

  line(80+x,330,50+x,340);
  line(50+x,340,50+x,370);
   floodfill(190+x,333,WHITE);
 
//car windows
 setfillstyle(1,0);
  outtextxy(150+x,335,"TAXI");
  line(165+x,305,165+x,330);
  line(165+x,330,230+x,330);
  line(230+x,330,195+x,305);
  line(195+x,305,165+x,305);

  line(160+x,305,160+x,330);
  line(160+x,330,95+x,330);
  line(95+x,330,120+x,305);
  line(120+x,305,160+x,305);
   floodfill(167+x,313,WHITE);
   floodfill(150+x,313,WHITE);

//car wheels
   circle(110+x,370,17);
   circle(240+x,370,17);
                    //road
    line(0,390,640,390);

 //Home
    setfillstyle(8,11);
  


     rectangle(20,270,180,380); //first floor
     rectangle(110,305,160,380);//first floor door
 
     rectangle(20,160,180,270);  //second floor
     rectangle(110,195,160,270);//second floor door
     floodfill(25,280,WHITE);
     floodfill(25,171,WHITE);

     setfillstyle(3,6);
     rectangle(40,320,70,350); //first floor window
     rectangle(40,210,70,245);
     floodfill(50,217,WHITE);
     floodfill(50,327,WHITE);

    setfillstyle(4,13);
    rectangle(40,245,70,295);
    rectangle(40,295,70,320);
    floodfill(50,302,WHITE);
    floodfill(50,252,WHITE);

    setfillstyle(1,6);
    rectangle(20,150,180,170);
    floodfill(24,157,WHITE);

      line(0,253,20,270);
      line(0,143,20,160);
      line(0,363,20,380);    //lhs of home
      

      line(0,153,20,170);
      line(0,263,20,280);
      line(0,143,0,363);
     setcolor(x);
 

   outtextxy(250,50,"\n RUNNING TAXI\n");
   
     setcolor(15);
     outtextxy(190,70," BY-SAMARTH SHENDRE");

    delay(20);
    cleardevice();
    }

getch();
closegraph();
}


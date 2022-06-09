#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#define ROWS 40.0
#define COLUMNS 40.0

using namespace std;

void unit(int,int);
int phyWidth= 700;
int phyHeight= 700;
int rows=0,columns=0;
int viewWidth= 700;
int viewHeight= 700;
int logWidth=100;
int logHeight=100;
int centerX=logWidth/2;
int centerY=logHeight/2;
float mouseX=centerX, mouseY=centerY;
int sqWid=20;
bool sqUp=true;
int sqDelta=0;
int maxY=22;
int xr=98;
int xl=2;
int sw =2 ;
int sh =2;
int xf = 50;
int yf = 50;
int alphaY=0;
int activX = 0;
int activY = 0;
int activate = 0;
int a;
int b;
int step = 0;


vector<vector<int> > vect;


void resetVect(){
    vect=    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
}


void activateCell(int x, int y){
    int r, c;

    x=ceil(x);
    y=ceil(y);

    if(x % 2 != 0){
        x++;
        r=x;
    }
    else{
        r=x;
    }

    if(y % 2 != 0){
        y++;
        c=y;
    }
    else{
        c=y;
    }

    a=ceil(r/2)-1;
    b=ceil(c/2)-1;

    while(activate == 1){
        if(vect[a][b]==1) vect[a][b]=0;
        else vect[a][b]=1;
        activate = 0;
    }
}



void drawborder(){
    int y =2;
    glColor3f(0.0, 0.0, 0.0);
    for (int i=0;i<30;i++){

        glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);



            glVertex2f(xr-sw, y-sw +alphaY);
            glVertex2f(xr+sw, y-sw +alphaY);
            glVertex2f(xr+sw, y+sw +alphaY);
            glVertex2f(xr-sw, y+sw +alphaY);


            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(xl-sw, y-sw -alphaY);
            glVertex2f(xl+sw, y-sw -alphaY);
            glVertex2f(xl+sw, y+sw -alphaY);
            glVertex2f(xl-sw, y+sw -alphaY);


        y+=6;
    }


      if (alphaY == 4){
         alphaY = 0;
      }
     else {
        alphaY++;
      }

 glEnd();
}
void printSome(char *str,int x,int y) {
    glColor3f (0.0, 0.0, 1.0);
    glRasterPos2d(x,y);
    for (int i=0;i<strlen(str);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    glFlush();
}
void printtitle(char *str,int x,int y) {
    glColor3f (0.0, 1.0, 1.0);
    glRasterPos2d(x,y);
    for (int i=0;i<strlen(str);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    glFlush();
}

void buttons(){

     glColor3f(0.0, 0.0, 0.0);

     glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);



        glVertex2f(38, 75);
        glVertex2f(68,75 );
        glVertex2f(68,60 );
        glVertex2f(38,60 );


        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(38,45);
        glVertex2f(68,45 );
        glVertex2f(68,30 );
        glVertex2f(38,30 );

     glEnd();

}

void drawgrid()
{
    int r=2;
    int s=100;
    int c=2;
     glColor3f(1.0, 1.0, 1.0);
     glBegin(GL_LINES);
      glColor3f(1.0, 1.0, 1.0);
        for (int i=0; i<50; i++ ){
            glVertex2i(r,0);
            glVertex2i(r,100);
            r+=2;
        }

    glEnd();

    glBegin(GL_LINES);
        for (int i=0; i<50; i++ ){
            glVertex2i(0,c);
            glVertex2i(100,c);
            c+=2;
        }
    glEnd();
}


//void mouseClick(int btn, int state, int x, int y)
//{
//if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
//mouseX = x; mouseX=0.5+1.0*mouseX*logWidth/phyWidth;
//mouseY = phyHeight- y;mouseY=0.5+1.0*mouseY*logHeight/phyHeight;
//}
//if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN && btn==buttons) {

//exit(1);

//}
//glutPostRedisplay();
//}

void drawSquares(){
    int r,c;
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if(vect[i][j] == 1){
                r=(i+1)*2;
                c=(j+1)*2;
                glBegin(GL_QUADS);
                    glColor3f(1.0, 1.0, 1.0);
                    glVertex2f(r-2, c-2);
                    glVertex2f(r-2, c);
                    glVertex2f(r,c);
                    glVertex2f(r,c-2);
                glEnd();
            }
        }
    }
}

void Timer(int value) {

    glutTimerFunc(40, Timer, value);
    glutPostRedisplay();

}

static void displaygame();


static void displaystart(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawborder();
    buttons();
    printSome("START",48,66);
    printSome("EXIT",49,36);
    printtitle("Conway's Game Of Life",35,90);

    if(mouseX >= 38 && mouseX <=68){
        //START BUTTON
        if(mouseY >= 60 && mouseY <= 75){
            activate = 0;
            glutDisplayFunc(displaygame);
        }
        //EXIT BUTTON
        else if(mouseY >= 30 && mouseY <= 45){
            exit(1);
        }
    }

    glutSwapBuffers();
    glFlush();

}

vector<vector<int> > stepForward(vector < vector<int> > vect){
    step=0;
    vector < vector<int> > temp = vect;
    for (int i = 1; i < vect.size()-1; i++)
    {
        for (int j = 1; j < vect[i].size()-1; j++)
        {
            cout << i << j << endl;
            int alive = 0;
            if(vect[i][j+1] == 1) alive++;
            if(vect[i+1][j+1] == 1) {alive++;}
            if(vect[i+1][j] == 1) alive++;
            if(vect[i+1][j-1] == 1) alive++;
            if(vect[i][j-1] == 1) alive++;
            if(vect[i-1][j-1] == 1) alive++;
            if(vect[i-1][j] == 1) alive++;
            if(vect[i-1][j+1] == 1) alive++;

            if(alive == 0 || alive == 1) temp[i][j]=0;
            else if(alive == 2) {}
            else if(alive == 3) temp[i][j]=1;
            else temp[i][j]=0;
        }
    }
    return temp;;
}

vector<vector<int> > stepLoop(vector < vector<int> > vect){
    vector < vector<int> > temp = vect;
    for (int i = 1; i < vect.size()-1; i++)
    {
        for (int j = 1; j < vect[i].size()-1; j++)
        {
            cout << i << j << endl;
            int alive = 0;
            if(vect[i][j+1] == 1) alive++;
            if(vect[i+1][j+1] == 1) {alive++;}
            if(vect[i+1][j] == 1) alive++;
            if(vect[i+1][j-1] == 1) alive++;
            if(vect[i][j-1] == 1) alive++;
            if(vect[i-1][j-1] == 1) alive++;
            if(vect[i-1][j] == 1) alive++;
            if(vect[i-1][j+1] == 1) alive++;

            if(alive == 0 || alive == 1) temp[i][j]=0;
            else if(alive == 2) {}
            else if(alive == 3) temp[i][j]=1;
            else temp[i][j]=0;
        }
    }
    return temp;;
}

vector<vector<int> > stepBackward(vector < vector<int> > vect){
    step=0;
    vector < vector<int> > temp = vect;
    for (int i = 1; i < vect.size()-1; i++)
    {
        for (int j = 1; j < vect[i].size()-1; j++)
        {
            cout << i << j << endl;
            int alive = 0;
            if(vect[i][j+1] == 1) alive++;
            if(vect[i+1][j+1] == 1) {alive++;}
            if(vect[i+1][j] == 1) alive++;
            if(vect[i+1][j-1] == 1) alive++;
            if(vect[i][j-1] == 1) alive++;
            if(vect[i-1][j-1] == 1) alive++;
            if(vect[i-1][j] == 1) alive++;
            if(vect[i-1][j+1] == 1) alive++;

            if(alive == 0 || alive == 1) temp[i][j]=1;
            else if(alive == 2) {}
            else if(alive == 3) temp[i][j]=0;
            else temp[i][j]=1;
        }
    }
    return temp;;
}

static void displaygame (void){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    drawgrid();
    if(activate == 1){
        activateCell(mouseX,mouseY);
        activate = 0;
    }
    if(step == 1)
        vect = stepForward(vect);

    if(step == -1)
        vect = stepBackward(vect);
    if(step == 5)
        vect = stepLoop(vect);

    drawSquares();
    glutSwapBuffers();
    glFlush();
}

void mouseClick(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
        mouseX = x; mouseX=0.5+1.0*mouseX*logWidth/phyWidth;
        mouseY = phyHeight - y;mouseY=0.5+1.0*mouseY*logHeight/phyHeight;
        activate = 1;
        //cout << mouseX << endl;
        //cout << mouseY << endl;
    }
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) {
        exit(1); // To Exit the Program
    }


    glutPostRedisplay();
}



void specialKeyboard(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT){
        step = -1;
    }
    if(key == GLUT_KEY_RIGHT)
        step = 1;
    if(key == GLUT_KEY_F1)
        resetVect();
    if(key == GLUT_KEY_F2)
        displaystart();
    if(key == GLUT_KEY_HOME)
        step = 5;
    glutPostRedisplay();
}


void init()
{
    glClearColor( 1.0, 0.0, 1.0, 0.0);

    glMatrixMode( GL_PROJECTION);
    gluOrtho2D( 0.0, logWidth, 0.0, logHeight);
}

void init2()
{
    glClearColor( 0.0, 0.0, 0.0, 0.0);

    glMatrixMode( GL_PROJECTION);
    gluOrtho2D( 0.0, logWidth, 0.0, logHeight);
}
/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
        resetVect();
        glutInitWindowSize(viewWidth, viewHeight);
        glutInitWindowPosition(100,100);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("Conway's Game of Life");
        init();
        glutDisplayFunc(displaystart);

    Timer(0);



    /*glutInitWindowSize(viewWidth, viewHeight);
    glutInitWindowPosition(200,200);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Game");
    init2();
    glutDisplayFunc(displaygame);*/
//    glutMouseFunc(mouseClick);
    glutMouseFunc(mouseClick);
    glutSpecialFunc(specialKeyboard);

    glutMainLoop();

    return EXIT_SUCCESS;
}

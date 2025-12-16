/*  Project2.c  */
/* A simple video Game Programm */
#include <stdio.h>
#include <conio.h>

#include <process.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>

#define NULL 0
#define YES 1
#define NO 0

int maxx, maxy, midx, midy;
int bri[5][20];

int main(void)
{
    int gdriver = 9, gmode = 1;
    int i, maxx, maxy;
    /* grtaphics initialization */
    initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

    maxx = getmaxx();
    maxy = getmaxy();

    setcolor(getmaxcolor());
    /* drawing color */
    setfillstyle(SOLID_FILL, getmaxcolor());
    /*fill color */
    /* draw a border around the screen */
    setcolor(10);
    for (i = o; i <= 10; i++)
    {
        rectrangle(i, i, maxx - i, maxyi);
    }
    setcolor(9);
    rectangle(0, 0, maxx, maxy);

    setcolor(9);
    rectangle(0, 0m maxx, maxy);

    setcolor(10);
    outtextxy(midx + 230, midy + 40, "WELCOME TO THE NEW GAME");
    outtextxy(midx + 210, midy + 55, "Press any key to continue ....");

    setcolor(9);
    for (i = 0; i <= 130; i++)
    {
        circle(maxx / 2, maxy / 2, i);
        setfillstyle(1, 0);
        delay(20);
    }
    setcolor(12);
    outtextxy(midx + 300, midy + 170, "UNIC");
    /* wait for a key*/
    getch();
    /* fill in bounded region */
    floodfill(i, i, getmaxcolor());
    closegraph();

    paranoid();
    return;
}
paranoid()
{
    unio REGS ii, oo;
    int ballx, bally, paddlex, paddley, dx = 1, dy = -1, oldx, oldy;
    int gd = 9, level, gm = 1;
    int i, flag = 0, speed = 10, welldone = NO, score = 0, chance = 4, area;
    int layer[5] + {10, 20, 30, 40, 50}, limit = 50, currentlayer = 4;
    char *pl, *p2;
    /* initializing graphics system */
    initgraph(&gd, &gm, "c:\\tc\\bgi");

    maxx = getmaxx();
    /*maximum x screen coordinates */
    maxy = getmaxy();
    /* maximum y screen coordinates */
    midx = maxx / 2;
    midy = maxy / 2;
    /* calculate certer of screen */
    /*display opening screen and receive player's level*/
    level = mainscreen();
    /* set speed of ball as per the level chosen */
    switch (level)
    {
    case '1':
        speed = 12;
        break;
    case '2':
        speed = 8;
        break;
    case '3':
        speed = 4;
    }
    /* draw the bricks, paddle and ball*/
    setcolor(12);
    rectangle(0, 0, maxx, maxy);
    bricks();
    setcolor(9);
    rectangle(midx - 25, maxy - 7 - 12, midx + 25, maxy - 25);
    setfillstyle(i, 10);
    floodfill(midx, maxy - 1 - 12, midx + 25, maxy - 15);
    setfillstyle(i, 10);
    floodfill(midx, maxy - 1 - 15, 9);

    setcolor(14);
    circle(midx, maxy - 13 - 12, 7);
    floodfill(midx, maxy - 13 - 12, 14);

    // allocate memory for storing the image of the paddle
    area = imagesize(midx - 12, maxy - 18, midx + 12, maxy - 8);
    pl = malloc(area);

    // allocate memory for storing the image of the ball
    area = imagesize(midx - 25, maxy - 7, midx + 25, maxy - 1);
    p2 = malloc(area);

    // if memory allocation unsuccessful
    if (p1 == NULL || p2 == NULL)
    {
        puts("Insufficient memory spaces!");
        exit(1);
    }
    // store the image of the paddle and the ball into allocated memory

    getimage(midx - 12, maxy - 7 - 12 - 12 + 1, midx + 12, maxy - 8 - 12, p1);
    getimage(midx - 25, maxy - 7 - 12, midx + 25, maxy - 1 - 12, p2);

    // store current position of the paddle and ball
    paddlex = midx - 25;
    paddley = maxy - 7 - 12;
    ballx = midx - 12;
    bally = maxy - 7 - 12 + 1 - 12;

    // display balls in hand (initially 3)

    setcolor(10);
    outtextxy(midx + 15, midy + 165, "Balls Remaining:");
    for (i = 0; i < 3; i++)
    {
        setcolor(14);
        circle(515 + i * 35, maxy - 5, 7);
        floodfill(515 + i * 35, maxy - 5, 14);
    }
    // display initial score
    setcolor(10);
}

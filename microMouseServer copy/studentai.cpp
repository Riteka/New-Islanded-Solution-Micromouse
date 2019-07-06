
#include "micromouseserver.h"
static int count = 0;
static int tracker[20][20][4];
static int direction= 0 ;
static int matrixinit = false;
static bool reverse = false;
static int xx = 0;
static int yy = 0;


void microMouseServer::studentAI()
{
    if (matrixinit == false) {
        for (int a = 0; a < 20; a = a +1) {
            for (int b = 0; b < 20; b = b +1) {
                for (int c = 0; c < 4; c = c +1) {
                    tracker[a][b][c]= 1;
                }
            }
        }
        matrixinit = true;
    }
    //int x = 0;
    //int y = 0;
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
 if tracker[x][0][
*/


//count is to keep track of how many left turns are made consecutively
        if (!isWallRight() && direction==0 && (!tracker[xx][yy][1]==0)) {
            reverse = false;
            direction = 1;
            tracker[xx][yy][1]++;
            xx=xx+1;
            turnRight();
            moveForward();
            count = 0; //if there was a left turn followed by this, count will be set to 0 again, since it's a consecutive left turn isn't possible
            void printUI(const char *turnright);
        }
        else if (!isWallRight() && direction==1 && (!tracker[xx][yy][2]==0)) {
            reverse = false;
            direction = 2;
            tracker[xx][yy][2]++;
            yy=yy-1;
            turnRight();
            moveForward();
            count = 0;
            void printUI(const char *turnright);
        }
        else if (!isWallRight() && direction==2 && (!tracker[xx][yy][3]==0)) {
            reverse = false;
            direction= 3;
            tracker[xx][yy][3]++;
            xx=xx-1;
            turnRight();
            moveForward();
            count = 0;
            void printUI(const char *turnright);
        }
        else if (!isWallRight() && direction == 3 && (!tracker[xx][yy][0]==0)) {
            reverse = false;
            direction = 0;
            tracker[xx][yy][0]++;
            yy=yy+1;
            turnRight();
            moveForward();
            count = 0;
            void printUI(const char *turnright);
        }


        else if (!isWallForward() && direction==0 && (!tracker[xx][yy][0]==0)) {
            if (reverse == true && isWallLeft()) {
                tracker[xx][yy][ (direction + 2) % 4]=0;
            }
            else {
                tracker[xx][yy][0]++;
            }
            yy=yy+1;
            moveForward();
            count = 0; //if there was a left turn followed by this, count will be set to 0 again, since it's a consecutive left turn isn't possible
            void printUI (const char *moveforward);
        }
        else if (!isWallForward() && direction==1 && (!tracker[xx][yy][1]==0)) {
            if (reverse == true && isWallLeft()) {
                tracker[xx][yy][ (direction + 2) % 4]=0;
            }
            else {
                tracker[xx][yy][1]++;
            }
            xx=xx+1;
            moveForward();
            count = 0;
            void printUI (const char *moveforward);
        }
        else if (!isWallForward() && direction==2 && (!tracker[xx][yy][2]==0)) {
            if (reverse == true && isWallLeft()) {
                tracker[xx][yy][ (direction + 2) % 4]=0;
            }
            else {
                tracker[xx][yy][2]++;
            }
            yy=yy-1;
            moveForward();
            count = 0;
            void printUI (const char *moveforward);
        }
        else if (!isWallForward() && direction == 3 && (!tracker[xx][yy][3]==0)) {
            if (reverse == true && isWallLeft()) {
                tracker[xx][yy][ (direction + 2) % 4]=0;
            }
            else {
                tracker[xx][yy][3]++;
            }
            xx=xx-1;
            moveForward();
            count = 0;
            void printUI (const char *moveforward);
        }

        else if (!isWallLeft() && direction==0 && (!tracker[xx][yy][3]==0)) {
            reverse == false;
            direction = 3;
            tracker[xx][yy][3]++;
            xx=xx-1;
            turnLeft();
            moveForward();
            count++;
            void printUI (const char *turnleft);
        }
        else if (!isWallLeft() && direction==1 && (!tracker[xx][yy][0]==0)) {
            reverse == false;
            direction = 0;
            tracker[xx][yy][0]++;
            yy=yy+1;
            turnLeft();
            moveForward();
            count++;
            void printUI (const char *turnleft);
        }
        else if (!isWallLeft() && direction==2 && (!tracker[xx][yy][1]==0)) {
            reverse == false;
            direction= 1;
            tracker[xx][yy][1]++;
            xx=xx+1;
            turnLeft();
            moveForward();
            count++;
            void printUI (const char *turnleft);
        }
        else if (!isWallLeft() && direction == 3 && (!tracker[xx][yy][2]==0)) {
            reverse == false;
            direction = 2;
            tracker[xx][yy][2]++;
            yy=yy-1;
            turnLeft();
            moveForward();
            count++;
            void printUI (const char *turnleft);
        }
    else {
        //if front, right, and left have walls, the mouse can do a uturn, to face the opposite direction
        tracker[xx][yy][direction]=0;
        if (direction == 0) {
            yy = yy-1;
        }
        if (direction == 1) {
            xx = xx-1;
        }
        if (direction == 2) {
            yy = yy+1;
        }
        if (direction == 3) {
            xx = xx+1;
        }
        turnRight();
        turnRight();
        moveForward();
        direction = (direction+2) % 4;
        reverse = true;
    }
    if (count==3) {
        //when the mouse makes three left turns that designates the end of the maze since it's the only part which is two by two
        void foundFinish();
        exit(0);
    }
}

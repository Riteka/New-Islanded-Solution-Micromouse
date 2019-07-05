
#include "micromouseserver.h"
static int count = 0;
static int tracker[20][20][4];
static int direction= 0 ;
static int matrixinit = false;



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
    int x = 0;
    int y = 0;
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
        if (!isWallRight() && direction==0 && (!tracker[x][y][1]==0)) {
            direction = 1;
            tracker[x][y][1]++;
            x=x+1;
            turnRight();
            moveForward();
            count = 0; //if there was a left turn followed by this, count will be set to 0 again, since it's a consecutive left turn isn't possible
            void printUI(const char *turnright);
        }
        else if (!isWallRight() && direction==1 && (!tracker[x][y][2]==0)) {
            direction = 2;
            tracker[x][y][2]++;
            y=y-1;
            turnRight();
            moveForward();
            count = 0;
            void printUI(const char *turnright);
        }
        else if (!isWallRight() && direction==2 && (!tracker[x][y][3]==0)) {
            direction= 3;
            tracker[x][y][3]++;
            x=x-1;
            turnRight();
            moveForward();
            count = 0;
            void printUI(const char *turnright);
        }
        else if (!isWallRight() && direction == 3 && (!tracker[x][y][0]==0)) {
            direction = 0;
            tracker[x][y][0]++;
            y=y+1;
            turnRight();
            moveForward();
            count = 0;
            void printUI(const char *turnright);
        }


        else if (!isWallForward() && direction==0 && (!tracker[x][y][0]==0)) {
            tracker[x][y][0]++;
            y=y+1;
            moveForward();
            count = 0; //if there was a left turn followed by this, count will be set to 0 again, since it's a consecutive left turn isn't possible
            void printUI (const char *moveforward);
        }
        else if (!isWallForward() && direction==1 && (!tracker[x][y][1]==0)) {
            tracker[x][y][1]++;
            x=x+1;
            moveForward();
            count = 0;
            void printUI (const char *moveforward);
        }
        else if (!isWallForward() && direction==2 && (!tracker[x][y][2]==0)) {
            tracker[x][y][2]++;
            y=y-1;
            moveForward();
            count = 0;
            void printUI (const char *moveforward);
        }
        else if (!isWallForward() && direction == 3 && (!tracker[x][y][3]==0)) {
            tracker[x][y][3]++;
            x=x-1;
            moveForward();
            count = 0;
            void printUI (const char *moveforward);
        }

        else if (!isWallLeft() && direction==0 && (!tracker[x][y][3]==0)) {
            direction = 3;
            tracker[x][y][3]++;
            x=x-1;
            turnLeft();
            moveForward();
            count++;
            void printUI (const char *turnleft);
        }
        else if (!isWallLeft() && direction==1 && (!tracker[x][y][0]==0)) {
            direction = 0;
            tracker[x][y][0]++;
            y=y+1;
            turnLeft();
            moveForward();
            count++;
            void printUI (const char *turnleft);
        }
        else if (!isWallLeft() && direction==2 && (!tracker[x][y][1]==0)) {
            direction= 1;
            tracker[x][y][1]++;
            x=x+1;
            turnLeft();
            moveForward();
            count++;
            void printUI (const char *turnleft);
        }
        else if (!isWallLeft() && direction == 3 && (!tracker[x][y][2]==0)) {
            direction = 2;
            tracker[x][y][2]++;
            y=y-1;
            turnLeft();
            moveForward();
            count++;
            void printUI (const char *turnleft);
        }
    else {
        //if front, right, and left have walls, the mouse can do a uturn, to face the opposite direction
        /* tracker[x][y][direction]=0;
        if (direction == 0) {
            y = y-1;
        }
        if (direction == 1) {
            x = x-1;
        }
        if (direction == 2) {
            y = y+1;
        }
        if (direction == 3) {
            x = x+1;
        }
        turnRight();
        turnRight();
        moveForward();
        direction = (direction+2) % 4;
        //while (isWallRight() && isWallLeft()) {

        //   moveForward();
        //} */
        turnRight();
        turnRight();
        moveForward();
    }
    if (count==3) {
        //when the mouse makes three left turns that designates the end of the maze since it's the only part which is two by two
        void foundFinish();
        exit(0);
    }
}

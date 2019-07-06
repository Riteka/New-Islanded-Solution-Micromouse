
#include "micromouseserver.h"
static int count = 0;
static int tracker[20][20][4];
static int direction= 0 ;
static int matrixinit = false;
static int xx = 0;
static int yy = 0;

void microMouseServer::updateXY(int &x, int &y, int newDir) {
    switch(newDir) {
        case 0 : y++; break;
        case 1 : x++; break;
        case 2 : y=y-1; break;
        case 3: x=x-1; break;
    }
}
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

    bool rightPreferred = true;
    bool leftPreferred = true;
    bool forwardPreferred = true;

    int rightDir = (direction + 1) % 4;
    int leftDir = (direction + 3) % 4;
    int forwardDir = direction;
    int reverseDir = (direction + 2) % 4;


    if (isWallRight()) {
        rightPreferred = false;
    }
    if (isWallLeft()) {
        leftPreferred = false;
    }
    if (isWallForward()) {
        forwardPreferred = false ;
    }

    if (rightPreferred && forwardPreferred) {
        if (tracker[xx][yy][forwardDir] < tracker[xx][yy][rightDir]) {
            rightPreferred = false;
        }
        else {
            forwardPreferred = false;
        }
    }

    if (leftPreferred == true) {
        if (rightPreferred) {
            if (tracker[xx][yy][leftDir] < tracker[xx][yy][rightDir]) {
                rightPreferred = false;
            }
            else {
                leftPreferred = false;
            }
        }
        if (forwardPreferred) {
            if (tracker[xx][yy][leftDir] < tracker[xx][yy][forwardDir]) {
                forwardPreferred = false;
            }
            else {
                leftPreferred = false;
            }
        }
    }


    if (!isWallRight() && rightPreferred) {
        count = 0;
        tracker[xx][yy][rightDir]++;
        updateXY(xx, yy, rightDir);
        turnRight();
        moveForward();
        direction = rightDir;
    }
    else if (!isWallForward() && forwardPreferred) {
        count = 0;
        tracker[xx][yy][forwardDir]++;
        updateXY(xx, yy, forwardDir);
        moveForward();
        direction = forwardDir;
    }
    else if (!isWallLeft() && leftPreferred) {
        count++;
        tracker[xx][yy][leftDir]++;
        updateXY(xx, yy, leftDir);
        turnLeft();
        moveForward();
        direction = leftDir;
    }
    else {
        count = 0;
        turnRight();
        turnRight();
        tracker[xx][yy][reverseDir]++;
        updateXY(xx, yy, reverseDir);
        moveForward();
        direction = reverseDir;
    }

    if (count==3) {
        //when the mouse makes three left turns that designates the end of the maze since it's the only part which is two by two
        foundFinish();
    }

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



}

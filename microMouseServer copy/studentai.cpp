
#include "micromouseserver.h"
static int count = 0;
static int tracker[20][20][4];
static int direction= 0 ;
static int matrixinit = false;
static int xx = 0;
static int yy = 0;

void microMouseServer::updateXY(int &x, int &y, int newDir) {
//  changes x-coordinate or y-coordinate based on the direction the mouse faces after turning or moving forward
    switch(newDir) {
        case 0 : y++; break;    //  if the direction of the new position is north, then the previous y-coordinate is increased by one
        case 1 : x++; break;    //  if the direction of the new position is east, then the previous x-coordinate is increased by one
        case 2 : y=y-1; break;  //  if the direction of the new position is south, then the previous y-coordinate is decreased by one
        case 3: x=x-1; break;   //  if the direction of the new position is west, then the previous x-coordinate is decreased by one
    }
}
void microMouseServer::studentAI()
{
/*  the following initializes all the cells of the 20-20-4 matrix with the starting value of 1; intialized to 1 because originally had a
    plan to change cell values to 0 to block them when backtracking after reverse */
    if (matrixinit == false) {
        for (int a = 0; a < 20; a = a +1) {
            for (int b = 0; b < 20; b = b +1) {
                for (int c = 0; c < 4; c = c +1) {
                    tracker[a][b][c]= 1;
                }
            }
        }
        matrixinit = true;  //  this is added so that the matrix is not reset every single time program loops
    }
//  all the variables are intialized to true but will later be cleared out, so that only one remains or none remains (will make u-turn)
    bool rightPreferred = true;
    bool leftPreferred = true;
    bool forwardPreferred = true;

    int rightDir = (direction + 1) % 4;     // the new direction the mouse is facing after making a right turn
    int leftDir = (direction + 3) % 4;      // the new direction the mouse is facing after making a left turn
    int forwardDir = direction;             // moving forward does not change the direction of the mouse, but this variable is there for consistency
    int reverseDir = (direction + 2) % 4;   // the new direction after the mouse makes a u-turn (the opposite of the original direction)

//  presence of wall: if there is a wall in that direction, the mouse will not be able to move there, so the preference will be false
    if (isWallRight()) {
        rightPreferred = false;

    }
    if (isWallLeft()) {
        leftPreferred = false;
    }
    if (isWallForward()) {
        forwardPreferred = false ;
    }

/*
   exit value count: the mouse turns in the direction in which it has traveled less; if the mouse has traveled equally in all directions,
   turning right takes priority, then moving forward, and then turning left.
*/
    if (rightPreferred && forwardPreferred) {
        if (tracker[xx][yy][forwardDir] < tracker[xx][yy][rightDir]) {
            rightPreferred = false;     //if the # of times moving forward is less than turning right, moving forward will take priority
        }
        else {
            forwardPreferred = false;   //if the # of times moving forward and turning right are equal or if the # of times moving forward is greater, turning right will take priority
        }
    }
    if (leftPreferred == true) {
        if (rightPreferred) {
            if (tracker[xx][yy][leftDir] < tracker[xx][yy][rightDir]) {
                rightPreferred = false; //if the # of times moving left is less than turning right, turning left will take priority
            }
            else {
                leftPreferred = false;  //if the # of times turning left and turning right are equal or if the # of times turning left is greater, turning right will take priority
            }
        }
        if (forwardPreferred) {
            if (tracker[xx][yy][leftDir] < tracker[xx][yy][forwardDir]) {
                forwardPreferred = false;//if the # of times moving left is less than moving forward, turning left will take priority
            }
            else {
                leftPreferred = false;  //if the # of times turning left and moving forward are equal or if the # of times turning left is greater, moving forward will take priority
            }
        }
    }

/*
    the following performs the actual moving and turning, increases the # of times the mouse leaves a cell in a specific direction, changes
    the x and y coordinates correspondingly, updates the direction the mouse is facing, and tracks if the mouse has reached the end or not.

    the variable count is to keep track of how many left turns are made consecutively
*/
    if (!isWallRight() && rightPreferred) {
        count = 0;
        tracker[xx][yy][rightDir]++;    //increments the # of times the mouse exits in that direction
        updateXY(xx, yy, rightDir);     //changes the x or y coordinate using the created function
        turnRight();
        moveForward();
        direction = rightDir;  //updates the direction
        printUI ("turn right");
    }
    else if (!isWallForward() && forwardPreferred) {
        count = 0;
        tracker[xx][yy][forwardDir]++;
        updateXY(xx, yy, forwardDir);
        moveForward();
        direction = forwardDir;
        printUI ("move forward");
    }
    else if (!isWallLeft() && leftPreferred) {
        count++;
        tracker[xx][yy][leftDir]++;
        updateXY(xx, yy, leftDir);
        turnLeft();
        moveForward();
        direction = leftDir;
        printUI ("turn left");
    }
    else {
        //  for making a u-turn after reaching a dead-end
        count = 0;
        turnRight();
        turnRight();
        tracker[xx][yy][reverseDir]++;
        updateXY(xx, yy, reverseDir);
        moveForward();
        direction = reverseDir;
        printUI ("u-turn");
    }

    if (count==3) {
        //  when the mouse makes three left turns, that designates the end of the maze since it's the only part which is two by two
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

}

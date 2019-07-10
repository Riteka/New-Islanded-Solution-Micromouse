# New-Islanded-Solution-Micromouse


The idea behind the solution was to move in the direction that is least traveled from the present cell, while also implementing the right-hand rule in the case where some directions are traveled equally. Ideally, at some point, the mouse will be able to reach the goal through this method. 



ACTUAL IMPLEMENTATION:
- initialized the [20][20][4] matrix with its cells filled with 1's (thinking that 0's can be used in case to block cells);     chose a three-dimensional matrix so that it is easier to keep track of all the values in one place, and since the directions   have an effect on the coordinates
    - the first dimension represents the x-coordinate, the second represents the y-coordinate, the third dimension represents       the direction the mouse exits the cell
        - directions: 0 is north, 1 is east, 2 is south, 3 is west
- updating the direction of the mouse and its coordinates
    - created a function that based on the entry direction and turning left, right, forward, or reverse, it changes either the       x or y coordinate the mouse is facing (north: increments y, east: increments x, south: decrements y, west: decrements x)
    - based on the mouse's form of movement (right, left, reverse), the direction will be changed
- intialized three variables (rightPreferred, forwardPreferred, leftPreferred) to true, which will be later cleared out so       that only one direction is preferred or none of the directions is preferred (will perform a u-turn)
    - if there is a wall in that specific direction, the value of var is set to false
    - in the case where the mouse traveled equally in the three directions from the cell, it will follow the right-handrule,         taking priority as follows: turn right, move forward, turn left
    - if there are walls in all three directions, it will make a u-turn
- the end is defined by a two-by-two cell, so when the mouse makes three consecutive left turns, the program knows that it has reached the end of the maze


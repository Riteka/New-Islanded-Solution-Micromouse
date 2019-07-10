# New-Islanded-Solution-Micromouse


The idea behind the solution was to move in the direction that is least traveled from the present cell, while also implementing the right-hand rule in the case where some directions are traveled equally. Ideally, at some point, the mouse will be able to reach the goal through this method. 



INITIALIZATION:
- initialized the cells of [20][20][4] matrix with 1's (thinking that 0's can be used in case to block cells);     chose a three-dimensional matrix so that it is easier to keep track of all the values in one place, and since direction has an effect on the x or y coordinates
    - the first dimension represents the x-coordinate, the second represents the y-coordinate, the third dimension represents       the direction the mouse exits the cell
        - for each cell, there are four possible exit directions that are denoted by the third dimension of the matrix
                 - directions: 0 is north, 1 is east, 2 is south, 3 is west
                 - in the case where the cell borders a wall or is located on the edge of the maze, the mouse will never be
                 able to exit in that direction, leaving count as 1 (from initialization) for that exit direction
- initialized a variable representing the starting direction to 0, since the mouse starts off facing north
- initialized the starting x value to 0 and the starting y value to 0
- initialized the number of consecutive left turns to 0 (this value is used to determine the if mouse has reached end of maze)


ACTUAL IMPLEMENTATION:
- updating the direction of the mouse and its coordinates
    - created a function that based on the entry direction of the mouse into the new cell, it updates either the x or y coordinate; (north: increments y, east: increments x, south: decrements y, west: decrements x)
    - based on the mouse's form of movement (right, left, reverse), the direction will be changed
    
- intialized three variables (rightPreferred, forwardPreferred, leftPreferred) to true, which will be later cleared out so    that only one direction is preferred or none of the directions is preferred (will perform a u-turn)
    - if there is a wall in that specific direction, the value of variable is set to false; if there are walls in all three directions, it will make a u-turn
    - in the case where the mouse arrives at a cell and recognizes that it has previously traveled equally in the three  directions from the cell, it will follow the right-handrule, taking priority as follows: turn right (if there is also no wall on the right), move forward (if there is a wall on the right, but no wall in front), turn left (if there is a wall on the right and in front, but there is no wall on the left), makes a u-turn (if there is a wall on the right, in front, and on the left)
            - if for a specific xy pair (specific cell), matrix[x][y][0], matrix[x][y][1], matrix[x][y][2], matrix[x][y][3] are equal, then 
              the right hand-rule is followed; the starting cell's count for the direction the mouse exits in is also increased, the
              direction is changed to the new direction the mouse is facing, and this new direction, which is also the entry 
              direction for the cell that the mouse enters, will be used to update the x or y coordinate accordingly
    - otherwise, it will exit in the direction that is least traveled, respective to the current cell
            - if matrix[x][y][0]<matrix[x][y][1], matrix[x][y][0]<matrix[x][y][2], and matrix[x][y][0]<matrix[x][y][3], since the mouse
              has exited the least to the north (0), the mouse will exit north, and the program will also increment the exit count  
              for north in the cell it moves out of (matrix[x][y][0]++); only after that, the program will change the direction to 
              the new direction that the mouse is facing, and this new direction, which is also the entry direction for the new cell, 
              will be used to update the x or the y coordinate accordingly
              
- the end is defined by a two-by-two cell, so when the mouse makes three consecutive left turns, the program knows that it has reached the end of the maze


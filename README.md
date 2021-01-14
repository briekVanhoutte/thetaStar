# thetaStar
this is a simple implementation of the [theta*](https://en.wikipedia.org/wiki/Theta*)

## preview
![path preview](https://i.imgur.com/7J6grY2.png)

## world setup
###  Walls
the walls are randomly generated in Grid::GenerateWalls simpler randomization without ever 2 walls next to each other to prevent from having the walls goe fully around the start or end point

### tile setup
the size of the grid can be changed in Program.h::m_AmountOfNodes this only changes the size of one square to always fit in the screen

### start and endpoint
in the constructor of World you should see a 2 randomized variables randActorPos and randDestPos comment or delete these and in the variables actorPos and destPos respectively put the number of the tile you want to use as start and endpoint

## using the main file in another project
If you want to use this main file in another project you need to add in the properties from your solution
on the top of the page put configuration on all and platform on win32
in c/c++ Additional Include directories add $(projectDir)include
in Linker/general additional library directories add $(ProjectDir)lib-vc2019
in Linker/input additional dependencies add glfw3.lib;opengl32.lib;user32.lib;gdi32.lib;shell32.lib

## the solver algorithm
a theta* algorithm is basicly the same as a a* algorithm the only difference is that in the theta* algorithm a parent of a node should not be a neighbor if the node has line of sight that is enough

the advantage to this is that if you want to go diagonal it would be faster

# Development Log

#### 4/9/19
- Began exploring various libraries in openFrameworks such as the 3D graphics library and openCV computer vision library.
- Read about openFrameworks such as how it works and brainstormed on what I wanted to do and worked on the proposal.
- Time spent: 3.5 hours.

#### 4/10/19
- Read more about openFrameworks, including reading couple of the sections of their official online book.
- Played around openFrameworks, including trying some of their drawing functions and doing a little bit of animation.
- Successfully compiled openFramework's example application for the openCV library. Studied the code.
- Time spent: 3 hours.

#### 4/13/19
- Read about using the openCV library, including color recognition.
- Integrated webcam.
- Was able to get pixel color of a Rubik's Cube and neatly print it on the screen.
- Was able to calculate the average RGB values from a square area of the screen.
- Struggling with finding the best way to calculate the color difference/closeness. Looked at several methods online, such as comparing in HSL instead of RGB.
- Time spent: 7 hours

#### 4/16/19
- Began implementing color difference function.
- Time spent: 1 hour

#### 4/21/19
- Complete color difference function and write estimate color function using the color difference function.
- Time spent: 1 hour

#### 4/22/19
- The estimation of Rubik's Cube colors work. 
- Differentiating red and orange is still a little iffy.
- Implement ability to print the sides of the cube. Need to work on neatly printing them in corresponding locations.
- Time spent: 3 hours

### 4/24/19
- Able to get the cubes to print neatly when user presses a key.
- Added additional details to the visual such as a cube grid.
- Spent a long time trying to debug my reset functionality, but couldn't find the reason why it wasn't working.
- Time spent: 3 hours

### 4/30/19
- Browsed through several C++ Rubik's Cube solving programs, but was unable to find an optimal and easy to use program.
- A lot of the solving programs were in other programming languages.
- Many had little to no documentation, so it was difficult to figure out how I was supposed to use the program and input a state of the cube.
- Many also didn't compile successfully.
- I will continue to try and find a solving library.
- Time spent: 3 hours

### 5/1/19
- Decided to use a widely used, reliable, and optimal solving library that uses Kociemba's algorithm, but the catch is that it is written in C.
- The challenge will be integrating C code with C++.
- Took a while, but was able to successfully compile and run the solver.
- Time spent: 
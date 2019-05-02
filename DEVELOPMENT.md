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

#### 4/24/19
- Able to get the cubes to print neatly when user presses a key.
- Added additional details to the visual such as a cube grid.
- Spent a long time trying to debug my reset functionality, but couldn't find the reason why it wasn't working.
- Time spent: 3 hours

#### 4/30/19
- Browsed through several C++ Rubik's Cube solving programs, but was unable to find an optimal and easy to use program.
- A lot of the solving programs were in other programming languages.
- Many had little to no documentation, so it was difficult to figure out how I was supposed to use the program and input a state of the cube.
- Many also didn't compile successfully.
- I will continue to try and find a solving library.
- Time spent: 3 hours

#### 5/1/19
- Decided to use a widely used, reliable, and optimal solving library from GitHub that uses Kociemba's algorithm, but the catch is that it is written in C.
- The challenge will be integrating C code with C++.
- Was able to successfully compile and run the solving program on the command line, but took me a while to figure out due to not having experience with make files.
- First, I tried to integrate the Kociemba program by using system calls, which is a way to run an executable within a C++ program. Ran into a bunch of issues and challenges. Spent 3 hours trying to debug it until giving up.
- I decided to try and actually integrate the C source code into my project. Ran into a bunch of errors and challenges again. Needed to use some special syntax for calling C functions in C++ code (extern "C"). Still ran into bunch of problems and after hours of debugging and reading Stack Overflow, I fianlly figured out that it was Visual Studio's fault. It was automatically compiling the C files as C++ files and I had to dig deeply through settings to change the compiler option. 
- Definitely a painful night, but I'm glad it's working. Next step is outputting the solution based on the scanned cube.

- Was able to input the scramble state from the scanned cube to the solving algorithm. Successfully displays the solution to the screen!
- Fixed the reset function.
- Made small tweaks to optimize the program.
- Completed testing.
- Initial README file written.
- Project done at 11:55 PM!
- Time spent: 13 hours
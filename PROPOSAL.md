# Project Proposal

I currently have two ideas for the final project, both which involves the Rubik's Cube due to my interest in it.

My first idea is to make a fully functional 3x3 Rubik's Cube. Each turn of the cube will correspond to a letter on the keyboard in which the user can turn the cube by hitting a keystroke. Once I have a fully functioning cube, I would like to add additional implementations to my program, such as a timer for solving it and the ability to automatically scramble the cube. I plan to use the 3D graphics library from openFrameworks to draw the cube. 

My second idea is to implement a Rubik's Cube solver. The program would use the camera to scan the six sides of the cube and recognize the colors. Based on the colors, the program would generate a solution to the cube. In order to recognize the colors of the cube, I would use the ofxOpenCv library, which is the computer vision library. However, I probably will not code the solving algorithm myself and instead, use a solving library.

I think I have a good enough background on how the Rubik's Cube works and I have an idea on how I want to structure my code to represent the Rubik's Cube.

### Update

I have decided to go with my second idea of implementing a Rubik's Cube solver using ofxOpenCv. After messing around with an example application using ofxOpenCv, I became quite intrigued with computer vision. The idea of using the webcam for my program seemed like a completely new programming experience and I wanted to try something new and challenging.
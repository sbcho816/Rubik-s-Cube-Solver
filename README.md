# Rubik's Cube Solver
Program that recognizes the colors of the Rubik's Cube through the webcam and outputs the solution. Developed using the OpenCV library. 

### Running the Program
1. Install [openFrameworks](https://openframeworks.cc/).
2. Clone this repository.
3. Run the openFrameworks project generator.
4. From the project generator, import the cloned repository and add the ofxOpenCv addon.
5. The program can now be run using an IDE.

### Using the Program
- Position the Rubik's Cube so that each of the 9 green reference squares lies on a sticker of the cube as shown below.
![screenshot_1](https://github.com/uiuc-sp19-cs126/final-project-scho93/blob/master/images/screenshot_1.PNG)
- The program will show two real-time images of the cube face on the top left. The left image shows the estimated colors. The right image shows the actual colors detected by the webcam.
- Press `space` to scan a side of the cube.
- In order for the program to correctly save the state of the cube, the cube must be scanned in the following order:
    1. Scan green center with white center on top.
	2. Scan red center with white center on top.
	3. Scan blue center with white center on top.
	4. Scan orange center with white center on top.
	5. Scan yellow center with green center on top.
	6. Scan white center with blue center on top.
- After each scan, the scanned side will be displayed on the lower left of the screen. The photo below shows the white center being scanned.
![screenshot_2](https://github.com/uiuc-sp19-cs126/final-project-scho93/blob/master/images/screenshot_2.PNG)
- Press `s` to output the solution to the Rubik's Cube.
- The solution to the cube will be outputted in [Singmaster notation](https://proofwiki.org/wiki/Definition:Singmaster_Notation) as shown below.
![screenshot_3](https://github.com/uiuc-sp19-cs126/final-project-scho93/blob/master/images/screenshot_3.PNG)
- Apply the moves with green center facing you and white center on top and the cube will be solved.
- Press `r` to reset.

### Note
- Due to factors such as webcam quality, lighting of the environment, and different color shades of different Rubik's Cubes, the color estimation algorithm may not be 100% accurate.
- For best results, use the program	at a place with good lighting.
- Changing the angle of the webcam depending on lighting will improve color detection.

### Acknowledgments
- Kociemba's solving algorithm is taken from https://github.com/muodov/kociemba.
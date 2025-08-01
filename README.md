# microcontroller-media-center
A microcontroller media center built on the ARM Cortex-M3 (MCB1700) in C. Displays 320x240 BMP images, streams 44.1 kHz audio via USB with &lt;50ms latency, and runs a 30 FPS playable game

# Methodology
In general, for each element of the media center, there is a separate .c file that runs the main logic for it. In some cases there are more than one .c files, but the main idea is that the features are implemented separately. In order to navigate the program from one place to another, a function is called that initiates the code that runs the next element. Implementing the code this way allows for more readability and ease in programming the project since it is more modular. One aspect of the project can be changed without affecting the other parts.

![Image](https://github.com/muizzkhan0/microcontroller-media-center/blob/main/readme-images/diagram.jpg?raw=true)

# Design
## Main Menu
The main menu consists of a title and the three options for selecting the photo gallery, mp3 player and game. Moving the joystick up or down moves between the selections. The option being currently selected is highlighted in blue. Selecting an option using the joystick takes the user to the next screen.

![Image](https://github.com/muizzkhan0/microcontroller-media-center/blob/main/readme-images/main%20menu.png?raw=true)

## Photo Gallery
Launching the photo gallery presents the user to select one of four photo options. Similar to the main menu, the currently selected photo is highlighted in blue. Using the joystick to select a photo takes the user to a new screen where the photo is displayed with a title describing the photo. Moving the joystick to the left in any screen takes the user to the previous screen.
Photo 1 is a picture of Mario, Photo 2 is a picture of the Maple Leafs logo, Photo 3 is a picture of the Toronto Raptors logo and Photo 4 is a picture of the Blue Jays logo. Each photo has been scaled down to fit the LCD in an appropriate fashion.

![Image](https://github.com/muizzkhan0/microcontroller-media-center/blob/main/readme-images/photo%20gallery.png?raw=true)

![Image](https://github.com/muizzkhan0/microcontroller-media-center/blob/main/readme-images/raptors%20logo.png?raw=true)

## MP3 Player

Selecting the MP3 player takes the user to a splash screen indicating to the user that the audio is streaming. Moving the joystick to the left takes the user back to the main menu.

![Image](https://github.com/muizzkhan0/microcontroller-media-center/blob/main/readme-images/audio%20streaming.png?raw=true)

## Game
Selecting the game takes the user to a screen that displays the game’s controls and scoring. The user can then press select on the joystick to start the game.
The game consists of a black player that the player can control in any direction using the joystick. Red obstacles move across the screen from right to left which the play must dodge. Colliding with any object ends the game. Dodging obstacles grants the player one point. As the game progresses, more obstacles are added and the game speeds up.
Once the game ends the player is presented with a game over screen that displays their final score. The player can then press select on the joystick to return to the main menu.

![Image](https://github.com/muizzkhan0/microcontroller-media-center/blob/main/readme-images/game%20menu.png?raw=true)

![Image](https://github.com/muizzkhan0/microcontroller-media-center/blob/main/readme-images/game.png?raw=true)

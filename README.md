# microcontroller-media-center
A microcontroller media center built on the ARM Cortex-M3 (MCB1700) in C. Displays 320x240 BMP images, streams 44.1 kHz audio via USB with &lt;50ms latency, and runs a 30 FPS playable game

# Methodology
In general, for each element of the media center, there is a separate .c file that runs the main logic for it. In some cases there are more than one .c files, but the main idea is that the features are implemented separately. In order to navigate the program from one place to another, a function is called that initiates the code that runs the next element. Implementing the code this way allows for more readability and ease in programming the project since it is more modular. One aspect of the project can be changed without affecting the other parts.

![Image](https://github.com/user-attachments/assets/eb139752-c8c2-44e0-854b-05020d1df1d8)

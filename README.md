# Mall Drawing

Drawing a multi-storey mall, inside and outside environment with moving ability using OpenGL in C++.

Me and my teammate have done this work based on legacy OpenGL, starting from the basic drawing functions presented  The project was built and tested using Visual Studio 2022.

We included textures, models, lighting and a simple logic for moving to seem rather realistic. Before drawing anything, we created a general class `Draw` that has a set of functions which are responsible for drawing all important primitive shapes that any complix object may made from. These functions accept position, lengths, lighting normal direction, texture and texture mapping as parameters. This is very helpful during drawing the environment as a kind of abstraction. Repeatedly drawn objects were also arranged in functions so that they become easier to be drawn.

## What was drawn? 
The mall consists of two floors and two other underground floors, with a small garden and a street arround.
The first and second floors contain clothes markets, whereas, the first basement contain resturants and the second one is a car parking.
You can move between the floors in three ways :
- Normal stairs: your height is automatically fixed while moving on them.
- Electric stairs: for carrying up and down.
- Elevators: by standing inside and press buttons.

## Screenshots


## Control
For moving:
- **W:** forward
- **S:** backward
- **A:** left
- **D:** right
- **Upwards Arrow ↑:** up
- **Downwards Arrow ↓:** down

- **Mouse** is used for yaw rotating.

- **E:** move elevators up
- **Q:** move elevators down
- **T:** switch between first person (FP) and third person (TP) perspectives
- **N:** switch between day and night modes

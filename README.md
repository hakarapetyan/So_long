# 🎮 So Long: A Small 2D Journey

### 📖 Project Overview
So Long is a basic 2D game designed to introduce the fundamentals of computer graphics. The goal is to create a simple "top-down" game where a player collects items and reaches an exit while navigating a map.

Through this project, I explored:

Window Management: Opening and controlling a graphical window.

Event Handling: Responding to keyboard inputs (WASD) and mouse clicks.

Sprite Rendering: Drawing tiles, characters, and collectibles using textures.

Map Parsing: Reading and validating game levels from .ber files.

### 🕹️ Gameplay Rules
The game follows a simple set of mechanics:

The Goal: Collect every item (C) on the map and then reach the exit (E).

Movement: Use the W, A, S, and D keys to move up, down, left, and right.

Walls: You cannot walk through walls (1).

Step Counter: Every time you move, the total number of steps is displayed in the terminal.

### 🗺️ The Map System
The game levels are loaded from .ber files. These files use a grid of characters to define the world:

1: Wall

0: Empty Space

P: Player Starting Position

C: Collectible

E: Map Exit

Map Validation
A map is only valid if:
It is rectangular and surrounded by walls.
It contains exactly one starting position, exactly one exit, and at least one collectible.
There is a valid path (the player must be able to actually reach the exit and all collectibles).

### ⚙️ Technical Details
Graphics Library: Built using MiniLibX, a simple X-Window graphical library.

Language: Written in C following the Norm coding standard.

Memory: Strict management of heap memory to ensure zero leaks when the window is closed.

Error Handling: If the map file is invalid or a file is missing, the program exits cleanly with a helpful error message.

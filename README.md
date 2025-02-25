# Cub3D

## Overview
Cub3D is a project developed as part of the 42 school curriculum. It is a simple raycasting engine inspired by the classic game Wolfenstein 3D, written in C using the MiniLibX library. The goal of this project is to create a basic 3D game engine with a first-person perspective.

## Features
- Raycasting algorithm for 3D rendering
- Basic player movement (forward, backward, left, right)
- Rotation of the player's view
- Wall collision detection
- Textured walls
- Configurable map using a simple `.cub` file

### Build
Clone the repository and compile the project:
```bash
git clone <repository-url>
cd cub3d
make
```

## Usage
Run the program with a valid map file:
```bash
./cub3D maps/example.cub
```
### Controls
- `W` / `S`: Move forward / backward
- `A` / `D`: Move left / right
- `←` / `→`: Rotate view left / right
- `ESC`: Quit the game

## Map Configuration
Maps are described in `.cub` files. The format includes:
- **Resolution**: `R <width> <height>`
- **Textures**: `NO`, `SO`, `WE`, `EA` for walls
- **Colors**: `F` (floor), `C` (ceiling)
- **Map**: Defined with `1` for walls and `0` for empty space

Example:

NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
111111
100001
100001
111111


## Contributors
- hbutt
- hdelbecq




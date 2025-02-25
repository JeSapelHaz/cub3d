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
git clone https://github.com/JeSapelHaz/cub3d.git
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

- NO ./path_to_the_north_texture
- SO ./path_to_the_south_texture
- WE ./path_to_the_west_texture
- EA ./path_to_the_east_texture

- F 220,100,0
- C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
        1111111111111111111111111

## Contributors
- hbutt
- hdelbecq




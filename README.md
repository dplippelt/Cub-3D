# cub3D
A ray-casting 3D maze renderer implemented in C, built as part of the Codam (42 Network) curriculum. The engine renders a first-person view of a maze in real time using the miniLibX graphics library.

## Features
### Engine

- Ray-casting renderer with directional wall textures (North, South, East, West)
- Configurable floor and ceiling colors via `.cub` scene files
- Robust `.cub` file parser: validates textures, colors, map structure, and element ordering
- Map validation: wall enclosure, single player spawn, valid characters, correct door placement
- Continuous frame-based rendering loop (re-renders every frame, not just on input)
- FPS counter display (toggleable)

### Controls & Settings

- `WASD` to move, arrow keys to rotate
- Mouse look with focus-in/out tracking — cursor is hidden and re-centered while in focus
- Adjustable mouse sensitivity (`KP +` / `KP -`)  
- Adjustable field of view (`KP *` / `KP /`)
- `ESC` or window close button to exit cleanly

### Game

- Wall collisions
- Minimap (toggleable with `M`)
- Animated squirrel sprites
- Doors that open and close (`SPACE`)
- Custom maps can be added by creating your own .cub file and passing it as a parameter when starting cub3d


## Architecture
The program is structured as a two-phase pipeline: **parse** then **render**.

During the parse phase, the `.cub` file is read line by line using a custom `get_next_line`. The parser extracts texture paths and RGB floor/ceiling colors before locating the map block (which must come last). The map is then validated: wall enclosure is checked by copying the map with a border and flood-checking for gaps, player count is enforced to exactly one, and door placement is verified to be surrounded by walls on opposing sides.

Once parsing succeeds, the engine sets up an MLX window sized to fit the screen, initializes image buffers for the main view and minimap, loads wall textures from `.xpm` files, and registers event hooks for keyboard and mouse input. From there, `mlx_loop_hook` drives a continuous render loop. Every frame the engine updates player state based on held keys, computes frame time using `gettimeofday`, runs the DDA ray-caster across every screen column to determine wall hits, samples the correct texture pixel per column, draws the minimap, and renders animated sprites using a Z-buffer approach.

Mouse look captures `MotionNotify` events. When the window has focus the cursor is hidden and re-centered when it approaches the window edge, with the horizontal delta used to rotate the player's direction and camera plane vectors. Settings (mouse sensitivity, FOV) are adjusted in real time via numpad keys and displayed as on-screen text overlays.


## Usage
Requirements: `make`, `cc`, miniLibX dependencies (`libX11`, `libXext`, `libx11-dev`, `libxext-dev`, `libxfixes-dev`)
```
git clone git@github.com:dplippelt/Cub-3D.git
cd Cub-3D
make
./cub3D maps/config.cub    # or your own .cub file
```

### Scene file format (`.cub`)
```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm

F 70,8,8      # floor color (R,G,B)
C 40,40,40    # ceiling color (R,G,B)

111111
100N01
101001
111111
```
Map characters: `1` wall, `0` floor, `N`/`S`/`E`/`W` player spawn. The map must always be the last element in the file and must be fully enclosed by walls.

### Optional scene extensions
```
DO  ./path/to/door.xpm          # door texture
DOS ./path/to/door_side.xpm     # door side-wall texture
SQ0 ./path/to/sprite_0.xpm      # animated sprite frames (0–3)
SQ1 ./path/to/sprite_1.xpm
SQ2 ./path/to/sprite_2.xpm
SQ3 ./path/to/sprite_3.xpm
```
Map additions: `D` for a door, `C` for a sprite.

### Keybinds
| Key | Action |
|---|---|
| `W A S D` | Move |
| `← →` | Rotate |
| `Mouse` | Rotate (when window focused) |
| `SPACE` | Open/close door |
| `M` | Toggle minimap |
| `F` | Toggle FPS counter |
| `KP *` / `KP /` | Increase / decrease FOV |
| `KP +` / `KP -` | Increase / decrease mouse sensitivity |
| `KP 0` | Reset sensitivity to default |
| `ESC` | Quit |


## Notes
Mouse recentering requires native Linux. On WSL, the X compatibility layer silently ignores cursor warping, causing the mouse to drift without recentering.

## Team
[Dominique Lippelt](https://github.com/dplippelt) (parsing, minimap, mouse controls, settings system, frame-based rendering loop)  
[Takato Mitsuya](https://github.com/takato7) (ray-casting engine, texture rendering, wall collision, doors, sprites)

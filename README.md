# so_long

## 🧠 Objective
This project is part of the 42 core curriculum and aims to recreate a simple 2D game using a basic graphics library (`MiniLibX`), handling file input, real-time rendering, and user interaction in C.

It was developed using only the allowed standard C library and focuses on mastering:
- File I/O and map parsing
- Dynamic memory management
- Event-driven programming (keyboard input, window events)
- Graphics rendering via MiniLibX

## 🎮 Features
- Validates and parses `.ber` map files
- Renders a 2D tile-based world from the map (walls, player, collectibles, exit)
- Real-time keyboard controls (WASD or arrows) to move the player
- Detects win condition (all collectibles gathered, then exit reached)
- Displays movement count in the window

### Bonus Features (Partially Implemented)
- A patroling or static enemy that triggers **Game Over** on contact
- Movement counter displayed live in the game window

---

## ⚙️ Compilation

Make targets:
- make        - builds the game
- make clean  - removes object files
- make fclean - removes object files and the binary
- make re     - rebuilds everything

### Requirements:

MiniLibX (linked and compiled during build)

## 🚀 Usage
Basic execution:

```bash
./so_long test/big_map2.ber
```
> Where big_map2.ber is a valid map file. Several example maps can be found in the test/ folder.

Key controls:
- Arrow keys to move
- Window close button or ESC to exit

## 🧩 Challenges Faced
- Handling malformed maps (non-rectangular, invalid characters, missing items)
- Preventing memory leaks while dynamically loading map and images
- Managing graphical updates without screen flickering
- Displaying movement count without overwriting existing graphics
- Handling corner cases in player movement logic and enemy behavior

## ✅ Key Learnings & Solutions
- Learned how to structure a simple tile-based rendering engine using MiniLibX
- Designed modular components: map parser, game state, input handler, and renderer
- Implemented a clean game loop and event hooks with mlx_hook
- Applied robust error handling and resource deallocation

## 🔗 Related Projects
- libft – foundational C library used throughout the project

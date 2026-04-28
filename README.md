Circle Jump (Console Game)

Circle Jump is a simple console-based arcade game written in C++. The player controls a character that must jump and avoid obstacles while the game speed gradually increases.

🚀 Features
Real-time gameplay in console
Jump mechanics with basic physics simulation
Randomly generated obstacles (single and double pillars)
Score system based on passed obstacles
Simple UI rendered from text files
~60 FPS game loop using time-based updates
🛠️ Technologies
C++
Standard Library (iostream, vector, fstream, etc.)
Windows API (windows.h) for console control
_kbhit() and _getch() for real-time input
File-based rendering system
🎮 Gameplay
Press Space to jump
Avoid hitting pillars
Score increases when you successfully pass obstacles
Game ends on collision
⚙️ How It Works

The game uses a simple loop with fixed time steps (~16 ms per frame).

Main components:

Character – handles player position and jump logic
Pillar / DoublePillar – obstacle generation and movement
Map system – generates a 2D representation and writes it to a file
Renderer – reads the map file and displays it in the console

Rendering is done via text transformation:

Game state → Map.txt
Rotated/transformed → VisualMap.txt
Printed to console
📂 Project Structure
main.cpp – core game logic
Map.txt – generated game state
VisualMap.txt – rendered frame
UIs.txt – UI screens (menu, intro)
▶️ How to Run

Compile the project (Windows required):

g++ main.cpp -o game

Run:

game.exe
⚠️ Notes
Works only on Windows (uses windows.h and conio.h)
Console resizing is recommended for better experience
Uses file I/O for rendering (not optimized, but simple and flexible)
💡 Possible Improvements
Replace file-based rendering with direct buffer drawing
Add proper physics for jump (currently simplified)
Implement difficulty scaling
Add sound support
Cross-platform support (Linux/macOS)
👨‍💻 Author

Developed as a low-level C++ practice project focused on:

real-time input handling
game loop implementation
memory and performance awareness

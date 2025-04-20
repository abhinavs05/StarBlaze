# Space Blaster - 2D Shooting Game (SFML Version)

## 🎮 Description
A 2D shooting game built using SFML in C++. Control a spaceship, shoot enemies, and try to survive!

## 🧠 Features
- Real-time movement and shooting
- Enemies spawn over time and fall downward
- Score system
- Game over screen when enemies breach the bottom

## 🎮 Controls
- `A` / `D`: Move left and right
- `Space`: Shoot bullets
- `Close Window`: Exit game

## 🛠️ Requirements
- SFML 2.x installed on your system
- A compiler that supports C++11 or above

## 📦 How to Build
1. Make sure SFML is installed and linked correctly.
2. Compile using g++:
    ```
    g++ main.cpp -o sfml_game -lsfml-graphics -lsfml-window -lsfml-system
    ```
3. Run:
    ```
    ./sfml_game
    ```

> Note: Make sure `arial.ttf` is present in the same folder as the executable for text rendering.

## 📁 Files
- `main.cpp`: Game source code
- `README.md`: Instructions
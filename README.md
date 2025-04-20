# Space Blaster - Enhanced Edition 🚀

## 🎮 Description
An upgraded 2D space shooter built using SFML and C++. Blast your enemies, survive waves, and aim for the highest score!

## 🧠 Features
- Beautiful starry background
- Player rocket and animated enemy sprites
- Looping space-themed background music
- Dynamic scoring system and Game Over UI
- Sprite-based visuals instead of plain rectangles

## 🕹️ Controls
- `A` / `D`: Move left and right
- `Space`: Shoot bullets
- `Close Window`: Exit game

## 📷 UI Preview

![screenshot_updated](https://github.com/user-attachments/assets/c5b0a77f-e61b-4aa0-b4c9-15ee5df6ccba)


## 🛠️ Requirements
- SFML 2.x installed on your system
- C++11 compatible compiler
- All asset files in the same folder:
  - `player.png`
  - `enemy.png`
  - `background.jpg`
  - `background.ogg`
  - `arial.ttf`

## 🧪 Build & Run
```bash
g++ main.cpp -o sfml_game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
./sfml_game
```

> Make sure all images, font, and audio files are placed alongside the compiled binary.


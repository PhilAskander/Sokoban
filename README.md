# Sokobon

# Overview:
This is a simple implementation of the classic Sokoban game using C++ and SFML (Simple and Fast Multimedia Library). Sokoban is a puzzle game where the player pushes boxes to specific locations in the game world.

# Requirements:
- C++ compiler
- SFML library

# How To Play:
1. Build the project using a C++ compiler.
2. Run the executable with a Sokoban map file that is found in ps4b/ps4b/ps4a/level1.txt as a command-line argument: ./sokoban my_map.txt
3. Use the arrow keys or WASD to mvoe the player character.
4. Push the boxes to the target locations to win the game.
5. Press 'R' to reset the level.

# Map File Format
The Sokoban map file should follow a simple format:
- '#' represents walls.
- 'O' represents boxes.
- '@' represents the player character.
- '.' represents target locations for boxes.
- '' (space) represents empty spaces.




# Cosmic Journey
Software Development II Project - 2nd Prize Winner

This is the program created for the ELEN3009 - Software Development II course at the University of the Witwatersrand for the electrical engineering degree. This was the 2017 project.
The theme of the project was that the game had to be in the style of Gyruss. Gyruss is a fixed shooter arcade game designed by Yoshiki Okamoto and released by Konami in 1983.

## Running the game

### Pre-requisite Installations
- g++ installed 
- [SFML](https://www.sfml-dev.org/) installed 

### Clone
- Clone the repo using `git clone git@github.com:Vorapahct/Cosmic_Journey.git`

### Running Pre-Compiled
- Double-click game.exe (Windows)
- Use `./game` in terminal (Linux/Ubuntu)

### Compiling from Source
- Only need game-source-code files and Resources (inside executables) folder to compile 
- Put all the files in a folder so that there are 50 game source files and 1 Resource folder together
- Inside said folder, open terminal and type:

```shell
$ g++ -c Asteroid.cpp Asteroid.h CollisionHandler.cpp CollisionHandler.h Direction.h Enemy.cpp Enemy.h EnemyBullet.cpp EnemyBullet.h EnemySpawner.cpp EnemySpawner.h EntityType.h GameOverScreen.cpp GameOverScreen.h GameState.h Grid.cpp Grid.h HighScoreManager.cpp HighScoreManager.h IMovingEntity.cpp IMovingEntity.h IShootingMovingEntity.cpp IShootingMovingEntity.h LaserField.cpp LaserField.h LaserGenerator.cpp LaserGenerator.h Logic.cpp Logic.h main.cpp Player.cpp Player.h PlayerBullet.cpp PlayerBullet.h Position.cpp Position.h Presentation.cpp Presentation.h ResourceManager.cpp ResourceManager.h ResourceType.h Satellite.cpp Satellite.h SplashScreen.cpp SplashScreen.h StopWatch.cpp StopWatch.h WeaponType.h WinnerScreen.cpp WinnerScreen.h
$ g++ Grid.o main.o Enemy.o Logic.o Player.o Asteroid.o Position.o Satellite.o StopWatch.o LaserField.o EnemyBullet.o EnemySpawner.o PlayerBullet.o Presentation.o SplashScreen.o WinnerScreen.o IMovingEntity.o GameOverScreen.o LaserGenerator.o ResourceManager.o CollisionHandler.o HighScoreManager.o IShootingMovingEntity.o -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
$ ./game
```





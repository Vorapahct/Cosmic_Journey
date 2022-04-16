# Cosmic Journey
Software Development II Project - 2nd Prize Winner

This is the program created for the ELEN3009 - Software Development II course at the University of the Witwatersrand for the electrical engineering degree. This was the 2017 project.
The theme of the project was that the game had to be in the style of Gyruss. Gyruss is a fixed shooter arcade game designed by Yoshiki Okamoto and released by Konami in 1983.

## Running the game

### Pre-requisite Installations
- [g++](https://gcc.gnu.org/install/) installed 
- [SFML](https://www.sfml-dev.org/) installed 

### Running Pre-Compiled
- Clone the repo using `git clone git@github.com:Vorapahct/Cosmic_Journey.git`
- Use game.exe (Windows)
- Use `./game` in terminal (Linux/Ubuntu)


### Compiling from Source
Only need game-source-code files and Resources (inside executables) folder to compile so pu all these together like the structure shown below:
```
    .
    ├── docs   
    ├── executables
        └──Resources
    ├── game-source-code                
    |   └──Resources                 
    ├── test-source-code                
    ├── Dockerfile                 
    ├── README.md
```
Inside said folder, open terminal and type:

```shell
g++ -c Asteroid.cpp Asteroid.h CollisionHandler.cpp CollisionHandler.h Direction.h Enemy.cpp Enemy.h EnemyBullet.cpp EnemyBullet.h EnemySpawner.cpp EnemySpawner.h EntityType.h GameOverScreen.cpp GameOverScreen.h GameState.h Grid.cpp Grid.h HighScoreManager.cpp HighScoreManager.h IMovingEntity.cpp IMovingEntity.h IShootingMovingEntity.cpp IShootingMovingEntity.h LaserField.cpp LaserField.h LaserGenerator.cpp LaserGenerator.h Logic.cpp Logic.h main.cpp Player.cpp Player.h PlayerBullet.cpp PlayerBullet.h Position.cpp Position.h Presentation.cpp Presentation.h ResourceManager.cpp ResourceManager.h ResourceType.h Satellite.cpp Satellite.h SplashScreen.cpp SplashScreen.h StopWatch.cpp StopWatch.h WeaponType.h WinnerScreen.cpp WinnerScreen.h
g++ Grid.o main.o Enemy.o Logic.o Player.o Asteroid.o Position.o Satellite.o StopWatch.o LaserField.o EnemyBullet.o EnemySpawner.o PlayerBullet.o Presentation.o SplashScreen.o WinnerScreen.o IMovingEntity.o GameOverScreen.o LaserGenerator.o ResourceManager.o CollisionHandler.o HighScoreManager.o IShootingMovingEntity.o -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
./game
```

## 2022 Update
So its 5 years later and this looks like a pretty dead repo. However, I have grown so I decided to dockerise this repo to avoid users having to install millions of packages to run one file.

### Requirements
Unfortunately you need X-windows to allow the GUI to actually display on the host machine (at least on Windows, not sure about Unix machines). Anyway, I used VcXsrv to setup my X-window server. Just be sure to set it to 0 on the config page (-1 caused some weird issues). Following that, you just need your IPv4 - type "ipconfig" to get your ip.

### Docker
Make sure you X-windows server is running.
```shell
docker build -t cosmic_journey:1 .
docker run --rm -it -e DISPLAY="IPv4:0.0" cosmic_journey:1
docker run --rm -it -e DISPLAY="10.0.0.3:0.0" cosmic_journey:1 // Example
```

### Issues
For some unknown reason - the docker container runs the code much slower than when running it on host - I think its related to OpenGL and not detecting the host machine's capabilities. Tune in 5 years when I decide to look into this. 
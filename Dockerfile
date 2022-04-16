FROM ubuntu:20.04

COPY /executables/Resources /usr/src/Cosmic_Journey/Resources

COPY /game-source-code/ /usr/src/Cosmic_Journey/

WORKDIR /usr/src/Cosmic_Journey

# To add the universe repository to the container
RUN apt-get update &&\
 apt-get install -y software-properties-common &&\
 add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc) universe"

# For SFML
RUN apt-get install libsfml-dev -y 

# For GCC
RUN apt install build-essential -y

RUN g++ -c Asteroid.cpp Asteroid.h CollisionHandler.cpp CollisionHandler.h Direction.h Enemy.cpp Enemy.h EnemyBullet.cpp EnemyBullet.h EnemySpawner.cpp EnemySpawner.h EntityType.h GameOverScreen.cpp GameOverScreen.h GameState.h Grid.cpp Grid.h HighScoreManager.cpp HighScoreManager.h IMovingEntity.cpp IMovingEntity.h IShootingMovingEntity.cpp IShootingMovingEntity.h LaserField.cpp LaserField.h LaserGenerator.cpp LaserGenerator.h Logic.cpp Logic.h main.cpp Player.cpp Player.h PlayerBullet.cpp PlayerBullet.h Position.cpp Position.h Presentation.cpp Presentation.h ResourceManager.cpp ResourceManager.h ResourceType.h Satellite.cpp Satellite.h SplashScreen.cpp SplashScreen.h StopWatch.cpp StopWatch.h WeaponType.h WinnerScreen.cpp WinnerScreen.h

RUN g++ Grid.o main.o Enemy.o Logic.o Player.o Asteroid.o Position.o Satellite.o StopWatch.o LaserField.o EnemyBullet.o EnemySpawner.o PlayerBullet.o Presentation.o SplashScreen.o WinnerScreen.o IMovingEntity.o GameOverScreen.o LaserGenerator.o ResourceManager.o CollisionHandler.o HighScoreManager.o IShootingMovingEntity.o -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

CMD ["./game"]
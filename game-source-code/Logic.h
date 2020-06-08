#ifndef LOGIC_H
#define LOGIC_H

#include <memory>
#include <stdlib.h>
#include <ctime> 
#include <vector>

#include "StopWatch.h"
#include "Presentation.h"
#include "CollisionHandler.h"
#include "GameState.h"
#include "HighScoreManager.h"
#include "EnemySpawner.h"

using std::shared_ptr;
using std::make_shared;

/**
* Logic class - Controls the behaviour of the game objects before sending them to be rendered and displayed.
*/
class Logic
{
    public:
        /**
        * @brief Default constructor. Creates an instance of the game and initializes all of its objects.
        */
        Logic();
        /**
        * @brief Default destructor. Destroys the Logic object.
        */
        ~Logic();
        /**
        * @brief Function that starts the main game loop.
        */
        void run();
       
        
    private: 
        /**
        * @brief Function that loads all the resources and links it to a ResourceType
        */
        void loadTexturePaths();
        /**
        * @brief Function that sends a vector of shared pointers of type IMovingEntity to Presentation to draw.
        */
        void renderEntities();
        /**
        * @brief Function that randomly spawns objects of type Enemy if the random number generated allows.
        */
        void spawnEnemyNormal();
        /**
        * @brief Function that assigns the input from the user to a direction of the Player object. 
        */
        void updatePlayerPosition();
        /**
        * @brief Function that calls the virtual move override function for all objects that are alive.
        */
        void updateEntities();
        /**
        * @brief Function that calls Presentation object to get the key stroke and maps it to an enum. 
        */
        void inputCommands();
        /**
        * @brief Function that calls the SplashScreen object to display its window when game starts. 
        */
        void drawSplashScreen();
        /**
        * @brief Function that calls the WinnerScreen object to display its window when all enemies killed. 
        */
        void drawWinnerScreen();
        /**
        * @brief Function that calls the GameOverScreen object to display its window when Player loses all lives. 
        */
        void drawGameOverScreen();
        /**
        * @brief Function that randomly spawns group of 3 objects of type Satellite if the random number generated allows.
        */
        void spawnSatellites();
        /**
        * @brief Function that randomly spawns group of objects of 2 type LaserGenerator and 7 of type LaserField if the random number generated allows.
        */
        void spawnLaserGenerators();
        /**
        * @brief Function that randomly spawns an object of type Asteroid if the random number generated allows.
        */
        void spawnAsteroids();
        /**
        * @brief Function that checks for collisions between all valid entities.
        */
        void collisions();
        /**
        * @brief Function that checks the number of enemies killed and sends it to be displayed on game window.
        */
        void updateScores();
        /**
        * @brief Function that allows objects to shoot if the random number allows.
        */
        void entitiesShoot();
        /**
        * @brief Function that deletes all dead objects from a vector of shared pointers of type IMovingEntity.
        */
        void deleteDeadEntities();

        Presentation _presentation;
        GameState _gameState;
        const Grid _grid{800, 600};
        HighScoreManager _highScoreManager;
        ResourceManager _resourceManager;
        shared_ptr<PlayerBullet> _playerBullet;
        shared_ptr<Player> _player;
        vector<shared_ptr<IMovingEntity>> _gameObjects;
        CollisionHandler _collisionHandler;
        EnemySpawner _enemySpawner;
        int _highScore;
        int _enemiesRemaining;
        bool _debounce = false;
};

#endif // LOGIC_H

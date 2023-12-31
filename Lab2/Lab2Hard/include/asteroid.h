#ifndef ASTEROID_H
#define ASTEROID_H


typedef struct asteroid Asteroid;

Asteroid *createAsteroid(float x, float y, float vel, double angle, int screenW, int screenH, int sizeMult, SDL_Renderer *renderer, int *currentAsteroidAmount, int *totalAsteroidAmount);

void initAstArr(Asteroid **ast, int size);

void spawnContinuousAsteroids(Asteroid **asteroids, SDL_Renderer *renderer, float maxVel, float minVel, int *currentAsteroidAmount, int maxAsteroidAmount, int windowW, int windowH, int *totalAsteroidAmount);
void drawAsteroid(Asteroid *ast, SDL_Renderer *renderer);
void splitAsteroid(Asteroid *ast, Asteroid **asteroids, int *currentAsteroidAmount, SDL_Renderer *renderer, int *totalAsteroidAmount);
void moveAsteroid(Asteroid *ast);
void updateAsteroid(Asteroid **asteroids, int *currentAsteroidAmount, int deleteIndex);
void updateAsteroidArray(Asteroid **asteroids, int deleteIndex, int currentAsteroidAmount);
SDL_Rect getAstRect(Asteroid *ast);
char *getAstName(Asteroid *ast);
void destroyAsteroid(Asteroid *asteroid, Asteroid **asteroids, int deleteIndex, int *currentasteroidAmount);


#endif
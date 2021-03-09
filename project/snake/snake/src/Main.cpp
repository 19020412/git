#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "SDL.h"

class Game
{

public:

    Game();
    void Run();

private:

    bool running = true ;

    static const int FRAME_RATE = 1000 / 60;
    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 640;
    static const int GRID_WIDTH = 32;
    static const int GRID_HEIGHT = 32;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    enum class Block { head, empty };
    enum class Move { up, down, left, right };

    Move dir = Move::up;

    struct { int x = GRID_WIDTH / 2, y = GRID_HEIGHT / 2; } pos;

    SDL_Point head = { pos.x, pos.y };

    Block grid[GRID_WIDTH][GRID_HEIGHT];

    int speed = 1;

    void GameLoop();
    void Render();
    void Update();
    void PollEvents();
    void Close();

};

using namespace std;

Game::Game()
{
    for (int i = 0; i < GRID_WIDTH; ++i)
        for (int j = 0; j < GRID_HEIGHT; ++j)
        {
            grid[i][j] = Block::empty;
        }

}

void Game::Run()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    // Create Window
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }
    SDL_SetWindowTitle(window, "snake");

    GameLoop();
}

void Game::GameLoop()
{
    while (running)
    {
        PollEvents();
        Update();
        Render();
    }
}

void Game::PollEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
                dir = Move::up;
                break;

            case SDLK_DOWN:
                dir = Move::down;
                break;

            case SDLK_LEFT:
                dir = Move::left;
                break;

            case SDLK_RIGHT:
                dir = Move::right;
                break;
            }
        }
    }
}



void Game::Update()
{

    switch (dir)
    {
    case Move::up:
        if (pos.y > 0) {
        pos.y -= speed;
        pos.x = floorf(pos.x);
        }
        break;

    case Move::down:
        if (pos.y < GRID_HEIGHT - 1) {
            pos.y += speed;
            pos.x = floorf(pos.x);
        }
        break;

    case Move::left:
        if (pos.x > 0) {
            pos.x -= speed;
            pos.y = floorf(pos.y);
        }
        break;

    case Move::right:
        if (pos.x < GRID_WIDTH - 1)
        {
            pos.x += speed;
            pos.y = floorf(pos.y);
        }
        break;
    }

    int new_x = pos.x;
    int new_y = pos.y;

    grid[head.x][head.y] = Block::empty;

    head.x = new_x;
    head.y = new_y;

    Block& next = grid[head.x][head.y];

    next = Block::head;
}


void Game::Render()
{
    SDL_Rect block;
    block.w = SCREEN_WIDTH / GRID_WIDTH;
    block.h = SCREEN_WIDTH / GRID_HEIGHT;

    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);


    block.x = head.x * block.w;
    block.y = head.y * block.h;

    SDL_SetRenderDrawColor(renderer, 0x00, 0x7A, 0xCC, 0xFF);
    SDL_RenderFillRect(renderer, &block);

    SDL_RenderPresent(renderer);
}

void Game::Close()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char * argv[])
{
    Game game;
    game.Run();
    return 0;
}
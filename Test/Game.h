#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <string>
using namespace std;
class Game {
public:
	Game();
	bool getGameState();
	void CreateScreenGame();
	void Event();
	void Update();
	void Render();
	void Clear();
private:
	const int W = 800;
	const int H = 640;
	bool gameState;
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Event event;
	SDL_Texture* background;
	SDL_Texture* button;
	SDL_Rect scr;
	SDL_Rect des;
	//bien cho text
	TTF_Font* font;
	SDL_Surface* textSuf;
	SDL_Texture* textTT;
	SDL_Rect textRect;
	int time;
	string second;
	int position;
};

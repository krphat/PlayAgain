#include "Game.h"

Game::Game() {
	window = NULL;
	render = NULL;
	gameState = false;
	background = NULL;
	font = NULL;
	textSuf = NULL;
	textTT = NULL;
}

bool Game::getGameState() {
	return gameState;
}

void Game::CreateScreenGame() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_RESIZABLE);
	if (window) {
		render = SDL_CreateRenderer(window, -1, 0);
		if (render) {
			cout << "Khoi tao thanh cong !" << endl;
			gameState = true;
			background = IMG_LoadTexture(render, "filegame/image/background.png");
			button = IMG_LoadTexture(render, "filegame/image/button_exit.png");

			//Text
			font = TTF_OpenFont("LuckiestGuy-Regular.ttf", 45);
		}
		else {
			cout << "Khoi tao Render that bai !" << endl;
		}
	}
	else {
		cout << "Khoi tao window that bai !" << endl;
	}
}

void Game::Event() {
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		gameState = false;
	}
	//su kien nhan nut
	if (event.type == SDL_MOUSEMOTION) {
		if ((event.motion.x >= 0 && event.motion.x <= 550) && (event.motion.y >= 0 && event.motion.y <= 275)) {
			position = 0;
		}
		else {
			position = 549.5;
		}
	}

	//su kien chay xong 5s thi gameover
}

void Game::Update() {
	//set cho hien thi nut
	scr.h = 549.5;
	scr.w = 1099;
	scr.y = position;
	scr.x = 0;

	des.h = 275;
	des.w = 550;
	des.x = des.y = 0;
	//hien thi text diem
	time = SDL_GetTicks() / 1000;
	second = to_string(time);
	textSuf = TTF_RenderText_Solid(font, second.c_str(), { 255,255,66 });
	textTT = SDL_CreateTextureFromSurface(render, textSuf);
	textRect = { 100,400,textSuf->w, textSuf->h };
}

void Game::Render() {
	SDL_RenderClear(render);
	SDL_RenderCopy(render, background, NULL, NULL); // hien thi nen
	SDL_RenderCopy(render, button, &scr, &des); // hien thi nut
	SDL_RenderCopy(render, textTT, NULL, &textRect); //hien thi text
	SDL_RenderPresent(render);
}

void Game::Clear() {
	SDL_DestroyWindow(window);
	SDL_RenderClear(render);
	SDL_FreeSurface(textSuf);
	TTF_CloseFont(font);
	TTF_Quit();
}
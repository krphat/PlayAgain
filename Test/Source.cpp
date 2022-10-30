#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
using namespace std;
int main(int argc, char* argv[]) {
	Game testgame;
	testgame.CreateScreenGame();
	while (testgame.getGameState()) {
		testgame.Event();
		testgame.Update();
		testgame.Render();
	}
	testgame.Clear();
	return 0;
}
#include "Game.h"
#include <iostream>

namespace magma_game {
	Game::Game()
	{
	}

	std::string gameNameScene() {
		std::cout << "Inicio del juego\n";

		return "assets/scenes/menu.magmascene";

	}

	/*void getEngineInstances(magma_engine::CMagmaEngine* engine) {
		instances = engine;
	}*/
}
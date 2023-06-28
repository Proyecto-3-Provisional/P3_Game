#include <iostream>


#include <TheRiseOfSuxalote/Game.h>

namespace magma_game {
	void gameNameScene(std::vector<std::string>& strings) {
		std::cout << "Inicio del juego\n";

		strings.push_back("menu");
		strings.push_back("lose");
		strings.push_back("level");
		strings.push_back("win");
	}
}
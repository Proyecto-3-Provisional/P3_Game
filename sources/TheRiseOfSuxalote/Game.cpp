#include "Game.h"
#include <iostream>

#include <EC/entity.h>
#include <Input/input_manager.h>
#include <Physics/rigidbody.h>


Game::Game()
{

}

void prueba() {
	std::cout << "Funciona el juego\n";

	// Crear un componente nuevo 
	// Llegar al inputmanager, para detectar input
	// Acceder al rigidbody, para meter AddForce
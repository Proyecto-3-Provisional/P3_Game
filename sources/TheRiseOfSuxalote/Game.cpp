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

	
	
}

namespace magma_game
{
	PlayerController::PlayerController()
	{

	}

	PlayerController::~PlayerController()
	{

	}

	bool PlayerController::initComponent()
	{

		return false;
	}

	void PlayerController::update(float deltaTime)
	{		
		rb = ent->getComponent<magma_engine::Rigidbody>();
		if (Singleton<magma_engine::InputManager>::instance()->isKeyDown(SCANCODE_A)) {
			rb->addForce(magma_engine::Vector3D(-1, 0, 0));
		}
		else if (Singleton<magma_engine::InputManager>::instance()->isKeyDown(SCANCODE_D)) {
			rb->addForce(magma_engine::Vector3D(1, 0, 0));
		}
		else if (Singleton<magma_engine::InputManager>::instance()->isKeyDown(SCANCODE_W)) {
			rb->addForce(magma_engine::Vector3D(0, 0, -1));
		}
		else if (Singleton<magma_engine::InputManager>::instance()->isKeyDown(SCANCODE_S)) {
			rb->addForce(magma_engine::Vector3D(0, 0, 1));
		}
	}
}


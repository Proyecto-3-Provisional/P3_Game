#include "Game.h"
#include <iostream>

#include <EC/entity.h>
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
		//Singleton<magma_engine::InputManager>::instance()->showOrHideMouse();
		
		rb = ent->getComponent<magma_engine::Rigidbody>();
		rb->isEnable();
		//rb->addForce(magma_engine::Vector3D(0,0,0));
		//rb->isOnCollision();
		//rb->isCollideWith(0);
	}
}


#pragma once

#include <EC/component.h>
#include <Physics/rigidbody.h>
#include <EC/transform.h>
#include <EC/Vector3D.h>
#include <TheRiseOfSuxalote/endgame.h>

/*
* Componente que funciona sin fisicas.
* Tiene una dirección y una velocidad lineal que cuando choca con el jugador este morirá sin importar el tamaño,
  la bala también tiene una vida que al terminarse se elimina de la escena.	
*/

namespace magma_game
{
	class Bala : public magma_engine::Component
	{
	public:
		Bala();
		~Bala();

		// Iniciar los valores del componente
		virtual bool initComponent(std::map<std::string, std::string> args);
		// Coger otros valores necesarios de otros componentes
		virtual bool start();

		// Deteccion de colisiones, timer de la bala y movimiento uniforme
		void update(float deltaTime);

	private:
		// Deteccion de colisiones entre la bala y el jugador
		void detectCollision();

		// Velocidad de pixeles por segundo
		int velocidad;
		// Vida de la bala
		float seconds;
		// Direccion de la bala
		magma_engine::Vector3D dir;
		// Transform de la bala
		magma_engine::Transform* tr = nullptr;
	};
}
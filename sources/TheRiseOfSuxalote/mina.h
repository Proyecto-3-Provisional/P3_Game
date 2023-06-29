#pragma once

#include <EC/component.h>
#include <Physics/rigidbody.h>
#include <EC/transform.h>

/*
* Es un componente que necesita un cuerpo rígido estático que mata al jugador cuando este choque
  contra él sin importar el tamaño que tenga.
*/

namespace magma_game
{
	class Mina : public magma_engine::Component
	{
	public:
		Mina();
		~Mina();

		// Iniciar los valores del componente
		virtual bool initComponent(std::map<std::string, std::string> args);
		// Coger otros valores necesarios de otros componentes
		virtual bool start();

		// Detección de colision contra el jugador
		void update(float deltaTime);

	private:
		// Cuerpo rigido de la mina
		magma_engine::Rigidbody* rb = nullptr;
		// Transform de la mina
		magma_engine::Transform* tr = nullptr;
	};
}
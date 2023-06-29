#pragma once

#include <EC/entity.h>
#include <EC/component.h>
#include <TheRiseOfSuxalote/timer.h>

namespace magma_engine
{
	class Rigidbody;
}

namespace magma_game
{
	class Red : public magma_engine::Component
	{
	public:
		Red();
		virtual ~Red();

		virtual bool initComponent(std::map<std::string, std::string> args);
		virtual bool start();
		void update(float deltaTime);
		void onCollision(magma_engine::Entity* ent);

	private:
		magma_engine::Rigidbody* rb = nullptr; //componente rigidbody de la entidad
		Timer* penaltyTimer = nullptr; //componente timer de la entidad

		//esta es la entidad del jugador que cojeremos cuando se colisione con la red que la usaremos para
		//restaurar su velocidad cuando se acabe el tiempo de penalizacion
		magma_engine::Entity* playerEnt = nullptr; 

		float penaltySpeed; //La velocidad que quitara y restaurara al jugador
		float penaltyTime; //El tiempo que durara la penalizacion del jugador por chocar con la red

		//Este booleano es para que en el update se sepa que ha chocado el jugador con la red y que empiece a 
		//restaurar la velocidad del jugador cuando se acabe el tiempo y se destruya la entidad
		bool colisioned = false;
		//Este booleano es para que en el inicio de la partida se oculte el texto de la entidad en la primera llamada
		//de update
		bool startView = false;
	};
}
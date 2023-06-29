#pragma once

#include <EC/entity.h>
#include <EC/component.h>
#include <TheRiseOfSuxalote/timer.h>

namespace magma_engine
{
	class Rigidbody;
	//class Mesh;
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

		virtual void onEnable();

	private:
		magma_engine::Rigidbody* rb = nullptr;
		Timer* penaltyTimer = nullptr;
		//magma_engine::Mesh* mesh = nullptr;

		//esta es la entidad del jugador que cojeremos cuando se colisione con la red que la usaremos para
		//restaurar su velocidad cuando se acabe el tiempo de penalizacion
		magma_engine::Entity* playerEnt = nullptr; 

		float penaltySpeed;
		float penaltyTime;
		//float penaltyDuration;

		bool colisioned = false;
		bool startView = false;
	};
}
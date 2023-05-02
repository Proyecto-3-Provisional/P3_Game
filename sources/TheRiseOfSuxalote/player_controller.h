#pragma once

#include <EC/component.h>
#include <EC/vector3D.h>
#include <Physics/rigidbody.h>
#include <EC/transform.h>

namespace magma_game
{
	class PlayerController : public magma_engine::ec::Component
	{
	public:
		PlayerController();
		~PlayerController();

		virtual bool initComponent(std::map<std::string, std::string> args);
		virtual bool start();
		void update(float deltaTime);

	private:
		magma_engine::Rigidbody* rb = nullptr;
		magma_engine::Transform* tr = nullptr;
		float enemySpeed;

		magma_engine::Vector3D movementDirection;
		//simula al ajolote nadando a "empujones"
		float timeBetweenMovements;
		float currTimeBetweenMovements;
	};
}
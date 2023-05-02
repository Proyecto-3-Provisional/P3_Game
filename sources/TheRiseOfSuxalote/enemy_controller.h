#pragma once

#include <EC/component.h>
#include <EC/vector3D.h>
#include <Physics/rigidbody.h>
#include <EC/transform.h>

namespace magma_game
{
	class EnemyController : public magma_engine::ec::Component
	{
	public:
		EnemyController();
		~EnemyController();

		bool initComponent(magma_engine::Transform* playerTransform_, float playerSpeed_ = 10000.0f, float timeBetweenMovements_ = 2.0f, bool chasing_ = true);
		void update(float deltaTime);


	private:
		magma_engine::Rigidbody* rb = nullptr;
		magma_engine::Transform* tr = nullptr;
		magma_engine::Transform* playerTransform = nullptr;
		float enemySpeed;

		magma_engine::Vector3D movementDirection;

		// true para perseguir al jugador, false para huir
		bool chasing;

		float timeBetweenMovements;
		float currTimeBetweenMovements;
	};
}
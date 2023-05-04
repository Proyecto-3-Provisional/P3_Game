#include <TheRiseOfSuxalote/enemy_controller.h>

#include <Input/input_manager.h>

#include <EC/entity.h>
#include <EC/transform.h>

namespace magma_game
{
	EnemyController::EnemyController() : enemySpeed(0.0f), timeBetweenMovements(0.0f), currTimeBetweenMovements(0.0f), chasing(true)
	{
	}

	EnemyController::~EnemyController()
	{

	}

	bool EnemyController::initComponent(magma_engine::Transform* playerTransform_, float enemySpeed_, float timeBetweenMovements_, bool chasing_)
	{
		try {
			rb = ent->getComponent<magma_engine::Rigidbody>();
			tr = ent->getComponent<magma_engine::Transform>();
			playerTransform = playerTransform_;
			chasing = chasing_;

			enemySpeed = enemySpeed_;
			timeBetweenMovements = timeBetweenMovements_;
			currTimeBetweenMovements = timeBetweenMovements;

			magma_engine::Vector3D movementDirection(0, 0, 0);
		}
		catch (std::exception& e) {
			std::cout << "WARNING! - error en un componente enemy_controller:\n\n     " << e.what() << "\n\n";

			return false;
		}
		return true;
	}

	void EnemyController::update(float deltaTime)
	{
		bool move = false;

		magma_engine::Vector3D lineToPlayer = playerTransform->getPos() - tr->getPos();

		if (currTimeBetweenMovements < 0.0f) {

			if (chasing) {
				rb->addForce(lineToPlayer.normalize() * enemySpeed * deltaTime);
			}
			else {
				rb->addForce(lineToPlayer.normalize() * -1 * enemySpeed * deltaTime);

			}
			currTimeBetweenMovements = timeBetweenMovements;
			
		}

		if(chasing)
			tr->setDirection(lineToPlayer);
		else
			tr->setDirection(lineToPlayer * -1);


		currTimeBetweenMovements -= deltaTime;

	}
}
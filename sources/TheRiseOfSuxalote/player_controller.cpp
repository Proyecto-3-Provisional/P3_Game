#include "player_controller.h"
#include "EngineInstances.h"
#include <Input/input_manager.h>
#include <EC/entity.h>
#include <EC/transform.h>


namespace magma_game
{
	PlayerController::PlayerController() : enemySpeed(0.0f), timeBetweenMovements(0.0f), currTimeBetweenMovements(0.0f)
	{
	}

	PlayerController::~PlayerController()
	{

	}

	bool PlayerController::initComponent(std::map<std::string, std::string> args)
	{
		try {
			enemySpeed = stof(args["playerSpeed"]);
			timeBetweenMovements = stof(args["timeBetweenMovements"]);
			currTimeBetweenMovements = stof(args["timeBetweenMovements"]); ;

			magma_engine::Vector3D movementDirection(0, 0, 0);
		}
		catch (...) {
			return false;
		}
		return true;
	}

	bool PlayerController::start()
	{
		tr = ent->getComponent<magma_engine::Transform>();
		rb = ent->getComponent<magma_engine::Rigidbody>();
		return (tr != nullptr && rb != nullptr);
	}

	void PlayerController::update(float deltaTime)
	{
		bool move = false;

		if (currTimeBetweenMovements < 0.0f) {
			movementDirection = { 0,0,0 };

			if (instances->getInput()->isKeyDown(SCANCODE_A)) {

				rb->addForce(magma_engine::Vector3D(-1, 0, 0) * enemySpeed);
				movementDirection += magma_engine::Vector3D(-1, 0, 0);
				move = true;
			}
		
			if (instances->getInput()->isKeyDown(SCANCODE_D)) {

				rb->addForce(magma_engine::Vector3D(1, 0, 0) * enemySpeed);
				movementDirection += magma_engine::Vector3D(1, 0, 0);

				move = true;

			}

			if (instances->getInput()->isKeyDown(SCANCODE_W)) {

				rb->addForce(magma_engine::Vector3D(0, 0, -1) * enemySpeed);
				movementDirection += magma_engine::Vector3D(0, 0, -1);

				move = true;

			}

			if (instances->getInput()->isKeyDown(SCANCODE_S)) {

				rb->addForce(magma_engine::Vector3D(0, 0, 1) * enemySpeed);
				movementDirection += magma_engine::Vector3D(0, 0, 1);

				move = true;

			}

			if (move) {
				tr->setDirection(movementDirection);
				currTimeBetweenMovements = timeBetweenMovements;
			}

		}

		currTimeBetweenMovements -= deltaTime;

	}
}
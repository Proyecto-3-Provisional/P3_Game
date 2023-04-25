#include "PlayerController.h"

#include <EC/entity.h>
#include <Input/input_manager.h>
#include <Physics/rigidbody.h>

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
		try {
			rb = ent->getComponent<magma_engine::Rigidbody>();
			inputMgr = Singleton<magma_engine::InputManager>::instance();
			return true;
		}
		catch (...) {
			return false;
		}
	}

	void PlayerController::update(float deltaTime)
	{
		if (inputMgr->isKeyDown(SCANCODE_A)) {
			rb->addForce(magma_engine::Vector3D(-1, 0, 0));
		}
		else if (inputMgr->isKeyDown(SCANCODE_D)) {
			rb->addForce(magma_engine::Vector3D(1, 0, 0));
		}
		else if (inputMgr->isKeyDown(SCANCODE_W)) {
			rb->addForce(magma_engine::Vector3D(0, 0, -1));
		}
		else if (inputMgr->isKeyDown(SCANCODE_S)) {
			rb->addForce(magma_engine::Vector3D(0, 0, 1));
		}
	}
}
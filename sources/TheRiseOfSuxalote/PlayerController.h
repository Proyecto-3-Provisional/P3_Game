#pragma once

#include <EC/component.h>

class Rigidbody;
class InputManager;

namespace magma_game
{
	class PlayerController : public magma_engine::ec::Component
	{
	public:
		PlayerController();
		~PlayerController();

		bool initComponent() override;
		void update(float deltaTime) override;


	private:
		magma_engine::Rigidbody* rb;
		magma_engine::InputManager* inputMgr;
	};
}
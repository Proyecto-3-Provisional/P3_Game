#pragma once

#include <EC/component.h>
#include <Physics/rigidbody.h>
#include <EC/transform.h>

namespace magma_game
{
	class Mina : public magma_engine::Component
	{
	public:
		Mina();
		~Mina();

		virtual bool initComponent(std::map<std::string, std::string> args);
		virtual bool start();

		void update(float deltaTime);

	private:
		magma_engine::Rigidbody* rb = nullptr;
		magma_engine::Transform* tr = nullptr;
	};
}
#pragma once

#include <EC/component.h>
#include <Physics/rigidbody.h>
#include <EC/transform.h>
#include <EC/Vector3D.h>
#include <TheRiseOfSuxalote/endgame.h>

namespace magma_game
{
	class Bala : public magma_engine::Component
	{
	public:
		Bala();
		~Bala();

		virtual bool initComponent(std::map<std::string, std::string> args);
		virtual bool start();

		void update(float deltaTime);

	private:
		int velocidad;
		float seconds;
		magma_engine::Vector3D dir;
		magma_engine::Transform* tr = nullptr;
	};
}
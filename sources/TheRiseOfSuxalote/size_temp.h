#pragma once

#include <EC/entity.h>
#include <EC/vector3D.h>

namespace magma_engine {
	class Transform;
	class Rigidbody;
}

namespace magma_game
{

	class Size_Temp : public magma_engine::Component
	{
	public:
		Size_Temp();
		virtual ~Size_Temp();

		virtual bool initComponent(std::map<std::string, std::string> args);
		virtual bool start();
		void update(float deltaTime);

		float getTam();
		bool isPlayer();

		void setTam(float ntam);

		float tam = 1.0f;
		bool player = false;

	private:
		magma_engine::Transform* trPtr = nullptr;
		magma_engine::Rigidbody* rbPtr = nullptr;
		magma_engine::Vector3D originalScale;
	};
}
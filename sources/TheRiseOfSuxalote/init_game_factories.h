#pragma once

#include <EC/factory.h>

namespace magma_game
{
	struct magma_engine::ec::Component;

	/*class ProgressBarFactory : public magma_engine::Factory
	{
	public:
		magma_engine::ec::Component* createComponent(magma_engine::ec::Entity* e);
	};*/

	class TimerFactory : public magma_engine::Factory
	{
	public:
		magma_engine::ec::Component* createComponent(magma_engine::ec::Entity* e);
	};

	class PlayerControllerFactory : public magma_engine::Factory
	{
	public:
		magma_engine::ec::Component* createComponent(magma_engine::ec::Entity* e);
	};

	class EnemyControllerFactory : public magma_engine::Factory
	{
	public:
		magma_engine::ec::Component* createComponent(magma_engine::ec::Entity* e);
	};

	void setUpGameFactories();
}


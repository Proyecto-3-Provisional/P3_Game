#include "init_game_factories.h"

#include <EC/factory_manager.h>
#include <EC/entity.h>

#include "player_controller.h"
#include "enemy_controller.h"
#include "progress_bar.h"
#include "timer.h"

namespace magma_game
{
	magma_engine::Component* ProgressBarFactory::createComponent(magma_engine::Entity* e)
	{
		return e->addComponent<Progress_Bar>();
	}

	magma_engine::Component* TimerFactory::createComponent(magma_engine::Entity* e)
	{
		return e->addComponent<Timer>();
	}

	magma_engine::Component* PlayerControllerFactory::createComponent(magma_engine::Entity* e)
	{
		return e->addComponent<PlayerController>();
	}

	magma_engine::Component* EnemyControllerFactory::createComponent(magma_engine::Entity* e)
	{
		return e->addComponent<EnemyController>();
	}

	void setUpGameFactories(magma_engine::FactoryManager* f)
	{
		f->addFactory("PlayerController", new PlayerControllerFactory());
		f->addFactory("EnemyController", new EnemyControllerFactory());
		f->addFactory("ProgressBar", new ProgressBarFactory());
		f->addFactory("Timer", new TimerFactory());
	}
}


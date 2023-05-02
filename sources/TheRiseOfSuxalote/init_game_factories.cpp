#include "init_game_factories.h"

#include <EC/factory_manager.h>
#include <EC/entity.h>

#include "player_controller.h"
#include "enemy_controller.h"
#include "progress_bar.h"
#include "timer.h"

namespace magma_game
{
	/*magma_engine::ec::Component* ProgressBarFactory::createComponent(magma_engine::ec::Entity* e)
	{
		return e->addComponent<Progress_Bar>();
	}*/

	magma_engine::ec::Component* TimerFactory::createComponent(magma_engine::ec::Entity* e)
	{
		return e->addComponent<Timer>();
	}

	magma_engine::ec::Component* PlayerControllerFactory::createComponent(magma_engine::ec::Entity* e)
	{
		return e->addComponent<PlayerController>();
	}

	magma_engine::ec::Component* EnemyControllerFactory::createComponent(magma_engine::ec::Entity* e)
	{
		return e->addComponent<EnemyController>();
	}

	void setUpGameFactories()
	{
		magma_engine::FactoryManager::instance()->addFactory("PlayerController", new PlayerControllerFactory());
		magma_engine::FactoryManager::instance()->addFactory("EnemyController", new EnemyControllerFactory());
		//magma_engine::FactoryManager::instance()->addFactory("ProgressBar", new ProgressBarFactory());
		magma_engine::FactoryManager::instance()->addFactory("Timer", new TimerFactory());
	}
}


#include <TheRiseOfSuxalote/red.h>

#include <Physics/rigidbody.h>
#include <TheRiseOfSuxalote/player_controller.h>
#include <Render/mesh.h>

namespace magma_game
{
	Red::Red() : penaltySpeed(0.0f), penaltyTime(0.0f), colisioned(false), startView(false)
	{

	}

	Red::~Red()
	{
		
	}

	bool Red::initComponent(std::map<std::string, std::string> args)
	{
		try {
			penaltySpeed = stof(args["penSpeed"]);
			penaltyTime = stof(args["penTime"]);
		}
		catch (std::exception& e) {
			std::cout << "WARNING! - error en un componente red:\n\n     " << e.what() << "\n\n";

			return false;
		}
		
		return true;
	}

	bool Red::start() 
	{
		rb = ent->getComponent<magma_engine::Rigidbody>();
		if (rb == nullptr) 
		{
			std::cout << "WARNING! el rigidbody es null en el start de red \n";
			return false;
		}

		penaltyTimer = ent->getComponent<Timer>();
		if (penaltyTimer == nullptr)
		{
			std::cout << "WARNING! timer es nullptr en el start de red \n";
			rb = nullptr;
			return false;
		}

		
		penaltyTimer->setTime(penaltyTime);
		//penaltyTimer->setVisible(false);
		//penaltyTimer->pause();
		

		return true;
	}

	void Red::update(float deltaTime)
	{	
		if (!startView)
		{
			penaltyTimer->setVisible(false);
			startView = true;
		}

		if (rb->isOnCollision() && !colisioned)
		{
			auto ents = rb->getCollisionObjs();
			for (auto e : ents)
			{
				if (e->hasComponent<PlayerController>())
				{
					onCollision(e);
					playerEnt = e;
				}
			}
		}

		if (colisioned)
		{
			if (penaltyTimer->getTime() <= 0)
			{
				playerEnt->getComponent<PlayerController>()->setVelocity(penaltySpeed);
				ent->setAlive(false);
			}
		}

	}

	void Red::onCollision(magma_engine::Entity* e)
	{
		e->getComponent<PlayerController>()->setVelocity(-penaltySpeed);

		penaltyTimer->setVisible(true);
		//penaltyTimer->resume();
		penaltyTimer->reset();

		colisioned = true;
		ent->getComponent<magma_engine::Mesh>()->setVisible(false);
	}

	void Red::onEnable()
	{
		penaltyTimer->setVisible(false);
	}
}
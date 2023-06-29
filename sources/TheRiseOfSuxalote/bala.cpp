#include <TheRiseOfSuxalote/bala.h>

#include <Input/input_manager.h>

#include <EC/scene_manager.h>
#include <EC/entity.h>
#include <EC/transform.h>
#include <TheRiseOfSuxalote/endgame.h>

namespace magma_game
{
	Bala::Bala() {}

	Bala::~Bala() {}

	bool Bala::initComponent(std::map<std::string, std::string> args)
	{
		try {
			velocidad = stoi(args["Vel"]);
			float dirX = stof(args["DirX"]);
			float dirY = stof(args["DirY"]);
			float dirZ = stof(args["DirZ"]);

			dir = magma_engine::Vector3D(dirX, dirY, dirZ);
		}
		catch (std::exception& e) {
			std::cout << "WARNING! - error en un componente endgame:\n\n     " << e.what() << "\n\n";

			return false;
		}
		return true;
	}

	bool Bala::start()
	{
		tr = ent->getComponent<magma_engine::Transform>();
		return (tr != nullptr);
	}

	void Bala::update(float deltaTime)
	{
		magma_engine::Entity* player = nullptr;
		for (magma_engine::Entity* e : Singleton<magma_engine::SceneManager>::instance()->getSceneEntities()) {
			if (e->hasComponent<Endgame>() && e->hasComponent<magma_engine::Transform>()) {
				player = e;
				break;
			}
		}

		if (player == nullptr)
			return;

		magma_engine::Transform* trPlayer = player->getComponent<magma_engine::Transform>();

		int xPlayerLeft = trPlayer->getPos().getX() - trPlayer->getW() * 2; int xPlayerRight = trPlayer->getPos().getX() + trPlayer->getW() * 2;
		int zPlayerUp = trPlayer->getPos().getZ() - trPlayer->getD() * 2; int zPlayerDown = trPlayer->getPos().getZ() + trPlayer->getD() * 2;

		int xLeft = tr->getPos().getX() - tr->getW() * 2; int xRight = tr->getPos().getX() + tr->getW() * 2;
		int zUp = tr->getPos().getZ() - tr->getD() * 2; int zDown = tr->getPos().getZ() + tr->getD() * 2;

		bool isCollidingX = (xPlayerRight >= xLeft) && (xPlayerLeft <= xRight);
		bool isCollidingZ = (zPlayerDown >= zUp) && (zPlayerUp <= zDown);

		bool isColliding = isCollidingX && isCollidingZ;

		if (isColliding) {
			Endgame* endPlayer = player->getComponent<Endgame>();
			endPlayer->winOrLose(false);
		}
		else {
			tr->setPosition(tr->getPos() + (dir * (velocidad * deltaTime)));
		}
	}
}
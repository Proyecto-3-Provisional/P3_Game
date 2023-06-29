#include <TheRiseOfSuxalote/mina.h>

#include <Input/input_manager.h>

#include <EC/entity.h>
#include <EC/transform.h>
#include <TheRiseOfSuxalote/endgame.h>

namespace magma_game
{
	Mina::Mina() {}

	Mina::~Mina() {}

	bool Mina::initComponent(std::map<std::string, std::string> args)
	{
		return true;
	}

	bool Mina::start()
	{
		rb = ent->getComponent<magma_engine::Rigidbody>();
		tr = ent->getComponent<magma_engine::Transform>();
		return (tr != nullptr && rb != nullptr);
	}

	void Mina::update(float deltaTime)
	{
		if (rb->isOnCollision()){
			auto colEnts = rb->getCollisionObjs();
			for (int i = 0; i < colEnts.size(); i++) {
				if (colEnts[i]->hasComponent<Endgame>()) {
					colEnts[i]->getComponent<Endgame>()->winOrLose(false);
				}
			}
		}
	}
}
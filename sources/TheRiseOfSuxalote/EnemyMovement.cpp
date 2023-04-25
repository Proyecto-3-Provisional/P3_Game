#include "EnemyMovement.h"

#include <math.h>

#include <EC/entity.h>
#include <Physics/rigidbody.h>

magma_game::EnemyMovement::EnemyMovement(int x, int z) : x(x), z(z)
{
}

magma_game::EnemyMovement::~EnemyMovement()
{
}

bool magma_game::EnemyMovement::initComponent()
{
	try {
		startMove();
		return true;
	}
	catch (...) {
		return false;
	}
}

void magma_game::EnemyMovement::startMove()
{
	float scale = sqrt(x * x + z * z);
	x = x / scale;
	z = z / scale;
	ent->getComponent<magma_engine::Rigidbody>()->addForce(magma_engine::Vector3D(x * velScale, 0, z * velScale));
}

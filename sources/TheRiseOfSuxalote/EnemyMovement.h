#pragma once

#include <EC/component.h>

namespace magma_game
{
	class EnemyMovement : public magma_engine::ec::Component
	{
	public:
		EnemyMovement(int x, int z);
		~EnemyMovement();

		bool initComponent() override;

	private:
		void startMove();

		int velScale = 1000;
		float x, z;
	};
}
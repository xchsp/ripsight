#include <assert.h>
#include <ctime>
#include "enemy_spawner.h"

void EnemySpawner::OnTick(float deltaTime)
{
	m_SpawnTimer += deltaTime;
	if (m_SpawnTimer >= m_SpawnRate)
	{
		Spawn();
		m_SpawnTimer = 0.0f;
	}
}

void EnemySpawner::Spawn()
{
	assert(m_MinSpawnCount < m_MaxSpawnCount);
	// TODO:
	// 1) Pick a random side to spawn new zombie(s). (Top, Right, Bottom or Left)
	// 2) Roll a random number and generate the zombie(s).
	// 3) Give the required position values to zombie(s).

	// Which side of the map we want to generate zombies in?
	int maxSide = 4;
	int minSide = 1;
	int sideIndex = std::rand() % (maxSide - minSide + 1) + minSide;

	// How many zombies are going to be spawned?
	// int count = std::rand() % (m_MaxSpawnCount - m_MinSpawnCount + 1) + m_MinSpawnCount;
	int count = 1;

	switch (sideIndex)
	{
	case 1: // Top
	{
		int randomHorizontalPosition = 0;
		randomHorizontalPosition = std::rand() % (m_EngineEntry->GetWindowWidth() - 0 + 1) + 0;
		for (int i = 0; i < count; i++)
		{
			engine::Actor* zombie = new engine::Actor("Zombie");
			BlueprintManager::CraftZombie(m_EngineEntry, zombie, engine::Vector2D(randomHorizontalPosition, -10.0f));
			GetOwner()->GetOwnerWorld()->AddActorRuntime(zombie);
		}
	}
		break;

	case 2: // Right
	{
		int randomVerticalPosition = std::rand() % (m_EngineEntry->GetWindowHeight() - 0 + 1) + 0;
		for (int i = 0; i < count; i++)
		{
			engine::Actor* zombie = new engine::Actor("Zombie");
			BlueprintManager::CraftZombie(m_EngineEntry, zombie, engine::Vector2D(m_EngineEntry->GetWindowWidth() + 10, randomVerticalPosition));
			GetOwner()->GetOwnerWorld()->AddActorRuntime(zombie);
		}
	}
		break;

	case 3: // Bottom
	{
		int randomHorizontalPosition = std::rand() % (m_EngineEntry->GetWindowWidth() - 0 + 1) + 0;
		for (int i = 0; i < count; i++)
		{
			engine::Actor* zombie = new engine::Actor("Zombie");
			BlueprintManager::CraftZombie(m_EngineEntry, zombie, engine::Vector2D(m_EngineEntry->GetWindowWidth() + 10, m_EngineEntry->GetWindowHeight() + 10.0f));
			GetOwner()->GetOwnerWorld()->AddActorRuntime(zombie);
		}
	}
		break;

	case 4: // Left
	{
		int randomVerticalPosition = std::rand() % (m_EngineEntry->GetWindowHeight() - 0 + 1) + 0;
		for (int i = 0; i < count; i++)
		{
			engine::Actor* zombie = new engine::Actor("Zombie");
			BlueprintManager::CraftZombie(m_EngineEntry, zombie, engine::Vector2D(0 - 10.0f, randomVerticalPosition));
			GetOwner()->GetOwnerWorld()->AddActorRuntime(zombie);
		}
	}
		break;
	}
}
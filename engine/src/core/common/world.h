#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>
#include "public/engine_entry.h"
#include "core/blueprints/components/box_collider_2D.h"
#include "core/blueprints/components/sprite_renderer.h"
#include "core/common/actor.h"

namespace engine
{
	// Contains entities and updates the game state frame by frame.
	class World
	{
	public:
		World(EngineEntry* engineEntry);
		World(EngineEntry* engineEntry, bool isActive);
		~World();

		// Will be called every frame to update components of actors in world.
		void Tick();

		// Adds given actor to world. 
		void AddActor(Actor* actor);

		Actor* GetActorByName(const std::string& name);

	private:
		bool m_IsActive = false;
		EngineEntry* m_EngineEntry = nullptr;
		std::vector<Actor*> m_Actors;
		std::vector<BoxCollider2D*> m_CollidersInWorld;

		void ProcessEvents();
		void UpdateActors(float deltaTime);
		void HandleCollisions();
		void Render();
	};
}

#endif // !WORLD_H
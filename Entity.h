#pragma once
#include "SubEntity.h"

class Entity
{
public:
	SubEntity* _sub_entity_ptr;

	Entity(const SubEntity& sub_entity);
	Entity(const Entity& other);
	Entity(Entity&& other) noexcept;
	Entity& operator=(const Entity& other);
	Entity& operator=(Entity&& other) noexcept;
	~Entity();
};


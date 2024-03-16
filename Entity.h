#pragma once
#include "SubEntity.h"

class Entity
{
public:
	SubEntity m_sub_entity;

	Entity(SubEntity&& sub_entity) noexcept;
	Entity(const Entity& other);
	Entity(Entity&& other) noexcept;
	Entity& operator=(const Entity& other);
	Entity& operator=(Entity&& other) noexcept;
	~Entity();
};


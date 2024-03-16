#include "Entity.h"

Entity::Entity(SubEntity&& sub_entity) noexcept
{
	std::cout << "Entity: Created!\n";

	m_sub_entity = std::move(sub_entity);
}

Entity::Entity(const Entity& other) 
{
	std::cout << "Entity: Copy!\n";

	m_sub_entity = other.m_sub_entity;
}

Entity::Entity(Entity&& other) noexcept
{
	std::cout << "Entity: Move!\n";

	m_sub_entity = std::move(other.m_sub_entity);
}

Entity& Entity::operator=(const Entity& other)
{
	std::cout << "Entity: Assignment Copy!\n";

	m_sub_entity = other.m_sub_entity;
	return *this;
}
Entity& Entity::operator=(Entity&& other) noexcept
{
	std::cout << "Entity: Assignment Move!\n";

	m_sub_entity = other.m_sub_entity;
	return *this;
}

Entity::~Entity()
{
	std::cout << "Entity: Destructed!\n";
}

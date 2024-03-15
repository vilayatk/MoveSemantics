#include "Entity.h"

Entity::Entity(const SubEntity& sub_entity)
{
	std::cout << "Entity: Created!\n";

	_sub_entity_ptr = new SubEntity(sub_entity);
}

Entity::Entity(const Entity& other) 
{
	std::cout << "Entity: Copy!\n";

	_sub_entity_ptr = new SubEntity(*other._sub_entity_ptr);
}

Entity::Entity(Entity&& other) noexcept
{
	std::cout << "Entity: Move!\n";

	_sub_entity_ptr = other._sub_entity_ptr;
	other._sub_entity_ptr = nullptr; // best practice to avoid double deletion and dangling pointers
}

Entity& Entity::operator=(const Entity& other)
{
	std::cout << "Entity: Assignment Copy!\n";

	_sub_entity_ptr = new SubEntity(*other._sub_entity_ptr);
	return *this;
}
Entity& Entity::operator=(Entity&& other) noexcept
{
	std::cout << "Entity: Assignment Move!\n";

	_sub_entity_ptr = other._sub_entity_ptr;
	other._sub_entity_ptr = nullptr;  // best practice to avoid double deletion and dangling pointers
	return *this;
}

Entity::~Entity()
{
	delete _sub_entity_ptr;
	std::cout << "Entity: Destructed!\n";
}

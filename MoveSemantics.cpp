#include <iostream>
#include "Entity.h"

int main()
{
	Entity entity(SubEntity("One", "Two", "Three"));
	std::cout << "=========Entity Created=========\n\n";

	std::cout << "Entity Move Constructor\n\n";
	Entity entity_2(std::move(entity));

	std::cout << "Value of entity 2 is " << entity_2._sub_entity_ptr->_some_string << std::endl;

	std::cout << "Value of entity is " << entity._sub_entity_ptr->_some_string << std::endl;;
	return 0;
}

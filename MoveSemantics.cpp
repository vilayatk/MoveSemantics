#include <iostream>

class SubEntity
{
public:
	std::string _some_string;
	std::string _some_string_2;
	std::string _some_string_3;

	SubEntity(const std::string& string_1, const std::string& string_2, const std::string& string_3)
	{
		std::cout << "Sub Entity: Created!\n";
		_some_string = string_1;
		_some_string_2 = string_2;
		_some_string_3 = string_3;
	}
	SubEntity(const SubEntity& other)
	{
		std::cout << "Sub Entity: Copy!\n";

		_some_string = other._some_string;
		_some_string_2 = other._some_string_2;
		_some_string_3 = other._some_string_3;
	}
	SubEntity(SubEntity&& other) noexcept
	{
		std::cout << "Sub Entity: Move!\n";

		_some_string = std::move(other._some_string);
		_some_string_2 = std::move(other._some_string_2);
		_some_string_3 = std::move(other._some_string_3);
	}
	SubEntity& operator=(const SubEntity& other)
	{
		std::cout << "Sub Entity: Asignment Copy!\n";

		*this = SubEntity(other);
		return *this;
	}
	SubEntity& operator=(SubEntity&& other) noexcept
	{
		std::cout << "Sub Entity: Asignment Move!\n";

		*this = SubEntity(other);
		return *this;
	}
	~SubEntity()
	{
		std::cout << "Sub Entity: Destructed!\n";
	}
};
class Entity
{
public:
	const double* arr = new double[100];
	SubEntity* _sub_entity_ptr;

	Entity(const SubEntity& sub_entity)
	{
		std::cout << "Entity: Created!\n";

		_sub_entity_ptr = new SubEntity(sub_entity);
	}
	Entity(SubEntity&& sub_entity)
	{
		std::cout << "Entity: Created RVal!\n";

		_sub_entity_ptr = new SubEntity(std::move(sub_entity));
	}

	Entity(const Entity& other)
	{
		std::cout << "Entity: Copy!\n";

		_sub_entity_ptr = new SubEntity(*other._sub_entity_ptr);
	}
	Entity(Entity&& other) noexcept
	{
		std::cout << "Entity: Move!\n";

		_sub_entity_ptr = other._sub_entity_ptr;
		//other._sub_entity_ptr = nullptr; // required
	}
	Entity& operator=(const Entity& other)
	{
		std::cout << "Entity: Assignment Copy!\n";

		*this = Entity(other);
		return *this;
	}
	Entity& operator=(Entity&& other) noexcept
	{
		std::cout << "Entity: Assignment Move!\n";

		*this = Entity(other);
		return *this;
	}
	~Entity()
	{
		std::cout << "Entity: Destructed!\n";
	}
};

int main()
{
	Entity entity(SubEntity("One", "Two", "Three"));
	std::cout << "=========Entity Created=========\n\n";

	std::cout << "Entity Move Constructor\n\n";
	Entity entity_2 = entity;
	return 0;
}

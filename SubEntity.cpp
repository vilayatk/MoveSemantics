#include "SubEntity.h"

SubEntity::SubEntity(const std::string& string_1, const std::string& string_2, const std::string& string_3)
{
	std::cout << "Sub Entity: Created!\n";
	_some_string = string_1;
	_some_string_2 = string_2;
	_some_string_3 = string_3;
}

SubEntity::SubEntity(const SubEntity& other)
{
	std::cout << "Sub Entity: Copy!\n";

	_some_string = other._some_string;
	_some_string_2 = other._some_string_2;
	_some_string_3 = other._some_string_3;
}

SubEntity::SubEntity(SubEntity&& other) noexcept
{
	std::cout << "Sub Entity: Move!\n";

	_some_string = std::move(other._some_string);
	_some_string_2 = std::move(other._some_string_2);
	_some_string_3 = std::move(other._some_string_3);
}

SubEntity& SubEntity::operator=(const SubEntity& other)
{
	std::cout << "Sub Entity: Asignment Copy!\n";

	_some_string = other._some_string;
	_some_string_2 = other._some_string_2;
	_some_string_3 = other._some_string_3;
	return *this;
}

SubEntity& SubEntity::operator=(SubEntity&& other) noexcept
{
	std::cout << "Sub Entity: Asignment Move!\n";

	this->_some_string = std::move(other._some_string);
	this->_some_string_2 = std::move(other._some_string_2);
	this->_some_string_3 = std::move(other._some_string_3);
	return *this;
} 

SubEntity::~SubEntity()
{
	std::cout << "Sub Entity: Destructed!\n";
}

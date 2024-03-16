#pragma once
#include <string>
#include <iostream>

class SubEntity
{
public:
	std::string _some_string;
	std::string _some_string_2;
	std::string _some_string_3;

	SubEntity() = default;
	SubEntity(const std::string& string_1, const std::string& string_2, const std::string& string_3);
	SubEntity(const SubEntity& other);
	SubEntity(SubEntity&& other) noexcept;
	SubEntity& operator=(const SubEntity& other);
	SubEntity& operator=(SubEntity&& other) noexcept;
	~SubEntity();
};



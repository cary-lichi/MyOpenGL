#pragma once
#include <glm/glm.hpp>

//²ÄÖÊ
class Light
{
public:
	Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position) {
		_ambient = ambient;
		_diffuse = diffuse;
		_specular = specular;
		_position = position;
	};
	~Light() {};
	glm::vec3 Ambient()
	{
		return _ambient;
	}
	void Ambient(glm::vec3 value)
	{
		_ambient = value;
	}

	glm::vec3 Diffuse()
	{
		return _diffuse;
	}
	void Diffuse(glm::vec3 value)
	{
		_diffuse = value;
	}

	glm::vec3 Specular()
	{
		return _specular;
	}
	void Specular(glm::vec3 value)
	{
		_specular = value;
	}

	glm::vec3 Pos()
	{
		return _position;
	}
	void Pos(glm::vec3 value)
	{
		_position = value;
	}
private:
	glm::vec3 _position;
	
	glm::vec3 _ambient;
	glm::vec3 _diffuse;
	glm::vec3 _specular;
};


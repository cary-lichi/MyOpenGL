#pragma once
#include <glm/glm.hpp>

//²ÄÖÊ
class Material
{
public:
	Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float _shinines) {
		_ambient = ambient;
		_diffuse = diffuse;
		_specular = specular;
		_shininess = _shinines;
	};
	~Material() {};
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

	float Shininess()
	{
		return _shininess;
	}
	void Shininess(float value)
	{
		_shininess = value;
	}
private:
	glm::vec3 _ambient;
	glm::vec3 _diffuse;
	glm::vec3 _specular;
	float _shininess;
};


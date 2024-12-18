#pragma once

#include <Shader.hpp>
#include <Object.hpp>

#ifndef LIGHT_H
#define LIGHT_H


namespace Machine {

	struct LightSpecs {
		glm::vec3 position;
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
	};

	class Light : public Object
	{
	private:
		LightSpecs lightVals;
	public:
		Light();
		Light(glm::vec3 Position);
		Light(glm::vec3 Position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
		void Use(const Shader &shader);
	};
}

#endif
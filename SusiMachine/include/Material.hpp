#pragma once

#include <glm/glm.hpp>
#include <Shader.hpp>
#include <Texture.hpp>

#ifndef MATERIAL_H
#define MATERIAL_H

namespace Machine {

	struct MatProperties
	{
		glm::vec3 ambientColor;
		glm::vec3 diffuseColor;
		glm::vec3 specularColor;
		float shineStrength;
	};

	class Material {
	private:
		MatProperties properties;
	public:
		Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shiny);
		void Use(const Shader &shaderRef);
		void Defaults() {
			properties.ambientColor = glm::vec3(1.0f, 0.5f, 0.31f);
			properties.diffuseColor = glm::vec3(1.0f, 0.5f, 0.31f);
			properties.specularColor = glm::vec3(0.5f, 0.5f, 0.5f);
			properties.shineStrength = 32.0f;
		}
		void SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shiny);
	};
}

#endif
#pragma once

#include <glm/glm.hpp>
#include <Shader.hpp>
#include <Texture.hpp>

#ifndef MATERIAL_H
#define MATERIAL_H

namespace Machine {

	struct MatProperties
	{
		Texture* specularMap;
		float shineStrength;
		Texture* diffuseMap;
	};

	class Material {
	private:
		MatProperties properties;
	public:
		Material();
		Material(Texture* specularMap_, Texture* diffuseMap_, float shiny_);
		void Use(const Shader& shaderRef);
		void Defaults() {
			properties.specularMap = new Texture("Resources/Textures/container2_specular.jpg", GL_TEXTURE_2D, 0, false);
			properties.shineStrength = 32.0f;
			properties.diffuseMap = new Texture("Resources/Textures/container2.png", GL_TEXTURE_2D, 1, false);
		}
	};
}

#endif
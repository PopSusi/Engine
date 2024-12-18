#include <Material.hpp>

namespace Machine {
	Material::Material() {
		this->properties.diffuseMap = new Texture("Resources/Textures/container.jpg", GL_TEXTURE_2D, 0, false);
		this->properties.specularMap = new Texture("Resources/Textures/container.jpg", GL_TEXTURE_2D, 0, false);
		this->properties.shineStrength = 32.0f;
	}
	Material::Material(Texture* specularMap_, Texture* diffuseMap_, float shiny_) {
		this->properties.diffuseMap = diffuseMap_;
		this->properties.specularMap = specularMap_;
		this->properties.shineStrength = shiny_;
	}
	void Material::Use(const Shader& shaderRef) {
		shaderRef.setFloat("material.shiny", this->properties.shineStrength);
		this->properties.diffuseMap->Bind();
		shaderRef.setInt("material.diffuse", 0);
		this->properties.specularMap->Bind();
		shaderRef.setInt("material.specular", 1);
	}
}


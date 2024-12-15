#include <Material.hpp>

namespace Machine {

	void Material::SetValues(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shiny) {
		this->properties.ambientColor = ambient;
		this->properties.diffuseColor = diffuse;
		this->properties.specularColor = specular;
		this->properties.shineStrength = shiny;
	}
	void Material::Use(const Shader& shaderRef) {
		shaderRef.setVec3("material.ambient", this->properties.ambientColor);
		shaderRef.setVec3("material.diffuse", this->properties.diffuseColor);
		shaderRef.setVec3("material.specular", this->properties.specularColor);
		shaderRef.setFloat("material.shininess", this->properties.shineStrength);
	}
	Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shiny) {
		this->properties.ambientColor = ambient;
		this->properties.diffuseColor = diffuse;
		this->properties.specularColor = specular;
		this->properties.shineStrength = shiny;
	}
}


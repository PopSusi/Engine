#include <Light.hpp>

namespace Machine {
	Light::Light(){
		this->worldPos = glm::vec3(0.0f, 0.0f, 0.0f);
		this->lightVals.ambient = glm::vec3(0.2f, 0.2f, 0.2f);
		this->lightVals.diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
		this->lightVals.specular = glm::vec3(1.0f, 1.0f, 1.0f);
	}
	Light::Light(glm::vec3 Position) {
		this->worldPos = Position;
		this->lightVals.ambient = glm::vec3(0.2f, 0.2f, 0.2f);
		this->lightVals.diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
		this->lightVals.specular = glm::vec3(1.0f, 1.0f, 1.0f);
	}
	Light::Light(glm::vec3 Position, glm::vec3 ambient_, glm::vec3 diffuse_, glm::vec3 specular_) {
		this->worldPos = Position;
		this->lightVals.ambient = ambient_;
		this->lightVals.diffuse = diffuse_;
		this->lightVals.specular = specular_;
	}
	void Light::Use(const Shader &shader) {
		shader.setVec3("light.ambient", this->lightVals.ambient);
		shader.setVec3("light.diffuse", this->lightVals.diffuse);
		shader.setVec3("light.specular", this->lightVals.specular);
		shader.setVec3("light.position", this->lightVals.position);
	}
}

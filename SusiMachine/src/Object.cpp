#include <Object.h>
#include <cmath>

using namespace Machine;

	Object::Object(){
		//std::cout << "Empty declare" << std::endl;
	}
	Object::Object(glm::vec3 Position) {
		//std::cout << "Full declare" << std::endl;
		this->worldPos = Position;
	}
	void Object::Translate(glm::vec3 deltaTranslation) {
		this->worldPos += glm::vec3(deltaTranslation);
		this->worldPos += glm::vec3(deltaTranslation.x, deltaTranslation.y, deltaTranslation.z);
		//std::cout << translation.x << std::endl;
		//std::cout << worldTrans.x << std::endl;
	}
	void Object::Rotate(glm::vec3 deltaRotation) {
		glm::vec3 forward;
		forward.x = cos(glm::radians(deltaRotation.x)) * cos(glm::radians(deltaRotation.y));
		forward.y = -sin(glm::radians(deltaRotation.y));
		forward.z = sin(glm::radians(deltaRotation.x)) * cos(glm::radians(deltaRotation.y));
		//this->worldRot += deltaRotation;
		forwardVec = glm::normalize(forward);
		rightVec = glm::normalize(glm::cross(forwardVec, glm::vec3(0.0f, 1.0f, 0.0f)));
		upVec = glm::normalize(glm::cross(forwardVec, rightVec));

		/*
		std::cout << forwardVec.x;
		std::cout << ", ";
		std::cout << forwardVec.y;
		std::cout << ", ";
		std::cout << forwardVec.z << std::endl;
		*/

		//std::cout << deltaRotation.x << std::endl;
		//std::cout << worldTrans.x << std::endl;
	}
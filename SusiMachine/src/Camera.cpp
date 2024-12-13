
#include <Camera.h>
using namespace glm;

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

namespace Machine {
	void Camera::InitializeDirections() {
		this->cameraTarget = vec3(0.0f, 0.0f, 0.0f);
		this->forwardVec = normalize(getWorldPosition() - cameraTarget);
		this->upVec = vec3(0.0f, 1.0f, 0.0f);
		this->rightVec = normalize(cross(upVec, forwardVec));
		std::cout << forwardVec.x;
		std::cout << ", ";
		std::cout << forwardVec.y;
		std::cout << ", ";
		std::cout << forwardVec.z << std::endl;
	}
}
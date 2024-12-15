#pragma once

#include <Object.hpp>

#ifndef CAMERA_H
#define CAMERA_H


using namespace glm;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
namespace Machine {
	class Camera : public Machine::Object {
	private:
		vec3 cameraTarget;
		void InitializeDirections();
		void UpdateCameraVectors();
	public:
		Camera() {
			vec3 cameraTarget = vec3(0.0f, 0.0f, 0.0f);
			InitializeDirections();
		}
		Camera(vec3 Position) {
			this->worldPos = Position;
			InitializeDirections();
		}
		inline vec3 getForward() { return forwardVec; };
		inline vec3 getRight() { return rightVec; };
		inline vec3 getUp() { return upVec; };
		mat4 GetViewMatrix() { return lookAt(worldPos, worldPos + forwardVec, upVec); }
		void ProcessKeyboard(float deltaTime);
	};
};

#endif
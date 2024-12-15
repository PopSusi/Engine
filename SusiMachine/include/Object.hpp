#pragma once

#include <glm/glm.hpp>
#include <Texture.hpp>
#include <iostream>

#ifndef OBJECT_H
#define OBJECT_H

namespace Machine {
	class Object {
	protected:
        glm::vec3 worldPos;
        glm::vec3 worldRot;
        glm::vec3 forwardVec;
        glm::vec3 upVec;
        glm::vec3 rightVec;
		Texture* texture;
        void InitializeDirections();
	public:
        static const float vertices[288];

        Object();
		Object(glm::vec3 Position);
		inline glm::vec3 getWorldPosition() { return worldPos; }
        inline glm::vec3 getWorldPos() { return worldPos; }
        inline glm::vec3 getWorldRotation() { return worldRot; }

        void Translate(glm::vec3 deltaTranslation);
        void Rotate(glm::vec3 deltaRot);
	};
}

#endif
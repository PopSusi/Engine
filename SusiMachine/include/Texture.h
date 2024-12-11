#pragma once

#include <GLFW/glfw3.h>
namespace Machine {
	class Texture {
	public:
		Texture(const char* path, GLenum type);
		void Bind();
	};
}
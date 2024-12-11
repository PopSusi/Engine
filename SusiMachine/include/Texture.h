#pragma once

#include <GLFW/glfw3.h>
namespace Machine {
	class Texture {
	private:
		GLuint id;
		int size;

	public:
		Texture(const char* path, GLenum type);
		~Texture();
		void Bind();
	};
}
#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GLFW/glfw3.h>
namespace Machine {
	class Texture {
	private:
		GLuint id;
		int size;
		GLenum typeof;
		GLint textureUnit;

	public:
		Texture(const char* path, GLenum type, GLint texture_Unit, bool flip);
		void Bind();

		~Texture();
		inline GLuint getID() const { return this->id; }
		inline GLuint getUnit() const { return this->textureUnit; }
	};
}
#endif
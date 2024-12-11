#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <Texture.h>

namespace Machine {
		Texture::Texture(const char* path, GLenum type) {
            int nrChannels;
            unsigned char* data = stbi_load("Resources/Textures/container.jpg", &size, &size, &nrChannels, 0);
            glGenTextures(1, &this->id);
            glBindTexture(type, this->id); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object

            // set the texture wrapping parameters
            glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);

            // set texture filtering parameters
            glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
            if (data)
            {
                glTexImage2D(type, 0, GL_RGB, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(type);
            }
            else
            {
                std::cout << "Failed to load texture" << std::endl;
            }
            stbi_image_free(data);
		}

        Texture::~Texture() {
            glDeleteTextures(1, &this->id);
        }

        void Texture::Bind() {
            glBindTexture(GL_TEXTURE_2D, id);
        }
	};
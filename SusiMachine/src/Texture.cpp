#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <Texture.h>

namespace Machine {
		Texture::Texture(const char* path, GLenum type, GLint texture_Unit, bool flip) {
            int nrChannels;
            typeof = type;
            textureUnit = texture_Unit;

            if(flip) stbi_set_flip_vertically_on_load(true);

            unsigned char* data = stbi_load(path, &size, &size, &nrChannels, 0);
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
                GLint channelType;
                if (nrChannels == 3) {
                    channelType = GL_RGB;
                }
                else if (nrChannels == 4) {
                    channelType = GL_RGBA;
                }
                else {
                    std::cout << "Invalid nrChannels of: " + nrChannels << std::endl;
                }
                glTexImage2D(type, 0, channelType, size, size, 0, channelType, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(type);
                std::cout << "Loaded texture from: " << std::endl;
            }
            else
            {
                std::cout << "Failed to load texture from: " << std::endl;
            }
            stbi_image_free(data);
		}

        Texture::~Texture() {
            glDeleteTextures(1, &this->id);
        }

        void Texture::Bind() {
            glActiveTexture(GL_TEXTURE0 + this->textureUnit);
            glBindTexture(typeof, this->id);
        }
	};
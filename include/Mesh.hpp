#pragma once

#include <glm/glm.hpp>
#include <Texture.hpp>
#include <vector>
#include <Shader.hpp>
#ifndef MATERIAL_H
#define MATERIAL_H

namespace Machine {

    struct Vertex{
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
    };

    class Mesh
    {
        public:
            std::vector<Vertex> vertices;
            std::vector<GLuint> indices;
            std::vector<Texture> textures;
            Mesh(std::vector<Vertex> vertices_, std::vector<GLuint> indices_, std::vector<Texture> textures_);
            void Draw(Shader &shader);
        private:
            GLuint VAO, VBO, EBO;
            void setupMesh();
    };
}

#endif
#include "Mesh.hpp"
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <string.h>

namespace Machine{
    Mesh::Mesh(std::vector<Vertex> vertices_, std::vector<GLuint> indices_, std::vector<Texture> textures_){
        this->vertices = vertices_;
        this->indices = indices_;
        this->textures = textures_;

        this->setupMesh();
    }
    void Mesh::setupMesh(){
        glGenVertexArrays(1, &this->VAO);
        glGenBuffers(1, &this->VBO);
        glGenBuffers(1, &this->EBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).

        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glBindBuffer(GL_ARRAY_BUFFER, this->EBO);
        glBufferData(GL_ARRAY_BUFFER, this->vertices.size(), &this->vertices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(Vertex), (GLvoid*)0);
        // tex coord attribute
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

        glBindVertexArray(0);
    }
    void Mesh::Draw(Shader &shader){
        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;
        for(unsigned int i = 0; i < textures.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding
            // retrieve texture number (the N in diffuse_textureN)
            std::string number;
            std::string name = reinterpret_cast<const char*>(glGetString(textures[i].myType));
            if(name == "texture_diffuse")
                number = std::to_string(diffuseNr++);
            else if(name == "texture_specular")
                number = std::to_string(specularNr++);

            shader.setInt(("material." + name + number).c_str(), i);
            glBindTexture(GL_TEXTURE_2D, textures[i].getID());
        }
        glActiveTexture(GL_TEXTURE0);

        // draw mesh
        glBindVertexArray(this->VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}   
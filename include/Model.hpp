#pragma once

#include <glad.h>
#include <glm/glm.hpp>
#include <Texture.hpp>
#include <Mesh.hpp>
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#ifndef MODEL_H
#define MODEL_H

namespace Machine
{
    class Model{
        private:
            std::string directory;
            std::vector<Mesh> meshes;

            void loadModel(std::string path);
            void loadModel(std::string path);
            void processNode(aiNode *node, const aiScene *scene);
            Mesh processMesh(aiMesh *mesh, const aiScene *scene);
            std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
        public:
            Model(char *path){
                loadModel(path);
            }
            void Draw(Shader *shader);
    };
} // namespace Machine


#endif

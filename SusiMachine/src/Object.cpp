#include<iostream>

#include <Object.h>
using namespace Machine;

	Object::Object(){
		//std::cout << "Empty declare" << std::endl;
	}
	Object::Object(glm::vec4 worldTrans, Texture* texIn) {
		//std::cout << "Full declare" << std::endl;
		this->worldTrans = worldTrans;
		this->texture = texIn;
	}
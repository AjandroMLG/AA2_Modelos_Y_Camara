#pragma once
#include "Model.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "glm.hpp"

#define MODEL_MANAGER ModelManager::Instance()

class ModelManager
{
private:

	ModelManager() = default;
	ModelManager(const ModelManager&) = delete;
	ModelManager& operator =(const ModelManager&) = delete;
public:

	std::vector<Model> models;

	inline static ModelManager& Instance()
	{
		static ModelManager objectManager;
		return objectManager;
	}
	~ModelManager()
	{}

	 Model LoadOBJModel(const std::string& filePath, Textura* textura);	

	 void InitializeModels();

};
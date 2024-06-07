#pragma once
#include "MatrixTools.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gtc/type_ptr.hpp>
#include <vector>
#include "ModelManager.h"

class Scene
{
	std::vector<GLuint> compiledPrograms;
	std::vector<glm::vec3> spawnPositions;
public:
	Scene(std::vector<GLuint> compiledPrograms) : compiledPrograms(compiledPrograms)
	{
		spawnPositions.push_back(glm::vec3(0, 0, -2));
		spawnPositions.push_back(glm::vec3(1.5, 0, 0.5));
		spawnPositions.push_back(glm::vec3(-1.5, 0, 1));
		spawnPositions.push_back(glm::vec3(-1.75, 0, 0.75));
		spawnPositions.push_back(glm::vec3(0, 0, 0));
		spawnPositions.push_back(glm::vec3(1, 0, -1));
		spawnPositions.push_back(glm::vec3(2, 0, 2));
		spawnPositions.push_back(glm::vec3(-2, 0, 2));
		spawnPositions.push_back(glm::vec3(-2, 0, -2));
		spawnPositions.push_back(glm::vec3(2, 0, -1));
	}

	 std::vector<GameObject*> GenerateMap(int amount)
	{
		 std::vector<GameObject*> gameObjects;
		for (int i = 0; i < amount; i++)
		{
			//models.push_back(ModelManager::LoadOBJModel("Assets/Models/troll.obj", compiledPrograms[0],spawnPositions[0], glm::vec3(0, 1, 0), 0, glm::vec3(0.7f), glm::vec4(0.5, 0.5, 0.5, 1.0f)));
			gameObjects.push_back(new GameObject(compiledPrograms[0], spawnPositions[MatrixTools::RandonNumberBetween(0, spawnPositions.size() - 1)], glm::vec3(0, 1, 0), glm::vec3(MatrixTools::RandomNumberBetweenFloat(0.3,1)), MODEL_MANAGER.models[MatrixTools::RandonNumberBetween(0, 3)]));

		}
		return gameObjects;
	}

};
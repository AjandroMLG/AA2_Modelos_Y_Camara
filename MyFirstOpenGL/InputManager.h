#pragma once
#include "camera.h"

class InputManager
{
    Camera& camera;
    GLFWwindow* window;
    bool keyPressed;
    double xPos, yPos;

public:

    InputManager(Camera& camera, GLFWwindow* window);
    void Update();   
};

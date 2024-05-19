#pragma once
#include "camera.h"

class InputManager
{
    Camera& camera;
    GLFWwindow* window;
    bool keyPressed;

public:

    InputManager(Camera& camera, GLFWwindow* window);
    void Update();   
};

#pragma once
#include "camera.h"

class InputManager
{
    Camera& camera;
    GLFWwindow* window;
    bool keyPressed;
    bool flashLight = true;
    double xPos, yPos;

public:

    InputManager(Camera& camera, GLFWwindow* window);
    bool GetFlash();
    void Update();   
};

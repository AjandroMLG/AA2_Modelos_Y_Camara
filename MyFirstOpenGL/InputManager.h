#pragma once
#include "camera.h"

class InputManager
{
    Camera& camera;
    GLFWwindow* window;
    bool keyPressed;

public:

    InputManager(Camera& camera, GLFWwindow* window)
        : camera(camera), window(window) {
       
        keyPressed = false;
    }

    void Update()
    {
        if (!keyPressed)
        {    
            
            if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS )
            {
                camera.ChangeCamera(1);
                keyPressed = true;
            }
            else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS )
            {
                camera.ChangeCamera(2);
                keyPressed = true;
            }
            else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS )
            {
                camera.ChangeCamera(3);
                keyPressed = true;
            }
        }
        else {
            // Aqu� se establece keyPressed como false solo si ninguna tecla est� presionada
            if (
                glfwGetKey(window, GLFW_KEY_1) != GLFW_PRESS &&
                glfwGetKey(window, GLFW_KEY_2) != GLFW_PRESS &&
                glfwGetKey(window, GLFW_KEY_3) != GLFW_PRESS) {
                keyPressed = false;
            }
        }
    }       
};

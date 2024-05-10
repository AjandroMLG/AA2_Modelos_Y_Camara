#pragma once
#include "Cube.h"

/*class InputManager
{
    GameObject* cube;
    GameObject* pyramid;
    GameObject* orthohedron;
    GLFWwindow* window;
    bool wireFrameView;
    bool keyPressed;

public:
    bool paused;

    InputManager(GameObject* cube, GameObject* pyramid, GameObject* orthohedron, GLFWwindow* window)
        : cube(cube), pyramid(pyramid), orthohedron(orthohedron), window(window) {
        wireFrameView = false;
        keyPressed = false;
        paused = false;
    }

    void Update()
    {
        if (!keyPressed)
        {
            if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && !paused)
            {
                cube->SpeedUp();
                pyramid->SpeedUp();
                orthohedron->SpeedUp();
                keyPressed = true;
            }
            else if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS && !paused )
            {
                cube->SpeedDown();
                pyramid->SpeedDown();
                orthohedron->SpeedDown();
                keyPressed = true;
            }
            else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && !paused)
            {
                if (!wireFrameView)
                {
                    wireFrameView = !wireFrameView;
                    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                }
                else
                {
                    wireFrameView = !wireFrameView;
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                }
                keyPressed = true;
            }
            else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && !paused)
            {
                cube->ChangeRender();
                keyPressed = true;
            }
            else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && !paused)
            {
                orthohedron->ChangeRender();
                keyPressed = true;
            }
            else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && !paused)
            {
                pyramid->ChangeRender();
                keyPressed = true;
            }
            else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
            {
                paused = !paused;
                keyPressed = true;
            }
        }
        else {
            // Aquí se establece keyPressed como false solo si ninguna tecla está presionada
            if (glfwGetKey(window, GLFW_KEY_M) != GLFW_PRESS &&
                glfwGetKey(window, GLFW_KEY_N) != GLFW_PRESS &&
                glfwGetKey(window, GLFW_KEY_1) != GLFW_PRESS &&
                glfwGetKey(window, GLFW_KEY_2) != GLFW_PRESS &&
                glfwGetKey(window, GLFW_KEY_3) != GLFW_PRESS &&
                glfwGetKey(window, GLFW_KEY_4) != GLFW_PRESS &&
                glfwGetKey(window, GLFW_KEY_SPACE) != GLFW_PRESS) {
                keyPressed = false;
            }
        }
    }       
};
*/
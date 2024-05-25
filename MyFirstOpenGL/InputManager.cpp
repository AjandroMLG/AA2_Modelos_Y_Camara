#include "InputManager.h"
#include <glm.hpp>

InputManager::InputManager(Camera& camera, GLFWwindow* window) : camera(camera), window(window)
{
    keyPressed = false;
}

void InputManager::Update()
{
    if (!keyPressed)
    {

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            camera.GoFront();
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {            
            camera.GoLeft();
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            camera.GoBack();
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            camera.GoRight();
        }
    }
    else {
        // Aquí se establece keyPressed como false solo si ninguna tecla está presionada,3#
        if (
            glfwGetKey(window, GLFW_KEY_W) != GLFW_PRESS &&
            glfwGetKey(window, GLFW_KEY_S) != GLFW_PRESS &&
            glfwGetKey(window, GLFW_KEY_A) != GLFW_PRESS &&
            glfwGetKey(window, GLFW_KEY_D) != GLFW_PRESS) {
            keyPressed = false;
        }
    }
    glfwGetCursorPos(window, &xPos, &yPos);

    float xoffset = xPos - camera.lastX;
    float yoffset = camera.lastY - yPos; // Invertido porque los sistemas de coordenadas de Y van al revés
    camera.lastX = xPos;
    camera.lastY = yPos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    camera.yaw += xoffset;
    camera.pitch += yoffset;

    // Asegurarse de que pitch no pase de los límites
    if (camera.pitch > 89.0f)
        camera.pitch = 89.0f;
    if (camera.pitch < -89.0f)
        camera.pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    front.y = sin(glm::radians(camera.pitch));
    front.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.front = glm::normalize(front);


}


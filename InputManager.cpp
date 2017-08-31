#include "InputManager.h"

void InputManager::Update(){
    if(Keyboard::KeyDown(GLFW_KEY_ESCAPE)){
        glfwTerminate();
    }
}

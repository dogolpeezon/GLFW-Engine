#include "Mouse.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = {0};
bool Mouse::buttonDown[GLFW_MOUSE_BUTTON_LAST] = {0};
bool Mouse::buttonUp[GLFW_MOUSE_BUTTON_LAST] = {0};

void Mouse::MousePosCallback(GLFWwindow* window, double _x, double _y){

 
}


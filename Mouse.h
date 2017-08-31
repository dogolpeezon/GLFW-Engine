#ifndef MOUSE
#define MOUSE
#include <GLFW/glfw3.h>

class Mouse
{
public:
    static void MousePosCallback(GLFWwindow* window_, double _x, double _y);
    static void MouseButtonCllaback(GLFWwindow* window, int button, int action, int mods);

    static double GetMouseX();
    static double GetMouseY();

    static bool ButtonUp(int button);
    static bool ButtonDown(int button);
    static bool Button(int button);
    
private:
    static double x;
    static double y;

    static bool buttons[];
    static bool buttonDown[];
    static bool buttonUp[];

};

#endif
#ifndef ENGINE
#define ENGINE
/* #elif defined(__linux__)
    #define OS_LINUX
#else
    #error "unknown platform" */
#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>

class Engine{
public:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;

    Engine();
    ~Engine();
    

    bool Initialize(const char* windowTitle);
    void Update();
    void Input();
    void BeginRender();
    void EndRender();

private:
    static GLFWwindow* window;
};
#endif

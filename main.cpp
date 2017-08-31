#include "Engine.h"
#include "Keyboard.h"
#include "InputManager.h"
#include <iostream>
using namespace std;

int main(void){
    cout << "Entered main...";

    Engine engine;
    engine.Initialize("GLFW window title");

    //InputManager im;

while(true){
     engine.Update();
     //engine.Input();
     //im.Update();
     engine.BeginRender();
     engine.EndRender();
 }

    return 0;
}

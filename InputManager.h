#ifndef INPUTMANAGER
#define INPUTMANAGER

#include "Engine.h"
#include "Keyboard.h"

class InputManager{
public:
    InputManager();
    InputManager(Keyboard* _Key);
    void Update();
private:

};
#endif

#ifndef EMULATOR_H_
#define EMULATOR_H_

#include "CommandInterface.h"
#include "UserInterface.h"

class Emulator
{
public:
    Emulator();

    int powerOn();
    int powerOff();
    int quit();
    
    virtual ~Emulator();

private:
    UserInterface ui;
    CommandInterface ci;

    bool state;

};

#endif // EMULATOR_H_

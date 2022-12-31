#include "Emulator.h"

Emulator::Emulator()
    : ui(UserInterface()), ci(CommandInterface()), state(false)
{

}

int Emulator::powerOn()
{
    ui.run();
    ci.run();
    state = true;
    return 0; }

int Emulator::powerOff()
{
    return 0;
}

int Emulator::quit()
{
    return 0;
}

Emulator::~Emulator()
{

}
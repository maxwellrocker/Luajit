#include "../include/airplane.h"

airplane::airplane()
{
    //ctor
    seat = 0;
    type = "";
}

airplane::~airplane()
{
    //dtor
}

void airplane::setSeat(int _seat)
{
    seat = _seat;
}
int airplane::getSeat()
{
    return seat;
}
void airplane::setType(const char* _type)
{
    type = _type;
}
const char* airplane::getType()
{
    return type;
}

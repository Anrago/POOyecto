#include "Snake.h"

Snake::Snake()
{
    Header = {5, 3};
    Tail = {7,2};
}

Snake::Snake(Vector2 Header, Vector2 Tail)
{
    this->Header = Header;
    this->Tail = Tail;
}
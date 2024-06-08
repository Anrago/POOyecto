#include "raylib.h"

class Snake
{
public:
    Vector2 Header;
    Vector2 Tail;

    Texture2D skin;
    
    Snake();
    Snake(Vector2 Header,Vector2 Tail);
    Rectangle DrawSnake(int PosX, int PosY,int CELL_SIZE, int PADDING);
    // Definir textura con o sin posicion, (Igual creo que no es necesario definir la posicion)
    void DefineSkin();
    void FreeSkin();
};



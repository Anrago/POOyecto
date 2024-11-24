#include "raylib.h"

class Snake
{
public:
    Vector2 header;
    Vector2 tail;

    Texture2D skin;
    
    Snake();
    Snake(Vector2 header,Vector2 tail);
    Rectangle DrawSnake(int PosX, int PosY,int CELL_SIZE, int PADDING);
    // Definir textura con o sin posicion, (Igual creo que no es necesario definir la posicion)
    void DefineSkin();
    void FreeSkin();
};



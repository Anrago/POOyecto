#include "raylib.h"
#include "Dice.h"
class Player
{
public:
    short int numPlayer;
    Color playerColor;
    Texture2D skin;
    Vector2 position = {0,9};
    bool win= false;
    
    Player(short int numPlayer=1,Color playerColor = BLUE);
    // Solo dibuja el jugador
    void DrawPlayer(int posX, int posY, int cellSize, int padding);
    
    // retorna la posicion actual del jugador
    Rectangle BoxPlayer(int posX, int posY, int cellSize, int padding);
    
    void Move(int NumCas);
    void DefineSkins(int index);
    void DefineSkin();
    void DefineSkin2();
    void DefineSkin3();
    void DefineSkin4();

    Vector2 GetPosition();
};
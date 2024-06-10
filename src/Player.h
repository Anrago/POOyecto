#include "raylib.h"
#include "Dice.h"
class Player
{
public:
    short int NumPlayer;
    Color PlayerColor;
    Texture2D skin;
    Vector2 Position = {0,9};
    
    Player(short int NumPlayer=1,Color PlayerColor = BLUE);
    // Solo dibuja el jugador
    void DrawPlayer(int PosX, int PosY,int CELL_SIZE, int PADDING);
    // retorna la posicion actual del jugador
    Rectangle BoxPlayer(int PosX, int PosY,int CELL_SIZE, int PADDING);
    
    void Move(int NumCas);
    void DefineSkin();
    void DefineSkin2();
    void DefineSkin3();
    void DefineSkin4();

    Vector2 GetPosition();

    //virtual int Roll();


};
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Board.h"

/*      POOYECTO-SNAKE AND LADDERS

El pooyecto sera un serpientes y escaleras


COMANDOS
cd build
mingw32-make
./name.exe

*/

typedef enum Screen{
    MENU,
    PLAYER_SELECTION,
    GAME,
    WINNERS,
    EXIT
}Screen;

// ---------------------- Prototipos ---------------------- //
Screen DrawMenu(int screenWidth, int screenHeight);
void DrawExit(int screenWidth, int screenHeight);
void DrawGame (int screenWidth, int screenHeight, int NumPlayers,int NumDice, Board Tablero, Dice dado);
void Wait3Seconds();

// ---------------------- Main ---------------------- //
int main()
{
    // Ventana
    int screenWidth = 1280;
    int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "SerpientesyEscaleras");
    SetTargetFPS(60);
    srand(time(NULL));
    
    // Jugadores actuales jugando, esto por default, pero debera de actualizarse en la pantalla de players select
    int PlayerPlaying=2;
    
    // Tablero
    Board Tablero(PlayerPlaying);
    // Definimos la textura de las serpientes
    Tablero.DefineSnakeTexture();
    
    // Dados
    Dice dado;
    // Numero de dados con los que juagaran, igual se actualizaria en players select
    int NumDice=2;

    // Escena actual
    Screen currentScreen=MENU;

    bool exit = false;
    while (!WindowShouldClose() && exit == false)
    {
        switch (currentScreen)
        {
        case MENU:
        {
            currentScreen = DrawMenu(screenWidth,screenHeight);
            break;
        }
        case PLAYER_SELECTION:
        {
            break;
        }
        case GAME:
        {
            DrawGame(screenWidth,screenHeight,PlayerPlaying,NumDice,Tablero,dado);
            break;
        }
        case EXIT:
        {
            DrawExit(screenWidth,screenHeight);
            exit = true;
            break;
        }
        default:
            break;
        }
    }
    CloseWindow();

    // Liberamos memoria
    Tablero.FreeSnakeTexture();
    return 0;
}

// ---------------------- Menu y pantallas de movimiento ---------------------- //

Screen DrawMenu(int screenWidth, int screenHeight){
    
    // -------- Texturas -------- //
    Texture2D background = LoadTexture("../assets/MenuBackgroundClean.png");

    Texture2D startButton = LoadTexture("../assets/buttons/StartButtonDef.png");
    Texture2D exitButton = LoadTexture("../assets/buttons/ExitButton.png");

    // -------- Botones -------- //
    
    // Rec de iniciar
    Rectangle StartR;
    StartR.x=(screenWidth / 2) - (startButton.width / 2);
    StartR.y=screenHeight *0.57;
    StartR.width=startButton.width;
    StartR.height=startButton.height;

    // Posicion del boton de iniciar
    Vector2 StartV;
    StartV.x=StartR.x;
    StartV.y=StartR.y;

    // Rec de salida
    Rectangle ExitR;
    ExitR.x=(screenWidth / 2) - (exitButton.width / 2);
    ExitR.y=screenHeight * 0.77;
    ExitR.width=exitButton.width;
    ExitR.height=exitButton.height;

    // Posicion del boton de salida
    Vector2 ExitV;
    ExitV.x=ExitR.x;
    ExitV.y=ExitR.y;

    // Salida
    bool finish = false;

    Vector2 mouse;
    Vector2 click;


    while (finish== false)
    {
        BeginDrawing();
            mouse=GetMousePosition();

            // Checamos cada que da click en que posicion, y la almacenamos en click
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                click=mouse;
            }

            // Menu
            DrawTexture(background,0,0,WHITE);
            // Boton de iniciar
            DrawTextureEx(startButton,StartV,0.0f,1.0f,WHITE);
            // Boton de salir
            DrawTextureEx(exitButton,ExitV,0.0f,1.0f,WHITE);
            

            if(CheckCollisionPointRec(click,StartR)){
                // No deberia de ser game, deberia de ser la seleccion de cuantos personajes va a querer
                return GAME;
            }
            
            if(CheckCollisionPointRec(click,ExitR)){
                return EXIT;
            }

        EndDrawing();
    }
    return MENU;
}

void DrawExit(int screenWidth, int screenHeight){
    Texture2D background = LoadTexture("../assets/GOODBYE.png");

    float timetolive=1.5f;
    float actualtime=0.0f;
    
    while(actualtime <=timetolive){
        BeginDrawing();
            actualtime+=GetFrameTime();
            DrawTexture(background,0,0,WHITE);
        EndDrawing();
    }
    UnloadTexture(background);

}

void DrawGame (int screenWidth, int screenHeight, int NumPlayers,int NumDice, Board Tablero, Dice dado){
    // ------------ Recursos ------------ //
    
    Texture2D background = LoadTexture("../assets/GameBackground.png");
    
    Texture2D Dice = LoadTexture("../assets/DiceJoin.png");

    Font fuente = LoadFont("../assets/fuente/Minecraft.ttf");

    // ----------- Textos ------------- //
    char actualPlayer[4][10] = {"Player 1","Player 2","Player 3","Player 4"};

    // Posicion del texto
    Vector2 playerV;
    playerV.x= screenWidth *0.69;
    playerV.y= screenHeight *0.13;
    
    Vector2 diceV;
    diceV.x= (screenWidth *0.50) - 41;
    diceV.y= (screenHeight *0.50) - 41;
    
    Vector2 TdiceV;
    TdiceV.x= (screenWidth *0.55) - (Dice.width / 2);
    TdiceV.y= (screenHeight *0.65) - (Dice.height / 2);

    Vector2 TplayerV;
    TplayerV.x = screenWidth *0.20;

    char diceResultado[3];
    
    // turno y movimiento de jugadores
    int playerTurn=0;
    int playerMove=0;

    // tiempo de espera
    float timetolive=1.0f;
    float actualtime=0.0f;

    bool finish = false;

    // Mascara
    Color maskColor = {1,1,1,50};
    Rectangle maskV = {0,0,float(screenWidth),float(screenHeight)};

    /*
        
        Dibujar una forma de mostrar el ganador,
        Sonidos
    */

    while(finish == false){
        BeginDrawing();
            DrawTexture(background,0,0,WHITE);
            Tablero.DrawBoard(100, 60);
                    
                if (IsKeyPressed(KEY_SPACE))
                {
                    // tira el dado
                    playerMove = dado.DropDice();

                    itoa(playerMove,diceResultado,10);
                    
                    // reiniciamos el contador
                    actualtime=0.0f;

                    Texture2D PlayerSkin = Tablero.GetPlayerSkin(playerTurn);
                    TplayerV.y = (screenHeight / 2) - ((PlayerSkin.height * 4) / 2);

                    int op=50;

                    // mostramos el mensaje por 1.0 segnudos
                    while(actualtime <=timetolive){
                        BeginDrawing();
                            DrawTexture(background,0,0,WHITE);
                            Tablero.DrawBoard(100, 60);
                            
                            /*
                                Para la entrada de opacidad dibujamos todo de nuevo y vamos incrementando la 
                                opacidad de maskColor poco a poco hasta llegar a cierto punto en el tiempo
                                o tambien podria ser cierta cantidad de opacidad
                            */
                            if(actualtime <= 0.15f){
                                // Jugador actual
                                DrawTextEx(fuente,actualPlayer[playerTurn],playerV,72,1,WHITE);
                                // Mascara
                                DrawRectangleRec(maskV,maskColor);
                                op+=10;
                                maskColor = {1,1,1,op};
                            }
                            else
                            {
                                // Jugador actual
                                DrawTextEx(fuente,actualPlayer[playerTurn],playerV,72,1,WHITE);
                                // Mascara
                                DrawRectangleRec(maskV,maskColor);
                            }
                            
                            // Dados
                            DrawTextureEx(Dice,TdiceV,0.0f,0.5f,WHITE);
                            // Jugador
                            DrawTextureEx(PlayerSkin,TplayerV,0.0f,4.0f,WHITE);
                            // Resultado arrojado
                            DrawTextEx(fuente,diceResultado,diceV,82,1,WHITE);

                            actualtime+=GetFrameTime();

                        EndDrawing();
                    }

                    // Movemos el jugador
                    Tablero.MovePlayer(playerTurn,playerMove);
                    
                    // Cambiamos de turno
                    playerTurn++;
                    
                    // en caso de llegar al fin de los jugadores reiniciamos los turnos
                    if(playerTurn >= NumPlayers){
                        playerTurn=0;
                    }
                }
                
                DrawTextEx(fuente,actualPlayer[playerTurn],playerV,72,1,WHITE);

        EndDrawing();
    }
}

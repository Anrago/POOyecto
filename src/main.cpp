#include "raylib.h"
#include "Menu.h"

// -------------------------------------------------------------------------- //
    // ------------ Removimos librerias innecesarias ------------ //
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// ------------ Comenzamos a seguir un unico estandar para las variables (camelCase) ------------ //
// -------------------------------------------------------------------------- //

/*      POOYECTO-SNAKE AND LADDERS

COMANDOS para compilar el juego
cd build
mingw32-make
./name.exe

*/

// -------------------------------------------------------------------------- //
// ------------ Creamos un archivo .h para almacenar este struct ------------ //
// -------------------------------------------------------------------------- //

/*
typedef enum Screen{
    MENU,
    PLAYER_SELECTION,
    GAME,
    WINNERS,
    EXIT
}Screen;
*/

// ---------------------- Main ---------------------- //
int main()
{
    // Ventana
    int screenWidth = 1280;
    int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "SerpientesyEscaleras");
    SetTargetFPS(60);
    
    InitAudioDevice();
    
    srand(time(NULL));
    
    // Jugadores actuales jugando, esto por default, pero debera de actualizarse en la pantalla de players select
    int playersPlaying=4;

    int winner=0;

    // Tablero
    Board board(playersPlaying);
    
    // Dados
    Dice dice;
    // Numero de dices con los que juagaran, igual se actualizaria en players select
    int numDice=2;

    // Escena actual
    Screen currentScreen=MENU;

    // vector de ganadores
    std::vector <int> winners;

    bool exit = false;
    while (exit == false)
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
            playersPlaying = DrawPlayerSelection(screenWidth,screenHeight);
            if(playersPlaying == -1){
                currentScreen = MENU;
            }
            else
            {
                currentScreen = GAME;
            }
            break;
        }
        case GAME:
        {
            board.DefinePlayersPlaying(playersPlaying);
            winners = DrawGame(screenWidth,screenHeight,playersPlaying,numDice,board,dice);
            if(winner == -1){
                currentScreen = MENU;
            }
            else{
                currentScreen = WINNERS;
            }
            break;
        }
        case WINNERS:
        {
            currentScreen = DrawWinner(screenWidth,screenHeight,board,playersPlaying,winners);
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
    board.FreeSnakeTexture();
    return 0;
}

// ---------------------- Menu y pantallas de movimiento ---------------------- //

// -------------------------------------------------------------------------------------- //
// Pasamos las funciones de menu a un archivo .cpp y .h apropiado para liberar el main
// -------------------------------------------------------------------------------------- //
/*
    Screen DrawMenu(int screenWidth, int screenHeight){
        // -------- Audio -------- //
        Music musica = LoadMusicStream("../assets/musica/Stage1.mp3");

        Sound clicks = LoadSound("../assets/sound/pk.mp3");
        
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

        PlayMusicStream(musica);

        while (finish== false)
        {
            UpdateMusicStream(musica);
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
                    PlaySound(clicks);
                    return PLAYER_SELECTION;
                }
                
                if(CheckCollisionPointRec(click,ExitR)){
                    PlaySound(clicks);
                    return EXIT;
                }

            EndDrawing();
        }
        UnloadMusicStream(musica);
        UnloadSound(clicks);
        return MENU;
    }
*/

/*
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
*/

/*
std::vector<int> DrawGame (int screenWidth, int screenHeight, int NumPlayers,int NumDice, Board Tablero, Dice dado){
    // ------------ Recursos ------------ //
    
    Music musica = LoadMusicStream("../assets/musica/AncientLake.mp3");

    Sound tirar = LoadSound("../assets/sound/interactBOTW.mp3");

    Sound winSound = LoadSound("../assets/sound/Ohhh.mp3");

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
    TplayerV.x = screenWidth *0.70;

    char diceResultado[3];
    
    // turno y movimiento de jugadores
    int playerTurn=0;
    int playerMove=0;

    // tiempo de espera
    float timetolive=1.0f;
    float actualtime=0.0f;

    // Mascara
    Color maskColor = {1,1,1,50};
    Rectangle maskV = {0,0,float(screenWidth),float(screenHeight)};

    // Posicion actual del jugador, usada para saber quien gano
    Vector2 PlayerPosition;

    // vector que almacenara el orden de ganadores
    std::vector<int> winners;

    // posicion del array de winners
    int wc=0;

    // bandera de ciclo
    bool finish = false;

    Texture2D PlayerSkin = Tablero.GetPlayerSkin(playerTurn);
    TplayerV.y = (screenHeight / 2) - ((PlayerSkin.height * 4) / 2);

    // -------- Musica -------- //
    PlayMusicStream(musica);

    // volumen de musica
    float volumen = 1.0f;
    SetMusicVolume(musica,1.0f);
    
    while(finish == false){
        BeginDrawing();
            
            UpdateMusicStream(musica);
            
            if(IsKeyPressed(KEY_ESCAPE)){
                return winners;
            }
            DrawTexture(background,0,0,WHITE);
            Tablero.DrawBoard(100, 60);
            
            if(Tablero.players[playerTurn].win== true){
                playerTurn++;
                if(playerTurn >= NumPlayers){
                    playerTurn=0;
                }
            }

            SetMusicVolume(musica,volumen);

                if (IsKeyPressed(KEY_SPACE))
                {
                    // Sonido de tirar
                    PlaySound(tirar);

                    // tira el dado
                    playerMove = dado.DropDice();

                    itoa(playerMove,diceResultado,10);
                    
                    PlayerSkin = Tablero.GetPlayerSkin(playerTurn);
                    TplayerV.y = (screenHeight / 2) - ((PlayerSkin.height * 4) / 2);

                    int op=50;

                    // reiniciamos el contador
                    actualtime=0.0f;

                    // mostramos el mensaje por 1.0 segnudos
                    while(actualtime <=timetolive){
                        BeginDrawing();

                            UpdateMusicStream(musica);
                            
                            DrawTexture(background,0,0,WHITE);
                            Tablero.DrawBoard(100, 60);
                            
                            // 
                            //     Para la entrada de opacidad dibujamos todo de nuevo y vamos incrementando la 
                            //     opacidad de maskColor poco a poco hasta llegar a cierto punto en el tiempo
                            //     o tambien podria ser cierta cantidad de opacidad
                            // 
                            if(actualtime <= 0.15f){
                                // Musica
                                volumen-=0.1f;
                                SetMusicVolume(musica,volumen);
                                
                                // Jugador actual
                                DrawTextEx(fuente,actualPlayer[playerTurn],playerV,72,1,WHITE);
                                // Mascara
                                DrawRectangleRec(maskV,maskColor);
                                op+=10;
                                maskColor = {1,1,1,op};
                                // bajamos el volumen
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
                    volumen=1.0f;

                    // Movemos el jugador
                    Tablero.MovePlayer(playerTurn,playerMove);
                    
                    // Regresa la posicion actual del jugador
                    PlayerPosition=Tablero.GetActualPlayerPosition(playerTurn);

                    // Si es 0 0 Gano
                    if(PlayerPosition.x == 0 && PlayerPosition.y == 0){
                        winners.push_back(playerTurn);
                        wc++;

                        PlaySound(winSound);

                        Tablero.players[playerTurn].win = true;
                        
                        if(wc >= NumPlayers-1){
                            for(int i =0 ; i<NumPlayers;i++){
                                if(Tablero.players[i].win== false){
                                    winners.push_back(i);
                                    break;
                                }
                            }
                            finish = true;
                        }
                    }

                    // Cambiamos de turno
                    playerTurn++;
                    
                    // en caso de llegar al fin de los jugadores reiniciamos los turnos
                    if(playerTurn >= NumPlayers){
                        playerTurn=0;
                    }
                }

            // Actualizamos la textura
            PlayerSkin = Tablero.GetPlayerSkin(playerTurn);
            TplayerV.y = (screenHeight / 2) - ((PlayerSkin.height * 4) / 2);

            // Jugador actual
            DrawTextureEx(PlayerSkin,TplayerV,0.0f,4.0f,WHITE);
            
            // Jugador actual
            DrawTextEx(fuente,actualPlayer[playerTurn],playerV,72,1,WHITE);

        EndDrawing();
    }
    UnloadMusicStream(musica);
    return winners;
}
*/

/*
Screen DrawWinner(int screenWidth, int screenHeight, Board Tablero, int NumPayers, const std::vector<int>& winner){
    // -------------- Recursos -------------- //
    Sound win = LoadSound("../assets/sound/OHMYGOD.mp3");

    Music musica = LoadMusicStream("../assets/musica/Victoria.mp3");

    Font fuente = LoadFont("../assets/fuente/Minecraft.ttf");

    Sound clicks = LoadSound("../assets/sound/pk.mp3");

    Texture2D ButtonPlayAgain= LoadTexture("../assets/buttons/PlayAgain.png");
    Texture2D ButtonExit= LoadTexture("../assets/buttons/ExitButton.png");

    Color background = {56,56,56,255};
    
    // -------------- Text Position -------------- // 

    const char winnerText[10] = {"WINNER"};
    const char secondText[10] = {"2do"};
    const char thirdText[10] = {"3ro"};

    int winnerSize=MeasureText(winnerText,54);

    Vector2 winnerV;
    winnerV.x = (screenWidth / 2) - (winnerSize / 2)+20;
    winnerV.y = screenHeight *0.20;

    // -------------- Buttons Position -------------- // 

    // Boton de jugar nuevamente
    Rectangle PlayAgainR;
    PlayAgainR.x = screenWidth *0.55;
    PlayAgainR.y = screenHeight *0.80;
    PlayAgainR.width = ButtonPlayAgain.width;
    PlayAgainR.height = ButtonPlayAgain.height;

    Vector2 playAgainV;
    playAgainV.x = PlayAgainR.x;
    playAgainV.y = PlayAgainR.y;
    
    
    // Boton de salir
    Rectangle ExitR;
    ExitR.x = screenWidth *0.25;
    ExitR.y = screenHeight *0.80;
    ExitR.width = ButtonExit.width;
    ExitR.height = ButtonExit.height;

    Vector2 ExitV;
    ExitV.x=ExitR.x;
    ExitV.y=ExitR.y;

    // -------------- Winner -------------- // 
    // Ganador
    Texture2D winnerT= Tablero.GetPlayerSkin(winner[0]);
    Texture2D secondT;
    Texture2D thirdT;
    if(NumPayers > 1){
        // 2do lugar
        secondT= Tablero.GetPlayerSkin(winner[1]);
        if(NumPayers >2){
            //3er lugar
            thirdT= Tablero.GetPlayerSkin(winner[2]);
        }
    }
    for (int i = 0;i<NumPayers;i++ ){
        std::cout<<winner[i]<<std::endl;
    }

    Vector2 PlayerWinnerV;
    PlayerWinnerV.x = (screenWidth /2 ) - (winnerT.width*5 / 2);
    PlayerWinnerV.y = (screenHeight /2 ) - (winnerT.height*5 / 2);
    // ----- Segundo lugar ------- //
    // imagen
    Vector2 SecondV;
    SecondV.x = screenWidth *0.10;
    SecondV.y = (screenHeight /2 ) - (secondT.height*4 / 2);
    
    // texto
    Vector2 TSecondV;
    TSecondV.x = screenWidth *0.15;
    TSecondV.y = (screenHeight /2 ) - (secondT.height*4 / 2) - 100;
    
    // ----- Tecer lugar ------- //
    // imagen
    Vector2 ThirdV;
    ThirdV.x = screenWidth *0.80;
    ThirdV.y = (screenHeight /2 ) - (thirdT.height*3 / 2);
    
    // texto
    Vector2 TThirdV;
    TThirdV.x = screenWidth *0.83;
    TThirdV.y = (screenHeight /2 ) - (thirdT.height*3 / 2) - 100;

    // -------------- Extra -------------- // 
    
    Vector2 mouse;
    Vector2 click;

    bool finish = false;

    PlayMusicStream(musica);

    PlaySound(win);

    while(finish == false){
        BeginDrawing();
            
            UpdateMusicStream(musica);

            mouse = GetMousePosition();
            
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                click=mouse;
            }

            // Fondo
            ClearBackground(background);
            
            // texto de ganador
            DrawTextEx(fuente,winnerText,winnerV,54,1,YELLOW);

            // ------------- winners ------------ //
            DrawTextureEx(winnerT,PlayerWinnerV,0.0f,5.0f,WHITE);
            if(NumPayers >1){
                // Textura
                DrawTextureEx(secondT,SecondV,0.0f,4.0f,WHITE);
                // texto
                DrawTextEx(fuente,secondText,TSecondV,54,1,WHITE);
                
                if(NumPayers > 2){
                    // textura
                    DrawTextureEx(thirdT,ThirdV,0.0f,3.0f,WHITE);
                    // texto
                    DrawTextEx(fuente,thirdText,TThirdV,54,1,WHITE);
                }
            }
            
            
            // Botones
            // Jugar nuevamente
            DrawTextureEx(ButtonPlayAgain,playAgainV,0.0f,1.0f,WHITE);
            
            // Salir
            DrawTextureEx(ButtonExit,ExitV,0.0f,1.0f,WHITE);

            if(CheckCollisionPointRec(click,PlayAgainR)){
                PlaySound(clicks);
                return GAME;
            }
            if(CheckCollisionPointRec(click,ExitR)){
                PlaySound(clicks);
                return MENU;
            }

        EndDrawing();
    }
    return MENU;
}
*/

/*
int DrawPlayerSelection(int screenWidth, int screenHeight){
    
    // ------ Recrusos --------- //
    Sound clicks = LoadSound("../assets/sound/pk.mp3");
    
    Texture2D background = LoadTexture("../assets/HowManyPlayers.png");
    
    Texture2D button1 = LoadTexture("../assets/buttons/1.png");
    Texture2D button2 = LoadTexture("../assets/buttons/2.png");
    Texture2D button3 = LoadTexture("../assets/buttons/3.png");
    Texture2D button4 = LoadTexture("../assets/buttons/4.png");

    // -------- Buttons  --------- //
    Vector2 p1;
    p1.x = screenWidth*0.10;
    p1.y = screenHeight*0.10;

    Rectangle p1R;
    p1R.x=p1.x;
    p1R.y=p1.y;
    p1R.width=button1.width;
    p1R.height=button1.height;
    
    Vector2 p2;
    p2.x = screenWidth*0.65;
    p2.y = screenHeight*0.10;
    
    Rectangle p2R;
    p2R.x=p2.x;
    p2R.y=p2.y;
    p2R.width=button1.width;
    p2R.height=button1.height;
    
    Vector2 p3;
    p3.x = screenWidth*0.10;
    p3.y = screenHeight*0.70;
    
    Rectangle p3R;
    p3R.x=p3.x;
    p3R.y=p3.y;
    p3R.width=button1.width;
    p3R.height=button1.height;
    
    Vector2 p4;
    p4.x = screenWidth*0.65;
    p4.y = screenHeight*0.70;
    
    Rectangle p4R;
    p4R.x=p4.x;
    p4R.y=p4.y;
    p4R.width=button1.width;
    p4R.height=button1.height;

    bool finish = false;

    Vector2 mouse;
    Vector2 click;

    while (finish == false){
        BeginDrawing();
            mouse = GetMousePosition();

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                click=mouse;
            }
            DrawTexture(background,0,0,WHITE);
            
            DrawTextureEx(button1,p1,0.0f,1.0f,WHITE);
            DrawTextureEx(button2,p2,0.0f,1.0f,WHITE);
            DrawTextureEx(button3,p3,0.0f,1.0f,WHITE);
            DrawTextureEx(button4,p4,0.0f,1.0f,WHITE);

            if(IsKeyPressed(KEY_ESCAPE)){
                PlaySound(clicks);

                return -1;
            }

            if(CheckCollisionPointRec(click,p1R)){
                PlaySound(clicks);
                
                return 1;
            }
            
            if(CheckCollisionPointRec(click,p2R)){
                PlaySound(clicks);
                
                return 2;
            }
            
            if(CheckCollisionPointRec(click,p3R)){
                PlaySound(clicks);
                
                return 3;
            }
            
            if(CheckCollisionPointRec(click,p4R)){
                PlaySound(clicks);
                
                return 4;
            }
        EndDrawing();
    }
    return 0;
}
*/
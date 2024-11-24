#include "Menu.h"

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

#include "Screen.h"
#include "Board.h"
#include "Dice.h"

// StartScreen
Screen DrawMenu(int screenWidth, int screenHeight);

// ExitScreen
void DrawExit(int screenWidth, int screenHeight);

// PlayersScreen
int DrawPlayerSelection(int screenWidth, int screenHeight);

// GameScreen
std::vector<int> DrawGame (int screenWidth, int screenHeight, int NumPlayers,int NumDice, Board* Tablero, Dice dado);

// WinnerScreen
Screen DrawWinner(int screenWidth, int screenHeight, Board* Tablero, int NumPayers, const std::vector<int>& winner);
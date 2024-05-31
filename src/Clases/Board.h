#pragma once

class Board{
public:
    int GridSize;
    int Gridx;
    Vector2 startGrid;
    Board();
    Board(int screenWidth, int screenHeight);
};

Board::Board(){
    this->GridSize=50;
}

Board::Board(int screenWidth, int screenHeight){
    this->GridSize = 60;
    this->Gridx=10;
    this->Gridx=10;
    this->startGrid.x=(screenWidth / 2 ) - (GridSize * 5);
    this->startGrid.y=(screenHeight / 2 ) - (GridSize * 5);
}


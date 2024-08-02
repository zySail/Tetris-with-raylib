#include "position.h"

Position::Position(int row = 0, int col = 0) : row(row), col(col){}

void Position::setPosition(int row, int col){
    this->row = row;
    this->col = col;
}

int Position::getRow(){
    return row;
}
int Position::getCol(){
    return col;
}
#include "position.h"

Position::Position(){row = 0; col = 0;}
Position::Position(int row = 0, int col = 0) : row(row), col(col){}

void Position::setPosition(int row, int col){
    this->row = row;
    this->col = col;
}

int Position::getRow() const{
    return row;
}
int Position::getCol() const{
    return col;
}

void Position::add(int rowOffest, int colOffest){
    row += rowOffest;
    col += colOffest;
}
#pragma once
#include <utility>
#include <map>
#include <vector>
#include "position.h"


class Block{
private:
    int id;
    //const int blockSize;
    int statusVal;
    std::map<int, std::vector<Position>> status;
    Position offest;
public:
    Block();
    void addStatus(int key, std::vector<Position> pos);
    void rotate();
    void undoRotate();
    void Draw();
    int getId();
    void setId(int new_id); // used by child block constructor
    void move(int rowOffest, int colOffest);
    std::vector<Position> getCellPosition(); // apply offest to all status
};

//virtual ~block();

class LBlock : public Block{
public:
    LBlock();
};

class JBlock : public Block{
public:
    JBlock();
};

class IBlock : public Block{
public:
    IBlock();
};

class OBlock : public Block{
public:
    OBlock();
};

class SBlock : public Block{
public:
    SBlock();
};

class TBlock : public Block{
public:
    TBlock();
};

class ZBlock : public Block{
public:
    ZBlock();
};

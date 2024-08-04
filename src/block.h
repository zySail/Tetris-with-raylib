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
public:
    Block(int id);
    void addStatus(int key, std::vector<Position> pos);
    void changeStatus();
    void Draw();
    void setId(int new_id);
};

//std::pair<int, int> postion;
//virtual void draw() = 0; 
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

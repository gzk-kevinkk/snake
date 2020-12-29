#ifndef _snake_h
#define _snake_h
#include "base.h"
#include "input.h"
#include "mapdata.h"
using std::deque;
using std::pair;

class Snake{
public:
    Snake();
    pair<int, int> get_head()
    {
        return head;
    }
    void change_direction(enum Direction dir)
    {
        this->dir = dir;
    }
    void add_length()
    {
        length++;
    }
    void move(enum Direction);
private:
    int length;
    pair<int, int> head;
    deque<pair<int, int>> que;
    enum Direction dir;

    friend class Snake_Map;
};
#endif
#ifndef _snakemap_h
#define _snakemap_h

#include "snake.h"
#include "base.h"
#include "input.h"
#include "mapdata.h"
#include <random>
#include <pthread.h>
#include <ctime>
using std::cout;
using std::deque;
using std::pair;
using std::vector;

void *input_thread(void *);

class Snake_Map{
public:
    Snake_Map(Snake &sn);
    bool is_eaten();
    void create_food();
    void show();
    void change_direction(enum Direction new_dir);
    void update();

private:
    Snake& snake;
    vector<vector<char>> map;
    enum Direction dir;
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u;
    pair<int, int> food;
};

#endif
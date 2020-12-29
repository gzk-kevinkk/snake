#include "snakemap.h"

void* input_thread(void* sm){
    Snake_Map *map = (Snake_Map *)sm;
    while (true)
    {
        enum Direction dir = get_direction();
        map->change_direction(dir);
    }
    return nullptr;
}

Snake_Map::Snake_Map(Snake& sn):snake(sn),map(MAP_HEIGHT,vector<char>(MAP_WIDTH)),e(time(0)),dir(South),u(0,MAP_WIDTH*MAP_HEIGHT-1){
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++)
    {
        for (j = 0; j < MAP_WIDTH; j++)
        {
            map[i][j] = MAP_CHAR;
        }
    }
    for (deque<pair<int, int>>::iterator it = snake.que.begin(); it != snake.que.end();it++){
        i = (*it).first;
        j = (*it).second;
        map[i][j] = SNAKE_CHAR;
    }
    map[i][j] = SNAKE_HEAD_SOUTH;
    bool cond = true;
    int temp = u(e);
    int row;
    int col;
    while (cond)
    {
        temp = u(e);
        row = temp / MAP_WIDTH;
        col = temp % MAP_WIDTH;
        if(map[row][col]==MAP_CHAR){
            cond = false;
            map[row][col] = SNAKE_FOOD_CHAR;
            food.first = row;
            food.second = col;
        }
    }
    pthread_t k;
    pthread_create(&k, nullptr, input_thread, this);
    return;
}

void Snake_Map::change_direction(enum Direction new_dir){
    if(dir==West){
        if(new_dir==North||new_dir==South)
            dir = new_dir;
    }
    else if(dir==East){
        if(new_dir==North||new_dir==South)
            dir = new_dir;
    }
    else if(dir==North){
        if(new_dir==West||new_dir==East)
            dir = new_dir;
    }
    else{
        if(new_dir==West||new_dir==East)
            dir = new_dir;
    }
    return;
}

void Snake_Map::show(){
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++)
    {
        for (j = 0; j < MAP_WIDTH; j++)
        {
            map[i][j] = MAP_CHAR;
        }
    }
    for (deque<pair<int, int>>::iterator it = snake.que.begin(); it != snake.que.end();it++){
        i = (*it).first;
        j = (*it).second;
        map[i][j] = SNAKE_CHAR;
    }
    map[food.first][food.second] = SNAKE_FOOD_CHAR;
    switch (dir)
    {
    case South:
        map[i][j] = SNAKE_HEAD_SOUTH;
        break;
    case North:
        map[i][j] = SNAKE_HEAD_NORTH;
        break;
    case East:
        map[i][j] = SNAKE_HEAD_EAST;
        break;
    default:
        map[i][j] = SNAKE_HEAD_WEST;
        break;
    }
    system("clear");
    cout << "\n\n\n";
    for (i = 0; i < MAP_HEIGHT; i++)
    {
        for (j = 0; j < MAP_WIDTH; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n\n";
}

void Snake_Map::create_food(){
    int temp;
    int row;
    int col;
    bool cond = true;
    while (cond)
    {
        temp = u(e);
        row = temp / MAP_WIDTH;
        col = temp % MAP_WIDTH;
        if(map[row][col]==MAP_CHAR){
            cond = false;
            map[row][col] = SNAKE_FOOD_CHAR;
            food.first = row;
            food.second = col;
        }
    }
}

bool Snake_Map::is_eaten(){
    pair<int, int> head = snake.head;
    return food.first == head.first && food.second == head.second;
}

void Snake_Map::update(){
    snake.change_direction(dir);
    snake.move(dir);
    bool cond = is_eaten();
    if(cond){
        snake.add_length();
        create_food();
    }
    else
        snake.que.pop_front();
    return;
}
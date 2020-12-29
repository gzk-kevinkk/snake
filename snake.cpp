#include "snake.h"

Snake::Snake(){
    length = 3;
    for (int i = 0; i < 3; i++)
    {
        que.push_back({MAP_HEIGHT / 2 - 1 + i, MAP_WIDTH / 2});
    }
    dir = South;
    head = que.back();
};

void Snake::move(enum Direction d){
    // change_direction(d);
    // if(is_eat)
    //     add_length();
    // else
    //     que.pop_front();
    
    if (d == West)
        que.push_back({head.first, --head.second});
    else if (d == North)
        que.push_back({--head.first, head.second});
    else if (d == East)
        que.push_back({head.first, ++head.second});
    else if (d == South)
        que.push_back({++head.first, head.second});
    return;
}
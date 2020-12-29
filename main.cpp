#include "input.h"
#include "mapdata.h"
#include "snake.h"
#include "snakemap.h"
using std::cout;
using std::endl;
using std::pair;

Snake snake;
Snake_Map map(snake);

void init(){
    input_init();
    input_enter_off();
};

bool is_end(){
    pair<int, int> head = snake.get_head();
    if(head.first<0||head.first>=MAP_HEIGHT||head.second<0||head.second>=MAP_WIDTH)
        return true;
    return false;
};

void start_game(){
    while(!is_end()){
        map.show();
        map.update();
        usleep(PAUSE_LENGTH);
    }
};

void* testfun(void* h){
    while(true){
        enum Direction dir = get_direction();
        cout << endl;
        cout << dir << endl;
    }
    return nullptr;
}

int main(){
    init();
    start_game();
    return 0;
}
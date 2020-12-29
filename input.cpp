#include "input.h"

struct termios ts;

void input_init(void){

};

void input_enter_off(void){
    tcgetattr(STDIN_FILENO, &ts);
    ts.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &ts);
}

void input_enter_on(void){
    tcgetattr(STDIN_FILENO, &ts);
    ts.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &ts);
}

enum Direction get_direction(void){
    char c = getchar();
    enum Direction result = West;
    switch (c)
    {
    case 'a':
        result = West;
        break;
    case 'w':
        result = North;
        break;
    case 'd':
        result = East;
        break;
    case 's':
        result = South;
        break;
    default:
        result = Error;
        break;
    }
    return result;
}
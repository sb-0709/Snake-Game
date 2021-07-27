#ifndef SNAKE_H
#define SNAKE_H

#include<windows.h>//library to define snake position as it has the coordinate structure
#include<vector>

using namespace std;

class snake
{
    private:
        COORD pos;
        int len;
        int vel;
        char direction;
        vector<COORD> body;
    public:
        snake(COORD pos, int vel);//constructor to define initial position and velocity of snake
        void change_dir(char dir);
        void move_snake();
        COORD get_pos();
        bool eaten(COORD food_pos);
        void grow();
        bool collided();
        vector<COORD>get_body();
};

#endif // SNAKE_H

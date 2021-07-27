#include "snake.h"

#define WIDTH 50
#define HEIGHT 25

snake::snake(COORD pos, int vel)//constructor function
{
    this->pos=pos;
    this->vel=vel;
    len=1; // length is 1 initially as it can't be 0 since snake will contain head itself
    direction='n';// direction is initially set to none since snake is not moving now
    body.push_back(pos);//this is to add head of the snake at position pos
}
void snake::change_dir(char dir) {direction=dir;}//function to set direction of snake
void snake::move_snake()
{
    switch(direction)
    {
    case 'u':
        pos.Y-=vel; //so if snake moves up then it's y coordinate must decrease with velocity
        break;
    case 'd':
        pos.Y+=vel;
        break;
    case 'l':
        pos.X-=vel;
        break;
    case 'r':
        pos.X+=vel;
        break;
    }

    body.push_back(pos);
    if(body.size()>len)
        body.erase(body.begin());//if food not eaten by snake then remove this inserted part
}
COORD snake::get_pos() {return pos;}//function to define position of the snake

bool snake::eaten(COORD food_pos)//to check whether food is eaten by snake or not
{
    if(food_pos.X==pos.X && food_pos.Y==pos.Y)
        return true;
    else
        return false;
}
void snake::grow()//function to grow length of the snake when it eats the food
{
    len++;
}
bool snake::collided()//this function is to do game over whenever snake collides with the wall
{
    if(pos.X<1 || pos.X>WIDTH-2 || pos.Y<1 || pos.Y>HEIGHT-2)
        return true;
    for(int i = 0; i < len-1; i++)//this is to consider collision of snake's head with it's own body part
    {
        if(pos.X == body[i].X && pos.Y == body[i].Y) return true;
    }
    return false;
}
vector<COORD> snake::get_body() {return body;}

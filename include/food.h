#ifndef FOOD_H
#define FOOD_H

#include<windows.h>//to define position of food, include this header file
#include<cstdlib>//header file to define random positioning of food

#define WIDTH 50
#define HEIGHT 25

class food
{
    private:
        COORD pos;//store position of food which will re-generate after eaten up by snake
    public:
        food();
        void generate_food();
        COORD get_pos();
};

#endif // FOOD_H

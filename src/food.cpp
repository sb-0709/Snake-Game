#include "food.h"

food::food()
{
    generate_food();//this constructor will generate our food at random position
}

void food::generate_food()
{
    pos.X=(rand()% (WIDTH-3))+1;
    pos.Y=(rand()% (HEIGHT-3))+1;//rand returns random position or coordinates of food
}

COORD food::get_pos() {return pos; } //this function will return position of current food

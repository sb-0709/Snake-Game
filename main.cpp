#include<iostream>
#include<conio.h>
#include<ctime>//to seed the random function
#include<cstdlib> //this header file is to use shell command or console command
#include<windows.h>//this header file allows to control cursor's position on console
/*#define sq(x) x*x     this is macros-> one line functions written using symbols in which here when sq(5) is called ,
it will do 5*5
*/
#include"snake.h"
#include"food.h"

#define UP 72//ascii values of control keys

#define DOWN 80

#define LEFT 75

#define RIGHT 77

using namespace std;

#define WIDTH 50//no. of columns
#define HEIGHT 25//no. of rows

int score=0;//global variable

snake snake({WIDTH/2, HEIGHT/2}, 1);// initially snake is present in the middle of the board and it has velocity of covering 1 character per second
food food;//to generate food object, constructor is used

void board() //to design board
{
    COORD snake_pos=snake.get_pos();
    COORD food_pos=food.get_pos();

    vector<COORD> snake_body = snake.get_body();
    cout<<"SCORE: "<<score<<"\n\n";

    for(int i=0;i<HEIGHT; i++)
    {
        cout<<"\t\t#";
        for(int j=0;j<WIDTH-2;j++)
        {
            if(i==0 || i==HEIGHT-1)
            cout<<'#';
            else if(i==snake_pos.Y && j+1==snake_pos.X)
            cout<<'o'; //snake
            else if(i==food_pos.Y && j+1==food_pos.X)
            cout<<'*'; //food
            else//snake body part detection
            {
                bool isBodyPart = false;
                for(int k = 0; k < snake_body.size()-1; k++)//-1 as head is excluded
                {
                    if(i == snake_body[k].Y && j+1 == snake_body[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }

                if(!isBodyPart) cout << ' ';
            }
        }
        cout<<"#\n";
    }
}
void print()
{
    char c;
    cout<<"****** WELCOME TO SNAKE GAME *******";
    cout<<"\n\nRULES ARE AS FOLLOWS:\n";
    cout<<"\n1. Use arrow keys to move the snake.\n2. Food will be provided at random coordinates of the screen.\n";
    cout<<"3. Every time the snake eats the food, the length of the snake will be increased by 1 element and thus the score.\n";
    cout<<"4. Game will get over if there occurs a collision of the snake with the wall or with itself.\n\n";
    cout<<"DO YOU WISH TO PLAY?\nIf yes type y else type n: ";
    cin>>c;
    if(c=='n')
        exit(0);
}

int main()
{
    print();
    system("cls");
    srand(time(NULL));
    bool game_over=false;//variable to track if game is over

    while(!game_over)
    {
        board();

        if (kbhit())
        {
            switch(getch())
            {
                 case UP:snake.change_dir('u');break;//if arrow up then move up
                 case LEFT:snake.change_dir('l');break;//if arrow left then move left
                 case DOWN:snake.change_dir('d');break;//if arrow down then move down
                 case RIGHT:snake.change_dir('r');break;//if arrow right then move right
            }
        }
        if(snake.collided())
         {
            game_over=true;
            system("cls");
            if(score==0){
                cout<<"\n\n     YOUR SCORE: "<<score;
                cout<<"\n\n Better luck next time!!\n\n Continue playing!!\n\n";
            }
            else{
                cout<<"\n\n     YOUR SCORE: "<<score;
                cout<<"\n\n Great job!!\n\n Continue playing!!\n\n";
            }
            break;
         }

        //function to check whether snake has eaten food or not
        if(snake.eaten(food.get_pos()))
        {
            food.generate_food();//if eaten generate food and increase length of snake
            snake.grow();
            score++;
        }

         snake.move_snake();//calling function to move snake

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
      //this will take cursor and will just put back at origin without clearing console
    }
    return 0;
}


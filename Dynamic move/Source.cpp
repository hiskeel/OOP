#include"Console.h"
#include<chrono>//clock()

enum Direction { LEFT, RIGHT, UP, DOWN };
class Hero
{
private:
    int hp;
    int h, w;
    COORD position;
    string name;
    char symbol;
    Direction dir;
    void Print(char filler)const
    {
        for (int i = 0; i < h; i++)
        {
            gotoxy(position.X, position.Y + i);
            for (int j = 0; j < w; j++)
            {
                if (i == 0) { cout << "   |\\__/|"; }
                if (i == 1) { cout << "  /_    _\\"; }
                if (i == 2) { cout << "  |  7   |"; }
                if (i == 3) { cout << "   \\ __ /"; }
                if (i == 4) { cout << "  / |  | \\"; }
                if (i == 5) { cout << " | |    | |"; }
                if (i == 6) { cout << " | |    | |"; }
                if (i == 7) { cout << " | |____| |"; }
                if (i == 8) { cout << "_| |_  |_ |_"; }
               

                
            }
            cout << endl;
        }
    }
public:
    Hero() :hp(100), h(1), w(1), position({ 0,0 }), name("no name"), symbol('#'), dir(RIGHT) {}
    Hero(string name, int h, int w, char symbol) :hp(100), position({ 0,0 }), dir(RIGHT),
        name(name), symbol(symbol)
    {
        this->h = h >= 1 ? h : 1;
        this->w = w >= 1 ? w : 1;
        //if (w >= 1)
        //    this->w = w;
        //else
        //    this->w = 0;        
    }
    void ShowInfo()const
    {
        cout << "--------------- Player [" << name << "] Hp : " << hp << "-------------" << endl;
    }

    void SetPosition(int x, int y)
    {
        position.X = x >= 0 ? x : 0;
        position.Y = y >= 0 ? y : 0;
    }
    void Move()
    {
        ClearHero();
        bool isMoved = false;
        switch (dir)
        {
        case LEFT:isMoved = MoveLeft(); break;
        case RIGHT:isMoved = MoveRight(); break;
        case UP:isMoved = MoveUp(); break;
        case DOWN:isMoved = MoveDown(); break;
        }
        isMoved ? PrintHero() : MarkHero();
    }
    void ChangeDirection(Direction dir)
    {
        this->dir = dir;
    }
    bool IsValidPosition(int x, int y)
    {
        return x >= 0 && y >= 0;
    }
    bool MoveRight()
    {
        if (IsValidPosition(position.X + 1, position.Y))
        {
            position.X++;
            return true;
        }
        return false;

    }
    bool MoveLeft()
    {
        if (IsValidPosition(position.X - 1, position.Y))
        {
            position.X--;
            return true;
        }
        return false;

    }
    bool MoveDown()
    {
        if (IsValidPosition(position.X, position.Y + 1))
        {
            position.Y++;
            return true;
        }
        return false;
    }
    bool MoveUp()
    {
        if (IsValidPosition(position.X, position.Y - 1))
        {
            position.Y--;
            return true;
        }
        return false;
    }

    void PrintHero()const
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::GREEN);
        Print(symbol);
    }
    void MarkHero()const
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::RED);
        Print(symbol);
    }
    void ClearHero()const
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::BLACK);
        Print((char)219);
    }
};

int main()
{

    //system("Color 2A");
    hidecursor();
    Hero hero("Bill", 10, 3, (char)219);
    hero.ShowInfo();
    //hero.Print();

    hero.SetPosition(10, 10);
    //hero.Print();
    time_t interval = 500;
    time_t start = clock();
    int key;
    while (true)
    {
        if (clock() >= start + interval)
        {
            hero.Move();
            start = clock();
        }

        if (_kbhit())
        {

            key = _getch();

            if (key == 224)
            {
                key = _getch();
                //cout << key;
                switch (key)
                {
                case 77:hero.ChangeDirection(RIGHT); break;
                case 80:hero.ChangeDirection(DOWN); break;
                case 72:hero.ChangeDirection(UP); break;
                case 75:hero.ChangeDirection(LEFT); break;
                }
            }

        }
    }
}
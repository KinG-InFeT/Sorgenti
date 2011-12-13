//compile with: g++ foo.cpp -o foo -lpthread -lncurses

#include <iostream>
#include <curses.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68
#define startLenght 4

struct piece {
    char Pi;
    int x;
    int y;
    struct piece *next;
};

struct egg {
    char Pi;
    int x;
    int y;
};
pthread_t thread;

struct piece *head;
struct piece *tail;
egg theEgg;

int ch, dirx, diry, lastx, lasty, score, level, dir, s;

void *input(void *) {
    while(1) {
        char CH;
        CH = getch();
        if(CH == UP && ch != DOWN )
            ch = CH;
        else if(CH == DOWN && ch != UP )
            ch = CH;
        else if(CH == LEFT && ch != RIGHT)
            ch = CH;
        else if(CH == RIGHT && ch != LEFT )
            ch = CH;
        else if(CH == 'q' || CH == 's')
            ch = CH;
        pthread_join(thread, NULL);
    }
}
void spawnBG() {
    int i, j;
    
    for(i = 0;i < 22; i++) {
                for(j = 0; j < 44; j++) {
                    if(i > 20 || j > 42 || i < 1 || j < 1) {
                        attron(COLOR_PAIR(1));
                        mvaddch(i,j,'o');
                    }
                }
            }
}

void push2() {
    struct piece *p;
    p = new piece;
    p->x = head->x - dirx;
    p->y = head->y - diry;
    p->Pi = ' ';
    p->next = NULL;
    p->next = head;
    head = p;

}
void push() {
    struct piece *p;
    struct piece *i;
    int j, a;
    int lol;
    p = new piece;
    p->x = lastx + dirx;
    p->y = lasty + diry;
    lastx = p->x;
    lasty = p->y;
    p->Pi = ' ';
    p->next = NULL;
    lol = 0;
    a = 0;
    if(head == NULL) {
        head = p;
        tail = p;
    }
    else {
        for(i = head; i!= NULL && lol == 0; i = i->next) {
            if((p->x == i->x && i->y == p->y)) {
                dirx = 1;
                diry = 0;
                lastx = 5;
                lasty = 5;
                lol = 1;
                head = tail = NULL;
                s = 0;
                mvprintw(LINES-2, 10, "Premi S per ricominciare \n");
            }
            if(p->x == 43 && ch == RIGHT) {
                //lastx = 0;
                dirx = 1;
                diry = 0;
                lastx = 5;
                lasty = 5;
                lol = 1;
                head = tail = NULL;
                s = 0;
                mvprintw(LINES-2, 10, "Premi S per ricominciare \n");
            }
            else if(p->x == 0 && ch == LEFT) {
                //lastx = 43;
                dirx = 1;
                diry = 0;
                lastx = 5;
                lasty = 5;
                lol = 1;
                head = tail = NULL;
                s = 0;
                mvprintw(LINES-2, 10, "Premi S per ricominciare \n");
            }
            else if(p->y == 21 && ch == DOWN) {
                //lasty = 0;
                dirx = 1;
                diry = 0;
                lastx = 5;
                lasty = 5;
                lol = 1;
                head = tail = NULL;
                s = 0;
                mvprintw(LINES-2, 10, "Premi S per ricominciare \n");
            }
            else if(p->y == 0 && ch == UP) {
                //lasty = 21;
                dirx = 1;
                diry = 0;
                lastx = 5;
                lasty = 5;
                lol = 1;
                head = tail = NULL;
                s = 0;
                mvprintw(LINES-2, 10, "Premi S per ricominciare \n");
                
            }
            
        }
        if(lol == 0)
        {
            tail->next = p;
            tail = p;
        }

    }
}
void spawnEgg() {
    do{
            theEgg.x = rand() % 25;
            theEgg.y = rand() % 19;
   }while(((theEgg.x > 44) || (theEgg.y > 20) || (theEgg.x < 2)  || (theEgg.y < 2)));
}
void update() {
    struct piece *p;
    for(p = head; p!= NULL; p = p->next) {
        attron(COLOR_PAIR(5));
        mvprintw(p->y, p->x, "%c", p->Pi);
    }
    attron(COLOR_PAIR(4));
    mvaddch(theEgg.y, theEgg.x, theEgg.Pi);
    if(lastx == theEgg.x && lasty == theEgg.y) {
        attron(COLOR_PAIR(1));
        mvaddch(theEgg.y, theEgg.x, ' ');
        score += 10 * 9;
        spawnEgg();
        push2();
    }
    attron(COLOR_PAIR(3));
    mvprintw(LINES-1, 2, "YOUR SCORE: %d", score);
}

void pop() {
    struct piece *p;
    if(head != NULL) {
        p = head;
        mvaddch(p->y, p->x, ' ');
        head = p->next;
        delete p;
        
    }
}




int main(int argv, char **argc) {
    int i, j;
    /*
    if(atoi(argc[0]) > 1 || atoi(argc[0]) < 9)
    {
        level = atoi(argc[0]);
    }
    else {
        cout << "Usage: snake [level]\n";
        exit(0);
    }*/
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_BLACK, COLOR_CYAN);

    srand((unsigned) time(NULL));
    
        
    tail = NULL;
    head = NULL;

    char ground[COLS][LINES];
    spawnBG();
    dirx = 1;
    diry = 0;
    lastx = 5;
    lasty = 5;

    keypad(stdscr, NULL);

    theEgg.Pi = ' ';
    attron(COLOR_PAIR(3));
    mvprintw(LINES-2, 10, "Premi S per cominciare \n");
    pthread_create(&thread, NULL, input, (void *)NULL);
    score = 0;
    s = 0;
    do {
       
        if(ch == UP) {
            dirx = 0;
            diry = -1;
            dir = 3;
        }
        else if(ch == DOWN) {
            dirx = 0;
            diry = 1;
            dir = 3;
        }
        else if(ch == RIGHT) {
            dirx = 1;
            diry = 0;
            dir = 0;
        }
        else if(ch == LEFT) {
            dirx = -1;
            diry = 0;
            dir = 0;
        }
        else if(ch == 's') {
            score = 0;
            erase();
            dirx = 1;
            diry = 0;
            lastx = 5;
            lasty = 5;
            for(i = 0;i < startLenght; i++)
                push();
            spawnBG();
            spawnEgg();
            theEgg.Pi = ' ';
            ch = RIGHT;
            s = 1;
            
        }
        if(s == 1) {
            push();
            pop();
            update();
        }
        refresh();
        level = 9;
        int l = 1000000/15 + level - dir;
        usleep(l);
    }while(ch != 'q');

    
    endwin();
    return 0;
}


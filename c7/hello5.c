#include<stdio.h>
#include<curses.h>
#include<unistd.h>
//模拟字符串在屏幕四壁弹来弹去

#define LEFTEDGE 10
#define RIGHTEDGE 150
#define ROW 10

int main(){
    char message[]="Hello";
    char blank[] = "      ";
    int dir = +1;
    int pos = LEFTEDGE;

    initscr();
    clear();
    while(1){
        move(ROW,pos);
        addstr(message);
        move(LINES-1,COLS-1);
        refresh();
        usleep(100);
        move(ROW,pos);
        addstr(blank);
        pos += dir;
        if (pos >= RIGHTEDGE) dir = -1;
        if(pos <= LEFTEDGE) dir = +1;
    }
    return 0;
}

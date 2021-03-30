#include<curses.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    int i;
    initscr();
    clear();
    for(i=0;i<LINES;i++){
        move(i,i+1);
        addstr("hello world");
        refresh();
        sleep(1);
        move(i,i+1);
        addstr("                            ");
    }
    endwin();
    return 0;
}


#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;

#define page_len 1024
#define need_lines 10

int get_page(int f, char* buff){
    int length = read(f, buff, page_len);
    lseek(f,-length,SEEK_CUR);
    return length;
}
   
int get_line(int f, char* buff, int& all_lines){
    for(int i=page_len-1;i>=0;i--){
        if(buff[i] == '\n'){
            all_lines++;
        }
        if(all_lines == need_lines){
            return 1;
        }
        printf("%c",buff[i]);
    }
    return 0;
}

int main(int args, char* argv[]){
    char* filename = argv[1];
    char* buff = nullptr;
    int all_lines = 0;
    int f = open(filename,O_RDONLY);
    lseek(f,0,SEEK_END);

    while( all_lines < need_lines ){
        lseek(f, -page_len, SEEK_CUR); 
        if(get_page(f,buff) <= page_len){
            get_line(f,buff,all_lines);
            break;
        }
        if(get_line(f,buff,all_lines)){
            break;
        }
    }
    return 0;
}

        
        
        
        
        
        



    



    


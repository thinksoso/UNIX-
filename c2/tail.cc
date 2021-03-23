#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;

#define page_len 10
#define need_lines 3


int get_page(int f, char* buff){
    //因为是倒着读的，注意read之后要归位
    lseek(f,-page_len,SEEK_CUR);
    int length = read(f, buff, page_len);
    lseek(f,-length,SEEK_CUR);
    return length;
}
   
int get_line(int f, char* buff, int& all_lines, int& all_bytes){
    int length = get_page(f,buff);
    if(length == 0 ) return 1;
    for(int i=length-1;i>=0;i--){
        if(buff[i] == '\n'){
            all_lines++;
        }
        if(all_lines == need_lines){
            return 1;
        }
        all_bytes++;
    }
    return 0;
}

int main(int args, char* argv[]){
    //先求出倒数第n行的位置，再read，有点蠢，后续改成求出位置的同时存入读取结果
    char* filename = argv[1];
    char buff[page_len];
    char result[100000];
    int all_lines = 0;
    int f = open(filename,O_RDONLY);
    int file_bytes = lseek(f,0,SEEK_END);
    int all_bytes = 0;
    while( all_bytes <= file_bytes ) {
        if(get_line(f,buff,all_lines,all_bytes)){
            break;
        }
    }
    lseek(f,-all_bytes,SEEK_END);
    read(f,result,all_bytes);
    cout<<result<<endl;
    return 0;
}

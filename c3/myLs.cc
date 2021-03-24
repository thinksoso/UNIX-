#include <dirent.h>
#include <iostream>
using namespace std;

void showinfo(const char* name){
    DIR * dir = opendir(name);
    struct dirent *info;
    while((info=readdir(dir))!=NULL){
        cout << info->d_ino << " " << info->d_type << " " << info->d_name << endl;
    }
}


int main(int argc, char* argv[]){
    char *name;
    if(argc==1){
        char tmp ='.';
        showinfo(&tmp);
    }
    for(int i=1;i<argc;i++){
        showinfo(argv[i]);
    }
    return 0;
}


    

#include <string.h>
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include <unistd.h>

int get_inode(char *name){
    struct stat info;
    stat(name,&info);
    return info.st_ino;
}

void find_name(int inode,char* name){
    struct dirent *info;
    DIR* dir_ptr;
    dir_ptr = opendir(".");
    while((info=readdir(dir_ptr))!=NULL){
        if(info->d_ino == inode){
            strncpy(name,info->d_name,info->d_namlen);
            name[info->d_namlen]='\0';
            break;
        }
    }
    closedir(dir_ptr);
    return ;
}


void dp(){
    int i1 = get_inode(".");
    int i2 = get_inode("..");
    char dir_name[256];
    if( i1 == i2){
        return ;
    }
    chdir("..");
    find_name(i1,dir_name);
    dp();
    printf("/%s",dir_name);
    return;
}

int main(){
    dp();
    printf("\n");
    return 0;
}    
    

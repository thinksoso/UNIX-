#include <utmpx.h>
#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
using namespace std;
#define UTMPXFILE "/var/run/utmpx"
int main(){
    struct utmpx * u;
    while((u=getutxent())!=NULL){
        cout<< u->ut_line << " " << u->ut_host << u->ut_id <<endl;
    }
    return 0;
}


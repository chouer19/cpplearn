#include <stdio.h>

int range(int a, int b){
    static long long int i;
    static int state = 0;
    switch( state ){
        case 0:
            state = 1;
            for ( int i=a; i<b; i++){
                return i;
            }
        case 1:;
    }
    state = 0;
    return 0;
}

int main(){
    int i;
    for(;i=range(1,5);){
        printf("control at main:%d\n",i);
    }
    return 0;
}

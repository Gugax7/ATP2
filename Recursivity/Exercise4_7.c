#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){
    if(b == 0){
        return a;
    }
    return mdc(b,a%b);
}

int main(){
    
    printf("%i", mdc(15,9));
    return 0;
}
#include <stdio.h>

int fact (int input){
    if(input == 1){
        return input;
    }
    else{
        return (input * fact(input-1));
    }
} 


int main(int argc, char *argv[]){
    int factorial = fact(atoi(argv[1]));
    printf("%d\n", factorial);
    return 0;
}

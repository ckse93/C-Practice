#include <stdio.h>
//swapping two integers using pointers

void swapping (int * a, int * b ){
    int c = *a;
    * a = *b;
    *b = c;
}

int main (int argc, char**argv){
    int a = 10;
    int b =20;
    
    printf ("a = %d, b =%d\n", a,b);
    swapping (&a, &b);
    printf ("a = %d, b =%d\n", a,b);

    return 0;
}

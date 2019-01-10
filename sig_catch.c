#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

struct sigaction act;
struct sigaction act2;
void exit_now(){
    printf ("exiting in ");
    for (int i = 10 ; i > 0 ; i--){
        printf ("%d\n", i);
        sleep(1);
    }
    exit(1);
}

void not_now (){
    printf ("main loop is still running\n");
}

int main(int argc, char const *argv[]){
    act.sa_handler = exit_now;
    act.sa_flags= 0;

    act2.sa_handler = not_now;
    act2.sa_flags = 0;

    while (1){
        for (int i = 0 ; i < 10 ; i++){
            printf ("running...\n");
            sleep (1);
            sigaction(SIGINT, &act2, NULL);
        }

        for (int j = 0 ; j < 10; j++){
            printf ("resting....\n");
            sleep (1);
            sigaction(SIGINT, &act, NULL);
        }

    }
    return 0;
}

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
struct sigaction act;

void caught_SIGINT (int sig){
	fprintf(stderr, "caught SIGINT signal, exiting in 5 seconds\n");
	sleep(5);
	exit(1);
}

int main(int argc, char * argv[]){
	act.sa_handler = caught_SIGINT; //linking handler to execute caught_SIGINT function above
	//act.sa_handler = SIG_IGN; // if you uncomment this, it will simply ignore ctrl+c signal (SIGINT)
	sigaction (SIGINT, &act, NULL); // this will allow you to redirect ctrl+c signal to caught_SIGINT function above
	printf("hit ctrl+c to exit\n");
	while(1);
	return 0;
}

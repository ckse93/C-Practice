#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 512//max string size will be 512

int main(int argc, char const *argv[]) {
char str[MAX_SIZE];
printf("%s\n", "write the message into stdin: ");
read (0, str, MAX_SIZE); // reading from 0, stdin, store that into str
printf("%s %s\n", "printf statement : ", str);
write(1,str,strlen(str)); // 1 indicates stdout, which will be the terminal.
return 0;
}

#include "main.h"


int main(int ac, char **argv){
    char *prompt = "XXX $";
    char *line;
    size_t len = 0;

    (void)ac; (void)argv;

    printf("%s", prompt);
    getline(&line, &len, stdin);
    printf("%s\n", line);

    free(line);
    return 0;
}
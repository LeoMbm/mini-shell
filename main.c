#include "main.h"


int main(int ac, char **argv){
    char *prompt = "XXX $ ";
    char *line;
    size_t len = 0;
    ssize_t chars_read;

    (void)ac; (void)argv;
    // Create a loop that prints the prompt and waits for input
    while (1){    
        printf("%s", prompt);
        chars_read = getline(&line, &len, stdin);
        // Check for EOF (Ctrl+D or failure)
        if (chars_read == -1){
            printf("Exiting...\n");
            return -1;
        }   
        printf("%s\n", line);
        free(line);
    }




    return 0;
}
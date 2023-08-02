#include "main.h"


int main(void){
    char *prompt = ":) $ ";
    char *line = NULL, *line_cpy = NULL;
    size_t len = 0;
    ssize_t chars_read;
    const char *delim = " \n";
    char *token;
    int num_tokens = 0;
    int i;
    char **argv = NULL;


    while (1){
    printf("%s", prompt);
    // Read a line from stdin
    chars_read = getline(&line, &len, stdin);
    line_cpy = NULL; 

    if (chars_read == -1) {
        printf("Exiting...\n");
        break; // Exit the loop when CTRL+D is encountered
    }

    line_cpy = malloc(sizeof(char) * (chars_read));

    if (line_cpy == NULL){
        printf("Error: malloc failed\n");
        return -1;
    }

    // Copy the line to a new buffer
    strcpy(line_cpy, line);


    // Check for EOF (Ctrl+D or failure)
    if (chars_read == -1){
        printf("Exiting...\n");
        return -1;
    } else {

        for (i = 0; i < num_tokens; i++) {
            free(argv[i]);
        }
        free(argv);

        // Tokenize the line
        token = strtok(line, delim);

        // Count the number of tokens
        num_tokens = 0;
        while (token != NULL){
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(line_cpy, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * (strlen(token)));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;
        execmd(argv);
        // Check for empty line
        printf("%s\n", line);
        }
    free(line_cpy);
    }

    free(line);
    return 0;
}
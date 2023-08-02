#include "main.h"

char *getpath(char *cmd){
    char *path, *path_cpy, *token, *cmd_path;
    int cmd_len, dir_len;
    struct stat st;
    path = getenv("PATH");
    if (path){
        /*  Make a copy of the path */
        path_cpy = strdup(path);
        /*  Get the length of the command */
        cmd_len = strlen(cmd);
        /*  Tokenize the path*/
        token = strtok(path_cpy, ":");

        while(token != NULL){
            dir_len = strlen(token);
            /*  Allocate memory for the command path */
            cmd_path = malloc(sizeof(char) * (dir_len + cmd_len + 2));
            /*  Copy the directory to the command path */
            strcpy(cmd_path, token);
            /*  Add a slash to the end of the directory */
            strcat(cmd_path, "/");
            /*  Add the command to the end of the command path */
            strcat(cmd_path, cmd);
            strcat(cmd_path, "\0");
            /*  Check if the command path exists */

            if (stat(cmd_path, &st) == 0){
                /*  Return the command path */
                free(path_cpy);
                return cmd_path;
            } else {
                /*  Free the memory allocated for the command path */
                free(cmd_path);
                /*  Get the next directory */
                token = strtok(NULL, ":");
            }

        }
        /*  Free the memory allocated for the path copy */
        free(path_cpy);

        if (stat(cmd, &st) == 0){
            return cmd;
        } else {
            return NULL;
        }
    }

    return NULL;
    
}
#include "main.h"


void execmd(char **argv){

    char *cmd = NULL, *path = NULL;

    if (argv){
        cmd = argv[0];
        path = getpath(cmd);
        
        if (execve(path, argv, NULL) == -1){
            perror("Error:");
        }
    }

}

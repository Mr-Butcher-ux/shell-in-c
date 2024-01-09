#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include    <stdio.h>
#include    <signal.h>
 
#define    MAXARGS        20                /* cmdline args    */
#define    ARGLEN        100                /* token length    */
#define BUFFER_LEN 1024                     /*Buffer length    */
 
void execute( char *arglist[] );
int main() {
    char line[BUFFER_LEN];  //get command line
    char *argv[ARGLEN];        //user command
    char* path= "/bin/";    //set path at bin
    char progpath[MAXARGS];      //full file path
    int numargs;               //arg count
   // char    *makestring();
   
numargs = 0;
    while(numargs < MAXARGS) {
 
    printf("Bryan-Rocha> ");                    //print shell prompt
    if(!fgets(line, BUFFER_LEN, stdin)) //accepts user imputs
       
        break;
    size_t length = strlen(line);
    if (line[length - 1] == '\n')
        line[length - 1] = '\0';
    
    if(strcmp(line, "!!")==0) { //
        
        for(int n = 0; n<10 ; n++) {
            
            if(argv[n] != NULL)
                printf("History command  %d: %s\n",n, argv[n]); // prints history commands
            }
        }
    
    if(strcmp(line, "exit")==0) {            //check if command is exit
        break;
        
    }
        
    char *token;                  //split command into separate strings
    token = strtok(line," ");
        int i=0;
        while(token!=NULL && i < 100) {
            argv[i]=token;
            token = strtok(NULL," ");
            i++;
        }
    
        argv[i]=NULL;                     //set last value to NULL for execvp

    numargs=i;                           //get arg count
        for(i=0; i<numargs; i++) {
            printf("%s\n", argv[i]);      //print command/args
        }
        strcpy(progpath, path);           //copy /bin/ to file path
        strcat(progpath, argv[0]);            //add program to path

        for(i=0; i<strlen(progpath); i++) {    //delete newline
            if(progpath[i]=='\n'){
                progpath[i]='\0';
            }
        }
        int pid= fork();              //fork child

        if(pid==0) {               //Child
            execvp(progpath,argv);
            fprintf(stderr, "Child process could not do execvp\n");

        } else {                    //Parent
            wait(NULL);
            printf("Child exited\n");
        }
        
}
    return 0;
}

 
   

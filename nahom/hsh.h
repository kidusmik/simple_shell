#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

/* Shell functions*/
int hsh_loop(char *av[], int execution_counter, char **env);
int new_process(char *av[], int execution_counter, char **env);

/* string functions */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif /* HSH_H */

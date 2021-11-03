#ifndef HSH_H
#define HSH_H
#define _GNU_SOURCE
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

/* diffrent utility functions */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_getenv(char *name, char **env);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, int size);
void print_env(char **env);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);

#endif /* HSH_H */

#ifndef HSH_MAIN_H
#define HSH_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int check_command(char *command_file, char *prompt);
int check_exit(char *command_file);
int run_child_shell(void);
int check_hsh(char *command_file);
int len_pid(pid_t pid);
char *pid_to_str(pid_t pid);
int char_to_int(char *ch);
pid_t str_to_pid(char *pid_str);
int power(int a, int b);
int count_env_vars(char **env);
void _setenv(char *hsh_env_name, char *this_pid_str, int env_count, int pid_length, char **env);
int _strlen(char *string);
int check_printenv(char *command_file);
void _printenv(char **env);
void _strcat(char *path, char *command, char *command_path);
char *find_command(char *command_file, char **path);
char * _strdup(char *from);

#endif /* HSH_MAIN_H */

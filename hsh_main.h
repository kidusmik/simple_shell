#ifndef HSH_MAIN_H
#define HSH_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int run_parent_shell(pid_t hsh_pid, pid_t this_pid, char **env);
int check_command(char *command_file, struct stat *st, char *prompt);
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
#endif /* HSH_MAIN_H */
#ifndef HSH_H
#define HSH_H

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
void _setenv(char *hsh_env_name, char *this_pid_str,
		int env_count, int pid_length,
		char **env);
int _strlen(char *string);
int check_printenv(char *command_file);
void _printenv(char **env);
void _strcat(char *path, char *command, char *command_path);
char *find_command(char *command_file, char **path, char *prompt);
char *_strdup(char *from);
char *get_prompt(char **env);
void print_prompt(char *prompt);
void get_each_paths(char **path);
void get_each_command_argv(char **command_argv, char *input_buffer);
int _strcmp(char *string1, char *string2);
int execute_command(char *command, char **command_argv,
			char **env, char *prompt);
ssize_t line_input_check(char **input_buffer, size_t *b_size,
				FILE *stream, char *prompt);
void free_dptr(char **dptr1, char **dptr2, int size);
void free_ptrs(char *ptr1, char *ptr2, char *pt3);

#endif /* HSH_H */

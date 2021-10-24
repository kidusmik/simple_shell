#ifndef HSH_MAIN_H
#define HSH_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int run_parent_shell(void);
int check_command(char *command_file, struct stat *st, char *prompt);
int check_exit(char *command_file);
int run_child_shell(void);
int check_hsh(char *command_file);

#endif /* HSH_MAIN_H */

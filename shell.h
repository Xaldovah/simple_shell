#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <ctype.h>
#include <limits.h>

#define MAXIMUM_INPUT 1024
#define PROMPT "shell$ "
#define MAX_ARGS 64
#define MAX_PATHS 64
#define MAX_PATH_LENGTH 256
#define BUFFER_SIZE 1024

typedef struct passinfo
{
	char *pass;
} info_t;

extern char **environ;

/* Function prototypes */
void custom_signal_handler(int signal_iden);
char **custom_tokenize(char *str, char *delimiter, int count);
int _atoi(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(const char *str);
char *_strcat(char *destination, char *source);
char *custom_getenv(const char *var_name);
void res_handle_exit(char **res_tokens, char *res_line);
char *rem_newline_char(char *str);
int builtin(char **tokens, char *ln);
int count_chars(char *input, char *delimiters);
int count_words(char *input);
char *string_toupper(char *s);
void *_realloc(void *pointer, unsigned int prev_size, unsigned int new_size);
void _puts(char *s);
int _putchar(char i);
int _strncmp(const char *str1, const char *str2, size_t limit);
char *check_path(char *cmd);
int read_buffer(char *buffer, int desc, int *start, int *finish);
int process_buffer(char *buffer, int *start, char **lineptr, int line_length);
int _getline(char **ptr, int desc);
void prt_environ(void);
int _alpha(int a);
int _echo(char **command);
void un_putchar(unsigned int i);
void _putchr(int i);
int echo_exec(char **command, int status);
int _cd(char **command, __attribute__((unused))int last);
char *concatenate_path(char *dir_path, char *file_name);
char *lookup_path(char *command_name);
int execute_cmd(char *command_name, char **arguments);
void execute_exit(char **tokens, char *ln);
void execute_env(void);
void execute_setenv(char **tokens);
void execute_unsetenv(char **tokens);
char *my_strtok(char *str, const char *delimiter);
unsigned int check_char(char character, const char *str);
void free_tokens(char **tokens);
char *_strdup(char *s);
char *_check(const char *memstack, const char *pinch);
int _executable(info_t *paper, char *pass);
char *_chars(char *passtr, int begin, int end);
char *_path(info_t *paper, char *passtr, char *command);
char *_path(info_t *, char *, char *);
void frees_get_env(char *environ_path);
void frees_tokens(char **tokens);

#endif

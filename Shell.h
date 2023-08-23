#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* for con_num() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* for com_chain */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* for read plus write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr_1 - singly linked list
 * @str: a string
 * @num: the number field
 * @next: points to the next node
 */
typedef struct liststr_1
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/**
 * struct passinfo_2 - contains pseudo-arguements to pass into a function,
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 */
typedef struct passinfo_2
{
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}


/**
 * struct builtin_3 - contains a builtin string and related function
 * @func: the function
 * @type: the builtin command flag
 */
typedef struct builtin_3
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* loophsh.c */
int loophsh(char **);

/* toem-parser.c */
char *dupchars_1(char *, int, int);
char *findpath_2(info_t *, char *, char *);
int iscmd_3(info_t *, char *);

/* toem_shloop.c */
int hsh_4(info_t *, char **);
void findcmd_5(info_t *);
int findbuiltin_6(info_t *);
void forkcmd_7(info_t *);

/* toem-exits.c */
char *_1strncat(char *, char *, int);
char *_2strchr(char *, char);
char *_3strncpy(char *, char *, int);

/* toem-string.c */
char _1strcat(char *, char *);
int _2strcmp(char *, char *);
int _3strlen(char *);
char _4startswith(const char *, const char *);

/* toem-string-1.c */
void _6puts(char *);
int _7putchar(char);
char _8strdup(const char *);
char *_9strcpy(char *, char *);

/* toem-environ.c */
char *_getenv(info_t *, const char *);
int _1myenv(info_t *);
int _2mysetenv(info_t *);
int _3myunsetenv(info_t *);
int _4populateenvlist(info_t *);

/* toem-getinfo.c */
void _1setinfo(info_t *info, char **av)
void _2clearinfo(info_t *info)
void _3freeinfo(info_t *info, int all)

/*toem-getline.c */
void _1sigintHandler(int);
int _2getline(info_t *, char **, size_t *);
ssize_t _3readbuf(info_t *info, char *buf, size_t *i)
ssize_t _4getinput(info_t *);
ssize_t _5inputbuf(info_t *info, char **buf, size_t *len)

/* toem-builtin.c */
int _1myhelp(info_t *);
int _2myexit(info_t *);
int _3mycd(info_t *);
int _4myhistory(info_t *);
int _5unsetalias(info_t *);

/* toem-builtin-1.c */
int _6setalias(info_t *);
int _7printalias(info_t *);
int _8myalias(info_t *);

/* toem_errors.c */
int _1putsfd(char *str, int fd);
void _2eputs(char *);
int _3eputchar(char);
int _4putfd(char c, int fd);
void _5printerror(info_t *, char *);
/* toem-errors-1.c */
void removecomments(char *);
int _2erratoi(char *);
int printd(int, int);
char *convertnumber(long int, int, int);

/* toem-atoi.c */
int _1atoi(char *);
int _2isalpha(int);
int interactive_3(info_t *);
int isdelim_4(char, char *);

/* toem-realloc.c */
void 1_realloc(void *, unsigned int, unsigned int);
char 2_memset(char *, char, unsigned int);
void 3_ffree(char **);

/* toem-tokenizer.c */
char **strtow_1(char *, char *);
char **strtow_2(char *, char);

/* toem-getenv.c */
int _1unsetenv(info_t *, char *);
char **_2getenviron(info_t *);
int _3setenv(info_t *, char *, char *);


/* toem-history.c */
int _1readhistory(info_t *info);
int _2buildhistorylist(info_t *info, char *buf, int linecount);
int _3renumberhistory(info_t *info);
char *_4gethistoryfile(info_t *info);
int _5writehistory(info_t *info);

/* toem-vars.c */
void checkchain_1(info_t *, char *, size_t *, size_t, size_t);
int ischain_2(info_t *, char *, size_t *);
int replacealias_31(info_t *);
int replacestring_32(char **, char *);
int replacevars_33(info_t *);

/* toem-lists.c */
list_t *addnode_1(list_t **, const char *, int);
list_t *addnodeend_2(list_t **, const char *, int);
int deletenodeatindex_3(list_t **, unsigned int);
void freelist_4(list_t **);
size_t listlen_5(const list_t *);

/* toem-lists-1.c */
char **listtostrings_6(list_t *);
ssize_t getnodeindex_7(list_t *, list_t *);
list_t *nodestartswith_8(list_t *, char *, char);
size_t printliststr_9(const list_t *);
size_t printlist_10(const list_t *);

#endif

struct stat;

// system calls
int fork(void);
int exit(int) __attribute__((noreturn));
int wait(int*);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(const char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void fprintf(int, const char*, ...) __attribute__ ((format (printf, 2, 3)));
void printf(const char*, ...) __attribute__ ((format (printf, 1, 2)));
char* gets(char*, int max);
unsigned strlen(const char *s);
void*    memset(void *dst, int c, unsigned n);
int atoi(const char*);
int      memcmp(const void *a, const void *b, unsigned n);
void*    memcpy(void *dst, const void *src, unsigned n);

// umalloc.c
void*    malloc(unsigned n);
void     free(void *ptr);

//threads user-level functions declaration 
int thread_create(void (*fcn)(void *), void *arg);
void thread_exit(void);
int thread_join(int pid);

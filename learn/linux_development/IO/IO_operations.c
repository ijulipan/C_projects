/*
    Function Prototypes for open, creat(), read(), write(), 
    lseek(), fopen(), fclose(), fgetc(), fgets(), fputc() and fputs()
*/ 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Open function prototypes
int open(const char *name, int flags);
int open(const char *name, int flags, mode_t mode);

// fopen() function prototypes
FILE *fopen(const char *filename, const char *mode);

// Create function protype
int creat(const char *name, mode_t mode);

// Read function prototype
ssize_t read(int fd, void *buf, size_t len);

// fgetc() function prototype
int fgetc(FILE *fp); // Reads a character from the file

// fgets() function prototype
char *fgets(char *buf, int n, FILE *fp); // Reads up to n-1 characters from the input stream and stores in buf

// Write function prototype
ssize_t write(int fd, const void *buf, size_t count);

// fputc() function prototype
int fputc(int c, FILE *fp); // Writes the character c to the file pointed.

// fputs() function prototype
int fputs(const char *s, FILE *fp); // Writes the string s to the file pointed

// lseek function prototype
off_t lseek(int fd, off_t offset, int whence);

// Close function prototype
int close(int fd);

// fclose function prototype
int fclose(FILE *fp);

// String Copy Functions

/*
    strcpy() copies the string from src to dest. It copies until null-terminator
    \0 is reached. strncpy() copies up to n characters or until \0 is found. 
*/
char *strcpy(*dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

// String Comparison Functions
/*
    strcmp() compares str1 with str2 char by char until \0.
    strncmp() compares until n characters.
    
    Returns:
    < 0 if str1 is less than str2.
    0 if str1 is equal to str2.
    > 0 if str1 is greater than str2.
*/
int strcmp(const char *str1, const char *str2);
int strncmp(const char *s1, const char *s2, size_t n);

// String Search Function
/*
    Finds the first occurence of the substring needle in the string haystack

    Returns:
    A pointer to the first occurrence of needle in haystack
    If needle not found, returns NULL
*/
char *strstr(const char *haystack, const char *needle);

// Memory Handling Function
/*
    Copies n bytes from the source memory area src to the destination memory area dest

    Returns:
    A pointer to the destination dest
*/
void *memcpy(void *dest, const void *src, size_t n);

// System function
/*
    Calls /bin/sh to execute the command specified by command
*/
int system(const char *command);

int main(){
    // Example of open()
    int fd = open("./test.bin", 0644);
    if (fd == -1){
        // Error, check errno
    } else {
        // Success, proceed
    }

    // Example of creat()
    int fd = creat("./test.bin", 0644);
    if (fd == -1){
        // Error, check errno
    } else {
        // Success, proceed
    }

    // Example of read()
    ssize_t nr = read(fd, buf, len);
    if (nr == -1){
        // Error, check errno
    } else if (nr != len) {
        // Partial read, handle as needed
    }

    // Example of write()
    ssize_t nr = write(fd, &word, count);
    if (nr == -1){
        // Error, check errno
    } else if (nr != count) {
        // Partial write, handle as needed
    }

    // Example of lseek
    lseek(fd, 0, SEEK_SET); // Set position to the start
    lseek(fd, 15, SEEK_END); // Move position to 15 bytes from the end

    close
}
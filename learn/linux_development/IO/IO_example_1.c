#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){
    int ret, fd;
    char buf[1024] = {0};
    char buf1[] = "hello world";
    char buf11[] = "xxhello worldxx";
    char buf2[1024] = {0};
    char filename[] = "./test.txt";

    fd = open(filename, O_RDWR | O_CREAT, 00755); // Create file if it does not exist
    if (fd < 0){
        ret = fd;
        goto err_open;
        printf("Open error: %d\n", errno); // Print error if open fails
        return fd; // Exit if open fails
    }

    printf("Open: %s success\n", filename);
    // Write the first string to the file
    lseek(fd, 0, SEEK_SET);
    write(fd, buf1, strlen(buf1));
    lseek(fd, 0 , SEEK_SET);

    int nu = read(fd, buf, sizeof(buf));
    printf("read: %d: %s\n", nu, buf);
    lseek(fd, 0, SEEK_SET);
    nu = read(fd, buf, sizeof(buf));
    printf("read: %d: %s\n", nu, buf);
    close(fd);

    return 0;
    err_open:
        printf("open error: %d\n", errno);
        return ret;
}
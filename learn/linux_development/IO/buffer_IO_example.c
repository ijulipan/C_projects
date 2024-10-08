#include <stdio.h>

int main(){
    FILE *fp = NULL;
    char buf[255];

    // Open the file in read and write mode
    fp = fopen("./test.txt", "r+");

    // Read and print a string until a space or newline
    fscanf(fp, "%s", buf);
    printf("1: %s\n", buf);

    // Read and print the next line
    fgets(buf, 255, fp);
    printf("2: %s\n", buf);

    // Read and print another line
    fgets(buf, 255, fp);
    printf("3: %s\n", buf);

    // Write to the file
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);

    // Close the file
    fclose(fp);

    return 0;
}
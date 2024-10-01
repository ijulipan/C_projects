#include <stdio.h>

union Endianness {
    int num;
    unsigned char bytes[sizeof(int)];
};

int main(){
    union Endianness e;
    e.num = 1;

    if(e.bytes[0] == 1){
        printf("Little-endian\n");
    } else{
        printf("Big-endian\n");
    }

    return 0;
}
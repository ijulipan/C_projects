#include <stdio.h>

unsigned int reverse_bits(unsigned int num){

    unsigned int reverse_num = 0;
    int bits = sizeof(num) * 8; // Total number of bits (either 32 or 64)

    for (int i = 0; i < bits; i++){
        if(num & (1 << i)) {
            reverse_num |= 1 << ((bits - 1) - i);
        }
    }
    return reverse_num;
}


int main(){
    unsigned int num;

    printf("Enter a number to reverse: ");
    scanf("%u", &num);

    
    unsigned int reversed = reverse_bits(num);
    printf("Reversed bit pattern: %u\n", reversed);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_POOL_SIZE 1024 // Define the size of the memory pool

typedef struct Block {
    size_t size; // Size of the block
    struct Block* next; // Pointer to the next block
    int free; // Flag indicating whether the block is free
} Block;

typedef struct MemoryPool {
    char pool[MEMORY_POOL_SIZE]; // Memory pool
    Block* freeList; // Free block linked list
} MemoryPool;

MemoryPool memPool;

// Initialize the memory pool
void initMemoryPool() {
    memPool.freeList = (Block*)memPool.pool; // Set the head pointer of the free block list to point to the memory pool
    memPool.freeList->size = MEMORY_POOL_SIZE - sizeof(Block); // Initialize the size of the free block
    memPool.freeList->next = NULL; // No other free blocks currently
    memPool.freeList->free = 1; // Mark as a free block
}

// Custom malloc function
void* myMalloc(size_t size) {
    Block* current = memPool.freeList; // Start from the head of the free block list
    while (current != NULL) {
        // Check if the block is large enough and is free
        if (current->free && current->size >= size) {
            // Split the block
            if (current->size >= size + sizeof(Block) + 1) { // Check if there's enough space to split
                Block* newBlock = (Block*)((char*)current + sizeof(Block) + size);
                newBlock->size = current->size - size - sizeof(Block);
                newBlock->next = current->next;
                newBlock->free = 1;

                current->size = size; // Update the size of the current block
                current->next = newBlock; // Update the linked list
            }
            current->free = 0; // Mark as allocated
            return (char*)current + sizeof(Block); // Return the pointer to the data area
        }
        current = current->next; // Move to the next block
    }
    return NULL; // No available blocks
}

// Custom free function
void myFree(void* ptr) {
    if (ptr == NULL) return; // Check for null pointer

    Block* block = (Block*)((char*)ptr - sizeof(Block)); // Get the block header
    block->free = 1; // Mark as free block

    // Merge free blocks
    Block* current = memPool.freeList;
    while (current != NULL) {
        if (current->free && current->next && current->next->free) {
            current->size += sizeof(Block) + current->next->size; // Merge size
            current->next = current->next->next; // Skip the merged block
        } else {
            current = current->next; // Move to the next block
        }
    }
}

// Test custom memory management
int main() {
    initMemoryPool(); // Initialize the memory pool

    // Test memory allocation
    int* arr = (int*)myMalloc(10 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
    } else {
        for (int i = 0; i < 10; i++) {
            arr[i] = i; // Initialize the array
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    // Free memory
    myFree(arr);
    return 0;
}

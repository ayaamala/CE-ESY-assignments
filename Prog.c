
#include <stdio.h>
#include <string.h>
#define MAX_CAPACITY 10  
typedef struct {
    char data_store[MAX_CAPACITY];
    int read_pos;  
    int write_pos; 
    int active_elements; 
} RingBuffer;
void setupBuffer(RingBuffer *rb) {
    rb->read_pos = 0;
    rb->write_pos = 0;
    rb->active_elements = 0;
}

void pushData(RingBuffer *rb, char item) {
    
    if (rb->active_elements >= MAX_CAPACITY) {
        printf("\nBuffer Overflow! Cannot add: %c", item);
        return;
    }
    
    rb->data_store[rb->write_pos] = item;
    
    rb->write_pos = (rb->write_pos + 1) % MAX_CAPACITY;
    rb->active_elements++;
}

char popData(RingBuffer *rb) {
    
    if (rb->active_elements <= 0) {
        printf("\nBuffer Underflow!");
        return '\0';
    }
    
    char value = rb->data_store[rb->read_pos];
    rb->read_pos = (rb->read_pos + 1) % MAX_CAPACITY;
    rb->active_elements--;
    return value;
}

int main() {
    RingBuffer myBox;
    setupBuffer(&myBox);

    char userInput[100];
    const char *tag = "CE-ESY";

       printf("Enter your name: ");
    if (scanf("%90s", userInput) != 1) return 1; 

       strcat(userInput, tag);
    printf("Processed string: %s\n", userInput);

       printf("Storing characters...\n");
    int len = strlen(userInput);
    for (int j = 0; j < len; j++) {
        pushData(&myBox, userInput[j]);
    }

       printf("\nOutput from Buffer: ");
    while (myBox.active_elements > 0) {
        printf("%c", popData(&myBox));
    }
    
       if (myBox.active_elements == 0) {
        printf("\nVerification: System is clear.\n");
    }

    return 0;
}

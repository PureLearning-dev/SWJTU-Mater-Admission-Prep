#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 6 

// Function to replace digits with the string "number"
char* addNumber(char* string, int* returnSize) {
    int len = strlen(string);
    int index = 0;
    
    // Allocate memory: Worst case is all digits. 
    // Each digit becomes 6 characters, plus 1 for the null terminator '\0'.
    char* result = (char*)malloc(sizeof(char) * (N * len + 1)); 
    
    // Safety check: handle memory allocation failure
    if (result == NULL) return NULL; 

    for (int i = 0; i < len; i++) {
        // Check if the current character is a digit
        if (string[i] >= '0' && string[i] <= '9') {
            // Replace digit with 'n','u','m','b','e','r'
            // Note: Use single quotes for character literals
            result[index++] = 'n'; 
            result[index++] = 'u';
            result[index++] = 'm';
            result[index++] = 'b';
            result[index++] = 'e';
            result[index++] = 'r';
        } else {
            // Keep the original non-digit character
            result[index++] = string[i];
        }
    }
    
    // Crucial: Manually add the null terminator to mark the end of the string
    result[index] = '\0'; 
    
    // Record the actual length of the new string
    *returnSize = index;  
    
    return result;
}

int main() {
    // Array size is automatically calculated based on the initializer string
    char string[] = "woed55dk5k"; 
    int finalLen;
    
    char* data = addNumber(string, &finalLen);
    
    if (data != NULL) {
        printf("Result: %s\n", data);
        free(data);
    }
    
    return 0;
}
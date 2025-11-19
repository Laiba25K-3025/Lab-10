#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

void encrypt(char *text, int shift);
void decrypt(char *text, int shift);

void encrypt(char *text, int shift) {
    int i = 0;
    char ch;

    while (text[i] != '\0') {
        ch = text[i];
        
        if (ch >= 'A' && ch <= 'Z') {
            char start = 'A';
            
            int char_index = ch - start;
            
            int shifted_index = (char_index + shift + 26) % 26;
            
            text[i] = start + shifted_index;
        }
        else if (ch >= 'a' && ch <= 'z') {
            char start = 'a';
            
            int char_index = ch - start;
            
            int shifted_index = (char_index + shift + 26) % 26;
            
            text[i] = start + shifted_index;
        }

        i++;
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, -shift);
}

int main() {
    char original_message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int shift_value = 3;

    printf("Enter the message to encrypt (max %d chars):\n", MAX_MESSAGE_LENGTH - 2);
    fgets(original_message, MAX_MESSAGE_LENGTH, stdin); 

    original_message[strcspn(original_message, "\n")] = 0;

    strcpy(encrypted_message, original_message); 

    printf("\nOriginal:  %s\n", original_message);

    encrypt(encrypted_message, shift_value);
    printf("Encrypted: %s\n", encrypted_message);
    
    strcpy(decrypted_message, encrypted_message); 

    decrypt(decrypted_message, shift_value);
    printf("Decrypted: %s\n", decrypted_message);

    return 0;
}

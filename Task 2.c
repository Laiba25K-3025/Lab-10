#include <stdio.h>
#include <string.h>

int main() {
	int i;
    char emails[][50] = {
        "user@gmail.com",
        "john.doe@company.org",
        "invalid-email",
        "admin@university.edu"
    };

    int n = 4;

    printf("Email Domain Extraction:\n");

    for(i = 0; i < n; i++) {
        char email[50];
        strcpy(email, emails[i]);

        printf("Email: %s  ->  ", email);

        char *at = strchr(email, '@');  // Find '@'

        if(at != NULL && strchr(at, '.') != NULL) {
            printf("Domain: %s\n", at + 1);  // Print everything after '@'
        } else {
            printf("Domain: Invalid email\n");
        }
    }

    return 0;
}

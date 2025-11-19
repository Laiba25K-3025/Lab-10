#include <stdio.h>
#include <string.h>

int main() {
	int i;
    char password[100];
    int length, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++) {
     
        if (password[i] >= 'A' && password[i] <= 'Z')
            hasUpper = 1;

        if (password[i] >= '0' && password[i] <= '9')
            hasDigit = 1;

        if (password[i] == '!' || password[i] == '@' || password[i] == '#' ||
            password[i] == '$' || password[i] == '%')
            hasSpecial = 1;
    }


    if (length >= 8 && hasUpper && hasDigit && hasSpecial) {
        printf("Password is strong.\n");
    } else {
        printf("Password is not strong.\n");
        printf("Missing:\n");

        if (length < 8)
            printf("- At least 8 characters long\n");
        if (!hasUpper)
            printf("- At least one uppercase letter\n");
        if (!hasDigit)
            printf("- At least one digit\n");
        if (!hasSpecial)
            printf("- At least one special character (!, @, #, $, %)\n");
    }

    return 0;
}


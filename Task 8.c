#include <stdio.h>
#include <string.h>

#define CATEGORIES 3
#define ITEMS 3
#define NAME_LENGTH 30

int main() {
    char category[CATEGORIES][20] = {"Appetizers", "Main Course", "Desserts"};
    char items[CATEGORIES][ITEMS][NAME_LENGTH] = {
        {"Spring Rolls", "Garlic Bread", "Bruschetta"},
        {"Grilled Chicken", "Pasta Alfredo", "Veggie Burger"},
        {"Chocolate Cake", "Ice Cream", "Fruit Salad"}
    };
    float prices[CATEGORIES][ITEMS] = {
        {5.5, 4.0, 6.0},
        {12.0, 11.5, 9.5},
        {7.0, 5.0, 6.5}
    };
    int i, j;

    printf("********** MENU **********\n\n");

    for(i = 0; i < CATEGORIES; i++) {
        printf("%s:\n", category[i]);
        for(j = 0; j < ITEMS; j++) {
            printf("  %s - $%.2f\n", items[i][j], prices[i][j]);
        }
        printf("\n");
    }

    printf("**** Budget-Friendly Items (Under $10) ****\n\n");
    for(i = 0; i < CATEGORIES; i++) {
        for(j = 0; j < ITEMS; j++) {
            if(prices[i][j] < 10.0) {
                printf("%s (%s) - $%.2f\n", items[i][j], category[i], prices[i][j]);
            }
        }
    }

    return 0;
}


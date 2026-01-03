#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int age;
} Dog;

int main() {
    Dog* dogs = NULL;
    int count = 0;
    char temp_name[100];

    while (1) {
        printf("Dog name: ");
        
        if (fgets(temp_name, sizeof(temp_name), stdin) == NULL) {
            break;
        }

        if (temp_name[0] == '\n') {
            break;
        } else {
            temp_name[strcspn(temp_name, "\n")] = 0;
        }

        Dog* temp_ptr = realloc(dogs, (count + 1) * sizeof(Dog));
        if (temp_ptr == NULL) {
            free(dogs);
            return 1;
        }
        dogs = temp_ptr;

        strcpy(dogs[count].name, temp_name);
        printf("%s's age: ", dogs[count].name);
        scanf("%d", &dogs[count].age);
        
        getchar();
        count++;
        printf("Dog added!\n\n");
    }

    printf("\n--- Dogs ---\n");
    for (int i = 0; i < count; i++) {
        printf("Dog %d: %s, %d years \n", i + 1, dogs[i].name, dogs[i].age);
    }

    getchar();
    free(dogs);
    return 0;
}
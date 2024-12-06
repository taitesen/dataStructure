#include "../include/ll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int choice = 0;
    do {
        system("clear");
        printf("\n\n1. Add Entry at the beginning of a list.\n");
        printf("2. Add Entry at the end of a list.\n");
        printf("3. Add Entry at specific position of a list.\n");
        printf("4. Delete Entry at specific position of a list.\n");
        printf("5. Update Entry at specific position of a list.\n");
        printf("6. Exit the program.\n");
        printf("\n");
        Show();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        ClearBuffer();

        while (choice < 1 || choice > 6) {
            system("clear");
            printf("%d is not a valid option\n", choice);
            printf("\n1. Add Entry at the beginning of a list.\n");
            printf("2. Add Entry at the end of a list.\n");
            printf("3. Add Entry at specific position of a list.\n");
            printf("4. Delete Entry at specific position of a list.\n");
            printf("5. Update Entry at specific position of a list.\n");
            printf("6. Exit the program.\n");
            printf("\n");
            Show();
            printf("Enter the correct choice: ");
            scanf("%d", &choice);
            ClearBuffer();
        }

        switch (choice) {
        case 1: {
            char buffer[100];
            char name[40];
            printf("Enter data: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    strncpy(name, buffer, sizeof(name) / sizeof(name[0]));
            }
            InsertAtBegin(name);
            break;
        }
        case 2: {
            char buffer[100];
            char name[40];
            printf("Enter data: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    strncpy(name, buffer, sizeof(name) / sizeof(name[0]));
            }
            InsertAtEnd(name);
            break;
        }
        case 3: {
            char buffer[100];
            char name[40];
            int position = 1;
            printf("Enter data: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    strncpy(name, buffer, sizeof(name) / sizeof(name[0]));
            }
            printf("Enter position: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    position = atoi(buffer);
            }
            InsertAtPos(name, position);
            break;
        }
        case 4: {
            char buffer[100];
            int position = 1;
            printf("Enter position to delete: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    position = atoi(buffer);
            }
            Delete(position);
            break;
        }
        case 5: {
            char buffer[100];
            char name[40];
            int position = 1;

            printf("Which position do you want to update: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    position = atoi(buffer);
            }

            printf("Enter new data: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    strncpy(name, buffer, sizeof(name) / sizeof(name[0]));
            }
            Update(name, position);
            break;
        }
        case 6:
            printf("Exiting..\n");
            break;
        }
    } while (choice != 6);
    return 0;
}

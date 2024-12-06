#include "../include/ll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int choice = 0;
    int position = 0;
    int counter = 0;
    char message[100];
    do {
        system("clear");
        printf(" -- TODO LIST MIZO VERSION --\n");
        Show();
        printf("\n");
        if (choice > 0 || choice < 5) {
            if (choice == 2 && (head == NULL))
                printf("Delete tur a awm rih lo\n");
            else if (choice == 2 && (position > counter))
                printf("%d na a awm lo. Delete theih loh.\n", position);
            else if (choice == 3 && (head == NULL))
                printf("Update tur a awm rih lo\n");
            else if (choice == 3 && (position > counter))
                printf("%d na a awm lo. Update theih loh.\n", position);
            else if (choice < 1 || choice > 4)
                printf("%d HI A ENTER THEIH LOH\n", choice);
            else
                printf("1 to 4 A THLAN THEIH\n");
        }

        printf("\n");
        printf("1. Add list.\n");
        printf("2. Delete list.\n");
        printf("3. Update list.\n");
        printf("4. Exit.\n");
        printf("\n");
        printf("[ 1 to 4 ] duh ber enter rawh: ");
        scanf("%d", &choice);
        ClearBuffer();
        strcpy(message, "");

        switch (choice) {
        case 1: {
            char buffer[120];
            printf("I duh ziak rawh: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    strncpy(message, buffer,
                            sizeof(message) / sizeof(message[0] - 1));
            }
            InsertAtEnd(message);
            break;
        }
        case 2: {
            if (head == NULL) {
                break;
            }
            counter = CountNode();
            if (counter == 1) {
                Delete(1);
                break;
            }
            printf("Eng zat na nge i delete duh?: ");
            scanf("%d", &position);
            ClearBuffer();
            if (position > counter) {
                break;
            }
            Delete(position);
            position = 0;
            break;
        }
        case 3: {
            if (head == NULL) {
                break;
            }
            char buffer[120];
            counter = CountNode();
            if (counter == 1) {
                printf("I duh ziak rawh: ");
                if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1,
                          stdin) != NULL) {
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if (strlen(buffer) > 0)
                        strncpy(message, buffer,
                                sizeof(message) / sizeof(message[0]) - 1);
                }
                UpdateAtPos(message, 1);
                break;
            }
            printf("Eng zatna nge i replace duh: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    position = atoi(buffer);
            }
            if (position > counter) {
                break;
            }

            printf("I duh ziak rawh: ");
            if (fgets(buffer, sizeof(buffer) / sizeof(buffer[0]) - 1, stdin) !=
                NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';

                if (strlen(buffer) > 0)
                    strncpy(message, buffer,
                            sizeof(message) / sizeof(message[0]) - 1);
            }
            UpdateAtPos(message, position);
            position = 0;
            break;
        }
        case 4: {
            printf("Exiting..\n");
        }
        }
    } while (choice != 4);
    return 0;
}

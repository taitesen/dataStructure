#include "../include/ll.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int choice = 0;
    int position;
    int counter = 0;
    char message[100];
    do {
        system("clear");
        printf(" -- TODO LIST MIZO VERSION --\n");
        Show();
        printf("\n");
        if(choice > 0 || choice < 5){
            if(choice == 2 && (head == NULL))
                printf("Delete tur a awm rih lo\n");
            else if(choice == 2 && (position > counter))
                printf("%d na a awm lo. Delete theih loh.\n", position);
            else if (choice == 3 && (head == NULL))
                printf("Update tur a awm rih lo\n");
            else if (choice == 3 && (position > counter))
                printf("%d na a awm lo. Update theih loh.\n", position);
            else
                printf("ERRORS A AWM RIH LOVE\n");
        }
        printf("\n");
        printf("1. Add list.\n");
        printf("2. Delete list.\n");
        printf("3. Update list.\n");
        printf("4. Exit.\n");
        printf("\n");
        printf("1 to 4 enter rawh: ");
        scanf("%d", &choice);
        ClearBuffer();

        position = 0;
        counter = 0;
        strcpy(message, "");

        while( choice < 1 || choice > 4 ){
            system("clear");
            printf(" -- TODO LIST MIZO VERSION --\n");
            Show();
            printf("\n");
            printf("%d HI A THLAN THEIH LOH.\n", choice);
            printf("\n");
            printf("1. Add list.\n");
            printf("2. Delete list.\n");
            printf("3. Update list.\n");
            printf("4. Exit.\n");
            printf("\n");
            printf("1 atanga 4 chiah a thlan theih: ");
            scanf("%d", &choice);
            ClearBuffer();
        }
        switch (choice) {
            case 1:{
                char buffer[120];
                printf("I duh ziak rawh: ");
                if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) != NULL){
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if(strlen(buffer) > 0)
                        strncpy(message, buffer, sizeof(message)/sizeof(message[0] - 1));
                }
                InsertAtEnd(message);
                break;
            }
            case 2:{
                if(head == NULL){
                    break;
                }
                counter = CountNode();
                if(counter == 1){
                    Delete(1);
                    break;
                }
                printf("Eng zat na nge i delete duh?: ");
                scanf("%d", &position);
                ClearBuffer();
                if(position > counter){
                    break;
                }
                Delete(position);
                break;
            }
            case 3:{
                if(head == NULL){
                    break;
                }
                char buffer[120];
                counter = CountNode();
                if(counter == 1){
                    printf("I duh ziak rawh: ");
                    if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) != NULL){
                        buffer[strcspn(buffer, "\n")] = '\0';

                        if(strlen(buffer) > 0)
                            strncpy(message, buffer, sizeof(message)/sizeof(message[0]) - 1 );
                    }
                    UpdateAtPos(message, 1);
                    break;
                }
                printf("Eng zatna nge i replace duh: ");
                if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) != NULL){
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if(strlen(buffer) > 0)
                        position = atoi(buffer);
                }
                if(position > counter){
                    break;
                }

                printf("I duh ziak rawh: ");
                if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) != NULL){
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if(strlen(buffer) > 0)
                        strncpy(message, buffer, sizeof(message)/sizeof(message[0]) - 1 );
                }
                UpdateAtPos(message, position);
                break;
            }
            case 4:{
                printf("Exiting..\n");
            }
        }
    } while (choice != 4);
    return 0;
}

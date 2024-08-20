#include "../include/ll.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int choice = 0;
    char choicebuffer[50];
    while(choice != 5){
        printf("1. Add Entry at the first.\n");
        printf("2. Add Entry at the end.\n");
        printf("3. Add Entry at position.\n");
        printf("4. Delete Entry at position.\n");
        printf("5. Exit.\n");
        Show();

        printf("Choose any of the following[1-5]: ");
        if(fgets(choicebuffer, sizeof(choicebuffer)/sizeof(choicebuffer[0]) - 1, stdin) != NULL){
            choicebuffer[strcspn(choicebuffer, "\n")] = '\0';
            choice = atoi(choicebuffer);
        }

        switch (choice) {
            case 1: {
                char buffer[100];
                char name[40];
                printf("Enter data: ");
                if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) !=  NULL){
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if(strlen(buffer) > 0)
                        strncpy(name, buffer, sizeof(name)/sizeof(name[0]));
                }
                InsertAtBegin(name);
                break;
            }
            case 2: {
                char buffer[100];
                char name[40];
                printf("Enter data: ");
                if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) !=  NULL){
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if(strlen(buffer) > 0)
                        strncpy(name, buffer, sizeof(name)/sizeof(name[0]));
                }
                InsertAtEnd(name);
                break;
            }
            case 3: {
                char buffer[100];
                char name[40];
                int position = 1;
                printf("Enter data: ");
                if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) !=  NULL){
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if(strlen(buffer) > 0)
                        strncpy(name, buffer, sizeof(name)/sizeof(name[0]));
                }
                printf("Enter position: ");
                if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) !=  NULL){
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if(strlen(buffer) > 0)
                        position = atoi(buffer);
                }
                InsertAtPos(name, position);
                break;
            }
            case 4: {
                char buffer[100];
                int position = 1;
                printf("Enter position to delete: ");
                if(fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) - 1, stdin) !=  NULL){
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if(strlen(buffer) > 0)
                        position = atoi(buffer);
                }
                Delete(position);
                break;
            }
            case 5:
                printf("Exiting..\n");
            break;
            default:
                printf("Choose between 1 to 5\n");
        }
    }
    return 0;
}

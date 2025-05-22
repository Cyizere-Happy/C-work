#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

struct song {
    char *name;
    struct song *next;
};

void addSong(struct song **head, char *name) {
    struct song *newsong = (struct song *)malloc(sizeof(struct song));
    if (newsong == NULL) return;

    newsong->name = (char *)malloc(strlen(name) + 1);
    if (newsong->name != NULL) {
        strcpy(newsong->name, name);
    }
    newsong->next = NULL;

    if (*head == NULL) {
        *head = newsong;
    } else {
        struct song *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newsong;
    }
}

void listSongs(struct song *head) {
    struct song *current = head;
    if (head == NULL) {
        printf("No songs in the playlist.\n");
        return;
    }
    printf("\nPlaylist:\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

void deleteSong(struct song **head, char *name) {
    if (*head == NULL) return;

    struct song *current = *head;
    struct song *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current);
            printf("Deleted song: %s\n", name);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Song not found: %s\n", name);
}

void insertInFront(struct song **head, char *name) {
    struct song *newsong = (struct song *)malloc(sizeof(struct song));
    if (newsong == NULL) return;

    newsong->name = (char *)malloc(strlen(name) + 1);
    if (newsong->name != NULL) {
        strcpy(newsong->name, name);
    }
    newsong->next = *head;
    *head = newsong;
}

void insertInMiddle(struct song *head, char *name) {
    if (head == NULL) return;

    struct song *slow = head;
    struct song *fast = head;

    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct song *newsong = (struct song *)malloc(sizeof(struct song));
    if (newsong == NULL) return;

    newsong->name = (char *)malloc(strlen(name) + 1);
    if (newsong->name != NULL) {
        strcpy(newsong->name, name);
    }

    newsong->next = slow->next;
    slow->next = newsong;
}

int main() {
    struct song *head = NULL;
    int choice;
    char name[MAX_NAME_LEN];

    do {
        printf("\n--- Song Playlist Menu ---\n");
        printf("1. Add song to end\n");
        printf("2. Add song to front\n");
        printf("3. Add song in the middle\n");
        printf("4. Delete a song\n");
        printf("5. List songs\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0'; 
                addSong(&head, name);
                break;
            case 2:
                printf("Enter song name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                insertInFront(&head, name);
                break;
            case 3:
                printf("Enter song name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                insertInMiddle(head, name);
                break;
            case 4:
                printf("Enter song name to delete: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteSong(&head, name);
                break;
            case 5:
                listSongs(head);
                break;
            case 0:
                printf("Exiting playlist...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    // Free memory
    struct song *current = head;
    while (current != NULL) {
        struct song *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

void encodeMessage(char msg[]);
void decodeMessage(char msg[]);

int main() {
    char message[200];
    int choice;

    while (1) {
        printf("\n1. Encode Message\n2. Decode Message\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';

        if (choice == 1)
            encodeMessage(message);
        else if (choice == 2)
            decodeMessage(message);
        else
            printf("Invalid choice.\n");
    }
    return 0;
}

void encodeMessage(char msg[]) {
    int len = strlen(msg);
    char temp;

    for (int i = 0; i < len / 2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }

    for (int i = 0; i < len; i++) {
        msg[i] = msg[i] ^ (1 << 1);
        msg[i] = msg[i] ^ (1 << 4);
    }

    printf("Encoded Message: %s\n", msg);
}

void decodeMessage(char msg[]) {
    int len = strlen(msg);
    char temp;

    for (int i = 0; i < len; i++) {
        msg[i] = msg[i] ^ (1 << 1);
        msg[i] = msg[i] ^ (1 << 4);
    }

    for (int i = 0; i < len / 2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }

    printf("Decoded Message: %s\n", msg);
}

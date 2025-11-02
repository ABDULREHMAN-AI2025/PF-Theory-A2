#include <stdio.h>
#include <string.h>

#define Max_Product 4
#define PromoCode "Eid2025"

void displayInventory(int productCodes[], char productName[][20], int quantities[], float prices[], int count);
float addToCart(int codes[], char productName[][20], int quantities[], float prices[], int count);
void generateInvoice(char customerName[], int CNIC, float totalAmount);

int main() {
    int CNIC;
    char customerName[20];
    int productCode[Max_Product] = {1, 2, 3, 4};
    char productName[Max_Product][20] = {"Shampoo", "Soap", "Face Wash", "Toothpaste"};
    int quantityOfStock[Max_Product] = {42, 31, 300, 150};
    float prices[Max_Product] = {100, 200, 300, 150};
    int choice;
    float totalAmount = 0;

    printf("Enter Customer Name: ");
    fgets(customerName, 20, stdin);
    customerName[strcspn(customerName, "\n")] = '\0';
    printf("Enter CNIC Number: ");
    scanf("%d", &CNIC);

    do {
        printf("\nSuper Market Billing System\n");
        printf("1. Display Inventory\n");
        printf("2. Add Item to Bill\n");
        printf("3. Generate Invoice\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayInventory(productCode, productName, quantityOfStock, prices, Max_Product);
                break;
            case 2:
                totalAmount += addToCart(productCode, productName, quantityOfStock, prices, Max_Product);
                break;
            case 3:
                generateInvoice(customerName, CNIC, totalAmount);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayInventory(int codes[], char names[][20], int quantities[], float prices[], int count) {
    printf("\n--- Inventory ---\n");
    printf("Code\tName\t\tStock\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%3d \t %-10s \t%d \t %.2f \n", codes[i], names[i], quantities[i], prices[i]);
    }
}

float addToCart(int codes[], char names[][20], int quantities[], float prices[], int count) {
    int code, qty;
    float cost = 0;

    displayInventory(codes, names, quantities, prices, count);

    printf("\nEnter product code to add: ");
    scanf("%d", &code);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    for (int i = 0; i < count; i++) {
        if (codes[i] == code) {
            if (qty > quantities[i]) {
                printf("Not enough stock available.\n");
                return 0;
            } else {
                cost = qty * prices[i];
                quantities[i] -= qty; // reduce stock
                printf("%d x %s added to bill. Cost: %.2f\n", qty, names[i], cost);
                return cost;
            }
        }
    }

    printf("Invalid product code.\n");
    return 0;
}

void generateInvoice(char name[], int cnic, float total) {
    char promo[20];
    printf("\n--- Customer Invoice ---\n");
    printf("Name: %s\nCNIC: %d\n", name, cnic);
    printf("Total Bill: %.2f\n", total);

    printf("Enter Promo Code (if any): ");
    scanf("%s", promo);

    if (strcmp(promo, PromoCode) == 0) {
        float discount = total * 0.25;
        total -= discount;
        printf("Promo code applied! 25%% discount = %.2f\n", discount);
    } else {
        printf("Invalid or no promo code. No discount applied.\n");
    }

    printf("Final Amount to Pay: %.2f \n", total);
    printf("Thank you for shopping \n");
}

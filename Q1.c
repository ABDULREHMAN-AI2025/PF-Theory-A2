#include <stdio.h>
#include <string.h>

#define Max_Books 100

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void processSale(int isbns[], int quantities[], int count);
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count);

int main()
{
    int isbns[Max_Books];
    char titles[Max_Books][50];
    float prices[Max_Books];
    int quantities[Max_Books];
    int count = 0, choice;

    do
    {
        printf("\n----- Library Book Management System -----\n");
        printf("1) Add a New Book\n");
        printf("2) Process a Sale\n");
        printf("3) Generate Low Stock Report\n");
        printf("4) Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addBook(isbns, titles, prices, quantities, &count);
            break;
        case 2:
            processSale(isbns, quantities, count);
            break;
        case 3:
            lowStockReport(isbns, titles, prices, quantities, count);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count)
{
    if (*count >= Max_Books)
    {
        printf("Inventory is full!\n");
        return;
    }

    int isbn;
    printf("Enter ISBN Number: ");
    scanf("%d", &isbn);
    getchar();

    for (int i = 0; i < *count; i++)
    {
        if (isbns[i] == isbn)
        {
            printf("Book already exists!\n");
            return;
        }
    }

    isbns[*count] = isbn;

    printf("Enter the Title of Book: ");
    fgets(titles[*count], 50, stdin);
    titles[*count][strcspn(titles[*count], "\n")] = '\0';

    printf("Enter Price: ");
    scanf("%f", &prices[*count]);

    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;
    printf("Book Added Successfully!\n");
}

void processSale(int isbns[], int quantities[], int count)
{
    int sold, isbn;
    printf("Enter the ISBN number of the book to be sold: ");
    scanf("%d", &isbn);

    for (int i = 0; i < count; i++)
    {
        if (isbns[i] == isbn)
        {
            printf("Enter Quantity of book to be sold: ");
            scanf("%d", &sold);
            if (sold > quantities[i])
            {
                printf("Not Enough Quantity of Books.\n");
            }
            else
            {
                quantities[i] -= sold;
                printf("Purchase Completed. Copies Left: %d\n", quantities[i]);
            }
            return;
        }
    }
    printf("Book Not Found.\n");
}

void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count)
{
    printf("\n--- Low Stock Report (Quantity < 5) ---\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (quantities[i] < 5)
        {
            printf("ISBN %d |Title %s |Quantity %d | price %.2f | \n ",
                isbns[i],titles[i],quantities[i],prices[i]);
                found=1;
        }
    }
    if (found==0)
    {
        printf("All books are sufficiently stocked.\n");
    }
}
    


#include <stdio.h>

#define MAX 5

int main()
{
    int ids[MAX], quantities[MAX];
    char names[MAX][20];
    float prices[MAX];

    int count = 0, choice, i, id, pos, newQty;

    do
    {
        printf("\n===== PRODUCT INVENTORY SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Display All Products\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 0;
        }

        switch (choice)
        {
            case 1:
                if (count >= MAX)
                {
                    printf("Inventory is Full!\n");
                    break;
                }

                printf("Enter product ID: ");
                scanf("%d", &id);

                pos = 0;
                for (i = 0; i < count; i++)
                {
                    if (ids[i] == id)
                        pos = 1;
                }

                if (pos == 1)
                {
                    printf("Product ID already exists!\n");
                    break;
                }

                ids[count] = id;

                printf("Enter product Name: ");
                scanf(" %19[^\n]", names[count]);

                printf("Enter product price: ");
                scanf("%f", &prices[count]);

                printf("Enter product quantity: ");
                scanf("%d", &quantities[count]);

                count++;
                printf("Product added successfully!\n");
                break;

            case 2:
                printf("Enter product ID to search: ");
                scanf("%d", &id);

                pos = -1;

                for (i = 0; i < count; i++)
                {
                    if (ids[i] == id)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1)
                    printf("Product not found!\n");
                else
                {
                    printf("\nID: %d\n", ids[pos]);
                    printf("Name: %s\n", names[pos]);
                    printf("Price: %.2f\n", prices[pos]);
                    printf("Quantity: %d\n", quantities[pos]);
                }
                break;

            case 3:
                if (count == 0)
                {
                    printf("Inventory is empty!\n");
                }
                else
                {
                    printf("\nID\tName\tPrice\tQuantity\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("%d\t%s\t%.2f\t%d\n",
                               ids[i], names[i],
                               prices[i], quantities[i]);
                    }
                }
                break;

            case 4:
                printf("Enter product ID to update: ");
                scanf("%d", &id);

                pos = -1;

                for (i = 0; i < count; i++)
                {
                    if (ids[i] == id)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1)
                    printf("Product not found!\n");
                else
                {
                    printf("Current quantity: %d\n",
                           quantities[pos]);

                    printf("Enter new quantity: ");
                    scanf("%d", &newQty);

                    quantities[pos] = newQty;

                    printf("Quantity updated successfully!\n");
                }
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

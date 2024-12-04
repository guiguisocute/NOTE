#include <stdio.h>
#include <string.h>

#define MAX_ORDERS 10

typedef struct {
    char product_name[50];
    float unit_price;
    int quantity;
    float total_price;
} Order;

void calculate_total_prices(Order orders[], int size) {
    for (int i = 0; i < size; i++) {
        orders[i].total_price = orders[i].unit_price * orders[i].quantity;
    }
}

void sort_orders(Order orders[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (orders[j].total_price > orders[j + 1].total_price) {
                Order temp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp;
            }
        }
    }
}

int binary_search(Order orders[], int size, float target_price) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (orders[mid].total_price == target_price) {
            return mid;
        } else if (orders[mid].total_price < target_price) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    Order orders[MAX_ORDERS];
    for (int i = 0; i < MAX_ORDERS; i++) {
        scanf("%s %f %d", orders[i].product_name, &orders[i].unit_price, &orders[i].quantity);
    }
    float target_price;
    scanf("%f", &target_price);

    // Calculate total prices
    calculate_total_prices(orders, MAX_ORDERS);

    // Sort orders by total price
    sort_orders(orders, MAX_ORDERS);

    // Print sorted total prices
    for (int i = 0; i < MAX_ORDERS; i++) {
        printf("%.2f ", orders[i].total_price);
    }
    printf("\n");

    // Perform binary search
    int result = binary_search(orders, MAX_ORDERS, target_price);
    if (result != -1) {
        printf("%s %.2f %d %.2f\n", orders[result].product_name, orders[result].unit_price,
               orders[result].quantity, orders[result].total_price);
    } else {
        printf("Not found\n");
    }

    return 0;
}

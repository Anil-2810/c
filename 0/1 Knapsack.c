#include <stdio.h>

struct Item {
    int profit;
    int weight;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(struct Item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (items[i - 1].weight <= w) {

                dp[i][w] = max(
                    items[i - 1].profit +
                    dp[i - 1][w - items[i - 1].weight],

                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter profit and weight:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].profit, &items[i].weight);
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    printf("Maximum profit = %d\n",
           knapsack(items, n, capacity));

    return 0;
}

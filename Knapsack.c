#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float profitperweight;
};

int main(){
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[100];

    for(int i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d: ", i+1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].profitperweight = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i -1; j++){
            if(items[j].profitperweight < items[j+1].profitperweight){
                struct Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }

    float totalprofit = 0;
    int remaining = capacity;
    printf("\nItems taken:\n");
    for(int i = 0; i < n; i++){
        if(remaining == 0){
            break;
        }
        if(items[i].weight <= remaining){
            totalprofit += items[i].profit;
            remaining -= items[i].weight;
            printf("Item (P:%d W:%d) - 100%%\n", items[i].profit, items[i].weight);
        }else{
            float fraction = (float)remaining / items[i].weight;
            totalprofit += items[i].profit * fraction;
            printf("Item (P:%d W:%d) - %.2f%%\n", items[i].profit, items[i].weight, fraction*100);
            remaining = 0;
        }
    }
    printf("\nMaximum profit: %.2f\n", totalprofit);
    return 0;
}
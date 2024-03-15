//Fractional Knapsack
#include<stdio.h>
#include<stdlib.h>

struct item
{
    int value;
    int weight;
    double unit_value;
};

int compare(const void *p, const void *q)
{
    struct item *a = (struct item *) p;
    struct item *b = (struct item *) q;
    return (a->unit_value) <= (b->unit_value) ? 1 : 0;
}

double greedy_fractional_knapsack(int capacity, struct item items[], int i, int n)
{
    if(capacity <= 0 || i > n) return 0;
    if(capacity < items[i].weight)
    {
        double fractional = (double)capacity / items[i].weight; 
        return fractional * items[i].value + greedy_fractional_knapsack(0, items, i + 1, n);
    }
    return items[i].value + greedy_fractional_knapsack(capacity - items[i].weight, items, i + 1, n);
}

int main()
{
    int i;
    struct item items[3] = {{100, 20}, {60, 10}, {120, 30}};
    printf("Finding unit Value : \n");
    for(i = 0; i < 3; i++)
    {
        items[i].unit_value = (double) items[i].value / items[i].weight;
        printf("%d %d %.2lf\n", items[i].value, items[i].weight, items[i].unit_value);
    }
    printf("\n");

    qsort(items, 3, sizeof(struct item), compare);

    printf("Sorting in descending Order with uni value : ");
    for(i = 0; i < 3; i++)
    {
        printf("%d %d %.2lf\n", items[i].value, items[i].weight, items[i].unit_value);
    }
    printf("\n");

    double collected_value = greedy_fractional_knapsack(50, items, 0, 3);
    printf("Maximum Value : %.2lf\n",collected_value);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person 
{
    char name[50];
    int age;
};

int compare_people_name(const void *a, const void *b) 
{
    struct person *name1 = (struct person *)a;
    struct person *name2 = (struct person *)b;
    return strcmp(name1->name, name2->name);
}

int compare_people_age(const void *a, const void *b)
{
    struct person *age1 = (struct person *)a;
    struct person *age2 = (struct person *)b;
    return (age1->age - age2->age);
}

int main() 
{
    int i, n = 5;
    struct person people[5] = { {"Bob", 19}, 
                                {"Alice", 25}, 
                                {"Charlie", 22}, 
                                {"Vlad", 18}, 
                                {"Jhon", 23}};

    qsort(people, n, sizeof(struct person), compare_people_age);
    for (i = 0; i < n; ++i)
    {
        printf("%10s %4d\n", people[i].name, people[i].age);
    }
    printf("\n");
    
    qsort(people, n, sizeof(struct person), compare_people_name);
    for (i = 0; i < n; ++i)
    {
        printf("%10s %4d\n", people[i].name, people[i].age);
    }
    printf("\n");
    return 0;
}
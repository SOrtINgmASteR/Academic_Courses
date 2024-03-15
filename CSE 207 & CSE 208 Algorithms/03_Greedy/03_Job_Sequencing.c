//Job Sequencing
#include<stdio.h>
#include<stdlib.h>

int scheduler[10];
struct job
{
    int job_id;
    int deadline;
    int profit;
};

int compare(const void *p, const void *q)
{
    struct job *a = (struct job *) p;
    struct job *b = (struct job *) q;
    return (a->profit) <= (b->profit) ? 1 : 0;
}

int job_scheduling(struct job jobs[], int n) 
{
    int max_profit = 0, i, j;
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline; j > 0; j--) {
            if(scheduler[j] == 0) 
            {
                scheduler[j] = jobs[i].job_id;
                max_profit += jobs[i].profit;
                break;
            }
        }
    }
    return max_profit;
}
int main()
{
    int i, max_profit = 0;
    struct job jobs[5] = {{1, 2, 90}, {2, 1, 80}, {3, 2, 100}, {4, 3, 50}, {5, 1, 40}};
    printf("All Jobs & their deadline : \n");
    for(i = 0; i < 5; i++)
    {
        printf("id : %d, deadline : %d, profit : %d\n", jobs[i].job_id, jobs[i].deadline, jobs[i].profit);
    }
    printf("\n");

    qsort(jobs, 5, sizeof(struct job), compare);

    printf("Jobs sorted by profit : \n");
    for(i = 0; i < 5; i++)
    {
        printf("id : %d, deadline : %d, profit : %d\n", jobs[i].job_id, jobs[i].deadline, jobs[i].profit);
    }
    printf("\n");
    max_profit = job_scheduling(jobs, 5);
    printf("Max Profit : %d\n", max_profit);

    printf("Job List : \n");
    for(i = 1; i <= 3; i++)
    {
        printf("Job ID : %d\n", scheduler[i]);
    }
    return 0;
}
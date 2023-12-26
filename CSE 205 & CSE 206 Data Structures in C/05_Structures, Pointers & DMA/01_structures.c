//Structure Define & Initialization
#include<stdio.h>
struct
{
    int id;
    double cgpa;
}s1, s2 ,s3, s4[10];

int main()
{
    printf("Enter Student 1's ID : ");
    scanf("%d", &s1.id);
    printf("Enter Student 1's CGPA : ");
    scanf("%lf", &s1.cgpa);

    printf("Enter Student 2's ID : ");
    scanf("%d", &s2.id);
    printf("Enter Student 2's CGPA : ");
    scanf("%lf", &s2.cgpa);

    printf("Enter Student 3's ID : ");
    scanf("%d", &s3.id);
    printf("Enter Student 3's CGPA : ");
    scanf("%lf", &s3.cgpa);

    printf("Student 1 ID : %d\n", s1.id);
    printf("Student 1 CGPA : %.2lf\n", s1.cgpa);

    printf("Student 2 ID : %d\n", s2.id);
    printf("Student 2 CGPA : %.2lf\n", s2.cgpa);

    printf("Student 3 ID : %d\n", s3.id);
    printf("Student 3 CGPA : %.2lf\n", s3.cgpa);

    return 0;
}
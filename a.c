#include <stdio.h>
void multiply(int a[], int b[], int c[]);
void add(int a[], int b[], int c[]);
void output(int a[]);

int main()
{
    int a[1001] = {0};
    int b[1001] = {0};
    int c[2001] = {0};
    int d[2001] = {0};
    int n = 0;
    int i = 0;
    int j = 0;
    int index = 0;
    int value = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        scanf("%d", &index);
        a[index] = value;
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        scanf("%d", &index);
        b[index] = value;
    }
    multiply(a, b, c);
    add(a, b, d);
    output(c);
    printf("\n");
    output(d);
    return 0;
}

void multiply(int a[], int b[], int c[])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 1001; i++)
    {
        for (j = 0; j < 1001; j++)
        {
            if (a[i]!=0 && b[j]!=0)
                c[i + j] += a[i] * b[j];
        }
    }
}
void add(int a[], int b[], int c[])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 1001; i++)
    {
        for (j = 0; j < 1001; j++)
        {
            if (i == j)
            {
                c[i] += a[i] + b[j];
            }
        }
    }
}
void output(int a[])
{
    int i = 0;
    int flag = 0;
    int key = 0;


    for (i = 2000; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            flag = 1;
            
            if (key != 0){
                printf(" %d %d", a[i], i);
                key = 1;
            }else{
                printf("%d %d", a[i], i);
                key = 1;
            }
                
        }
    }

    if (flag == 0)
    {
        printf("0 0");
    }
}

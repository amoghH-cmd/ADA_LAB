#include <stdio.h>

#define INF 999

void floyd(int n, int cost[10][10])
{
    int i, j, k;

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }

    printf("The shortest path matrix is:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%4d", cost[i][j]);

        printf("\n");
    }
}

int main()
{
    int n, cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    }

    floyd(n, cost);

    return 0;
}
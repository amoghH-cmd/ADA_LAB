#include <stdio.h>

#define MAX 10
#define INF 9999

int parent[MAX];

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

void union_set(int i, int j)
{
    parent[j] = i;
}

int main()
{
    int n, cost[MAX][MAX];
    int t[MAX][2];
    int i, j, u, v;
    int min, mincost = 0;
    int edge_count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for (i = 1; i <= n; i++)
        parent[i] = 0;

    while (edge_count < n - 1)
    {
        min = INF;

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u);
        j = find(v);

        if (i != j)
        {
            edge_count++;
            t[edge_count][1] = u;
            t[edge_count][2] = v;
            mincost += min;
            union_set(i, j);
        }

        cost[u][v] = cost[v][u] = INF;
    }

    printf("\nEdges in MST:\n");
    for (i = 1; i <= edge_count; i++)
    {
        printf("%d - %d\n", t[i][1], t[i][2]);
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
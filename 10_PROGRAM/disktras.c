#include <stdio.h>

#define INF 9999

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, min_index = -1;

    for(int v = 0; v < n; v++)
    {
        if(!visited[v] && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int n, int src)
{
    printf("\nVertex\tDistance from Source %d\n", src);

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

void dijkstra(int graph[20][20], int n, int src)
{
    int dist[20], visited[20];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);

        if(u == -1)
            break;

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] &&
               graph[u][v] &&
               dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n, src);
}

int main()
{
    int n, graph[20][20], src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    printf("(Enter 0 if there is no direct edge)\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
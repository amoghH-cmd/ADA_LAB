#include <stdio.h>

#define V 5

int minDistance(int dist[], int visited[])
{
    int min = 10000, min_index;

    for(int v = 0; v < V; v++)
    {
        if(visited[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex\t Distance from Source\n");

    for(int i = 0; i < V; i++)
    {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int visited[V] = {0};

    for(int i = 0; i < V; i++)
        dist[i] = 10000;

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = 1;

        for(int v = 0; v < V; v++)
        {
            if(!visited[v] &&
               graph[u][v] &&
               dist[u] != 10000 &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] =
    {
        {0,10,0,30,100},
        {10,0,50,0,0},
        {0,50,0,20,10},
        {30,0,20,0,60},
        {100,0,10,60,0}
    };

    dijkstra(graph, 0);

    return 0;
}
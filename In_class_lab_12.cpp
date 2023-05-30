#include <stdio.h>
#include <limits.h>
#include <iostream>

#define NUM_VERTICES 6

// Function to find the vertex with the minimum time value from the set of vertices not yet included in the shortest path tree.
int minTime(int times[], bool visited[])
{
    int min = INT_MAX; // Set the initial minimum time to a very large value
    int minIndex; // Index of the vertex with the minimum time

    for (int v = 0; v < NUM_VERTICES; v++)
    {
        // If the vertex has not been visited and its time is less than or equal to the current minimum
        if (!visited[v] && times[v] <= min)
        {
            min = times[v]; // Update the minimum time
            minIndex = v; // Update the index of the vertex with the minimum time
        }
    }

    return minIndex; // Return the index of the vertex with the minimum time
}

// Function to print the times from the source vertex to all other vertices
int printSolution(int times[], int n)
{
    printf("Vertex   Time from Source\n");
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        printf("%d \t\t %d\n", i, times[i]);
    }
    return 0;
}

// Function to implement Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices
void dijkstra(int graph[NUM_VERTICES][NUM_VERTICES], int source)
{
    int times[NUM_VERTICES]; // Array to store the shortest times from the source vertex
    bool visited[NUM_VERTICES]; // Array to keep track of visited vertices

    // Initialize times and visited arrays
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        times[i] = INT_MAX; // Set the initial time to all vertices as infinity
        visited[i] = false; // Mark all vertices as not visited
    }

    times[source] = 0; // Set the time of the source vertex to 0

    // Find the shortest path for all vertices
    for (int count = 0; count < NUM_VERTICES - 1; count++)
    {
        int u = minTime(times, visited); // Find the vertex with the minimum time
        visited[u] = true; // Mark the vertex as visited

        // Update the times of the adjacent vertices of the visited vertex
        for (int v = 0; v < NUM_VERTICES; v++)
        {
            // If the vertex has not been visited, there is an edge between u and v, the time of u is not infinity,
            // and the time through u is smaller than the current time to v
            if (!visited[v] && graph[u][v] && times[u] != INT_MAX &&
                times[u] + graph[u][v] < times[v])
            {
                times[v] = times[u] + graph[u][v]; // Update the time to v
            }
        }
    }

    printSolution(times, NUM_VERTICES); // Print the shortest times from the source vertex to all other vertices
    float total_time = 0;
    for (int i = 0; i < 6; i++) {
        total_time += times[i];
    }
    std::cout<<"Average Time is "<< total_time / 5;
}

int main()
{
    int graph[NUM_VERTICES][NUM_VERTICES] =
    { {0, 10, 0, 0, 15, 5},
     {10, 0, 10, 30, 0, 0},
     {0, 10, 0, 12, 5, 0},
     {0, 30, 12, 0, 0, 20},
     {15, 0, 5, 0, 0, 0},
     {5, 0, 0, 20, 0, 0} };

    dijkstra(graph, 5); // Find the shortest paths from vertex 1 (source) to all other vertices

    return 0;
}

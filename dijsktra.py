from queue import PriorityQueue
class Graph:

    def __init__(self, num_of_vertices):
        self.v = num_of_vertices
        self.edges = [[-1 for i in range(num_of_vertices)] for j in range(num_of_vertices)]
        self.visited = []
    
    def add_edge(self, u, v, weight):
        self.edges[u][v] = weight
        self.edges[v][u] = weight

    def dijkstra(self, start_vertex):
        D = {v:float('inf') for v in range(self.v)}
        D[start_vertex] = 0

        pq = PriorityQueue()
        pq.put((0, start_vertex))

        while not pq.empty():
            (dist, current_vertex) = pq.get()
            self.visited.append(current_vertex)

            for neighbor in range(self.v):
                if self.edges[current_vertex][neighbor] != -1:
                    distance = self.edges[current_vertex][neighbor]
                    if neighbor not in self.visited:
                        old_cost = D[neighbor]
                        new_cost = D[current_vertex] + distance
                        if new_cost < old_cost:
                            pq.put((new_cost, neighbor))
                            D[neighbor] = new_cost
        return D



# set the num of vertex as 4
g = Graph(4)

# add the edge with the weight
# 0 = A
# 1 = B
# 2 = C
# 3 = D
g.add_edge(0, 1, 1)
g.add_edge(0, 2, 3)
g.add_edge(0, 3, 7)
g.add_edge(1, 3, 5)
g.add_edge(2, 3, 12)

D = g.dijkstra(0)

# find the sortestpath from A (0) to D (3)
print("Shortest path from vertex A to vertex D is", D[3])
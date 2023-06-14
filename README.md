# Network_Optimization
The goal of this project is to find the maximum bandwidth path in the routing network considered as
a graph with the weights as the maximum bandwidth of the edge or the connection between two
nodes. In this project, the well-know algorithms like Dijkstra’s and Kruskal Maximum Spanning
Tree are modified to solve for the maximum bandwidth path in the network. The Dijkstra’s
algorithm has been implemented in two ways i.e. using heap and without using heap data
structure. All the algorithms have been tested on two types of randomly generated graphs: a
sparse graph and a dense graph. The comparison of the average execution time of the three
algorithmic approaches is done to analyse the theoretical and practical complexities of this
algorithms.


# CSCE 629 Analysis of Algorithms Course Project Report
Utilizing certain data structures and methods covered in the course, the goal of this project is to implement a network routing protocol. This project focuses on the MAX-BANDWIDTH-PATH problem, which is regarded as a significant network optimization challenge. There are several techniques to find a path that has the most bandwidth between the source and the destination, but the effectiveness of each method depends on the structures and algorithms utilized. In order to determine the best route between two vertices for this project, we employed a graph network. Additionally, we employed Dijkstra's and Kruskal's, two well-known algorithms, to find a path. To utilize a heap structure, a heap sort for edges, or not to use a heap structure at all, they were all altered and tweaked. We evaluated the performance on random weighted undirected graphs that mathematically represented a dense or sparse graph using these three alternative implementations.

# Random Graph Generation:
In the given problem we are required to generate two types of graphs, sparse and dense. Each of these graphs have 5000 vertices. We use adjacency list representation of the graph for this problem. To implement adjacency list, we make an array of linked lists. Each element of this array stores a linked list of vertices. We define a struct to define the node of this linked list, and call this "vertex". The "vertex" struct contains three fields, namely, "id of the vertex", "weight of the edge between the ith element of the array and the current vertex id" and "the pointer to the next node in the linked list". Additionally, we need to maintain an array to store all the edges of the graph. To store the edge information, we define a struct which stores a pair of integers to store the node id and a weight field to store the weight of the edge between the two nodes.

The sparse graph in our implementation must have an average degree of 6, which means that each node in the sparse graph must have 6 neighbors on average. While in case of the dense graph we ensure that any given vertex is adjacent to 20% of other vertices on average. This implies that any given vertex should have a degree of 1000 on average.

To generate the above two random graphs, we use the approach discussed in class. First of all, to ensure that the entire graph is connected, we make a cycle in the graph by connecting the nodes from node id 0 to 4999(note that there are 5000 nodes in the graphs). After this while the average degree is less than 6 and 1000 for sparse and dense graphs respectively, we randomly pick up a node, and check while it's number of neighbors are less than 6(or 1000) and then randomly pick another node with fewer than 6(or 1000) node and make an edge between the two nodes. We also increase the total number of degrees in this process. Note that we break out of this loop once the average degree reaches 6(or 1000).

At the end of the above process we obtain randomly generated sparse and dense graphs with average degree of 6 and 1000 respectively. Note that we randomly choose an integer between 1 and 1000 to assign the weight to each of the new edges created.

# Max Heap:
The maximum heap structure that will be used for Dijkstra’s algorithm was implemented in the Heap class, supporting the functions of Maximum, Insert, and Delete. The implementation was closely based on the solution found from our assignment #2, but to further improve the performance of the Delete operation, we used a list to store the index of the vertices in the heap as we described in class. This position list is updated each time there is an Insert or Delete operation, where if the index of the vertex changes in the heap, then it is updated in the position list as well. This allows us to avoid inefficiently searching for a specific vertex in the heap considering we will know the exact position with this additional list.

# Routing Algorithms:
The input for each of these algorithms is graph G, a source vertex s, and a destination vertex t. Each of these algorithms will then return the maximum bandwidth path from s to t.

# 1. Dijkstra's Algorithm(Array - Based implementation)
To implement the dijkstra algorithm we use the same idea as discussed in the course lectures. In our implementation we make three arrays namely, status, daddy and bw. The "status" array stores the status of the nodes in the graph. Unseen nodes are marked as 0, fringers as 1 and inTree nodes as 2. We use the "daddy" array to store the parent of the given node. This array stores the path from source to destination. The "bw" array stores the maximum bandwidth from source to the current node. As we are using an array to store all the fringes in the graph, we iterate through the entire array to find the fringe with the maximum bandwidth. Thus this makes the time-complexity of

Dijkstra to be O(n^2) where n is the number of nodes. We break out of the loop when we change the destination's status to inTree.

<img width="828" alt="Screenshot 2023-06-13 at 8 00 48 PM" src="https://github.com/kushagrajain7/Network-Optimizer/assets/106591189/6876dd0d-ebd0-4645-8c3f-f60d60faf0ec">

# 2. Dijkstra's Algorithm(Heap - Based Implementation)
We use the similar algorithm as used above but here, instead of keeping the fringes in the array and iterating over this entire array to find the maximum band-width fringer, we maintain a max-heap structure to store the fringers. As the max-heap stores the maximum element as its root, we pick the fringer present on the root of this heap in our algorithm. In addition to the three arrays described above for the array-based implementation, we also initialize a heap created from our maxheap class as described above. By using a max-heap we are able to return the maximum element in O(1) time. To achieve this, we will use the Maximum function from the heap and the Delete function on the maximum node, which has been proven to take O(log n) based on the height of the tree. Finally, our two conditions consist of an unseen status and a fringe status. If a neighbor node is still unseen, then we will insert the fringe into the heap. However, if the second condition is true, then we will delete this vertex from the heap, update the bandwidth and parent arrays and insert this new vertex back into the heap. The operations for deleting and inserting into a heap take O(log n) as mentioned previously and finding the maximum O(1), which will result in overall complexity of this version of Dijkstra to be O(m log n), where m represents the edges of the graph and n the number of vertices.

<img width="828" alt="Screenshot 2023-06-13 at 8 02 59 PM" src="https://github.com/kushagrajain7/Network-Optimizer/assets/106591189/a15f35bf-a980-451c-972e-674c659a6e07">

<img width="828" alt="Screenshot 2023-06-13 at 8 03 33 PM" src="https://github.com/kushagrajain7/Network-Optimizer/assets/106591189/ebce32bc-5927-4b0c-8e2e-cd24b432c93d">

# 3. Kruskal's Algorithm(Using Heap Sort)

We implement kruskal's algorithm using the same algorithm as discussed in the class lectures. However, we do take advantage of the heap sort. We use the Kruskal algorithm to find the maximum spanning tree and then use the breadth first search to find the path between the source(s) and target(t). To achieve this we first use heapsort to sort all the edges present in the graph and implement the makeset, find and union functions as discussed in the class lectures. These functions allow us to build a new graph that contains only the edges that pertain to the maximum spanning tree. This graph is then passed to the path function which uses BFS to find the path along s to t. The returned path will be the maximum bandwidth path from s to t.

<img width="540" alt="Screenshot 2023-06-13 at 8 05 26 PM" src="https://github.com/kushagrajain7/Network-Optimizer/assets/106591189/302288e8-6664-4f11-b5ec-2a9c4d6c26e8">

<img width="540" alt="Screenshot 2023-06-13 at 8 06 00 PM" src="https://github.com/kushagrajain7/Network-Optimizer/assets/106591189/558036b5-e2c9-4bcb-a060-1befe550c89d">

<img width="540" alt="Screenshot 2023-06-13 at 8 05 45 PM" src="https://github.com/kushagrajain7/Network-Optimizer/assets/106591189/63108873-b8d4-4fcf-a286-08c1a772bae0">

<img width="540" alt="Screenshot 2023-06-13 at 8 06 36 PM" src="https://github.com/kushagrajain7/Network-Optimizer/assets/106591189/06f9e905-670d-485d-9c79-d3d1edf609bf">

For the sparse graphs, we observe the following relation in the overall average running time:

# (Faster) Dijkstra with Heap > Kruskal > Dijkstra without Heap (Slower)

The most time-consuming algorithm for sparse graphs is Dijkstra without the use of the heap structure, which as explained in the implementation, the overall complexity would be O(n2). This is due to having to iterate through the entire array of vertices every time it needs to find the maximum fringe. Therefore, it performs as expected. As was proven in class, Kruskal’s algorithm with the use of Union-Find operations and Dijkstra’s algorithm with the help of a heap structure would both take an overall complexity time of O(m log n). This is based on the notion that the Find operation would take O(log n) time and the Insert and Delete operations would also take O(log n). However, one additional modification that was added to Kruskal’s algorithm was the HeapSort function, which requires to sort through all the edges of the graph. In addition, after building the maximum spanning tree, the algorithm has to run a DFS algorithm to provide the path between the two vertices. Therefore, the performance difference would be due to the constants in the Big-O complexity. Although there could be a number of insertion and deletion operations, the amount of time it will take to sort through all edges in the graph and also perform DFS on all the edges in the new graph increase the constant value of overall time complexity, and therefore explain the reason it performs slower than Dijkstra’s implementation with a heap.

For the dense graphs, we observe the following relation in the overall average running time:

# (Faster) Dijkstra with Heap > Dijkstra without Heap > Kruskal (Slower)

Similar to the performance in sparse graphs, Dijkstra’s algorithm with the use of the heap structure takes the least amount of time to return the maximum bandwidth path. This demonstrates the usefulness of this algorithm in both types of graphs and is able to hold the overall complexity time of O(m log n) despite the number of edges being greater than the number of vertices. On the other end of the spectrum, Kruskal’s algorithm obtains the worst performance in dense graphs as it performs 16 times slower than Dijkstra, which is not a surprising observation. In our implementation, we had to use HeapSort to sort through the edges and therefore on a dense graph, this will be highly inefficient and dependent on the number of edges. In a dense graph, the number of edges will be greater than the number of vertices and the probability for two vertices to be connected to 20% of its neighbors is similar to having a vertex degree of 1000. As a result, the total number of edges would be at least over a million edges and having to sort through all these edges would be time consuming. This explains the terrible performance of Kruskal and a possible flaw in the implementation that could be improved.

# Conclusion and Future Improvements

According to our performance investigation, Kruskal's method performs the poorest in dense graphs, and the majority of the time is spent on HeapSort. Using a different sorting method may help with this part of the implementation. One of the primary problems is that Kruskal's performance depends on the number of edges, therefore the more edges there are, the longer this implementation takes to complete because it must sort through all the edges in the graph. The implementation could perform better if a different sorting method could sort over the edges more quickly. Although it is debatable how much could be improved, it would be helpful even if it were reduced to a level that was close to Dijkstra's various implementations.
In conclusion, we were able to solve the network optimization problem of determining the maximum bandwidth path overall by successfully implementing three distinct methods. We then tested the effectiveness of each of these methods on sparse and dense graphs. The outcomes showed that the heap-based Dijkstra implementation performed better for both sparse and dense graphs since it required the least amount of processing time.

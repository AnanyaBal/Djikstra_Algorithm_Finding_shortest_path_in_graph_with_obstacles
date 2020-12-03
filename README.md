# Finding the shortest path between two nodes in a graph having obstacles

This project aims to solve the problem of finding a suitable shortest path between two points on a map which avoids obstacles using a graph data structure.

The objective is to integrate Dijkstra’s algorithm with a module for random obstacle generation and find the shortest path on a graph between two points.

##Methodology##
1.	Random generation of obstacles using a time formula
2.	Use Dijkstra’s greedy algorithm to find shortest path by selecting the shortest edge at every point.

##Algorithm##
Let the node at which we are starting be called the initial node. Let the distance of node Y be the distance from the initial node to Y. Dijkstra's algorithm will assign some initial distance values and will try to improve them step by step.
1.	Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes.
2.	Set the initial node as current. Mark all other nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.
3.	For the current node, consider all of its neighbours and calculate their tentative distances. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbour B has length 2, then the distance to B (through A) will be 6 + 2 = 8. If B was previously marked with a distance greater than 8 then change it to 8. Otherwise, keep the current value.
4.	When we are done considering all of the neighbours of the current node, mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.
5.	If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.
6.	Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.

##Output##
![alt text](https://github.com/AnanyaBal/Djikstra_Algorithm_Finding_shortest_path_in_graph_with_obstacles/blob/main/dj%20(2).png)

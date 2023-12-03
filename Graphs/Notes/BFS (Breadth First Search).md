It checks all the neighbours of the starting node, then checks all the neighbours of the neighbouring nodes and so on until the destination node is found 

- Uses the queue data structure

## Benefits
1. It gives us the path with the least amount of nodes between the source and destination node
2. Dijkstra's algorithm and Prim's algorithm implement a similiar idea to BFS
3. Used when space is not an issue and time is of essence.
4. It can be used to detect cycles.

## Shortcomings
1. If the tree is very wide, then BFS would be impractical as it will take too much memory. A possible alternative would be a iterative deepening DFS

## Real Life Applications
1. In GPS systems to find nearby locations
2. In social media sites to reccomend potential users that the user might want to connect to
3. In peer to peer networks, BFS is used to find neighbouring nodes
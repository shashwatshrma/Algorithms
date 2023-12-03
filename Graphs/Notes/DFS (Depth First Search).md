This gives us a possible path between 2 nodes - a source node and a destination node, that is not necessarily the most optimal or the most efficient path.

- Uses stack data structure

## Benefits
1. More space efficient than BFS
2. Generally used when we need to search the entire tree
3. It can be used to detect cycles.

## Shortcomings
1. Will not work for a graph with an infinite branching factor
2. May not give the answer in time if it goes to the wrong path in a very big graph
3. If the search tree is very deep you will need to restrict the search depth for depth first search (iterative deepening).

## Real Life Applications
1. Used in simulation of games such as mazes that only have one solution
2. It can also be used to generate random mazes
3. Can be used on a web crawler to explore links on a website
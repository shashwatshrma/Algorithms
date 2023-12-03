A single source shortest path greedy algorithm that fixes the node with the smallest distance in each iteration. Dijkstra’s algorithm relax each edge exactly once.

## Benefits
1. It requires less computational cost than Bellman Ford algorithm.

## Shortcomings
1. It cannot find negative cycles.
2. It may not work for negative weights. 

## Real Life Applications
1. It can be used to find shortest path between real life destinations if we cannot use better algorithms such as A* that require heuristic
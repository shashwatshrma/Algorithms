A greedy Minimum Spanning Tree finding algorithm. It consists of the following steps:
1. Sort the edges in ascending order by weight
2. Connect vertices-1 edges avoiding cycles

## Benefits
1. Beneficial if the graph is not dense i.e. it's a sparse graph as opposed to Prims's

## Shortcomings
1. Both Kruskal's and Prim's follow the greedy approach so in a complex network, the algorithm may get stuck in a local minima.

## Real Life Applications
1. Due to the aforementioned shortcoming, it is not used in practical applications.
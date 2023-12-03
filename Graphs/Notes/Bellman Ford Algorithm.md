A single source shortest path algorithm that uses a dynamic programming approach. This finds the shortest path by relaxing each edge vertices-1 times

## Benefits
1. It can detect negative cycles
2. It works for negative weights as well

## Shortcomings
1. Requires more computational cost than Dijkstra's

## Real Life Applications
1. It is used in package transfer in distributed systems since we consider packet loss in the transfer too which can result in negative weights.
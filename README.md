# Final Project API (Algorithms and Data Structures 2021)

*This project was made between June and July 2021, at Politecnico di Milano.*

## GraphRanker

- The goal of this year's project is to manage a ranking among directed weighted graphs.
- The ranking keeps track of the k "best" graphs.
- The program to be created receives input:
   - Two parameters, given only once (on the first line of the file, separated by space):
       - `d`: the number of nodes in the graphs
       - `k`: the length of the ranking
   - A sequence of commands among:
       - `AddGraph [adjacency-matrix]`
       - `TopK`
### AddGraph
Requires adding a graph to those considered for ranking. It is followed by the adjacency matrix of the graph itself, printed one row per line, with elements separated by commas.
The nodes of the graph are to be considered logically labeled with an integer index between 0 and `d-1`; the node at position 0 is the one whose outgoing star is described by the first row of the matrix.
The weights of the graph edges are integers in the range `[0, 2^32 – 1]`.

### TopK
- Consider each graph from the start of the program until the `TopK` command, labeled with an integer corresponding to the number of graphs read before it (starting from 0).
- `TopK` requires the program to print the integer indices of the `k` graphs having the `k` smallest values of the following metric:
  - Sum of the shortest paths from node 0 to all other nodes in the graph reachable from 0.
- If there are multiple graphs with the same metric value, precedence is given to the ones that appeared first.
- Distances to nodes not reachable from 0 are considered null.
- The `k` integer indices are printed on a single line, separated by a space, in any order.

### Example Execution
<pre>

Received Input:               Comments and Expected Output
3 2                           Requests to manipulate graphs with 3 nodes and report the k=2 best
AddGraph                     Adding the first graph (index 0, sum of paths = 7)
0,4,3
0,2,0
2,0,0
AddGraph                     Adding the second graph (index 1, sum of paths = 5)
0,0,2
7,0,4
0,1,0
AddGraph                     Adding the third graph (index 2, sum of paths = 7)
3,1,8
0,0,5
0,9,0
TopK                         0 1 or 1 0
</pre>

### Requirements

- The correctness and efficiency of the proposed solution were evaluated with automated test suites to assess the time and space complexity of the algorithms used.

### Concluding Notes

- The proposed solution passed all tests with the highest time and space efficiency.




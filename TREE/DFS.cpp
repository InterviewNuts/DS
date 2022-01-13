// TOPIC: DFS (Depth First Search)

// NOTES:
// 0. Depth-first search (DFS) is an algorithm (or technique) for traversing a tree/graph.
// 2. DFS uses stack OR we can use recursive approach.

// APPLICATIONS OF DFS
// 0. To find minimum spanning tree and all pair shortest path tree.
// 1. Detecting cycle in a graph
// 2. Path finding
// 3. Topological sorting
// 4. To test graph is bipartite
// 5. Find strongly connected component of a graph
// 6. Maze related problems (find the shortest path)

// PROGRAM:
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> Vec;
vector<bool> visited;



void dfs(const vector<vector<int>>& Vec, int s) {
    std::stack<int> Stk;
    Stk.push(s);
    visited[s] = true;
    while (!Stk.empty()) {
        int node = Stk.top();
        Stk.pop();
        cout << node << " ";
        for (int i = 0; i < Vec[node].size(); ++i) {
            if (!visited[Vec[node][i]]) {
                Stk.push(Vec[node][i]);
                visited[Vec[node][i]] = true;
                }
            }
        }
    }

void initialize() {
    for (int i = 0; i < visited.size(); ++i)
        visited[i] = false;
    }



int main()
    {
    int nodes, edges, x, y;
    cin >> nodes;
    cin >> edges;
    Vec.resize(nodes + 1);
    visited.resize(nodes + 1);
    for (int i = 0; i < edges; ++i)
        {
        cin >> x >> y;
        Vec[x].push_back(y);
        Vec[y].push_back(x);
        }
    initialize();
    cout << endl;
    dfs(Vec, 1);
    return 0;
    }

// 6 7
// 1 2
// 1 4
// 4 5
// 2 4
// 2 3
// 3 6
// 4 6



/*
//! Test Program.

vec.resize(3);
vec[0].resize(3);
vec[1].resize(2);
vec[2].resize(4);

0. #->#,#,#
1. #->#,#
2. #->#,#,#,#



int main()
    {

    vector<vector<int>> vec;
    vec.resize(3);
    vec[0].resize(3);
    vec[1].resize(2);
    vec[2].resize(4);


    vec[0][0] = 10;
    vec[0][1] = 20;
    vec[0][2] = 30;


    vec[1][0] = 100;
    vec[1][1] = 110;

    vec[2][0] = 200;
    vec[2][1] = 210;
    vec[2][2] = 220;
    vec[2][3] = 230;


    for (int i = 0; i < 3; i++)
        {
        cout << " Size of ech 1D = " << vec[i].size() << endl;
        cout << " Row " << i << " = ";
        for (int j = 0; j < vec[i].size(); j++)
            {
            cout << ":" << vec[i][j];
            }
        cout << "\n";
        }
    return 0;
    }

    */
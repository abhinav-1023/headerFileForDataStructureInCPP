#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
/* adjeceny list graphs*/

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[this->v];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }
    void printAdjList()
    {
        /* iterate over all the rows */
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            /* every element of ith linked list */
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }
    void bfs(int source)
    {

        queue<int> q;
        bool *visited = new bool[v]{0};
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int f = q.front();
            cout << f << endl;
            q.pop();

            /* push the nbrs of current node inside q if the are not already visited */
            for (auto nbrs : l[f])
            {
                if (!visited[nbrs])
                {
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
        }
    }
    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ",";
        /* make a dfs call on all its unvisited neighbours */
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {

                dfsHelper(nbr, visited);
            }
        }
    }
    void dfs(int source)
    {
        bool *visited = new bool[v]{0};
        dfsHelper(source, visited);
    }

    void tapological_sort()
    {
        vector<int> indegree(v, 0);
        /* iterate over all the edges to find the right indgree */
        for (int i = 0; i < v; i++)
        {
            for (auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();
            /* iterate over the nbrs of this node and reduce their indegree by 1 */
            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1,4);
    g.addEdge(1,2 );
    
    
    g.tapological_sort();
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <set>

class Graph {
    int noVertices;
    int noEdges;
    std::vector<std::vector<int>> adjacencyList;

    /* Private methods */
    void addToMap(int x, int y) {
         adjacencyList[x-1].push_back(y-1);
         adjacencyList[y-1].push_back(x-1);
    }

public:
    Graph(int _v, int _e): noVertices(_v), noEdges(_e) {
        adjacencyList.resize(noVertices);
    }

    const Graph& operator +(const std::pair<int, int>& e) {
        addToMap(e.first, e.second);
        return *this;
    }

    void dfs(int start, std::vector<bool>& vis, std::set<int>& nodes) {
        nodes.erase(start);
        vis[start] = true;
        std::cout << start + 1 << " ";

        for(auto it = adjacencyList[start].begin(); it != adjacencyList[start].end(); ++it) {
            if(!vis[*it]) {
                nodes.insert(*it);
            }
        }

        if(nodes.size() > 0) {
            dfs(*(nodes.begin()), vis, nodes);
        }
    }
};

int main()
{
    int n, m, x, y;
    std::cin >> n >> m;

    Graph graph(n, m);
    for(int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        graph = graph + std::make_pair(x, y);
    }

    std::vector<bool> vis(n, false);
    std::set<int> nodes;
    nodes.insert(0);

    graph.dfs(0, vis, nodes);
    return 0;
}
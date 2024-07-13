#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN]; // 邻接表表示图
int parent[MAXN]; // 记录每个节点的前驱节点
bool visited[MAXN]; // 记录节点是否被访问过

// 深度优先搜索
void dfs(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            parent[next] = node; // 记录前驱节点
            dfs(next);
        } else if (next != parent[node]) { // 检测到环，且不是回溯时遇到的前驱节点
            // 输出环
            vector<int> cycle;
            int curr = node;
            do {
                cycle.push_back(curr);
                curr = parent[curr];
            } while (curr != next);
            cycle.push_back(next); // 将环的起始节点也添加到vector中

            // 逆序输出环上的节点
            for (int i = cycle.size() - 1; i >= 0; --i) {
                cout << cycle[i] << " ";
            }
            cout << endl;
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    return 0;
}
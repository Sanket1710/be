#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
void dfs(int v) {
 visited[v] = true;
 // Process node v here
 #pragma omp parallel for
 for (int i = 0; i < adj[v].size(); i++) {
 int u = adj[v][i];
 if (!visited[u]) {
 dfs(u);
 }
 }
}
int main() {
 int n, m, start;
 cin >> n >> m >> start;
 for (int i = 0; i < m; i++) {
 int u, v;
 cin >> u >> v;
 adj[u].push_back(v);
 adj[v].push_back(u);
 }
 dfs(start);
 // Output visited nodes
 cout << "Visited nodes: ";
 for (int i = 1; i <= n; i++) {
 if (visited[i]) {
 cout << i << " ";
 }
 }
 cout << endl;
 return 0;
}
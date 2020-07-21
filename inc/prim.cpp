template <typename G>
int prim(G &g, int n, int parent[], int dis[], bool visited[]) {
     fill(parent + 0, parent + n, -1);
     fill(dis + 0, dis + n, -1);
     fill(visited + 0, visited + n, false);
     dis[0] = 0;
     int sum = 0;
     for (int t = 0; t < n; ++t) {
         int kk = -1, a = -1;
         for (int i = 0; i < n; ++i) { 
             if (!visited[i] && (kk == -1 || (dis[i] > -1 && dis[i] < kk))) {
                kk = dis[i];
                a = i;
             }
         }
         if (a == -1 || kk == -1) {
             return -1;
         }
         sum += kk;
         visited[a] = true;
         g.traverse(a, [&](typename G::node n) {
             if (!visited[n.v] && (dis[n.v] == -1 || dis[n.v] > n.w)) {
                 dis[n.v] = n.w;
                 parent[n.v] = a;
             }
         });
     }
     return sum;
}

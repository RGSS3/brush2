template <size_t Maxindex = 256, typename Data = $node_type, size_t Maxnode = 1000000>
struct DiGraph {
    struct node {
        int v;
        Data w;
        int next;
    };
    node e[Maxnode];
    int cnt;
    int head[Maxindex];
    void clear(int n = Maxindex) {
        fill(head + 0, head + n, -1);
        cnt = 0;
    }
    void add(int a, int b, Data c) {
        e[cnt].v = b;
        e[cnt].w = c;
        e[cnt].next = head[a];
        head[a] = cnt++;
    }

    template <typename F>
    void traverse(int h, F f) {
        for (int k = head[h]; k != -1; k = e[k].next) {
            f(e[k]);
        }
    }
};

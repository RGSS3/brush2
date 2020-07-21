template <typename A1, typename A2, typename A3, typename A4, typename A5>
void dfs(A1 const &a,
        A2 b,
        A3 c,
        A4 d,
        A5 e);

template <typename A1, typename A2, typename A3, typename A4, typename A5>
void dfsimpl(A1 const &aa, A2 b, A3 c, A4 d, A5 e) {
    if (b(aa)) {
        c(aa);
        dfs(d(aa), b, c, d, e);
        e(aa);
    }
}

template <typename A1, typename A2, typename A3, typename A4, typename A5>
void dfs(A1 const &a,
        A2 b,
        A3 c,
        A4 d,
        A5 e) {
    for (auto const &aa : a) {
        dfsimpl(aa, b, c, d, e);
    }
}


#define prime_to(n) <%= Prime.take_while {|x| x <= n}.join(", ") %>
#define catalan(n) <%=  Catalan.first(n).join(", ") %>

template <typename F, typename G>
void factor(int n, F f, G prime_list) {
    for (auto k : prime_list) {
        if (k * k > n) {
            break;
        }
        if (n % k == 0) {
            int cnt = 0;
            while (n % k == 0) {
                ++cnt;
                n /= k;
            }
            f(k, cnt);
        }
    }
    if (n > 1) {
        f(n, 1);
    }
}

template <typename F>
void factor(int n, F f) {
    for (int k = 2; ;++k) {
        if (k * k > n) {
            break;
        }
        if (n % k == 0) {
            int cnt = 0;
            while (n % k == 0) {
                ++cnt;
                n /= k;
            }
            f(k, cnt);
        }
    }
    if (n > 1) {
        f(n, 1);
    }
}

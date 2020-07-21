template <typename base_type = $default_type, int radix = 10000, int N = 100>
struct MP {
    using type = MP<base_type, radix, N>;
    base_type a[N]{};
    int size = 0;
    MP (){}
    MP (string const &n) {
        read(n);
    }
    MP (long long const &n) {
        stringstream ss;
        ss << n;
        read(ss.str());
    }
    MP (uint64_t const &n) {
        stringstream ss;
        ss << n;
        read(ss.str());
    }

    void read(string const &s) {
        size = 0;
        fill(a + 0, a + N, 0);
        for (auto ch : s) {
            int c = ch - '0';
            *this = *this * 10 + c;
        }
    }

    void adjust() {
        while (size > 0 && a[size] == 0) {
            --size;
        }
    }
    void adjust_out(int k) {
        while (k < N - 1 && a[k] >= radix) {
            a[k + 1] += a[k] / radix;
            a[k] %= radix;
            ++k;
            if (size < k) {
                size = k;
            }
        }
 
    }

    MP operator +(MP const &rhs) const {
        MP c;
        c.size = max(size, rhs.size);
        c.a[0]=a[0]+rhs.a[0];
        $for(i,1,c.size+1){
            c.a[i]=a[i]+rhs.a[i]+c.a[i-1]/radix;
            c.a[i-1]%=radix;
        }
        c.adjust();
        return c;
    }

    MP operator +(int v) const {
        MP c = *this;
        c.a[0] += v;
        c.adjust_out(0);
        c.adjust();
        return c;
    }

    MP operator *(MP const &rhs) const {
        MP c;
        c.size = size + rhs.size;
        int a1 = size + 1, a2 = rhs.size + 1;
        $for(i,0,a1){
            $for(j,0,a2){
                c.a[i+j]+=a[i]*rhs.a[j];
                c.adjust_out(i+j);
            }
        }
        c.adjust();
        return c;
    }

    MP operator *(int v) const {
        MP c;
        int n = c.size = size;
        int a1 = size + 1;
        $for(i,0,a1){
            c.a[i]+=a[i]*v;
            c.adjust_out(i);
        }
        c.adjust();
        return c;
    }

    bool operator ==(MP const &rhs) const {
        if (size != rhs.size) {
            return false;
        }
        for (int i = 0; i <= size; ++i) {
            if (a[i] != rhs.a[i]) {
                return false;
            }
        }
        return true;
    }

    void print(const char *infmt = "%04d") const {
        for (int i = size; i >= 0; --i) {
            if (i == size) {
                printf("%d", a[i]);
            } else {
                printf(infmt, a[i]);
            }
        }
    }
};
using namespace std::rel_ops;

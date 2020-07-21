template <int N, int M, typename A>
struct matrix {
    A a[N][N];
    using type = matrix <N, M, A>;
    type operator +(const type & rhs) const {
        type out = {};
        $for(i,0,N){
            $for(j,0,N){
                out.a[i][j]=(a[i][j]+rhs.a[i][j]) % M;
            }
        }   
        return out;
    }
    type operator -(const type & rhs) const {
        type out = {};
        $for(i,0,N){
             $for(j,0,N){
                 out.a[i][j]=(a[i][j]-rhs.a[i][j]) % M;
             }
        }
        return out;
    }    
    type scale(const A &s) const {
        type out = {};
        $for(i,0,N){
             $for(j,0,N){
                 out.a[i][j]=a[i][j] * s % M;
             }
        }
        
        return out;
    }
    type operator *(const type &rhs) {
        type out = {};
        $for(i,0,N){
             $for(j,0,N){
                 $for(k,0,N){
                     out.a[i][j]+=a[i][k] * rhs.a[k][j];
                     out.a[i][j] %= M;
                 }
             }
        }
        return out;
    }

    static type identity() {
        type out = {};
        for (int i = 0; i < N; ++i) out.a[i][i] = 1;
        return out;
    }

    type power(int n) {
        type c = identity(), d = *this;
        while (n > 0) {
            if (n % 2 == 1) {
                c = c * d;
            }
            d = d * d;
            n /= 2;
        }
        return c;
    }

    void print() const {
        $for(i,0,N) {
            $for(j,0,N) {
                if (j) {
                    printf(" ");
                }
                printf("%d", a[i][j]);
            }
            puts("");
        }
    }

};
template <int N, typename A>
struct matrix <N, 0, A>{
    A a[N][N];
    using type = matrix <N, 0, A>;
    type operator +(const type & rhs) const {
        type out = {};
        $for(i,0,N){
            $for(j,0,N){
                out.a[i][j]=a[i][j]+rhs.a[i][j];
            }
        }   
        return out;
    }
    type operator -(const type & rhs) const {
        type out = {};
        $for(i,0,N){
            $for(j,0,N){
                out.a[i][j]=a[i][j]-rhs.a[i][j];
            }
        }
        return out;
    }    
    type scale(const A &s) const {
        type out = {};
        $for(i,0,N){
            $for(j,0,N){
                out.a[i][j]=a[i][j] * s;
            }
        }
        return out;
    }
    type operator *(const type &rhs) const {
        type out = {};
        $for(i,0,N){
             $for(j,0,N){
                 $for(k,0,N){
                     out.a[i][j]+=a[i][k] * rhs.a[k][j];
                 }
             }
        }
        return out;
    }

    static type identity() {
        type out = {};
        for (int i = 0; i < N; ++i) out.a[i][i] = 1;
        return out;
    }

    type power(int n) {
        type c = identity(), d = *this;
        while (n > 0) {
            if (n % 2 == 1) {
                c = c * d;
            }
            d = d * d;
            n /= 2;
        }
        return c;
    }

    void print() const {
        $for(i,0,N) {
            $for(j,0,N) {
                if (j) {
                    printf(" ");
                }
                printf("%d", a[i][j]);
            }
            puts("");
        }
    }

};



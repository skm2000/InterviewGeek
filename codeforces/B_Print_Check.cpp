    #include <cstdio>
    #include <algorithm>
     
    const int N = 5000, K = (int)1e5 + 1;
     
    int n, m, k;
    int t, p;
    int l[N], c[N], x[K];
     
    int main() {
        scanf("%d%d%d", &n, &m, &k);
     
        x[0] = 0;
     
        for (int i = 1; i <= k; ++i) {
            scanf("%d%d%d", &t, &p, &x[i]);
            if (t == 1)
                l[--p] = i;
            else
                c[--p] = i;
        }
     
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                printf("%d ", x[std::max(l[i], c[j])]);
            putchar('\n');
        }
     
        return 0;
    }
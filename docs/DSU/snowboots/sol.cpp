#include <bits/stdc++.h>
using namespace std;

struct Shoe {
    int s, d, id;
};

struct DSU {
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (sz[u] < sz[v])
            swap(u, v);

        par[v] = u;
        sz[u] += sz[v];
    }

    int size(int u) {
        return sz[find(u)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B;
    cin >> N >> B;

    vector<int> H(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> H[i];

    vector<Shoe> shoes(B);

    for (int i = 0; i < B; i++) {
        cin >> shoes[i].s >> shoes[i].d;
        shoes[i].id = i;
    }

    // Xử lý giày có s lớn trước
    sort(shoes.begin(), shoes.end(), [](const Shoe &a, const Shoe &b) {
        return a.s > b.s;
    });

    // Các vị trí có H[i] > s hiện tại
    // được coi là "ô cấm".
    vector<int> order(N);
    iota(order.begin(), order.end(), 1);

    // Ta cần thêm các ô theo H giảm dần.
    sort(order.begin(), order.end(), [&](int a, int b) {
        return H[a] > H[b];
    });

    DSU dsu(N);

    vector<bool> active(N + 1, false);
    vector<bool> ans(B);

    int ptr = 0;

    // Độ dài đoạn liên tiếp các ô H[j] > s
    int maxBlock = 0;

    for (auto shoe : shoes) {
        // Thêm tất cả vị trí có H[pos] > shoe.s
        while (ptr < N && H[order[ptr]] > shoe.s) {
            int u = order[ptr];
            active[u] = true;

            // Ban đầu u là một component kích thước 1
            maxBlock = max(maxBlock, 1);

            // Nối với bên trái nếu bên trái đã active
            if (u > 1 && active[u - 1]) {
                dsu.unite(u, u - 1);
                maxBlock = max(maxBlock, dsu.size(u));
            }

            // Nối với bên phải nếu bên phải đã active
            if (u < N && active[u + 1]) {
                dsu.unite(u, u + 1);
                maxBlock = max(maxBlock, dsu.size(u));
            }

            ptr++;
        }

        // Nếu tồn tại đoạn cấm có độ dài >= d
        // thì không thể đi qua.
        ans[shoe.id] = (maxBlock < shoe.d);
    }

    for (int i = 0; i < B; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }

    return 0;
}
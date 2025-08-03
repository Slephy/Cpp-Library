#include <slephy-cpp-lib/core/core.hpp>
#include <slephy-cpp-lib/math/power.hpp>
#include <slephy-cpp-lib/modint/acl-modint.hpp>

using mint = atcoder::modint998244353;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    {
        int val = 3, exp = 5;
        cout << power(val, exp) << endl;
    }
    {
        ll val = 10, exp = 12;
        cout << power(val, exp) << endl;
    }
    {
        ll val = 10;
        int exp = 12;
        cout << power(val, exp) << endl;
    }
    {
        int val = 10;
        ll exp = 8;
        cout << power(val, exp) << endl;
    }
    {
        mint val = 10, exp = 12;
        cout << power(val, exp) << endl;
    }
    {
        mint val = 10;
        ll exp = 12;
        cout << power(val, exp) << endl;
    }
    {
        double val = 10, exp = 100;
        cout << power(val, exp) << endl;
    }
    {
        double val = 10;
        ll exp = 100;
        cout << power(val, exp) << endl;
    }

    return 0;
}

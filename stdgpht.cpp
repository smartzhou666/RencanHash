#pragma once
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
struct hd {
    [[gnu::pure]] size_t operator()(uint64_t h) const noexcept {
        h *= 0x9E3779B97F4A7C15ULL;
        h ^= h >> 33;
        h *= 0xff51afd7ed558ccdULL;
        h ^= h >> 27;
        h *= 0xc4ceb9fe1a85ec53ULL;
        return h ^ (h >> 31);
    }
    [[gnu::pure]] size_t operator()(const string &s) const noexcept {
        // return operator()(hash<string>()(s));
        uint64_t hs = 0xCBF29CE484222325ULL;
        for (const auto &c : s) {
            hs ^= static_cast<uint64_t>(c);
            hs *= 0x00000100000001B3ULL;
        }
        return operator()(hs);
    }
    [[gnu::pure]] size_t operator()(double d) const noexcept {
        uint64_t hd;
        memcpy(&hd, &d, sizeof(double));
        if (__builtin_expect(hd == 0x8000'0000'0000'0000ULL, false)) hd = 0;
        return operator()(hd);
    }
    [[gnu::pure]] size_t operator()(float f) const noexcept {
        uint64_t hd = 0;
        memcpy(&hd, &f, sizeof(float));
        if (__builtin_expect(hd == 0x8000'0000U, false)) hd = 0;
        return operator()(hd);
    }
    [[gnu::pure]] size_t operator()(long double ld) const noexcept {
        return hash<long double>()(ld);
    }
    [[gnu::pure]] size_t operator()(nullptr_t) const noexcept {
        return 0;
    }
    template <typename T_>
    [[gnu::pure]] size_t operator()(T_ *p) const noexcept {
        return operator()(static_cast<uint64_t>(reinterpret_cast<uintptr_t>(p)));
    }
    template <typename Ty_, typename Tu_>
    [[gnu::pure]] size_t operator()(const pair<Ty_, Tu_> &p) const noexcept {
        size_t h1 = operator()(p.first);
        size_t h2 = operator()(p.second);
        size_t x = h1 ^ (h2 << 17 | h2 >> 47);
        return operator()(x);
    }
};
// Usage: gpht<Ty_, Tu_[, Hash_Fn = hd]>
//
// Type alias for gp_hash_table with an optimized hash functor
//
// Non-standard key types require a specialized hash function
template <typename Ty_, typename Tu_, typename Hash_Fn = hd>
using gpht = gp_hash_table<Ty_, Tu_, Hash_Fn, equal_to<Ty_>,
                           direct_mask_range_hashing<>, linear_probe_fn<>>;

#if __INCLUDE_LEVEL__ == 0
int main() {
    // example
    cin.tie(0)->sync_with_stdio(false);
    gpht<string, int> hsi;
    string s, pos;
    int n, T, x;
    cin >> n >> T;
    while (T--) {
        cin >> s >> x;
        hsi[s] = x;
    }
    while (n--) {
        cin >> pos;
        cout << hsi[pos] << ' ';
    }
}
#endif

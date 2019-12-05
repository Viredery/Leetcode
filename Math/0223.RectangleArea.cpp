class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area1 = (C - A) * (D - B), area2 = (G - E) * (H - F);
        long long I = max(A, E), J = max(B, F), K = min(C, G), L = min(D, H);
        long long interact = max(0ll, K - I) * max(0ll, L - J);
        return area1 + area2 - interact;
    }
};

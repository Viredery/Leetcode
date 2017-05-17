// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binarySearchFirstBadVersion(1, n);
    }
private:
    int binarySearchFirstBadVersion(int left, int right) {
        if (left == right) return left;
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            return binarySearchFirstBadVersion(left, mid);
        } else {
            return binarySearchFirstBadVersion(mid + 1, right);
        }
    }
};

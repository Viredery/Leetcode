class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int bucketsPerPig = minutesToTest / minutesToDie + 1;
        int numPigs = 0, numBuckets = 1;
        while (numBuckets < buckets) {
            numPigs++;
            numBuckets *= bucketsPerPig;
        }
        return numPigs;
    }
};

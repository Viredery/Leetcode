/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        int maxPoints = 0;
        for (int i = 0; i != points.size(); i++) {
            int numSamePoints = 1;
            unordered_map<int, unordered_map<int, int>> map;
            for (int j = i + 1; j != points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    numSamePoints++;
                else if (points[i].x == points[j].x)
                    map[0][0]++;
                else {
                    int x = points[i].x - points[j].x, y = points[i].y - points[j].y;
                    int gcd = generateGCD(x, y);
                    if (gcd != 0) {
                        x /= gcd;
                        y /= gcd;
                    }
                    map[x][y]++;
                }
            }
            int maxCurr = 0;
            for (auto iter = map.begin(); iter != map.end(); iter++)
                for (auto iterInner = iter->second.begin(); iterInner != iter->second.end(); iterInner++)
                    maxCurr = max(maxCurr, iterInner->second);
            maxPoints = max(maxPoints, maxCurr + numSamePoints);
        }
        return maxPoints;
    }
private:
    int generateGCD(int a, int b) {
        if (b == 0) return a;
    	else return generateGCD(b, a % b);
    }
};
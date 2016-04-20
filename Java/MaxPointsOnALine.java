// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

public class MaxPointsOnALine {
    public int maxPoints(Point[] points) {
        int max = 0;
        for (int i = 0; i < points.length; i++) {
            int localMax = 0;
            int overlap = 0;
            int vertical = 0;
            Map<Integer, Map<Integer, Integer>> mp = new HashMap<>();
            for (int j = 0; j < points.length; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    overlap++;
                } else if (points[i].x == points[j].x) {
                    vertical++;
                } else {
                    int deltaX = points[i].x - points[j].x;
                    int deltaY = points[i].y - points[j].y;
                    int count = 0;
                    if (deltaY == 0) {
                        mp.putIfAbsent(0, new HashMap<>());
                        count = mp.get(0).getOrDefault(0, 0) + 1;
                        mp.get(0).put(0, count);
                    } else {
                        int g = gcd(deltaX, deltaY);
                        deltaX /= g;
                        deltaY /= g;
                        mp.putIfAbsent(deltaY, new HashMap<>());
                        count = mp.get(deltaY).getOrDefault(deltaX, 0) + 1;
                        mp.get(deltaY).put(deltaX, count);
                    }
                    localMax = Math.max(localMax, count);
                }
            }
            max = Math.max(max, overlap + Math.max(vertical, localMax));
        }
        return max;
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}

class Solution {
private:
    int calculateManhattanDistance(const vector<int>& pointA, const vector<int>& pointB) {
        return abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int totalNodes = points.size();
        
        if (totalNodes <= 1) {
            return 0;
        }

        int totalMinimumCost = 0;
        int edgesConnected = 0;

        vector<int> minDistanceToMST(totalNodes, INT_MAX);
        vector<bool> inMST(totalNodes, false);

        minDistanceToMST[0] = 0;

        while (edgesConnected < totalNodes) {
            int nextNode = -1;
            int minimumEdgeWeight = INT_MAX;

            for (int i = 0; i < totalNodes; ++i) {
                if (!inMST[i] && minDistanceToMST[i] < minimumEdgeWeight) {
                    minimumEdgeWeight = minDistanceToMST[i];
                    nextNode = i;
                }
            }

            totalMinimumCost += minimumEdgeWeight;
            inMST[nextNode] = true;
            edgesConnected++;

            if (edgesConnected == totalNodes) {
                break;
            }

            for (int targetNode = 0; targetNode < totalNodes; ++targetNode) {
                if (!inMST[targetNode]) {
                    int currentEdgeWeight = calculateManhattanDistance(points[nextNode], points[targetNode]);
                    
                    if (currentEdgeWeight < minDistanceToMST[targetNode]) {
                        minDistanceToMST[targetNode] = currentEdgeWeight;
                    }
                }
            }
        }

        return totalMinimumCost;
    }
};
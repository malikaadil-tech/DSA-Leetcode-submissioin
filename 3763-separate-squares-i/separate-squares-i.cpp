class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        // Determine search range
        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)(sq[1] + sq[2]));
        }

        // Binary search on y
        for (int iter = 0; iter < 100; iter++) { // sufficient for 1e-5 precision
            double mid = (low + high) / 2.0;

            double above = 0.0, below = 0.0;

            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];

                if (mid <= y) {
                    // Entire square above the line
                    above += l * l;
                }
                else if (mid >= y + l) {
                    // Entire square below the line
                    below += l * l;
                }
                else {
                    // Line cuts the square
                    below += l * (mid - y);
                    above += l * (y + l - mid);
                }
            }

            if (above > below) {
                low = mid;   // move line upward
            } else {
                high = mid;  // move line downward
            }
        }

        return (low + high) / 2.0;
    }
};

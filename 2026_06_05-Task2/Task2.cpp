#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int median(vector<vector<int>> &mat) {
    int n = mat.size(); //3
    int m = mat[0].size(); //3

    int minVal = INT_MAX, maxVal = INT_MIN;

    for (int i = 0; i < n ; i++) {
        if (mat[i][0] < minVal) {
            minVal = mat[i][0];
        }
        if (mat[i][m - 1] > maxVal) {
            maxVal = mat[i][m - 1];
        }
    }

    int desired = (n * m + 1) / 2; 
    // 3 * 3  = 9+ 1 / 2 = 5
    int lo = minVal, hi = maxVal;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        // 5
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            //  only 3 elements that is greater then 5 , meaning upperbound find > 5,
            // lowerbound find <= 5
        }
      
        if (count < desired) {
            lo = mid + 1;
        } else {
            hi = mid;
            // hi = 5
        }
    }
    return lo;
}


int main() {
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median: " << median(mat) << endl;
    return 0;
}
// You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
// repr esents the coordinate of a point. Check if these points make a straight
// line in the XY plane.
//
//
//
//
//  Example 1:
//
//
//
//
// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true
//
//
//  Example 2:
//
//
//
//
// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// Output: false
//
//
//
//  Constraints:
//
//
//  2 <= coordinates.length <= 1000
//  coordinates[i].length == 2
//  -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
//  coordinates contains no duplicate point.
//  Related Topics Array Math Geometry
//  👍 561 👎 89

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Solution
{
public:
    bool checkStraightLine(const std::vector<std::vector<int>>& coordinates)
    {
        // Two points can only form straight lines
        if (coordinates.size() == 2)
        {
            return true;
        }

        const int d_x_first = coordinates[0][0] - coordinates[1][0];
        const int d_y_first = coordinates[0][1] - coordinates[1][1];
        // A line is straight if the slope between all pairs of points  is the same
        // Starting at second element because first slope is precomputed above
        for (int i = 2; i < coordinates.size(); ++i)
        {
            const int d_x_cur = coordinates[i][0] - coordinates[0][0];
            const int d_y_cur = coordinates[i][1] - coordinates[0][1];

            // If two slopes are equal, their deltas of the same dimension(x or y) will be multiples of each
            // other, multiplying them should then have an equal result
            if (d_x_first * d_y_cur != d_x_cur * d_y_first)
            {
                return false;
            }
        }
        return true;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

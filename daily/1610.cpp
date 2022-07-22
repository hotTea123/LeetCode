#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static constexpr double eps = 1e-8;
    static int sgn(double a) { return a < -eps ? -1 : a < eps ? 0
                                                              : 1; }
    static bool eq(double a, double b) { return sgn(a - b) == 0; }
    static bool ne(double a, double b) { return sgn(a - b) != 0; }
    static bool lt(double a, double b) { return sgn(a - b) < 0; }
    static bool le(double a, double b) { return sgn(a - b) <= 0; }
    static bool gt(double a, double b) { return sgn(a - b) > 0; }
    static bool ge(double a, double b) { return sgn(a - b) >= 0; }
    
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        vector<double> A;
        vector<int> an;
        int x, y, i, same_point = 0;
        double po;
        //求出所有点相对point的角度
        for (i = 0; i < points.size(); i++)
        {
            an = points[i];
            x = an[0] - location[0];
            y = an[1] - location[1];
            po = atan2(double(y), double(x)) * 180 / M_PI;
            if (y < 0)
                po = 360 + po;
            if (x == 0 && y == 0)
            {
                same_point++;
                continue;
            }
            A.emplace_back(po);
        }

        sort(A.begin(), A.end());
        int max_point = 0, max, max_start;
        double des_ang;
        int k, flag = 0, des_index = 0;
        for (k = 0; k < A.size(); k++)
        {
            max = 0;
            des_ang = A[k] + angle;
            if (ge(des_ang, 360))
            {
                flag = 1;
                des_ang -= 360;
            }
            //二分查找,找到不超过des_ang的最大数的索引
            int low = 0, high = A.size() - 1;
            if(le(A[high], des_ang))
                des_index = high;
            else{
                int mid;
                while (low < high)
                {
                    mid = (low + high + 1) >> 1;
                    if (gt(A[mid], des_ang))
                        high = mid - 1;
                    else
                        low = mid;
                }
                des_index = low;
            }

            //是否超过360度
            if (flag == 0)
                max = des_index - k + 1;
            else
                max = min(des_index + A.size() - k + 1, A.size());

            if (max > max_point)
            {
                max_point = max;
                max_start = k;
           }
        }
        return max_point + same_point;
    }
};
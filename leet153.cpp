//
// 20170821
//
// 기본 바이너리랑 다를 바가 없다??
//
//
//
//
//
//


#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    // not mine
//    int findMin(vector<int>& nums) {
//        int lo = 0;
//        int hi = nums.size() - 1;
//        while(lo < hi) {
//            int mid = (lo + hi) / 2;
//            if(nums[mid] < nums[hi])
//                hi = mid;
//            else
//                lo = mid + 1;
//        }
//        return nums[lo];
//    }
    
    int bs(vector<int> & nums, int l, int h)
    {
        int m = int((l + h) / 2);
        if (m == l || m == h) return std::min(nums[l], nums[h]);
        
        if (nums[l] <= nums[m] && nums[m] <= nums[h]) return nums[l]; // if the array originally are in ascending order.
        
        if (nums[l] > nums[m] && nums[h] > nums[m])
        {
            return nums[l] > nums[h] ? bs(nums, l, m) : bs(nums, m, h);
        }
        else if (nums[l] > nums[m] && nums[m] < nums[h])
        {
            return bs(nums, l, m);
        }
        else
            return bs(nums, m, h);
    }
    
    // mine
    int findMin(vector<int>& nums)
    {
        int h = (int)nums.size() - 1;
        if (!h) return nums[0];
        
        return bs(nums, 0, h);
    }
};

int main()
{
    Solution s = Solution();
    int arr[] = {6, 7, 0, 1, 2, 4, 5};
    int arr2[] = {5, 6, 7, 0, 1, 2, 4};
    int arr3[] = {2, 1};
    //vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    //vector<int> nums(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    vector<int> nums(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));

    //for (int i = 0; i < nums.size(); ++i) cout << nums[i] << endl;
    
    cout << s.findMin(nums) << endl;
    
    
    return 0;
}

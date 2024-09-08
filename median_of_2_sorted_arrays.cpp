// Time: O(log n) where n is the min(arr1 size, arr2 size)
// space O(1)

// algorithm: 
// find a partition/pivot in both arrays  such that at the pivot all elements on right are higher than on left in both arrays 
// pivot also needs to be based on total number of elements a1+a2. since we are finding the median
// 1. find pivot in array 1 (smaller array) using binary search (can also go linear but bs is more effcient)
// 2. since we know pivot in array 1, find pivot in array 2 by simple math
// 3. check if pivot is valid using equality checks on edge elements
// 4. get median if it is, move partition if it is not
// 5. how to move partition : if l1 > r2, we need to inclide right element of arr1 .. move right .. low = part_1 + 1
// 6. if l2 > r1 : we need to include right part of arr2 .. we move left.. high = part_1 - 1; 
// keep doing this until low and high cross each other

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size(); 

        int low = 0; 
        int high = n1; // we are doing Binary search on partitions not elements. hence not doing n1 - 1

        while(low <= high)
        {
            int part_n1 = low + ((high-low)/2);
            int part_n2 = ((n1+n2)/2) - part_n1;

            int l1 = (part_n1 == 0) ? numeric_limits<int>::min() : nums1[part_n1 - 1];
            int r1 = (part_n1 == n1) ? numeric_limits<int>::max() : nums1[part_n1];
            
            int l2 = (part_n2 == 0) ? numeric_limits<int>::min() : nums2[part_n2 - 1];
            int r2 = (part_n2 == n2) ? numeric_limits<int>::max() : nums2[part_n2];
            if(l1 <= r2 && l2 <=r1)
            {
                // we found median
                if((n1+n2)%2 == 1)
                {
                    return min(r1,r2);
                }
                else
                {
                    return (double)(min(r1,r2) + max(l1,l2))/2;
                }
            }
            else if(l1>r2)
            {
                // move left
                high = part_n1;
            }
            else
            {
                // move right
                low = part_n1+1;
            }

        }

        return -1;
    }
};
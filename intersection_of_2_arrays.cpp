// time : O(n+m)
// space : O(max(n,m))

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> count; 
        vector<int> result;

        for(int i : nums1)
        {
            if(count.contains(i) == true) count[i]++;
            else count[i]=1;
        }

        for(int i : nums2)
        {
            if(count[i]>0)
            {
                result.push_back(i);
                count[i]--;
            }            
        }

        return result;
    }
};


// Alteranative approaches - sorting is O(n long n) + O(n)
// sort both arrays 
// 1. use tow pointer method to find common numbers, if yes add to result if no increase the pointer of smaller numner 
// 2. use binary search on smaller array to find the 'first occurence' of a number we are looking for from bigger array 
//      Once you find the number, shrink the search space by move low to mid
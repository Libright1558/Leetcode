// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        unsigned int right = n;
        unsigned int pivot = (left + right) / 2;
        int result;
        bool bad = isBadVersion(pivot);
        
        while(left <= right) {
            if(left == right && isBadVersion(right) == true) {
                result = right;
                break;
            }
            
            if(bad == true) {
                right = pivot;
                pivot = (left + right) / 2;
            }
            else if(bad == false) {
                left = pivot + 1;
                pivot = (left + right) / 2;
            }
            
            bad = isBadVersion(pivot);
        }
        
        return result;
    }
};

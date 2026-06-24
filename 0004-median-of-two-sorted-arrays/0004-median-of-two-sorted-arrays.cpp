class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            int partitionA = (low + high) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int Aleft = (partitionA == 0)
                            ? INT_MIN
                            : nums1[partitionA - 1];

            int Aright = (partitionA == m)
                             ? INT_MAX
                             : nums1[partitionA];

            int Bleft = (partitionB == 0)
                            ? INT_MIN
                            : nums2[partitionB - 1];

            int Bright = (partitionB == n)
                             ? INT_MAX
                             : nums2[partitionB];

            // Correct partition found
            if (Aleft <= Bright && Bleft <= Aright) {

                // Even total length
                if ((m + n) % 2 == 0) {
                    return (max(Aleft, Bleft) +
                            min(Aright, Bright)) / 2.0;
                }

                // Odd total length
                return max(Aleft, Bleft);
            }

            // Move left
            else if (Aleft > Bright) {
                high = partitionA - 1;
            }

            // Move right
            else {
                low = partitionA + 1;
            }
        }

        return 0.0;
    }
};
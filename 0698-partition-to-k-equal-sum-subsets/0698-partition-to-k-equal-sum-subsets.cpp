class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int len = nums.size();
        if(k > len)
            return false;
        int sum = 0;
        for(auto n : nums)
            sum += n;
        //impossible to partition
        if(k > sum || sum%k != 0)
            return false;
        int target = sum/k;        
       //used buckets
        vector<bool> used(len, false);;
        //sort the nums in decreasing order
        sort(nums.begin(), nums.end(), greater());
        //start back tracking
        return backtrack(nums, k, 0, 0, target, used);
    }
    /*k is the buket number
    the k bucket has nums[start]
    used to check if a number has added to the bucket
    target is the goal of each bucket
    */
    bool backtrack(vector<int>& nums, int k, int start, int bucket, int target, vector<bool>& used){
        int len = nums.size();
        //base line
        if(k == 0){
            return true;
        }
        if(bucket > target)
            return false;
        
        if(bucket == target){
            //filled the current bucket, goto next
            return backtrack(nums, k-1, 0, 0, target, used);
        }
        for(int i = start; i < len; i++){
            //pruning
            if(used[i])
                continue;
            //back tracking
            used[i] = true;
            //next number
            if(backtrack(nums, k, i + 1, bucket + nums[i], target, used))
                return true;
            used[i] = false;
			//extra prunning
            if(bucket == 0)
                break;
        }
        return false;
    }
};
// 4ms
// class Solution {
// public:
//    // use global variables to avoid long parameter list
//    int target; // of each bucket
//    vector< int > ns;
//    vector< int > bucket;

//    bool canPartitionKSubsets( vector<int>& nums, int k ) {
//        int sum = 0;
//        for( int &n : nums ) sum += n;
//        if( sum % k ) return false; // not divisible
//        target = sum / k;
//        ns = vector< int >( nums );
//        bucket = vector< int >( k, 0 );
//        // starting with bigger ones makes it faster
//        sort( ns.begin(), ns.end() );
//        reverse( ns.begin(), ns.end() );
//        return put( 0 );
//    }

//    // put #n item of ns into some bucket to meet target
//    bool put( int n ) {
//        for( int i = 0; i < bucket.size(); ++i ) {
           
//            if( bucket[i] + ns[n] > target ) continue; // try next bucket
//            bucket[i] += ns[n]; // put it in!
//            if( n == ns.size() - 1 ) return true; // all items in bucket, no overflow
//            if( put( n + 1 ) ) return true; // move on to next item
//            else { // no solution = wrong bucket
//                bucket[i] -= ns[n]; // take it out
//                if( bucket[i] == 0 ) return false; // no need to try other empty bucket
//            }
//        }
//        return false; // no bucket fits
//    }
// };

// 1400ms
// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum = 0;
//         sum = accumulate(nums.begin(), nums.end(), sum);
//         if (nums.size() < k || sum % k) return false;
        
//         vector<int>visited(nums.size(), false);
        
//         return backtrack(nums, visited, sum / k, 0, 0, k);
//     }
    
//     bool backtrack(vector<int>& nums,vector<int> &visited, int target, int curr_sum, int i, int k) {
//         if (k == 1) 
//             return true;
//         if(i>=nums.size()) return false;
//         if (curr_sum == target) 
//             return backtrack(nums, visited, target, 0, 0, k-1);
        
//         for (int j = i; j < nums.size(); j++) {
//             if (visited[j] || curr_sum + nums[j] > target) continue;
            
//             visited[j] = true;
//             if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
//             visited[j] = false;
//         }
        
//         return false;
//     }
// };
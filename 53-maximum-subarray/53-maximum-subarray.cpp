class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int cs=0,ms=INT_MIN;
        for(int i=0;i<n;i++){
            cs += arr[i];
            ms = max(cs,ms);
            if(cs<0){ cs = 0; }
        }
        return ms;
    }
};



// My All other different approches
// int maxSubArraySum(vector<int> arr){
// 	int n = arr.size();
// 	vector<int> arr_sum(n,0);
// 	int sumTillNow = 0;
// 	for(int i=0;i<n;i++){
// 		sumTillNow += arr[i];
// 		if(sumTillNow < 0){
// 			arr_sum[i]=0;
// 			sumTillNow=0;
// 		}
// 		else
// 		{
// 			arr_sum[i]=sumTillNow;
// 		}

// 	}
// 	int x = *max_element(arr_sum.begin(),arr_sum.end()); 
// 	return x;

// }


// int maxSubArraySum_2(vector<int> arr){

// 	int n=arr.size();
// 	for(int i=1;i<n;i++){
// 		if (arr[i-1] > 0){
// 			arr[i]+=arr[i-1];
// 		}
// 	}
// 	return *max_element(arr.begin(),arr.end());
// }

// int maxSubArraySum_3(vector<int> arr){

// 	int n=arr.size();
// int cs=0,ms=INT_MIN;
// for(int i=1;i<n;i++){
//     cs += arr[i];
//     ms = max(cs,ms);
//     if(cs<0){ cs = 0; }
// }
// return ms;
// }
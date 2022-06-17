class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
	vector<int> arr_sum(n,0);
	int sumTillNow = 0;
	for(int i=0;i<n;i++){
		sumTillNow += arr[i];
		if(sumTillNow < 0){
			arr_sum[i]=arr[i];
			sumTillNow=0;
		}
		else
		{
			arr_sum[i]=sumTillNow;
		}

	}
	int x = *max_element(arr_sum.begin(),arr_sum.end()); 
	return x;
    }
};
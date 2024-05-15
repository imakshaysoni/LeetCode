class Solution {
public:
    void mergee(vector<int> &arr, int low, int mid, int high){

    vector<int> temp;
    int i = low;
    int j = mid+1;
    while(i<=mid and j<=high){
        if(arr[i]<=arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}
    
int countPairs(vector<int> &arr, int low, int mid, int high){
    
    int right = mid+1;
    int cnt = 0;
    for(int left=low;left<=mid;left++){
        while(right<=high && arr[left] > 2*1LL*arr[right]) right++;
        cnt += (right - (mid+1));
    }
    return cnt;
    
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low>=high) return cnt;
    int mid = (low+high)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += countPairs(arr, low, mid, high);
    mergee(arr, low, mid, high);
    return cnt;
}


    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
class Solution {
    public int maximumCandies(int[] candies, long k) {      
        int start = 1; 
        int end = Arrays.stream(candies).max().getAsInt();
        int result = 0;
        while(start<=end){
            int mid = (end + start)/2;
            if(allocate(mid,candies,k)){
              result = mid;
              start = mid+1;
            }
            else{
              end = mid-1;
            }
        }
        return result;
    }
    public boolean allocate(int mid , int candies[], long k){
        long noOfAllo = 0;
        for(Integer it: candies){
        noOfAllo +=  it/mid;
        }
     return (noOfAllo >= k);
    }
}
class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0) {
	    //Use set to check if the string contains all unique characters
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        for (int i = index; i < arr.size(); i++)
            ret = max(ret, maxLength(arr, str+arr[i], i+1));

        return ret;
    }
};




// class Solution {
// public:
//     int maxLength(vector<string>& arr) {
        
//         if(arr.size()==1) return 1;
//         int ans=0;
//         int temp_ans=0;
//         unordered_set<char> s;
//         helper(arr,0,ans, s, temp_ans,"");
        
//         return ans;
//     }
    
//     void helper(vector<string> &arr, int i, int ans, unordered_set<char> m, int temp_ans, string temp){
        
       
//         m(temp.begin(),temp.end());
//         if(m.size()!=temp.size()) return;
        
//         if(m.size()==temp.size()){
//             if(temp_ans>ans){ans=temp_ans; return;}
//         }
        
        
        
//         for(int index = i;index<arr.size();index++){
//             temp +=arr[index];
//             temp_ans++;
//             helper(arr,i+1,ans,m,temp_ans,temp);
//             temp -=arr[index];
//             temp_ans--;
//         }
        
//     }
// };
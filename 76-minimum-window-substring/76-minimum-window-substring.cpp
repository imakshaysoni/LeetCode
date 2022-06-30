class Solution {
public:
    string minWindow(string ms, string ps) {
        int n = ps.length();
	int FP[256] = {0};
	int FS[256] = {0};

	for(int i=0;i<ps.length();i++){
		char ch = ps[i];
		FP[ch]++;
	}

	int cnt=0,start=0;
	int min_so_far = INT_MAX;
	int window_size;
	int start_idx=-1;
	
	for(int i=0;i<ms.length();i++){
		char ch = ms[i];
		FS[ch]++;
		
		if(FP[ch] and FP[ch]>=FS[ch]){
			cnt++;
		}

		// Contraction start
		if(cnt==ps.length()){

			while(FS[ms[start]]==0 or FS[ms[start]] > FP[ms[start]]){
				FS[ms[start]]--;
				start++;
			}
			window_size = i - start + 1;
			if(window_size < min_so_far){
				min_so_far = window_size;
				start_idx = start;
			}

		}

	}
	if(start_idx==-1){
		return "";
	}
	return ms.substr(start_idx,min_so_far);
    }
};
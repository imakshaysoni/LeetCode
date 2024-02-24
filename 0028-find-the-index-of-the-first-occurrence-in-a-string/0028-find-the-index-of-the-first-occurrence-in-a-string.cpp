class Solution {
public:
    int strStr(string text, string pat) {
        // our code here.	
	if(pat.size()>text.size()) return -1;

	int t = text.size();
	int j=0;
	int start = -1;
	for(int i=0;i<t;i++){
		
		if(text[i]==pat[j]){
			int k=i;
			start=k;
			while(k<t && j<pat.size() and text[k]==pat[j]){
				k++; 
				j++;
			}
			if(j==pat.size()) return start;
			else j=0;
		}
	}
	return -1;
        
    }
};
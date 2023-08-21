class Solution {
public:
    vector<int> z_algo(string s){
        int n=s.size(), l=0,r=0;
        vector<int> z(n);
        for(int i=1;i<n;++i){
            if(i>r){
                l=r=i;
                while(r<n && s[r-l]==s[r]) r++;
                z[i]=r-l;
                r--;
            }else{
                int k=i-l;
                if(z[k]<r-i+1){
                    z[i]=z[k];
                }else{
                    l=i;
                    while(r<n && s[r-l]==s[r]) r++;
                    z[i]=r-l;
                    r--;
                }
            }
        }
        return z;
    }

    string longestPrefix(string s) {
        vector<int> z = z_algo(s);
        string str="";
        int n=s.size(),maxi=0;
        for(int i=0;i<n;++i){
            if(z[i]==s.size()-i){
               maxi=max(maxi,z[i]);
            }
        }
         str = s.substr(0,maxi);
        return str;
    }
};
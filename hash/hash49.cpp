class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> output;
    map<string,vector<string> > str2vec;
    for(int i=0;i<strs.size();i++){
        string s=strs[i];
        sort(s.begin(),s.end());
        str2vec[s].push_back(strs[i]);
    }
    for (auto& p : str2vec) {
            output.push_back(p.second);
        }
    return output;
    }
};
    


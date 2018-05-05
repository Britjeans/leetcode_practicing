//union-find solution
class Node{
public:
    double val=0.0;
    Node * parent;
    Node(){parent=this;}
};

class Solution {
public:      
    Node* findParent(Node* node) {
        if (node -> parent == node)
            return node;
        node -> parent = findParent(node -> parent);
        return node -> parent;
    }
   
    void Union(Node* one,Node* two,double value,unordered_map<string,Node*>& m){
      Node* xroot=findParent(one);
      Node* yroot=findParent(two);
      double ratio=(two->val)*value/one->val;
      for (auto it = m.begin(); it != m.end(); it ++)
            if (findParent(it -> second) == xroot)
                it -> second -> val *= ratio;
      xroot->parent=yroot;
    }


vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    vector<double> result;
    //choose one string as the base, and calculate all string's value
    unordered_map<string,Node*> m;
        for (int i = 0; i < equations.size(); i ++) {
            string s1 = equations[i].first, s2 = equations[i].second;
            if (m.count(s1) == 0 && m.count(s2) == 0) {
                m[s1] = new Node();
                m[s2] = new Node();
                m[s1] -> val = values[i];
                m[s2] -> val = 1;
                m[s1] -> parent = m[s2];
            } else if (m.count(s1) == 0) {
                m[s1] = new Node();
                m[s1] -> val = m[s2] -> val * values[i];
                m[s1] -> parent = m[s2];
            } else if (m.count(s2) == 0) {
                m[s2] = new Node();
                m[s2] -> val = m[s1] -> val / values[i];
                m[s2] -> parent = m[s1];
            } else {
                Union(m[s1], m[s2], values[i], m);
            }
        }
    for(auto& query:queries){
        if(m.count(query.first)==0||m.count(query.second)==0||findParent(m[query.first])!=findParent(m[query.second])){
            result.push_back(-1);
        }
        else
            result.push_back(m[query.first]->val/m[query.second]->val);
    }
    //do the calculation
    return result;

}

};


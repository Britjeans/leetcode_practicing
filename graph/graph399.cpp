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

//same algorithm as above, why this is faster should be discussed
class Solution {
    // date: 2016-09-12     location: Santa Clara City Library
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> map;
        vector<double> res;
        for (int i = 0; i < equations.size(); i ++) {
            string s1 = equations[i].first, s2 = equations[i].second;
            if (map.count(s1) == 0 && map.count(s2) == 0) {
                map[s1] = new Node();
                map[s2] = new Node();
                map[s1] -> value = values[i];
                map[s2] -> value = 1;
                map[s1] -> parent = map[s2];
            } else if (map.count(s1) == 0) {
                map[s1] = new Node();
                map[s1] -> value = map[s2] -> value * values[i];
                map[s1] -> parent = map[s2];
            } else if (map.count(s2) == 0) {
                map[s2] = new Node();
                map[s2] -> value = map[s1] -> value / values[i];
                map[s2] -> parent = map[s1];
            } else {
                unionNodes(map[s1], map[s2], values[i], map);
            }
        }

        for (auto query : queries) {
            if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
                res.push_back(-1);
            else
                res.push_back(map[query.first] -> value / map[query.second] -> value);
        }
        return res;
    }
    
private:
    struct Node {
        Node* parent;
        double value = 0.0;
        Node()  {parent = this;}
    };
    
    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        double ratio = node2 -> value * num / node1 -> value;
        for (auto it = map.begin(); it != map.end(); it ++)
            if (findParent(it -> second) == parent1)
                it -> second -> value *= ratio;
        parent1 -> parent = parent2;
    }
    
    Node* findParent(Node* node) {
        if (node -> parent == node)
            return node;
        node -> parent = findParent(node -> parent);
        return node -> parent;
    }
};


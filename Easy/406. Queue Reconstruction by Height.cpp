class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<pair<int, int>> ret;
        for (p : people) {
            ret.insert(ret.begin()+p.second, p);
        }
        return ret;
    }
    
    bool static compare(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

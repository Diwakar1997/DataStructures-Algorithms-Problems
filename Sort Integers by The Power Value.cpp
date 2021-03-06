//https://leetcode.com/problems/sort-integers-by-the-power-value/
int power[1001];
class Solution {
public:
    
    int getPower(int n) {
        if(n == 1)
            return 0;
        if(n & 1) {
            return 1 + getPower(3*n + 1);
        }
        else {
            return 1 + getPower(n/2);
        }
    }
    
    bool static comp(int &a, int &b) {
        if(power[a] == power[b])
            return a <= b;
        return power[a] <= power[b];
    }
    
    int getKth(int lo, int hi, int k) {
      power[0] = 0;
        power[1] = 0;
        vector<int> vec;
        for(int i = lo; i <= hi; i++) {
            power[i] = getPower(i);
            vec.push_back(i);
        }
        sort(vec.begin(), vec.end(), comp);
        
        return vec[k-1];
    }
};
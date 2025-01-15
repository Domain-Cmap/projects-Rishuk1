class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        int sidx = 0, pidx = 0;
        int staridx = -1, stmpidx = -1;

        while (sidx < slen) {
            
            if (pidx < plen && (s[sidx] == p[pidx] || p[pidx] == '?')) {
                sidx++;
                pidx++;
            }
            
            else if (pidx < plen && p[pidx] == '*') {
                staridx = pidx;
                stmpidx = sidx;
                pidx++;
            }
            
            else if (staridx != -1) {
                pidx = staridx + 1;
                stmpidx++;
                sidx = stmpidx;
            }
            
            else {
                return false;
            }
        }

        
        while (pidx < plen && p[pidx] == '*') {
            pidx++;
        }

        return pidx == plen;
    }
};
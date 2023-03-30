class Solution {
public:
    long long f(string s,char temp){
        long long first = 0, second = 0, comb = 0, res = 0;
    for (char ch : s)
        if (ch == temp) {
            comb += first * second;
            res += comb;
            second = 0;
            ++first;
        }
        else
            ++second;
    return res;
}
    long long numberOfWays(string s) {
        return f(s,'0') + f(s,'1');
    }
};
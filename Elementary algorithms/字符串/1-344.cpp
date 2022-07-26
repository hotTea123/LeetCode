#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        while(i < j){
            if(s[i] != s[j])
                swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
};

int main(){
    Solution sovle;
    vector<char> s = {'h','e','l','l','o'};
    sovle.reverseString(s);
    return 0;
}
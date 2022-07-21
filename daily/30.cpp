#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

/* **********
 * 算法思想：438题的进阶版，将单个字符改为单词，思路完全由一样，就是要多一个循环，改为用map存储每种
 单词出现次数
 * words[i].length=k，words.length=m，s.length=n
 * 时间复杂度O(k*(n-m)*m), 空间复杂度O(m*n)
 * **********/


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLen = s.size(), l = words[0].size(), wordsLen = words.size()*l;
        if(sLen < wordsLen)
            return {};
        vector<int> res;
        map<string, int> count;
        int differ, i, j;
        string sub;


        for(int t = 0;t < l;t++){
            //t表示轮次，共重复k次
            count.clear();
            //初始化s和words，O(mlogm)
            for(i = 0;i < words.size();i++)
                count[words[i]]--;
            for(j = t;j < t+wordsLen;j += l){
                sub = s.substr(j, l);
                count[sub]++;
            }
            differ = 0;
            //O(m)
            for(auto& n:count ){
                differ += abs(n.second);
            }

            //(n-m)*m
            for(i = t;i < sLen - wordsLen;i += l){
                if(differ == 0)
                    res.emplace_back(i);

                //删除第i个元素开始的那个单词
                sub = s.substr(i, l);   //O(m)
                count[sub]--;   //O(logk)
                if(count[sub] >= 0)    
                    differ--;
                else   
                    differ++;
                
                //添加第i+wordsLen开始的那个单词
                sub = s.substr(i+wordsLen, l);
                count[sub]++;
                if(count[sub] <= 0)
                    differ--;
                else   
                    differ++;
            }
            //最后要再判断一次！！！
            if(differ == 0)
                res.emplace_back(i);
        }    
        return res;
    }
};


int main(){
    // string s = "wordgoodgoodgoodbestword";
    // vector<string> words = {"word","good","best","word"};

    // string s = "barfoofoobarthefoobarman";
    // vector<string> words = {"bar","foo","the"};

    string s = "abarfoofoobarfoo";
    vector<string> words = {"foo","bar"};

    Solution solve;
    vector<int> res = solve.findSubstring(s, words);
    return 0;
}
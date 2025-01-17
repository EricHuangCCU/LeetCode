//解題思路：使用slicing window，設定好起點，並將出現的字元放進charMap中，
//如果發現字元重複且位於窗口中，就更新start位置，每次迴圈都會更新maxLen，更新最大長度
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxLen = 0, start = 0;

         for(int end=0; end<s.size(); end++){
            char currChar = s[end];

            if(charMap.find(currChar) != charMap.end() && charMap[currChar] >= start){
                start = charMap[currChar] + 1;
            }

            charMap[currChar] = end;
            maxLen = max(maxLen, end - start + 1);
         }
         return maxLen;
    }
};
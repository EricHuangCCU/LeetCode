//解題思路1：遍歷所有vector內元素，找出相加剛好為target的值
#include<vector>
#include<unordered_map>
using namespace std; 

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> sol ;

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    sol.push_back(i);
                    sol.push_back(j);
                    break;
                }
            }
        }

        return sol;
    }
};

//解題思路2：使用hash table快速查找
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hash_table;

        for(int i=0; i<nums.size(); i++){
            int restNum = target - nums[i];
            if(hash_table.find(restNum)!= hash_table.end()){
                return {i, hash_table[restNum]};
            }
            hash_table[nums[i]] = i;
        }

        return {};
    }
};
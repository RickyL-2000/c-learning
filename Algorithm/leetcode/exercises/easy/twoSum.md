# 两数之和

## my solution 1    (19/7/8)

time: 288 ms

memory: 9.1 mb

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int i, j;
            for (i = 0; i < nums.size()-1; ++i) {
                for (j = i+1; j < nums.size(); ++j) {
                    if (nums[i]+nums[j]==target) {
                        return {i,j};  //为什么要返回{}？
                    }
                }
            }
            return {i,j}; //不明白这里的return除了语法正确外有何意义
        }
    };

想出的最简单的暴力方法，本来还想先用快排把容器排个序再查找的，但是感觉不会简单到哪里去。


## reference solution 1    <unordered map>

time: 16 ms

memory:

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> ump;
            for (int i = 0; i < nums.size(); ++i) {
                ump[nums[i]] = i;
            }
            for (int i = 0; i < nums.size(); ++i) {
                int t = target - nums[i];
                if (ump.find(t) != ump.end() && i != ump[t]) {
                    return {i, ump[t]};
                }
            }
            return {};
        }
    };


## reference solution 2    <hash map>

一遍哈希表

time: 00 ms (???)

memory:


    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> n_map;
            vector<int> result(2,-1);
            /*
            for (int i = 0; i < nums.size(); ++i) {
                n_map.insert(make_pair(nums[i],i));
            }
            */
            for (int i = 0; i < nums.size(); ++i) {
                if (n_map.count(target - nums[i]) > 0) {
                    result[0] = n_map[target - nums[i]];
                    result[1] = i;
                    break;
                }
                n_map[nums[i]] = i; 
                // 用这种方式 insert map，既方便又快捷，就不需要一开始用一个多余的循环建立map了
            }
            return result;
        }
    };
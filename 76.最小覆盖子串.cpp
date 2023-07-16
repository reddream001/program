/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (43.89%)
 * Likes:    1822
 * Dislikes: 0
 * Total Accepted:    272.4K
 * Total Submissions: 619.6K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        for(char c:t)
        need[c]++;
        int left=0,right=0,vaild=0;
        //记录最小覆盖子串的起始索引及其长度
        int start=0,len=INT_MAX;
        while(right<s.size())
        {
            //记录移入窗口的字符
            char c=s[right];
            //右移窗口
            right++;
            //更新滑动窗口内的数据
            if(need.count(c))
            {
                window[c]++;
                if(window[c]==need[c])
                vaild++;
            }
            //判断是否窗口已经包含T所含所有字符
            while(vaild==need.size())
            {
                //更新最小覆盖子串
                if(right-left<len)
                {
                    start=left;
                    len=right-left;
                }
                //记录移除窗口的数据
                char d=s[left];
                left++;
                //更新移除左边界后的滑动窗口
                if(need.count(d))
                {
                    if(window[d]==need[d])
                    vaild--;
                    window[d]--;
                }
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};
// @lc code=end


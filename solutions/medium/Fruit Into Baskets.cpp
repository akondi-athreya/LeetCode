// Title: Fruit Into Baskets
            // Difficulty: Medium
            // Language: C++
            // Link: https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> mp;
        int i = 0, j = 0;

        int count = 0;
        while(j < n) {
            mp[fruits[j]]++;

            if(mp.size() <= 2) {
                count = max(count, j-i+1);
            }
            else {
                mp[fruits[i]]--;
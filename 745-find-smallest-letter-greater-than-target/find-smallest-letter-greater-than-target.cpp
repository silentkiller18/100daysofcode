class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto letter=upper_bound(letters.begin(),letters.end(),target);
        if(letter==letters.end())return letters[0];

        return *letter;
    }
};
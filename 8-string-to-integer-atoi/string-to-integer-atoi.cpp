#include<bits/stdc++.h>
class Solution {
public:
    int myAtoi(string str) {
            long long res = 0; 
        int i = 0, gt = 1;

        while (str[i] == ' ')
            i++;

        if (str[i] == '-' || str[i] == '+') {
            if (i < str.length() && isdigit(str[i + 1])) {
                if (str[i] == '-')
                    gt = -1;
            } else
                return 0;
            i++;
        } else if (!isdigit(str[i]))
            return 0;


        for (; i < str.length() && isdigit(str[i]); i++) {
            int val = str[i] - '0';
            res = res * 10 + val;
           
            if ((res * gt) > INT32_MAX)
                return INT32_MAX;
            if ((res * gt) < INT32_MIN)
                return INT32_MIN;
        }
        return (long) res * gt;
    }
};
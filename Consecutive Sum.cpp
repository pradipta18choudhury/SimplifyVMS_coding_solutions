/***********
Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

Example 1:

Input: 5
Output: 2
Explanation: 5 = 5 = 2 + 3
Example 2:

Input: 9
Output: 3
Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
Example 3:

Input: 15
Output: 4
Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
***********/


int sum(int num)
{
 int  k = 1;
      int res = 0;
      
      while(num >= k) {
        num -= k - 1;
        if(num % k++ == 0)  res++;
      }
      return res-1; 
}

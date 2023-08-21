Ques.

Maximum Score of Array
Accuracy: 25.8%Submissions: 10K+Points: 35
Given an array "arr" of positive integers with length N, your goal is to achieve the maximum possible score by removing elements from either the beginning or the end of the array. The score for removing an element is calculated as:

Score = element * length(arr) + minimum(arr)

Here, "arr" is considered before the current operation, and you can choose to remove elements from the start or end of the array.
"element" represents the value of the removed element. 

Example 1:

Input:
N = 2
arr = {1, 2}
Output: 7
Explanation: A possilbe way to perform the operations
-> remove first element, 
score = 1*length({1,2}) + min({1,2}) = 3
updated arr = {2}

-> remove last element 
score = 2*length({2}) + min({2}) = 4

-> total score = 3 + 4 = 7 

Example 2:

Input:
N = 3
arr = {2,3,4}
Output: 26
Explanation: A possilbe way to perform the operations
-> remove 4 from last, 
score = 4*length({2,3,4})+min({2,3,4}) = 14
updated arr = {2,3}

-> remove 2 from start, 
score = 2*length({2,3})+min({2,3}) = 6
updated arr = {3}

-> remove last element 3, 
score = 3*length({3})+min({3}) = 6

-> total score = 14 + 6 + 6 = 26   

Your Task: 
You don't need to read input or print anything. Complete the function MaxScore(), which takes integer N and an array of integers arr as input parameters and returns the maximum score you can get after performing all operations.


Constraints:
1 <= N <= 103 
1 <= arr[i] <= 109


Ans.

class Solution{
    Map<Integer,Boolean> mp= new TreeMap<>();
    public long MaxScore(int N, int arr[])
    {
        int n= arr.length-1;
        long dp[][]= new long [n+1][n+1];
        for(long []a: dp)
            Arrays.fill(a, -1);
        return solve(0, n, arr, dp);
    }
    public long solve(int f, int b, int []arr, long [][]dp)
    {
        if(b<f) return 0;
        if(dp[f][b]!=-1) return dp[f][b];
        long min= mi(f, b, arr);
        long p1= (long)arr[f]*(long)(b-f+1) + min + solve(f+1, b, arr, dp);
        long p2= (long)arr[b]*(long)(b-f+1) + min + solve(f, b-1, arr, dp);
        return dp[f][b]= Math.max(p1,p2);
    }
    public long mi(int f, int b, int []arr)
    {
        long min=Long.MAX_VALUE;
        for(int i=f; i<=b; i++)
        {
            min=Math.min(min,(long)arr[i]);
        }
        return min;
    }
}

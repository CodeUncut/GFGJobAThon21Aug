Ques.
  
Unleashing the Array's Potential
Accuracy: 23.9%Submissions: 24K+Points: 25
Given an array arr[ ] consisting of n integers, find the maximum Geek Value of the array to unleash its true potential. 

Geek value is defined as (arri - arrj) × arrk, where 1 ≤ i < j < k ≤ n.

 

Please note that if the Geek Value turns out to be negative, return 0 as the answer. 

Example 1:

Input :
n = 3
arr = {4,2,3}
Output:
6
Explanation:
We choose i=1,j=2,k=3 indices {one based indexing}
Geek value of array is (arr[i]-arr[j])*arr[k] = (4-2)*3 = 6.
Example 2:

Input :
n = 5
arr = {10,1,4,2,7}
Output:
63  
Explanation:
Take indices i=1,j=2 and k=5 {one based indexing} 
Geek value = (arr[1]−arr[2])×arr[5] = 63.
Your Task:

You don't need to read input or print anything. Your task is to complete the function maxValue() which takes an integer n, and an integer array arr[] as input parameters and returns an integer respresenting maximum Geek Value of the array. Return 0 if the Geek Value of array turns out to be negative.

Constraints:

3 <= n <= 105
1 <= arr[i] <= 109

Ans.
class Solution
{
    public:
    long long maxValue(int n, int arr[])
    {
        // code here
        long long int ans=0;
        vector<int> a(n,0);
        int mx=0;
        for(int i=0;i<n;i++) {
            a[i]=mx-arr[i];
            mx=max(mx,arr[i]);
        }
        mx=0;
        for(int i=0;i<n;i++) {
            long long int val = mx;
            val*=(long long int)(arr[i]);
            ans=max(ans,val);
            mx=max(mx,a[i]);
        }
        return ans;
    }
};

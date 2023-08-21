Ques.

Geek's Journey
Accuracy: 11.84%Submissions: 3K+Points: 40
You're provided with two arrays:

"geeksTown" of length n - representing the heights of buildings in Geek's town
"journey" of length m      - representing the heights of buildings he sees during his train journey.
Geek finds happiness when he encounters a series of buildings during his journey that completely match with geeksTown.

You have 'q' queries of the form [l, r], where you need to determine how many times Geek will feel happy during the journey  from [l, r].

Example 1:

Input:
n = 4,
geeksTown[] = {3, 0, 1, 9},
m = 11,
journey[] = {1, 3, 0, 1, 9, 1, 7, 3, 0, 1, 9},
q = 4,
queries[] = [
 [0, 3],
 [1, 5],
 [1, 10],
 [7, 9]
]
Output:
0 1 2 0
Explanation:


The pattern of GeekTown is repeated 0 times in query 1 i.e. [0, 3]
The pattern of GeekTown is repeated 1 times in query 2 i.e. [1, 5]
The pattern of GeekTown is repeated 2 times in query 3 i.e. [1, 10]
The pattern of GeekTown is repeated 0 times in query 4 i.e. [7, 9]
 

Example 2:

Input:
n = 2,
geeksTown[] = {2, 2},
m = 6,
journey[] = {2, 2, 2, 2, 2, 2},
q = 3,
queries[] = [
[0, 2],
[1, 4],
[0, 5]
]
Output:
2 3 5
Explanation:


The pattern of GeekTown is repeated 2 times in query 1 i.e. [0, 2]
The pattern of GeekTown is repeated 3 times in query 2 i.e. [1, 4]
The pattern of GeekTown is repeated 5 times in query 3 i.e. [0, 5]
Your Task:
You don't need to read input or print anything. Your task is to complete the function geeksJourney() which takes an integer array geeksTown[], an integer n , an integer array journey[], an integer m, a 2D integer array queries[][] and an integer q representing length of queries as input parameters and returns an array of length q where each element is respresenting the answer for each query.

 
Answer:

class Solution
{
    public:
    vector<int> geeksJourney(vector<int>& geeksTown, int n, 
                             vector<int>& journey, int m, 
                             vector<vector<int>>& queries, int q)
    {
         vector<int> result;
        vector<pair<int, int>> subarrayIndices; // To store the indices of geeksTown subarrays

        for (int i = 0; i <= m - n; ++i) {
            bool match = true;
            for (int j = 0; j < n; ++j) {
                if (geeksTown[j] != journey[i + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                subarrayIndices.push_back(make_pair(i, i + n - 1));
            }
        }

        for (int i = 0; i < q; ++i) {
            int left = queries[i][0];
            int right = queries[i][1];
            int count = 0;

            for (const auto& indices : subarrayIndices) {
                if (indices.first >= left && indices.second <= right) {
                    ++count;
                }
            }

            result.push_back(count);
        }

        return result;
    } 
};

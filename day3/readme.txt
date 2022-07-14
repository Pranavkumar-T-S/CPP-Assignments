Day 3 :
Topic:
Pointer 
Smart Pointers
Shared Pointer
Unique Pointer

Assignment:
A city has many buildings, which are arranged in a matrix order of size N * M. Some buildings are empty some have a family living in it. we can denote these buildings as a N * M matrix with number of person in a family as values, empty building will be denoted with zero. Each family in the building plans to form a group, a group can be only formed with adjacent neighbours vertically or horizontally.
 
Given an input matrix of size N * M. Have to find the number of groups that can be formed and the members count in each group. Write a function that will return an array with group members count and number of groups formed.
The group with more members will take leadership, so write 
another function to find the leader group.
 
Sample Input 1:
 
Matrix :  [ 0,    2,         0,         3,        1,
            4,    1,         2,         0,         0,
            2,    0,         0,         0,         0,
            0,    1,         0,         2,         3
            0,    0,         1,         1,         0]
 
Sample Output: [11, 4, 1, 7]
 		     Leader group : 11

Note:
1. Do not use STL (like, vector, map etc..)
2. Use dynamic memory allocation for arrays.
3. The program should exit without memory leaks.
Explanation:   
            
0,         2,         0,         3,         1,   
4,         1,         2,         0,         0,
2,         0,         0,         0,         0,
0,         1,         0,         2,         3
0,         0,         1,         1,         0
 
In the above matrix, the groups formed are {2, 4, 1, 2, 2}, {3, 1}, {1}, {2, 3, 1, 1}. Summing up the family members we get total members of a group as output.
 Thus the output is, [11, 4, 1, 7]
			Leader group : 11.
 
Optional :
The leader group need to take control of all other groups, so it need to find a path to other groups. Have to find the shortest distance between leader and other groups. 
 
Sample Output: [1, 1, 2].
 
Explanation:
0,         2_____________________ 3,         1,       
4,         1,         2,         0,         0,
2,         |,          | ,         0,         0,
0,        1,         | ,         2,          3
0,         0,         1,         1,         0
 
As denoted above, if a leader group is denoted as {11}. Thus, the distances found are
{11} to {4} is 1
{11} to {1} is 1
{11} to {7} is 2

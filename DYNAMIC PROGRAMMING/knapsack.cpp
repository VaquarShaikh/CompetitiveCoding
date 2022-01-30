#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007


// simple recursive (2^n) time complexity.
// int knapsack(int* weights, int* values, int n, int maxWeight){
// 	if(n == 0 || maxWeight == 0){
// 		return 0;
// 	}
// 	if(weights[0] > maxWeight){
// 		return knapsack(weights + 1,values + 1,n - 1,maxWeight);
// 	}
// 	int op1 = values[0] + knapsack(weights + 1,values + 1,n - 1,maxWeight - weights[0]);
// 	int op2 = knapsack(weights + 1,values + 1,n - 1,maxWeight);
// 	return max(op1,op2);
// }

// //memoization n^2 time complexity.
// int knapsackhelper(int* weights, int* values, int n, int maxWeight,int** output){
//     //base case
//     if(n == 0 || maxWeight == 0){
//         return 0;
//     }
//     if(weights[0] > maxWeight){
//         return knapsackhelper(weights+1,values+1,n-1,maxWeight,output);
//     }
//     if(output[n][maxWeight] != INT_MIN){
//         return output[n][maxWeight];
//     }
//     int op1 = knapsackhelper(weights+1,values+1,n-1,maxWeight - weights[0],output) + values[0];
//     int op2 = knapsackhelper(weights+1,values+1,n-1,maxWeight,output);
//     output[n][maxWeight] = max(op1,op2);
//     return output[n][maxWeight];

// }
// int knapsack(int* weights, int* values, int n, int maxWeight){
//     int** output = new int*[n+1];
//     for(int i = 0; i <= n; i++) {
//         output[i] = new int[maxWeight+1];
//         for(int j = 0; j <= maxWeight; j++) {
//             output[i][j] = INT_MIN;
//         }
//     }
//     return knapsackhelper(weights,values,n,maxWeight,output);
// }

//dynamic programming n^2 time , o(maxweight) space complexity.

int knapsack(int* weights, int* values, int n, int maxWeight){
	int dp[maxWeight + 1] = {0};
	for(int i = 0;i <= n;i++){
		for(int j = maxWeight;j >= weights[i];j--){
			dp[j] = max(dp[j],values[i] + dp[j - weights[i]]);
		}
	}
	return dp[maxWeight];
}

int main() {
	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;
}
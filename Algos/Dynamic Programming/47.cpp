// CPP Program to Number of ways to insert a 
// character to increase LCS by one 
#include<iostream>
#include<vector>
#define MAX 256 
using namespace std; 

// Return the Number of ways to insert a 
// character to increase the Longest 
// Common Subsequence by one 
int numberofways(string A, string B, int N, int M) 
{ 
	vector<int> pos[MAX]; 

	// Insert all positions of all characters 
	// in string B. 
	for (int i = 0; i < M; i++) 
		pos[B[i]].push_back(i + 1); 

	// Longest Common Subsequence 
	int dpl[N + 2][M + 2]; 
	memset(dpl, 0, sizeof(dpl)); 
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= M; j++) { 
			if (A[i - 1] == B[j - 1]) 
				dpl[i][j] = dpl[i - 1][j - 1] + 1; 
			else
				dpl[i][j] = max(dpl[i - 1][j], 
								dpl[i][j - 1]); 
		} 
	} 
	int LCS = dpl[N][M]; 

	// Longest Common Subsequence from reverse 
	int dpr[N + 2][M + 2]; 
	memset(dpr, 0, sizeof(dpr)); 
	for (int i = N; i >= 1; i--) { 
		for (int j = M; j >= 1; j--) { 
			if (A[i - 1] == B[j - 1]) 
				dpr[i][j] = dpr[i + 1][j + 1] + 1; 
			else
				dpr[i][j] = max(dpr[i + 1][j], 
								dpr[i][j + 1]); 
		} 
	} 

	// inserting character between position 
	// i and i+1 
	int ans = 0; 
	for (int i = 0; i <= N; i++) { 
		for (int j = 0; j < MAX; j++) { 
			for (auto x : pos[j]) { 
				if (dpl[i][x - 1] + dpr[i + 1][x + 1] == LCS) { 
					ans++; 
					break; 
				} 
			} 
		} 
	} 

	return ans; 
} 

// Driver Program 
int main() 
{ 
	string A = "aa", B = "babab"; 
	int N = A.length(), M = B.length(); 
	cout << numberofways(A, B, N, M) << endl; 
	return 0; 
} 

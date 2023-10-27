#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool isPrime(int n){
	if (n <= 1)
		return false;

	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;

	return true;
}

bool perfectSquare(int x) {
	int sr = sqrt(x);

	if (sr * sr == x) {
		return true;
	}
	else
		return false;
}

//time complexity: O(n^2) + O(n)(log(n) = O(n^2) :(((
vector<pair<int, int>> bigButtz(int num) {
	vector<pair<int, int>> result;
	vector<int>myVec;
	int m, n = 0;

	//o(n^2)
	for (int i = 2; i < num; i++) {
		if (isPrime(i) == true) {
			myVec.push_back(i);
		}
	}

	//o(n)*log(n) = nlog(n)
	for (int i = myVec.size() - 1; i >= 0; i--) {
		m = myVec[i]; //prime num vec
		n = sqrt(num - pow(m, 2));
		if ((perfectSquare(num - pow(m, 2)) == true) && m > n) {
			//binary search... since its sorted, only need to search end - i since m > n
			if (binary_search(myVec.begin(), myVec.end() - i, myVec[i])) {
				result.push_back(make_pair(myVec[i], n));
			}
		}
	}
	return result;
}

int main() {
	vector<pair<int, int>> result;
	result = bigButtz(237133);
	for (int i = 0; i < result.size(); i++){
		cout << result[i].first << ", " << result[i].second << endl;
	}
}

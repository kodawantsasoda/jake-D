#include <iostream>
#include <vector>
using namespace std;

bool perfectSquare(int x) {
	int sr = sqrt(x);

	if (sr * sr == x) {
		return true;
	}
	else
		return false;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

vector<pair<int, int>> bigButtz(int num) {
	vector<pair<int, int>> result;
	vector<int>myVec;
	int m, n, limit = 0;

	//o(n)
	for (int i = 2; i < num; i++) {
		m = i;
		n = sqrt(num - pow(m, 2));
		if (i == 2) {
			limit = num - pow(m, 2);
		}
		if (perfectSquare(num - pow(m, 2)) == true && m < n && gcd(m,n) == 1) {
			result.push_back(make_pair(n, m)); //reverse since n will be bigger for a while
		}
		if (i == limit) {
			break;
		}
	}
	return result;
}

int main() {
	vector<pair<int, int>> result;
	result = bigButtz(237133);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].first << ", " << result[i].second << endl;
	}
}

#include <bits/stdc++.h>

using namespace std;

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		vector<int> alphabet(26, 0);
		// get the frequency of every letter present
		for (int i = 0; i < (int) s.size(); i++) {
			alphabet[s[i] - 'a']++;
		}
		// store the values which are greater than 0 in a new vector
		vector<int> distinct;
		for (auto x : alphabet) {
			if (x > 0) {
				distinct.emplace_back(x);
			}
		}
		bool checker1 = true;
		// sort in increasing order
		sort(distinct.begin(), distinct.end());
		// do the typical fibonacci algorithm
		// f[i] = f[i - 1] + f[i - 2], all numbers in the vector must be in this format
		for (int i = 2; i < (int) distinct.size(); i++) {
			if (distinct[i] != distinct[i - 1] + distinct[i - 2]) {
				checker1 = false;
				break;
			}
		}
		// critical line of the code
		// swap the first and second digit because if the vector looks like (1, 2, 3, 4)
		// clearly, 4 != 3 + 2, but if you swap the first and second digit
		// the vector would now be (2, 1, 3, 4)
		// now, 4 == 3 + 1
		Swap(distinct[0], distinct[1]);
		bool checker2 = true;
		for (int i = 2; i < (int) distinct.size(); i++) {
			if (distinct[i] != distinct[i - 1] + distinct[i - 2]) {
				checker2 = false;
				break;
			}
		}
		cout << (checker1 || checker2 ? "Dynamic" : "Not") << '\n';
	}
	return 0;
}

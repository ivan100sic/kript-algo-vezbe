#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: <input-file> <key-file>\n";
		return 1;
	}

	string s = readfile(argv[1]);
	vector<int> p = read_permutation(argv[2]);

	if (!is_permutation(p)) {
		cout << "The key is invalid\n";
		return 2;
	}

	cout << transposition_encode(strip(s), p) << '\n';
}
#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "<input fajl>";
		return 0;
	}

	string s = strip(readfile(argv[1]));

	map<string, vector<int>> pos;

	for (int k=1; k<=12; k++) {
		cout << k << '\t' << coincidence_index_avg(s, k) << '\n';
	}
}
#include <bits/stdc++.h>
#include "common.h"
using namespace std;

pair<int, int> nadji_ab(set<int> ulaz, set<int> izlaz) {
	pair<int, int> ret(-1, -1);
	for (int a=0; a<26; a++) {
		for (int b=0; b<26; b++) {
			set<int> s;
			for (int x : ulaz) {
				s.insert((x * a + b) % 26);
			}
			if (s == izlaz) {
				ret = {a, b};
			}			
		}
	}
	return ret;
}

int main(int argc, char** argv) {

	if (argc < 2) {
		cerr << "<input fajl>\n";
		return 1;
	}

	string s = readfile(argv[1]);

	if (s.size() <= 1) {
		cerr << "Input fajl previse kratak\n";
		return 2;
	}

	// trazimo najcesci bigram
	vector<int> fr(26, 0);

	for (char x : s) {
		int v = kod(x);
		if (v >= 0) {
			fr[v]++;
		}
	}

	vector<pair<int, int>> f2;
	for (int i=0; i<26; i++) {
		f2.push_back({fr[i], i});
	}
	sort(f2.begin(), f2.end(), greater<pair<int, int>>());

	set<int> naj5;
	for (int i=0; i<5; i++) {
		naj5.insert(f2[i].second);
	}

	// a = 0, e = 4, i = 8, o = 14, n = 13
	auto p = nadji_ab(naj5, {0, 4, 8, 13, 14});
	
	cout << afina_sifra(s, p.first, p.second);
}
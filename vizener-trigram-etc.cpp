#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "<input fajl>";
		return 0;
	}

	string s = readfile(argv[1]);

	map<string, vector<int>> pos;

	for (size_t i=0; i<=s.size()-3; i++) {
		string podstr = s.substr(i, 3);
		for (char& x : podstr) {
			x = toupper(x);
		}
		pos[podstr].push_back(i);
	}

	for (auto& p : pos) {

		// preskacemo one koji se ne javljaju bar 2 puta
		// i koji sadrze nesto sto nije slovo
		if (p.second.size() < 2) {
			continue;
		}

		if (kod(p.first[0]) < 0 || kod(p.first[1]) < 0 || kod(p.first[2]) < 0) {
			continue;
		}

		cout << p.first << ":\n";
		for (int x : p.second) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}
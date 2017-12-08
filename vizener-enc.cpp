#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		cerr << "<input fajl> <kljuc>";
		return 1;
	}

	string s = readfile(argv[1]);
	string key = argv[2];

	vector<int> v;

	// proveri kljuc
	for (char x : key) {
		if (kod(x) == -1) {
			cerr << "Kljuc mora da se sastoji samo iz slova!\n";
			return 2;
		}
	}

	// kodiraj
	cout << vizener(s, key);
}
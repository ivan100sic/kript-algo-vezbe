#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Usage: <input-file>\n";
		return 1;
	}

	string s = readfile(argv[1]);

	vector<int> pojav(26, 0);

	for (char x : s) {
		if (kod(x) >= 0) {
			pojav[kod(x)]++;
		}
	}

	int h = max_element(pojav.begin(), pojav.end()) - pojav.begin();

	cout << cezarova_sifra(s, 26 - h);
}
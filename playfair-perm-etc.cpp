#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: <input-file> <key>\n";
		return 1;
	}

	string s = readfile(argv[1]);
	string key = argv[2];

	sort(key.begin(), key.end());
	key.resize(unique(key.begin(), key.end()) - key.begin());

	do {
		string q = playfair_desifruj(s, key);

		vector<int> fr(26, 0);
		for (char x : q) {
			if (kod(x) != -1) {
				fr[kod(x)]++;
			}
		}

		if (fr[kod('A')] <= 2*fr[kod('Z')] || fr[kod('E')] <= 3*fr[kod('Q')]
		 || fr[kod('I')] <= 1.5 * fr[kod('B')] || fr[kod('O')] <= 1.5 * fr[kod('V')])
		{
			continue;			
		}

		cout << q << '\n';

	} while (next_permutation(key.begin(), key.end()));
}
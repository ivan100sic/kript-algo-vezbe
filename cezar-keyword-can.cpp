#include <bits/stdc++.h>
#include "common.h"
using namespace std;

string solve(string tekst, string keyword) {
	int solution = 0;

	for (int offset=0; offset<26; offset++) {
		string tmp = cezarova_sifra(tekst, offset);
		if (tmp.find(keyword) != string::npos) {
			solution = offset;
		}
	}

	return cezarova_sifra(tekst, solution);
}

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "./a <input file> <keyword>\n";
		return 1;
	}

	cout << solve(readfile(argv[1]), argv[2]);
	
	return 0;
}

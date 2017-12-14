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

	cout << str_to_upper(playfair_sifra(s, key));
}
#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: <input-file> <key>\n";
		return 1;
	}

	string s = readfile(argv[1]);
	int k = atoi(argv[2]);

	cout << cezarova_sifra(s, k);
}
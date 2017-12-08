#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 4) {
		cout << "<input file> <a> <b>\n";
		return 1;
	}

	string tekst = readfile(argv[1]);
	int a = atoi(argv[2]);
	int b = atoi(argv[3]);

	int ai = inv26(a);

	if (ai == -1) {
		cerr << "a nije invertibilan\n";
		return 2;
	}

	int bi = ((- ai * b) % 26 + 26) % 26;

	cout << afina_sifra(tekst, ai, bi);
}
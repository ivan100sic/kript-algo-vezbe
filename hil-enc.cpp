#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: <input-file> <key>\n";
		return 1;
	}

	string s = readfile(argv[1]);
	string k = argv[2];

	int m = 1;

	// jeste kvadrat
	while (m*m < (int)k.size()) {
		m++;
	}

	if (m*m != (int)k.size()) {
		cerr << "Duzina kljuca nije potpun kvadrat\n";
		return 2;
	}

	if (k != strip(k)) {
		cerr << "Kljuc sadrzi ne-slova\n";
		return 3;
	}

	vector<vector<int>> mat(m, vector<int>(m, 0));
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			mat[i][j] = kod(k[m*i+j]);
		}
	}

	// ispitaj da li je invertibilna
	int d = determinanta_26(mat);

	if (gcd(d, 26) != 1) {
		cerr << "Matrica nije invertibilna\n";
		return 4;
	}

	s = strip(s);

	while (s.size() % m) {
		s += 'X';
	}

	string rezultat;

	for (size_t i=0; i<s.size(); i+=m) {
		// blok
		vector<int> vec(m);
		for (int j=0; j<m; j++) {
			vec[j] = kod(s[i+j]);
		}

		// pomnozi sa matricom
		vector<int> prod(m, 0);

		for (int red=0; red<m; red++) {
			for (int kol=0; kol<m; kol++) {
				prod[red]/*[0]*/ += mat[red][kol] * vec[kol]/*[0]*/;
			}
		}

		for (int j=0; j<m; j++) {
			rezultat += primeni('A', prod[j] % 26);
		}
	}

	cout << rezultat << '\n';
}
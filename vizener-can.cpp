#include <bits/stdc++.h>
#include "common.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Usage: <input-file>\n";
		return 1;
	}

	string s = readfile(argv[1]);

	int k = kasiski_test(s);

	if (k == 1) {
		cout << "Key length test inconclusive (1)...\n";
		return 2;
	}

	double cp = coincidence_index_avg(s, k-1);
	double c = coincidence_index_avg(s, k);
	double cn = coincidence_index_avg(s, k+1);

	if (!(c > cp && c > cn)) {
		cout << "Key length test inconclusive (2)...\n";
		return 2;
	}

	auto tr = raspleti(s, k);

	for (size_t i=1; i<k; i++) {
		int best_rot = 0;
		double best_ci = -1;

		for (int j=0; j<26; j++) {
			string b = cezarova_sifra(tr[i], j);
			double ci = coincidence_index_cross(tr[0], b);
			if (ci > best_ci) {
				best_ci = ci;
				best_rot = j;
			}
		}

		tr[i] = cezarova_sifra(tr[i], best_rot);
	}

	// spoji sve u jedno i uradi cezar-can

	string z = zapleti(tr);

	cout << cezar_auto_a(z);
}
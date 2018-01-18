#include <bits/stdc++.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Usage: <input-file>\n";
		return 1;
	}

	string s = readfile(argv[1]);

	cout << transposition_auto(s);
}
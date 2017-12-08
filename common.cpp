#include "common.h"
using namespace std;

int kod(char x) {
	if ('a' <= x && x <= 'z') {
		return x - 'a';
	}
	if ('A' <= x && x <= 'Z') {
		return x - 'A';
	}
	return -1;
}

char primeni(char x, int k) {
	if (kod(x) == -1) {
		return x;
	}
	if ('a' <= x && x <= 'z') {
		return 'a' + k;
	}
	if ('A' <= x && x <= 'Z') {
		return 'A' + k;
	}
}

string readfile(string path) {
	if (path == "-") {
		char x;
		string r;
		while (1) {
			int z = cin.get();
			if (z == -1) {
				break;
			}
			r += (char)z;
		}
		return r;
	} else {
		ifstream f(path, ios::binary);
		char x;
		string r;
		while (1) {
			int z = f.get();
			if (z == -1) {
				break;
			}
			r += (char)z;
		}
		return r;
	}
}

string cezarova_sifra(string s, int k) {
	for (char& x : s) {
		x = primeni(x, (kod(x) + k) % 26);
	}
	return s;
}

string afina_sifra(string s, int a, int b) {
	for (char& x : s) {
		x = primeni(x, (kod(x)*a + b) % 26);
	}
	return s;
}

int inv26(int a) {
	for (int x=0; x<26; x++) {
		if (a*x % 26 == 1) {
			return x;
		}
	}
	return -1;
}

string vizener(string s, string kljuc) {
	size_t k = kljuc.size();
	int i = 0;
	for (char& x : s) {
		x = primeni(x, (kod(x) + kod(kljuc[i % k])) % 26);
		i++;
	}
	return s;
}

string strip(string s) {
	string p;
	for (char x : s) {
		if (kod(x) >= 0) {
			p += x;
		}
	}
	return p;
}
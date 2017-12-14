#include "common.h"
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

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

string cezar_auto_a(string s) {
	vector<int> pojav(26, 0);

	for (char x : s) {
		if (kod(x) >= 0) {
			pojav[kod(x)]++;
		}
	}

	int h = max_element(pojav.begin(), pojav.end()) - pojav.begin();

	return cezarova_sifra(s, 26 - h);
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

double coincidence_index(string s) {
	// samo slova
	vector<int> a(26, 0);
	int sum = 0;

	for (char x : s) {
		int y = kod(x);
		a[y]++;
		sum++;
	}

	double tot = 0.0;

	for (int i=0; i<26; i++) {
		tot += (double)a[i] * a[i];
	}

	return tot / sum / sum;
}

vector<string> raspleti(string s, int k) {
	vector<string> a(k);
	for (size_t i=0; i<s.size(); i++) {
		a[i % k] += s[i];
	}

	return a;
}

string zapleti(vector<string> a) {
	string s;
	size_t i = 0, j = 0;
	while (1) {
		if (j == a[i].size()) {
			return s;
		}
		s += a[i][j];
		i++;
		if (i == a.size()) {
			i = 0;
			j++;
		}
	}
}

double coincidence_index_avg(string s, int k) {
	auto a = raspleti(s, k);
	double avg = 0;
	for (string& p : a) {
		avg += coincidence_index(p);
	}
	return avg / k;
}

int kasiski_test(string s) {

	map<vector<int>, vector<int>> pos;

	for (size_t i=0; i<=s.size()-3; i++) {
		string podstr = s.substr(i, 3);
		vector<int> kv(3);
		bool bad = false;
		for (int j=0; j<3; j++) {
			kv[j] = kod(podstr[j]);
			if (kv[j] == -1) {
				bad = true;
			}
		}
		if (!bad) {
			pos[kv].push_back(i);
		}
	}

	vector<int> raz;

	for (auto& p : pos) {
		for (size_t j=1; j<p.second.size(); j++) {
			int d = p.second[j] - p.second[0];
			raz.push_back(d);
		}
	}

	// nadji najveci g koji deli vise od pola svih razlika
	for (int g = s.size(); g > 0; g--) {
		int br = 0;
		for (int x : raz) {
			if (x % g == 0) {
				br++;
			}
		}
		if (2*br > (int)raz.size()) {
			return g;
		}
	}

	return 1;
}

double coincidence_index_cross(string a, string b) {
	a = strip(a);
	b = strip(b);
	vector<int> fa(26, 0), fb(26, 0);

	for (char x : a) {
		fa[kod(x)]++;
	}

	for (char x : b) {
		fb[kod(x)]++;
	}

	double r = 0.0;
	for (int i=0; i<26; i++) {
		r += fa[i] * 1.0 * fb[i];
	}
	return r / a.size() / b.size();
}


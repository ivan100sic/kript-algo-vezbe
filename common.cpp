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
	if ('a' <= x && x <= 'z') {
		return 'a' + k;
	}
	if ('A' <= x && x <= 'Z') {
		return 'A' + k;
	}
	return x;
}

string readfile(string path) {
	if (path == "-") {
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

string str_to_upper(string s) {
	for (char& x : s) {
		x = toupper(x);
	}
	return s;
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

vector<vector<int>> playfair_matrix(string key) {
	vector<vector<int>> a(5, vector<int>(5, -1));
	vector<bool> used(26, false);
	int i = 0, j = 0;

	auto m_append = [&a, &used, &i, &j](char x) {
		int y = kod(x);
		if (y == kod('W')) {
			y = kod('V');
		}
		if (!used[y]) {
			used[y] = true;
			a[i][j] = y;
			j++;
			if (j == 5) {
				j = 0;
				i++;
			}
		}
	};

	for (char x : key) {
		m_append(x);
	}

	for (char x='a'; x<='z'; x++) {
		m_append(x);
	}

	return a;
}

string playfair_preprocess(string s) {
	// zameni W -> V
	for (char& x : s) {
		if (kod(x) == kod('W')) {
			x = 'V';
		}
	}

	string b;
	for (char slovo : s) {
		if (b.size() && kod(b.back()) == kod(slovo)) {
			if (kod(slovo) == kod('X')) {
				b += 'Q';
			} else {
				b += 'X';
			}
		}
		b += slovo;
	}

	if (b.size() % 2) {
		if (kod(b.back()) == kod('X')) {
			b += 'Q';
		} else {
			b += 'X';
		}
	}

	return b;
}

string playfair_digram(vector<vector<int>>& mat, string a, int smer) {
	int i1=-1, j1=-1, i2=-1, j2=-1;

	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			if (mat[i][j] == kod(a[0])) {
				i1 = i;
				j1 = j;
			}
			if (mat[i][j] == kod(a[1])) {
				i2 = i;
				j2 = j;
			}
		}
	}

	// sanity checks
	if (i1 == -1 || j2 == -1) {
		return a;
	}

	if (i1 == i2 && j1 == j2) {
		return a;
	}

	if (i1 == i2) {
		// isti red, shiftuj kolone
		j1 = (j1 + smer + 5) % 5;
		j2 = (j2 + smer + 5) % 5;
	} else if (j1 == j2) {
		// ista kolona, shiftuj redove
		i1 = (i1 + smer + 5) % 5;
		i2 = (i2 + smer + 5) % 5;
	} else {
		// nije ni jedno ni drugo, swapuj kolone
		int t = j2;
		j2 = j1;
		j1 = t;
	}

	a[0] = primeni(a[0], mat[i1][j1]);
	a[1] = primeni(a[1], mat[i2][j2]);

	return a;
}

string playfair_sifra(string s, string key) {
	s = playfair_preprocess(strip(s));
	key = strip(key);

	auto mat = playfair_matrix(key);

	for (size_t i=0; i<s.size(); i+=2) {
		string q = playfair_digram(mat, s.substr(i, 2), 1);
		s[i] = q[0];
		s[i+1] = q[1];
	}

	return s;
}

string playfair_desifruj(string s, string key) {
	key = strip(key);

	auto mat = playfair_matrix(key);

	for (size_t i=0; i<s.size(); i+=2) {
		string q = playfair_digram(mat, s.substr(i, 2), -1);
		s[i] = q[0];
		s[i+1] = q[1];
	}

	return s;
}

vector<vector<int>> mminor(const vector<vector<int>>& mat, int r, int c) {
	int n = mat.size();

	vector<vector<int>> rez;

	for (int i=0; i<n; i++) {
		if (i != r) {
			vector<int> red;
			for (int j=0; j<n; j++) {
				if (j != c) {
					red.push_back(mat[i][j]);
				}
			}
			rez.push_back(red);
		}
	}

	return rez;
}

int determinanta_26(vector<vector<int>> mat) {
	int n = mat.size();

	if (n == 1) {
		return mat[0][0] % 26;
	}

	int zn = 1, r = 0;
	for (int i=0; i<n; i++) {
		r += determinanta_26(mminor(mat, 0, i)) * zn * mat[0][i];
		zn = 26 - zn;
	}

	return r % 26;
}

vector<vector<int>> mat_inverz_26(vector<vector<int>> mat) {
	vector<vector<int>> b = mat;
	int n = mat.size();

	if (n == 1) {
		b[0][0] = inv26(mat[0][0]);
		return b;
	}

	int dinv = inv26(determinanta_26(mat));

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			b[i][j] = ((i+j) % 2 ? 25 : 1) * 
				determinanta_26(mminor(mat, j, i)) *
				dinv % 26;
		}
	}

	return b;
}

vector<int> read_permutation(string fn) {
	ifstream ifs(fn);

	int n;
	ifs >> n;

	vector<int> p(n);
	for (int i=0; i<n; i++) {
		ifs >> p[i];
		p[i]--;
	}

	return p;
}

bool is_permutation(vector<int> p) {
	vector<int> c(p.size(), 0);
	for (int x : p) {
		if (x < 0 || x >= (int)p.size()) {
			return false;
		}
		if (c[x]++) {
			return false;
		}
	}
	return true;
}

string transposition_encode(string s, vector<int> p) {
	int k = p.size();
	while (s.size() % k) {
		s += 'X';
	}
	int b = s.size() / k;

	string rez = s;

	for (int i=0; i<(int)s.size(); i++) {
		int r = i / k;
		int c = i % k;

		int r2 = p[c];
		int c2 = r;

		rez[r2*b + c2] = s[i];
	}

	return rez;
}

vector<string> bigrami() {
	return {
		"AK", "AN", "AS", "AT", "AV", "CI",
		"DA", "ED", "EN", "IC", "IJ", "IN",
		"IS", "JA", "JE", "KA", "KO", "LI",
		"NA", "NE", "NI", "NO", "OD", "OJ",
		"OS", "OV", "PO", "PR", "RA", "RE",
		"RI", "ST", "TA", "TI", "VA", "ZA"
	};
}

string transposition_auto(string s) {
	auto bg_v = bigrami();
	set<string> bg(bg_v.begin(), bg_v.end());

	const int KEY_LEN_LIMIT = 12;

	int naj_skor = 0;
	string naj;

	auto bigram_skor = [&](string s) {
		int r = 0;
		for (size_t i=1; i<s.size(); i++) {
			r += bg.count(s.substr(i-1, 2));
		}
		return r;
	};

	// za svaku mogucu duzinu kljuca
	for (int k=2; k < (int)s.size() && k < KEY_LEN_LIMIT; k++) {
		// ako deli
		if (s.size() % k == 0) {
			// napravimo kolone
			vector<string> v(k);

			for (int i=0; i < (int)s.size(); i++) {
				v[i / (s.size() / k)] += s[i];
			}

			// napravimo matricu spajanja

			vector<vector<int>> mat(k, vector<int>(k, 0));

			for (int i=0; i<k; i++) {
				for (int j=0; j<k; j++) {
					if (i == j) {
						continue;
					}

					for (int f=0; f < (int)s.size()/k; f++) {
						mat[i][j] += bg.count(string() + v[i][f] + v[j][f]);
					}
				}
			}

			// matrica je tu samo za ukras

			/*

			cerr << "k " << k << '\n';
			for (string s : v) {
				cerr << s << '\n';
			}
			for (int i=0; i<k; i++) {
				for (int j=0; j<k; j++) {
					cerr << mat[i][j] << ' ';
				}
				cerr << '\n';
			}

			*/

			vector<int> perm(k);

			iota(perm.begin(), perm.end(), 0);

			do {
				string tmp;

				for (int i=0; i<(int)s.size() / k; i++) {
					for (int j=0; j<k; j++) {
						tmp += v[perm[j]][i];
					}
				}

				int tmp_skor = bigram_skor(tmp);

				// cerr << "string: " << tmp << '\n';
				// cerr << "skor " << k << ' ' << tmp_skor << '\n';

				if (tmp_skor > naj_skor) {
					naj_skor = tmp_skor;
					naj = tmp;
				}
			} while (next_permutation(perm.begin(), perm.end()));
		}
	}

	return naj;
}

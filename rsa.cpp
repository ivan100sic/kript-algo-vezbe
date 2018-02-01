#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
using namespace std;

typedef long long ll;

bool prost(ll x) {
	if (x < 2) {
		return false;
	}

	for (ll i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

// a, b >= 0
ll egcd(ll a, ll b, ll& x, ll&y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll g, x1, y1;
	g = egcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

default_random_engine eng { random_device{}() };
// vraca random broj sa tacno bn bitova
ll random_broj(ll bn) {
	uniform_int_distribution<ll> uid(1ll << (bn - 1), (1ll << bn) - 1);
	return uid(eng);
}

ll random_prost(ll bn) {
	while (1) {
		ll p = random_broj(bn);
		if (prost(p)) {
			return p;
		}
	}
}

ll random_uzajamno_prost(ll m) {
	while (1) {
		ll x = random_broj(60) % m;
		if (gcd(m, x) == 1) {
			return x;
		}
	}
}

ll mod_inv(ll a, ll m) {
	ll x, y;
	egcd(a, m, x, y);
	return (x % m + m) % m;
}

ll mod_exp(ll a, ll b, ll m) {
	if (b == 0) {
		return 1;
	}

	ll r = mod_exp(a, b / 2, m);
	r = r * r % m;
	if (b % 2) {
		r = r * a % m;
	}
	return r;
}

ll rsa_enc(ll n, ll e, ll x) {
	return mod_exp(x, e, n);
}

ll rsa_dec(ll n, ll d, ll x) {
	return mod_exp(x, d, n);
}

void test() {
	ll x, y;
	egcd(140, 89, x, y);
	cout << x << ' ' << y << '\n';

	cout << mod_inv(3, 1000) << '\n';
}

int main() {

	// test();

	int bn;
	cout << "Broj bitova za p [5-14]: ";
	cin >> bn;
	// q ima 3 bita vise
	ll p = random_prost(bn);
	ll q = random_prost(bn + 3);
	ll n = p * q;

	ll phi = (p - 1) * (q - 1);
	ll e = random_uzajamno_prost(phi);
	ll d = mod_inv(e, phi);

	cout << "Javni kljuc: " << n << ' ' << e << '\n';
	cout << "Tajni kljuc: " << d << '\n';
	cout << "Prosti faktori: " << p << ' ' << q << '\n';

	cout << "Unesi poruku za enkripciju, broj iz [0, n): ";
	ll msg;
	cin >> msg;

	cout << "Sifrirana poruka je: " << rsa_enc(n, e, msg) << '\n';

	cout << "Unesi poruku za dekripciju, broj iz [0, n): ";
	ll cyph;
	cin >> cyph;

	cout << "Desifrovana poruka je: " << rsa_dec(n, d, cyph) << '\n';

	getchar(); getchar(); getchar();
}

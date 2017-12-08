#include <bits/stdc++.h>
using namespace std;

/*
	Za dati karakter nalazi njegov numericki kod, ili ako nije slovo
	onda vraca -1. Vraca kod samo za mala i velika engleska slova.
*/
int kod(char x);

/*
	Za dato slovo x i kod k primenjuje kod k na to slovo i vraca rezultat.
	Ako slovo x nije malo ili veliko slovo engleskog alfabeta, vraca se x.
	U suprotnom vraca se malo/veliko slovo ciji je kod k, u zavisnosti od
	toga da li je x malo ili veliko slovo
*/
char primeni(char x, int k);

/*
	Cita celokupan sadrzaj fajla na putanji path u string koji vraca. Ukoliko
	fajl ne postoji vraca prazan string. Fajl se cita u binarnom obliku, tj.
	bajt po bajt. Funkcija nije optimizovana za brzinu! Ukoliko je dati fajl "-",
	cita do kraja standardnog ulaza - korisno za pipeove. Nije 100% byte-safe!
*/
string readfile(string path);

/*
	Primenjuje Cezarovu sifru sa pomakom k.
*/
string cezarova_sifra(string s, int k);

/*
	Primenjuje afinu sifru y = ax+b
*/
string afina_sifra(string s, int a, int b);

/*
	Inverz broja po modulu 26 ili -1 ako ne postoji.
*/
int inv26(int a);

/*
	Primenjuje Vizenerovu sifru. Kljuc mora biti validan!
*/
string vizener(string s, string kljuc);

/*
	Brise sve sto nije slovo iz stringa s
*/
string strip(string s);

/*
	Trazi indeks koincidencije za dati string s.
	Preskace sve sto nisu slova.
*/
double coincidence_index(string s);

/*
	Trazi prosecan indeks koincidencije za sve podstringove koji
	nastaju razvezivanjem datog stringa na k delova
*/
double coincidence_index_avg(string s, int k);
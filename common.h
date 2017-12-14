#include <bits/stdc++.h>
using namespace std;

/*
	Vraca nzd dva broja.
*/
int gcd(int a, int b);

/*
	Za dati karakter nalazi njegov numericki kod, ili ako nije slovo
	onda vraca -1. Vraca kod samo za mala i velika engleska slova.
*/
int kod(char x);

/*
	Za dato slovo x i kod k primenjuje kod k na to slovo i vraca rezultat.
	Ako slovo x nije malo ili veliko slovo engleskog alfabeta, vraca se x.
	U suprotnom vraca se malo/veliko slovo ciji je kod k, u zavisnosti od
	toga da li je x malo ili veliko slovo.
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
	Konvertuje ceo string u uppercase.
*/
string str_to_upper(string s);

/*
	Primenjuje Cezarovu sifru sa pomakom k.
*/
string cezarova_sifra(string s, int k);

/*
	Pokusava da resi cezarovu sifru tako sto pretpostavi da je A najcesce slovo.
*/
string cezar_auto_a(string s);

/*
	Primenjuje afinu sifru y = ax+b.
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
	Brise sve sto nije slovo iz stringa s.
*/
string strip(string s);

/*
	Trazi indeks koincidencije za dati string s.
	Preskace sve sto nisu slova.
*/
double coincidence_index(string s);

/*
	Vraca k stringova, gde i-ti string sadrzi sva slova i po modulu k.
*/
vector<string> raspleti(string s, int k);

/*
	Inverzna operacija od raspleti.
*/
string zapleti(vector<string> a);

/*
	Trazi prosecan indeks koincidencije za sve podstringove koji
	nastaju razvezivanjem datog stringa na k delova.
*/
double coincidence_index_avg(string s, int k);

/*
	Vraca guess za duzinu kljuca kod Vizenerove sifre.
*/
int kasiski_test(string s);

/*
	Vraca medjusobni indeks koincidencije izmedju dva stringa.
*/
double coincidence_index_cross(string a, string b);

/*
	Vraca matricu za Playfair sifru generisanu datim kljucem.
*/
vector<vector<int>> playfair_matrix(string key);

/*
	Od datog stringa vraca string koji je prilagodjen za upotrebu kod
	Playfair sifre.
*/
string playfair_preprocess(string s);

/*
	Kodira jedan Playfair digram. Ako ne uspe vraca dati string.
	Ne preporucuje se zvati direktno ovu funkciju.
*/
string playfair_digram(vector<vector<int>>& mat, string a, int smer);

/*
	Sifrira dati string datim kljucem pomocu Playfair sifre.
*/
string playfair_sifra(string s, string key);
/* Algoritma Kriptografi Vigenere Cipher
Rumus enkripsi vigenere cipher :
Pi = (Ci-Ki) mod 26
atau
Ci = ( Pi + Ki ) – 26, kalau hasil penjumlahan Pi dan Ki lebih dari 26

Rumus dekripsi vigenere cipher :
Pi = (Ci-Ki) mod 26
atau
Pi = ( Ci – Ki ) + 26, kalau hasil pengurangan Ci dengan Ki minus

Keterangan:
Ci = nilai desimal karakter ciphertext ke-i
Pi = nilai desimal karakter plaintext ke-i
Ki = nilai desimal karakter kunci ke-i

Nilai desimal karakter: A=0 B=1 C=2 ... Z=25
*/

#include <iostream>
#include <string>


using namespace std;

class Vigenere {
	public:
	string key;
	
	Vigenere(string key) //kunci vigerence
	{
		for(int i = 0; i < key.size();++i)
		{
			if (key[i] >= 'A' && key [i] <= 'Z')
				this->key += key [i];
			else if (key[i] >= 'a' && key[i] <= 'z')
				this->key += key [i] + 'A' - 'a';
		}
	}
	
	string enkrip(string text) //enkripsi vigerence
	{
		string out;
		for (int i = 0, j = 0; i < text.length(); ++i)
		{
			char c = text[i];
			if (c >= 'a' && c<= 'z')
				c += 'A' - 'a';
			else if ( c < 'A' || c> 'Z')
				continue;
			out += (c +key[j] -2 * 'A') %26 +'A';
			j = (j +1) % key.length();
		}
		return out;
	}
	
	string dekrip(string text) //dekripsi vigerence
	{
		string out;
		for (int i = 0, j = 0; i < text.length(); ++i)
		{
			char c = text[i];
			if (c >= 'a' && c<= 'z')
				c += 'A' - 'a';
			else if ( c < 'A' || c> 'Z')
				continue;
			out += (c - key[j] +26 ) %26 +'A';
			j = (j +1) % key.length();
		}
		return out;
	}
};

int main()
{
	int pilihan;
	string str, kunci;
	
	cout << "Masukan Plantaxt: ";
	cin >> str;
	cout << "Masukan Key: ";
	cin >> kunci;
	cout << "\n =================================\n";
	cout << "| 1. Enkripsi                     |\n";
	cout << "| 2. Dekripsi                     |\n";
	cout << " =================================\n";
	cout << " Masukan Pilihan: "; cin >> pilihan;
	
	string original=str;
	Vigenere chiper=kunci;
	string encrypted = chiper.enkrip(original);	
	string decrypted = chiper.dekrip(original);

	switch(pilihan){
		//Enkripsi
		case 1:
		cout << " Plantaxt: " << original <<endl;
		cout<<" Enkripsi: " <<encrypted <<endl;

		break;
		
		//Dekripsi
		case 2:
		cout << " Ciphertext: "<< original <<endl;
		cout<<" Dekripsi: " <<decrypted <<endl;
		
		break;
		
		default:
		cout << "\nMasukan Pilihan yang Benar!!!\n";
	}
	return 0;
}

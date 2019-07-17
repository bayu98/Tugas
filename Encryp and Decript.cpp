/* enkripsi dengan memgabungkan vegenere cipher dengan ceaser cipher
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
	int pilihan, i;
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
	string enc=encrypted;
	string dec = original;
	string decrypted = chiper.dekrip(original);
	
	switch(pilihan){
		//Enkripsi
		case 1:
		for (i=0; (i<100 && enc[i] != '\0'); i++){ //penambahan enkripsi ceaser cipher
			enc[i] = enc[i] + 8524;
		}
		cout << " Plantaxt: " << original <<endl;
		cout<<" Enkripsi: " <<enc <<endl;

		break;
		
		//Dekripsi
		case 2:
		for (i=0; (i<100 && dec[i] != '\0'); i++){
			dec[i] = dec[i] - 8524;
		}
		cout << " Ciphertext: "<< original <<endl;
		cout<<" Dekripsi: " <<dec <<endl;
		
		break;
		
		default:
		cout << "\nMasukan Pilihan yang Benar!!!\n";
	}
	return 0;
}

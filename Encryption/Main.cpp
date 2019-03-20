#include<iostream>
#include<string>

using namespace std;

#define ull unsigned long long 

string XOR(string, string);
string BCH(string);
string decToBin(ull);
string strToBin(string, bool, bool);

// a1 and a2 should be binary
string XOR(string a1, string a2)
{
	int size = a1.size() < a2.size() ? a1.size() : a2.size();
	string res = "";

	for (size_t i = 1; i <= size; i++)
	{
		char next = (a1[a1.size() - i] - '0' + a2[a2.size() - i] - '0' == 1) ? '1' : '0';
		res = next + res;
	}

	// TODO: Substring the fron excess part of the 
	//		 larger string to the front of res string

	return res;
}

// Binary Coded Hexadecimal
string BCH(string hexadec) { // TODO: Must convert all chars toUpperCase
	string res = "";

	for (size_t i = 0; i < hexadec.size(); i++)
	{
		string charBin = decToBin((hexadec[i] > '9') ? hexadec[i] - 'A' + 10 : hexadec[i] - '0');

		int initialPadding = 4 - charBin.size();

		while (initialPadding--)
		{
			charBin = "0" + charBin;
		}

		res += charBin;
	}

	return res;
}

string decToBin(ull dec) {
	int bin;

	string charBin = "";

	while (dec > 0)
	{
		bin = dec % 2;
		charBin = to_string(bin) + charBin;
		dec /= 2;
	}

	return charBin;
}

string toUpper(string str) {
	for (string::iterator i = str.begin(); i != str.end(); i++)
	{
		if ((*i) >= 'a' && (*i) <= 'z')
		{
			(*i) -= ('a' - 'A');
		}
	}
	return str;
}

string strToBin(string message, bool isSpaced, bool withInitialPadding) {
	string res = "";

	for (size_t i = 0; i < message.size(); i++)
	{
		ull decMessage = (ull)message[i];

		string charBin = decToBin(decMessage);

		int initialPadding = 8 - charBin.size();

		while (initialPadding-- && withInitialPadding)
		{
			charBin = "0" + charBin;
		}

		res += charBin;
		res += (message.size() - 1 == i || !isSpaced) ? "" : " ";
	}

	return res;
}

string runThroughTable(string input, int arr[], int size) {
	string res = "";

	for (size_t i = 0; i < size; i++)
	{
		res += input[arr[i] - 1];
	}

	return res;
}

string shiftLeft(string input, int shiftValue) {
	string res = input.substr(shiftValue);

	for (size_t i = 0; i < shiftValue; i++)
	{
		char c = input[i];
		res.push_back(c);
	}

	return res;
}

int main() {

	// Initialized message and key values
	string message = toUpper("0123456789ABCDEF");	 // In HEX. Pass through toUpper to make sure all in caps
	string key = toUpper("133457799BBCDFF1");	 // In HEX. Pass through toUpper to make sure all in caps

	// Converted HEX values to binary values
	string binMessage = BCH(message);
	string binKey = BCH(key);

	cout << binMessage << endl;
	cout << binKey << endl;

	// TODO: if message is larger than 64bit divide them into 64bit parts

	/// Key generation
	// Initialized PC-1 and PC-2 table
	int pc1[] = { 57, 49, 41, 33, 25, 17,  9,
				   1, 58, 50, 42, 34, 26, 18,
				  10,  2, 59, 51, 43, 35, 27,
				  19, 11,  3, 60, 52, 44, 36,
				  63, 55, 47, 39, 31, 23, 15,
				   7, 62, 54, 46, 38, 30, 22,
				  14,  6, 61, 53, 45, 37, 29,
				  21, 13,  5, 28, 20, 12,  4 };

	int pc2[] = { 14, 17, 11, 24, 1,   5,
				  3, 28, 15,  6,  21, 10,
				 23, 19, 12,  4,  26,  8,
				 16,  7, 27, 20,  13,  2,
				 41, 52, 31, 37,  47, 55,
				 30, 40, 51, 45,  33, 48,
				 44, 49, 39, 56,  34, 53,
				 46, 42, 50, 36,  29, 32 };


	// Run the binary key through PC-1 table to get permuted 56bit key
	string permutedKey56 = runThroughTable(binKey, pc1, 56);

	// Initialized arrays for C and D parts of the round keys
	string C[17];
	string D[17];

	// Initialized array of final subkeys
	string K[16];

	// Splited the key into left and right halves, where each half has 28 bits.
	C[0] = permutedKey56.substr(0, 28);
	D[0] = permutedKey56.substr(28, 28);

	// Initialized left-shift table
	int leftShifts[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

	// Shifting the C and D parts to left to get other subkeys
	for (size_t i = 1; i < 17; i++)
	{
		C[i] = shiftLeft(C[i - 1], leftShifts[i - 1]);
		D[i] = shiftLeft(D[i - 1], leftShifts[i - 1]);

		// Run the concatenated C and D parts through PC-2 table to get final subkeys
		K[i - 1] = runThroughTable(C[i] + D[i], pc2, 48);
	}

	cout << endl;

	system("pause");
	return 0;
}
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

int main() {
	//string message = "133457799BBCDFF1"; //This is an incredibly confidential message!

	//cout << "Plain text (original message): " << message << endl;

	//std::cout << strToBin(message, true, true) << std::endl;

	//cout << (int)'A' << endl;

	cout << BCH("133457799BBCDFF1") << endl;

	system("pause");

	return 0;
}
#pragma once

#include "Core.h"

class Utils
{
public:
	// A1 and B2 should be in binary
	static string OR(string a1, string a2)
	{
		string larger = a1.size() >= a2.size() ? a1 : a2;
		string smaller = a1.size() < a2.size() ? a1 : a2;


		string res = "";

		for (int i = 1; i <= larger.size(); i++)
		{
			char next = '0';
			if (i > smaller.size())
			{
				next = (larger[larger.size() - i] - '0' >= 1) ? '1' : '0';
				res = next + res;
				continue;
			}
			next = (larger[larger.size() - i] - '0' + smaller[smaller.size() - i] - '0' >= 1) ? '1' : '0';
			res = next + res;
		}

		return res;
	}

	// A1 and B2 should be in binary
	static string XOR(string a1, string a2)
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

	// Binary Coded Hexadecimal - returns binary of hex number
	static string BCH(string hexadec) { // TODO: Must convert all chars toUpperCase
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

	static string decToBin(ull dec) {
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

	static string toUpper(string str) {
		for (string::iterator i = str.begin(); i != str.end(); i++)
		{
			if ((*i) >= 'a' && (*i) <= 'z')
			{
				(*i) -= ('a' - 'A');
			}
		}
		return str;
	}

	static string strToBin(string message) {
		string res = "";

		for (size_t i = 0; i < message.size(); i++)
		{
			ull decMessage = (ull)message[i];

			string charBin = decToBin(decMessage);

			int initialPadding = 8 - charBin.size();

			while (initialPadding--)
			{
				charBin = "0" + charBin;
			}

			res += charBin;
		}

		return res;
	}

	static int binToDec(string input) {
		int dec = 0;
		for (int i = input.size() - 1, j = 0; i >= 0; i--, j++)
		{
			dec += (input[i] - '0') * pow(2, j);
		}

		return dec;
	}

	static string binToHex(string bin) {
		string res = "";
		for (size_t i = 0; i < bin.size() / 4; i++)
		{
			int decNum = binToDec(bin.substr(i * 4, 4));
			string hexNum = (decNum < 10) ? to_string(decNum) : string(1, decNum - 10 + 'A');
			res += hexNum;
		}

		return res;
	}

	static string stringToHex(string str) {
		string bin = strToBin(str);
		string hex = binToHex(bin);
		return hex;
	}

	static string hexToString(string hex) {
		int len = hex.length();
		std::string newString;
		for (int i = 0; i < len; i += 2)
		{
			string byte = hex.substr(i, 2);
			char chr = (char)(int)strtol(byte.c_str(), NULL, 16);
			newString.push_back(chr);
		}
		return newString;
	}

};

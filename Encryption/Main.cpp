#include<iostream>
#include<string>

#define ull unsigned long long 

std::string decToBin(ull dec) {
	int bin;

	std::string charBin = "";

	while (dec > 0)
	{
		bin = dec % 2;
		charBin = std::to_string(bin) + charBin;
		dec /= 2;
	}

	return charBin;
}

std::string strToBin(std::string message, bool isSpaced, bool isInitialPadding) {
	std::string res = "";

	for (size_t i = 0; i < message.size(); i++)
	{
		ull decMessage = (ull)message[i];

		std::string charBin = decToBin(decMessage);

		int initialPadding = 8 - charBin.size();

		while (initialPadding-- && isInitialPadding)
		{
			charBin = "0" + charBin;
		}

		res += charBin;
		res += (message.size() - 1 == i || !isSpaced) ? "" : " ";
	}

	return res;
}

int main() {
	std::string message = "133457799BBCDFF1"; //This is an incredibly confidential message!
	std::cout << "Plain text (original message): " << message << std::endl;
	//std::cout << strToBin(message, true, true) << std::endl;
	
	std::cout << decToBin(1383827165325090800) << std::endl;


	system("pause");

	return 0;
}
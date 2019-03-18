#include<iostream>
#include<string>


std::string strToBin(std::string message) {
	int bin;

	std::string res = "";

	for (size_t i = 0; i < message.size(); i++)
	{
		int decMessage = (int)message[i];

		std::string charBin = "";

		while (decMessage > 0)
		{
			bin = decMessage % 2;
			charBin = std::to_string(bin) + charBin;
			decMessage /= 2;
		}

		int initialPadding = 8 - charBin.size();

		while (initialPadding--)
		{
			charBin = "0" + charBin;
		}

		res += charBin;
		res += (message.size() - 1 == i) ? "" : " ";
	}

	return res;
}

int main() {

	std::string message = "This is an incredibly confidential message!"; //This is an incredibly confidential message!

	std::cout << "Plain text (original message): " << message << std::endl;

	std::cout << strToBin(message) << std::endl;

	std::cout << std::endl;

	system("pause");

	return 0;
}
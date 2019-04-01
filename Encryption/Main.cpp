#include "Core.h"
#include "DES.h"

int main() {
	string message = "Incredible sentence from DummyTeam";
	string key = "SuperKey";

	// TODO: Make it available for both upper and lover case

	// Initialized message and key values
	string messageHex = Utils::toUpper(DES::formatMessage(message));	 // In HEX. Pass through toUpper to make sure all in caps
	string keyHex = Utils::toUpper(Utils::stringToHex(message));			 // In HEX. Pass through toUpper to make sure all in caps

	cout << "Encryption key: \t" << key << endl;
	cout << "Message hex: \t\t" << messageHex << endl;
	cout << "Message text: \t\t" << Utils::hexToString(messageHex) << endl;

	// Converted HEX values to binary values
	string binMessage = Utils::BCH(messageHex);
	string binKey = Utils::BCH(keyHex);

	/// Encryption
	DES* des = new DES();

	string encryptedMessageBin = des->encrypt(binMessage, binKey);
	string encryptedMessageHex = Utils::binToHex(encryptedMessageBin);

	cout << "Encrypted HEX message: \t" << encryptedMessageHex << endl;
	cout << "Encrypted message: \t" << Utils::hexToString(encryptedMessageHex) << endl << endl;

	/// Decryption
	string decryptedMessageBin = des->decrypt(encryptedMessageBin, binKey);
	string decryptedMessageHex = Utils::binToHex(decryptedMessageBin);

	cout << "Decryption key: \t" << key << endl;
	cout << "Decrypted HEX message: \t" << decryptedMessageHex << endl;
	cout << "Decrypted message: \t" << Utils::hexToString(decryptedMessageHex) << endl;

	system("pause");
	return 0;
}
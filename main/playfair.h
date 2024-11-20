#pragma once
#include <string>
#include <vector>

using namespace std;

#define SIZE 25
class Playfair
{
	string mTable[SIZE];
	string mKey;
	string mPair;
public:
	vector<string> alphabet = {
		"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
	"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
	};
	Playfair(string mKey, string mPair) {
		this->mKey = mKey;
		this->mPair = mPair;
	}
	void makeTable();	//Table ����� ����Լ�
	void showTable();	//Table ��� ��� �Լ�
	string makeEncryption(string mEncryption);
};
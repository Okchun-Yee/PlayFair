#include "playfair.h"
#include <iostream>
#include <iomanip> // std::setw ����
#include <vector>
#include <string>
#include <algorithm> // std::find

using namespace std;

void Playfair::makeTable() {
	vector<char> temp;	//key���� char������ �ڸ��� ����

	//Key�� �ߺ� �����ϰ� ������ Table �����ϱ�
	for (int i = 0; i < this->mKey.length(); i++) {
		if (find(temp.begin(), temp.end(), this->mKey[i]) == temp.end()) {
			temp.push_back(this->mKey[i]);
		}
	}
	//alphabet �迭���� key���� �ߺ�����
	for (int i = 0; i < temp.size(); i++) {
		auto index = find(alphabet.begin(), alphabet.end(), string(1, temp[i]));
		if (index != alphabet.end()) {
			alphabet.erase(index);
		}
	}
	vector <string> str;
	int cnt = 0;
	for (int i = 0; i < temp.size() + alphabet.size(); i++) {
		if (i < temp.size()) str.push_back(string(1, temp.at(i)));
		else str.push_back(alphabet.at(cnt++));
	}

	//���ĺ����� '/'�� ���е� mPair �����
	auto pos = this->mPair.find('/');  // '/'�� ��ġ�� ã��
	string pair_1, pair_2;
	if (pos != string::npos) {
		pair_1 = this->mPair.substr(0, pos);      // ù ��° �κ� (a)
		pair_2 = this->mPair.substr(pos + 1);
	}
	
	 auto index = find(str.begin(), str.end(), pair_1);
	 if (index != str.end()) {
		 index = str.erase(index);
		 str.insert(index, pair_1 + "/" + pair_2);

		 index = find(str.begin(), str.end(), pair_2);
		 str.erase(index);
		 //for (string c : str) cout << c << endl;
	 }

	//mtable ����
	cnt = 0;
	for (int i = 0; i < SIZE; i++) {
		this->mTable[i] = str[i];
	}
	//for (int i = 0; i < SIZE; i++) cout << this->mTable[i]<< " ";
}
void Playfair::showTable() {
	for (int i = 0; i < SIZE; i++) {
		if (i % 5 == 0 && i != 0) cout << endl;
		cout << setw(3) << this->mTable[i] << " ";
	}
}
string Playfair::makeEncryption(string mEncryption) {
	return "";
}
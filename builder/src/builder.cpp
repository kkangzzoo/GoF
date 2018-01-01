#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int UNDEF_SENTENCE = 0;
const int NOMAL_SENTENCE = 1;
const int INTERROGATIVE_SENTENCE = 2;
const int IMPERATIVE_SENTENCE = 3;
const int TO_ENGLISH = 1;
const int TO_JAPANESE = 2;
const int TO_FRENCH = 3;

class Sentence {
public:
	Sentence() {
		data_ = " ";
		type_ = UNDEF_SENTENCE;
	}

	int GetType() {
		return type_;
	}
	string GetString() {
		return data_;
	}

	void SetSentenceData(string s) {
		SetSentenceType(s);
		data_ = s;
	}

protected:
	void SetSentenceType(string s) {
		type_ = NOMAL_SENTENCE;
	}

private:
	string data_;
	int type_;
};

class Manual {
public:
	string GetContents() {
		return contents_;
	}
	void AddContents(string s) {
		contents_ += s;
	}

private:
	string contents_;
};

Sentence GetSentence(ifstream&);
string TransNormalSentence(string, int);
string TransInterrogativeSentence(string, int);
string TransImperativeSentence(string, int);

void DoTranslate(char* pInFile, Manual& out, int wantedLang) {
	ifstream ifs(pInFile);
	if (!ifs) {
		cout << "Can't Open File: " << pInFile << endl;
		return;
	}

	string result;
	Sentence next;

	while (!(next = GetSentence(ifs)).GetString().empty()) {
		switch (next.GetType()) {
		case NOMAL_SENTENCE:
			result = TransNormalSentence(next.GetString(), wantedLang);
			break;
		case INTERROGATIVE_SENTENCE:
			result = TransInterrogativeSentence(next.GetString(), wantedLang);
			break;
		case IMPERATIVE_SENTENCE:
			result = TransImperativeSentence(next.GetString(), wantedLang);
			break;
		default:
			cout << "Untranslatable sentence type" << endl;
			return;
		}

		out.AddContents(result);
	}
}

Sentence GetSentence(ifstream& ifs) {
	int c;
	string s;
	Sentence sentence;

	while ((c = ifs.get()) != EOF) {
		s += c;
		if (c == '?' || c == '.')
			break;
	}
	sentence.SetSentenceData(s);
	return sentence;
}

string TransNormalSentence(string s, int wantedLang) {
	string output;

	switch (wantedLang) {
	case TO_ENGLISH:
			cout<<"영어"<<endl;
			break;
		case TO_JAPANESE:
			cout<<"일본어"<<endl;
			break;
		case TO_FRENCH:
			cout<<"프랑스"<<endl;
			break;
	}
	return output;
}

string TransInterrogativeSentence(string s, int wantedLang) {
	string output;

	switch (wantedLang) {
	case TO_ENGLISH:
		cout<<"영어"<<endl;
		break;
	case TO_JAPANESE:
		cout<<"일본어"<<endl;
		break;
	case TO_FRENCH:
		cout<<"프랑스"<<endl;
		break;
	}
	return output;
}

string TransImperativeSentence(string s, int wantedLang) {
	string output;

	switch (wantedLang) {
	case TO_ENGLISH:
			cout<<"영어"<<endl;
			break;
		case TO_JAPANESE:
			cout<<"일본어"<<endl;
			break;
		case TO_FRENCH:
			cout<<"프랑스"<<endl;
			break;
	}
	return output;
}



//int main() {
//	Manual out;
//	DoTranslate("input.txt", out, TO_ENGLISH);
//	cout<<out.GetContents()<<endl;
//	return 0;
//}

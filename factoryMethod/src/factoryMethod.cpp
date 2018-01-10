//============================================================================
// Name        : factoryMethod.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Document{
public:
	virtual bool Open(char* pFileName) =0;

};

class HwpDocument : public Document{
public:
	bool Open(char* pFileName){
		ifstream ifs(pFileName);
		if(!ifs)	return false;

		cout<<"Hwp"<<endl;
		//HWP 고유 프로세싱

		return true;
	}
};

class MsWordDocument : public Document{
public:
	bool Open(char* pFileName){
		ifstream ifs(pFileName);
		if(!ifs)	return false;

		cout<<"MsWord"<<endl;
		//MsWord 고유 프로세싱

		return true;
	}
};

class Application{
public:
	void NewDocument(char* pFileName){
		Document *pDoc=CreateDocument();
		docs_[pFileName]=pDoc;
		pDoc->Open(pFileName);
	}
	virtual Document* CreateDocument()=0;

private:
	map<string, Document *> docs_;
};

class HwpApplication : public Application{
public:
	Document* CreateDocument(){
		return new HwpDocument;
	}
};

class MsWordApplication : public Application{
public:
	Document* CreateDocument(){
		return new HwpDocument;
	}
};

int main() {
	HwpApplication hwp;
	hwp.NewDocument("input.hwp");
	return 0;
}

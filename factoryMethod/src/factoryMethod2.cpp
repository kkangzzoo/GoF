//============================================================================
// Name        : factoryMethod2.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : ���ڸ� ���� ������ ��ü�� ������ ���ϴ� Factory  Method ����
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

#define UNDEF_DOCUMENT 0
#define HWP_DOCUMENT 1
#define MSWORD_DOCUMENT 2
#define ANOTHER_DOCUMENT 3

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
		//HWP ���� ���μ���

		return true;
	}
};

class MsWordDocument : public Document{
public:
	bool Open(char* pFileName){
		ifstream ifs(pFileName);
		if(!ifs)	return false;

		cout<<"MsWord"<<endl;
		//MsWord ���� ���μ���

		return true;
	}
};

class AnotherDocument : public Document{
public:
	bool Open(char* pFileName){
		ifstream ifs(pFileName);
		if(!ifs)	return false;

		cout<<"MsWord"<<endl;
		//�˸��� ���� ���μ���

		return true;
	}
};

class Application{
public:
	void NewDocument(char* pFileName){
		Document *pDoc=CreateDocument(GetDocType(pFileName));
		if(pDoc==NULL)exit(0);
		docs_[pFileName]=pDoc;
		pDoc->Open(pFileName);
	}
	virtual Document* CreateDocument(int docType){
		switch(docType){
		case HWP_DOCUMENT:
			return new HwpDocument;
		case MSWORD_DOCUMENT:
			return new MsWordDocument;
		}
	}

protected:
	int GetDocType(char *pFileName){
		char *pExt=strrchr(pFileName, '.');
		if(strcmp(pExt, ".hwp")==0)	return HWP_DOCUMENT;
		else if(strcmp(pExt,".doc")==0) return MSWORD_DOCUMENT;
		else return ANOTHER_DOCUMENT;
	}

private:
	map<string, Document *> docs_;
};

class HwpApplication : public Application{};

class MsWordApplication : public Application{};

class AnotherApplication : public Application{
public:
	Document* CreateDocument(int docType){
		if(docType==ANOTHER_DOCUMENT)	return new AnotherDocument;
		else	//�ڽ��� ������ �� ���� ��ü�� ���� Ŭ������ ������� ����
			return Application::CreateDocument(docType);
};

//int main() {
//	AnotherApplication another;
//	another.NewDocument("input.dat");
//	return 0;
//}

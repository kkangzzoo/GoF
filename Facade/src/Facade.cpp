//============================================================================
// Name        : Facade.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : Facade 패턴.
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <iterator>

using namespace std;

class SearchCond{
public:
	SearchCond(map<string, string> nvList){
		condList_=nvList;
	}

	bool CheckCond(){
		//name, value 쌍들의 리스트에 대해 검색 조건을 검사
		return true;
	}

private:
	map<string, string> condList_;
};



class ListData{
	//디비에서 검색되는 결과 레코드가 저장되기 위한 자료구조
};

class ListDBResult{
public:
	int GetCount(){
		return result_.size();
	}

	void InitIterator(){
		iter_=result_.begin();
	}

	ListData GetNextData(){
		return *iter_++;
	}

private:
	list<ListData> result_;
	list<ListData>::iterator iter_;
};


class Database{
public:
	Database(){
		//db관리 시스템과 연결 수행
	}

	bool Execute(string sql, ListDBResult& result){
		//s1l 수행 결과를 result에 설정, sql 수행 과정에서 문제 있으면 false, 아니면 true 리턴
		return true;
	}
};

class SQLGenerator{
public:
	string GenerateSQL(SearchCond cond){
		string sql;

		//sql문 생성

		return sql;
	}
};

class DBHandler{
public:
	bool Search(map<string, string> nvList, ListDBResult& result){
		SearchCond cond(nvList);
		if(!cond.CheckCond()){
			cout<<"잘못된 검색조건"<<endl;
			return false;
		}

		SQLGenerator generator;
		string sql = generator.GenerateSQL(cond);

		return db_.Execute(sql,result);
	}

private:
	Database db_;
};


int main() {
	map<string, string> nvList;
	ListDBResult result;

	DBHandler handler;
	handler.Search(nvList, result);
	return 0;
}

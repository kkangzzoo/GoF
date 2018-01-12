/*
 * observer.h
 *
 *  Created on: 2018. 1. 12.
 *      Author: daum
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>
#include "scorecard.h"
using namespace std;

#define MAX_STUDENT_NUM 10

class Subject;
class ScoreData;

class Observer{
public:
	virtual void Update()=0;
};

class BarGraph : public Observer{
public:
	BarGraph(ScoreData * pScoreData);
	void Update();
	void PrintOut();
	void ChangScore(string name, int subjectType, int score);
private:
	ScoreData* pScoreData_;
	string name_[MAX_STUDENT_NUM];
	int motherLangScore_[MAX_STUDENT_NUM];
	int englishScore_[MAX_STUDENT_NUM];
	int mathScore_[MAX_STUDENT_NUM];
};

class PieChar : public Observer{
public:
	PieChar(string student, ScoreData *pScoreData);
	void Update();
	void PrintOut();
	void ChangScore(string name, int subjectType, int score);
private:
	ScoreData* pScoreData_;
	string name_;
	int motherLangScore_;
	int englishScore_;
	int mathScore_;
};

class LineGraph : public Observer{
public:
	LineGraph(ScoreData * pScoreData);
	void Update();
	void PrintOut();
	void ChangScore(string name, int subjectType, int score);
private:
	ScoreData* pScoreData_;
	string name_[MAX_STUDENT_NUM];
	int motherLangScore_[MAX_STUDENT_NUM];
	int englishScore_[MAX_STUDENT_NUM];
	int mathScore_[MAX_STUDENT_NUM];
};


#endif /* OBSERVER_H_ */

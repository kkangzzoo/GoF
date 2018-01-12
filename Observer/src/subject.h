/*
 * subject.h
 *
 *  Created on: 2018. 1. 12.
 *      Author: daum
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <string>
#include <list>
#include "scorecard.h"

using namespace std;

class Observer;

class Subject{
public:
	virtual ~Subject()=0;
	virtual void Attach(Observer *pObj);
	virtual void Detach(Observer *pObj);
	virtual void Notify();
protected:
	list<Observer *> observers_;
};

class ScoreData:public Subject{
public:
	void AddScore(ScoreCard *pScore);
	void RemoveScore(ScoreCard *pScore);

	list<ScoreCard*> GetScoreList();
	void SetScore(string name, int subjectType, int score);

private:
	list<ScoreCard *> scoreList_;

};



#endif /* SUBJECT_H_ */

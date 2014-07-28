/****************************************************************************************************************************************************
 *  File Name   		: sortelementsbyfrequency.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\sortelementsbyfrequency.h
 *  Created on			: May 1, 2014 :: 6:42:19 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/sort-elements-by-frequency/
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <algos/utils/ds/tree/treeds.h>
#include <algos/utils/common/tree/tree.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SORTELEMENTSBYFREQUENCY_H_
#define SORTELEMENTSBYFREQUENCY_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
struct keyFrequency{
	int key;
	unsigned int frequency;

	keyFrequency(){
		frequency = 0;
	}

	keyFrequency(int key){
		this->key = key;
		this->frequency = 1;
	}

	keyFrequency(int key,unsigned int frequency){
		this->key = key;
		this->frequency = frequency;
	}
};

//Tested
bool sortByFrequency(keyFrequency *first,keyFrequency *second){
	if(first->frequency == second->frequency){
		return first->key > second->key;
	}else{
		return first->frequency > second->frequency;
	}
}

//Tested
void sortElementByFrequencyONLOGN(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	hash_map<int,keyFrequency *> frequencyMap;
	hash_map<int,keyFrequency *>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]]->frequency += 1;
		}else{
			frequencyMap[userInput[counter]] = new keyFrequency(userInput[counter]);
		}
	}
	vector<keyFrequency *> frequencyList;
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		frequencyList.push_back(itToFrequencyMap->second);
	}
	sort(frequencyList.begin(),frequencyList.end(),sortByFrequency);
	unsigned int fillCounter = 0;
	for(unsigned int counter = 0;counter < frequencyList.size();counter++){
		while(frequencyList[counter]->frequency--){
			userInput[fillCounter++] = frequencyList[counter]->key;
		}
	}
}

//Tested
void setFNodesBSTInOrder(iftNode *ptr,vector<keyFrequency *> &inorderNodes){
	if(ptr == null){
		return;
	}
	setFNodesBSTInOrder(ptr->left,inorderNodes);
	inorderNodes.push_back(new keyFrequency(ptr->value,ptr->frequency));
	setFNodesBSTInOrder(ptr->right,inorderNodes);
}

//Tested
void sortElementsByFrequencyBSTONLOGN(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	treeutils *utils = new treeutils();
	iftNode *bst = utils->getFBSTreeFromVector(userInput);
	vector<keyFrequency *> allKeysWithFrequencies;
	setFNodesBSTInOrder(bst,allKeysWithFrequencies);
	sort(allKeysWithFrequencies.begin(),allKeysWithFrequencies.end(),sortByFrequency);
	unsigned int fillCounter = 0;
	for(unsigned int counter = 0;counter < allKeysWithFrequencies.size();counter++){
		while(allKeysWithFrequencies[counter]->frequency--){
			userInput[fillCounter++] = allKeysWithFrequencies[counter]->key;
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void sortElementByFrequencyON2(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	hash_map<int,bool> visitedValues;
	hash_map<int,bool>::iterator itToVisitedValues;
	vector<keyFrequency *> frequencyList;
	unsigned int frequency;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		if((itToVisitedValues = visitedValues.find(userInput[outerCounter])) == visitedValues.end()){
			frequency = 0;
			for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
				if(userInput[outerCounter] == userInput[innerCounter]){
					frequency += 1;
				}
			}
			frequencyList.push_back(new keyFrequency(userInput[outerCounter],frequency));
			visitedValues.insert(pair<int,bool>(userInput[outerCounter],new keyFrequency(userInput[outerCounter],frequency)));
		}
	}
	sort(frequencyList.begin(),frequencyList.end(),sortByFrequency);
	unsigned int fillCounter = 0;
	for(unsigned int counter = 0;counter < frequencyList.size();counter++){
		while(frequencyList[counter]->frequency--){
			userInput[fillCounter++] = frequencyList[counter]->key;
		}
	}
}

#endif /* SORTELEMENTSBYFREQUENCY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

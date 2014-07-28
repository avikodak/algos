/****************************************************************************************************************************************************
 *  File Name   		: findduplicates.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page07\findduplicates.h
 *  Created on			: May 1, 2014 :: 7:39:52 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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

#ifndef FINDDUPLICATES_H_
#define FINDDUPLICATES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printDuplicatesON(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size()==1){
		return;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[abs(userInput[counter])] > 0){
			userInput[abs(userInput[counter])] *= -1;
		}else{
			printf("%d\t",userInput[counter]);
		}
	}
}

void printDuplicatesONHashmap(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size()==1){
		return;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second > 1){
			printf("%d\t",itToFrequencyMap->first);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void printDuplicatesONLOGNSorting(vector<int> userInput){
	if(userInput.size() == 0||userInput.size() == 1){
		return;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0;
	bool isElementDuplicate;
	while(counter < userInput.size()){
		isElementDuplicate = false;
		while(counter < userInput.size() && userInput[counter] == userInput[counter+1]){
			isElementDuplicate = true;
			counter++;
		}
		printf("%d\t",userInput[counter]);
		counter++;
	}
}

void printDuplicatesFBST(iftNode *ptr){
	if(ptr == null){
		return;
	}
	printDuplicatesFBST(ptr->left);
	if(ptr->frequency > 1){
		printf("%d\t",ptr->value);
	}
	printDuplicatesFBST(ptr->right);
}

void printDuplicatesFBSTONLOGN(vector<int> userInput){
	if(userInput.size() == 0||userInput.size() == 1){
		return;
	}
	iftNode *rootFbst;
	treeutils *utils = new treeutils();
	rootFbst = utils->getFBSTreeFromVector(userInput);
	printDuplicatesFBST(rootFbst);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void printDuplicatesON2(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int outerCrawler,innerCrawler = 0;
	bool elementFound;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		if(userInput[outerCrawler] == INT_MAX){
			continue;
		}
		elementFound = false;
		for(innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				elementFound = true;
				userInput[innerCrawler] = INT_MAX;
			}
		}
		if(elementFound){
			printf("%d\t",userInput[outerCrawler]);
		}
	}
}

#endif /* FINDDUPLICATES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

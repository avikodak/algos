/****************************************************************************************************************************************************
 *  File Name   		: majorityelement.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page09\majorityelement.h
 *  Created on			: Apr 14, 2014 :: 7:05:36 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/majority-element/
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

#ifndef MAJORITYELEMENT_H_
#define MAJORITYELEMENT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int majorityElementMorrieVotingAlgorithmON(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	unsigned int frequency = 1;
	int probableMajorityElement = userInput[0];
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] == probableMajorityElement){
			frequency++;
		}else{
			frequency--;
			if(frequency == 0){
				frequency = 1;
				probableMajorityElement = userInput[counter];
			}
		}
	}
	frequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == probableMajorityElement){
			frequency++;
		}
	}
	return frequency > userInput.size()/2?probableMajorityElement:INT_MAX;
}

//Tested
int majorityElementONAuxspace(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	unsigned int maxFrequency = 0;
	int majorityValue;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
		if(frequencyMap[userInput[counter]] > maxFrequency){
			maxFrequency = frequencyMap[userInput[counter]];
			majorityValue = userInput[counter];
		}
	}
	return maxFrequency >= userInput.size()/2?majorityValue:INT_MAX;
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int majorityElementONLOGNSorting(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0,frequency,maxFrequency = 0;
	int probableMajorityElement;
	while(counter < userInput.size()){
		frequency = 0;
		while(counter+1 < userInput.size() && userInput[counter] == userInput[counter+1]){
			counter++;
			frequency++;
		}
		if(frequency > maxFrequency){
			maxFrequency = frequency;
			probableMajorityElement = userInput[counter];
		}
		counter++;
	}
	return maxFrequency >= userInput.size()/2?probableMajorityElement:INT_MAX;
}

//Tested
int majorityElementONLOGNBinarySearch(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0;
	unsigned int frequency;
	vector<int>::iterator lowerBoundKeyElement,upperBoundKeyElement;
	while(counter < userInput.size()){
		lowerBoundKeyElement = lower_bound(userInput.begin(),userInput.end(),userInput[counter]);
		upperBoundKeyElement = upper_bound(userInput.begin(),userInput.end(),userInput[counter]);
		frequency = upperBoundKeyElement - lowerBoundKeyElement + 1;
		if(frequency >= userInput.size()/2){
			return userInput[counter];
		}
		counter += frequency;
	}
	return INT_MAX;
}

//Tested
int majorityElementONLOGNBinarySearchOptimized(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int middleIndex = userInput.size()/2;
	//Since element frequency should be  > n/2 the probable element is the middle element
	vector<int>::iterator lowerBound,upperBound;
	lowerBound = lower_bound(userInput.begin(),userInput.end(),userInput[middleIndex]);
	upperBound = upper_bound(userInput.begin(),userInput.end(),userInput[middleIndex]);
	return (unsigned)(upperBound - lowerBound + 1) >= userInput.size()/2?userInput[middleIndex]:INT_MAX;
}

//Tested
void setMaxFrequencyElement(iftNode *ptr,iftNode **maxNode){
	if(ptr == null){
		return;
	}
	setMaxFrequencyElement(ptr->left,maxNode);
	if(*maxNode == null){
		*maxNode = ptr;
	}else{
		if((*maxNode)->frequency < ptr->frequency){
			*maxNode = ptr;
		}
	}
	setMaxFrequencyElement(ptr->right,maxNode);
}

//Tested
int majorityElementONLOGNBST(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	treeutils *utils = new treeutils();
	iftNode *rootBST = null,*maxiftNode = null;
	rootBST = utils->getFBSTreeFromVector(userInput);
	setMaxFrequencyElement(rootBST,&maxiftNode);
	//return 0;
	return maxiftNode->frequency > userInput.size()/2?maxiftNode->value:INT_MAX;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int majorityElementON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	int majorityValue;
	unsigned int frequency = 0,maxFrequency = 0;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequency = 0;
		for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				frequency++;
			}
		}
		if(frequency > maxFrequency){
			maxFrequency = frequency;
			majorityValue = userInput[outerCrawler];
		}
	}
	return maxFrequency >= userInput.size()/2?majorityValue:INT_MAX;
}

#endif /* MAJORITYELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

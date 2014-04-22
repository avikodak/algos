/****************************************************************************************************************************************************
 *  File Name   		: frequencyofintinsill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page05\frequencyofintinsill.h
 *  Created on			: Apr 20, 2014 :: 6:22:51 PM
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

#ifndef FREQUENCYOFINTINSILL_H_
#define FREQUENCYOFINTINSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int frequencyOfIntInSill(sillNode *ptr,int targetValue){
	if(ptr == null){
		return 0;
	}
	return ptr->value ==  targetValue?1+frequencyOfIntInSill(ptr->next,targetValue):frequencyOfIntInSill(ptr->next,targetValue);
}

unsigned int frequencyOfIntInSillIterative(sillNode *ptr,int targetValue){
	if(ptr == null){
		return 0;
	}
	sillNode *traversalNode = ptr;
	unsigned int frequency = 0;
	while(traversalNode != null){
		if(traversalNode->value == targetValue){
			frequency++;
		}
		traversalNode = traversalNode->next;
	}
	return frequency;
}

unsigned int frequencyOfIntInSillHashmap(sillNode *ptr,int targetValue){
	if(ptr == null){
		return 0;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	sillNode *traversalNode = ptr;
	while(traversalNode != null){
		if((itToFrequencyMap = frequencyMap.find(traversalNode->value)) != frequencyMap.end()){
			frequencyMap[traversalNode->value] += 1;
		}else{
			frequencyMap.insert(pair<int,unsigned int>(traversalNode->value,1));
		}
		traversalNode = traversalNode->next;
	}
	if((itToFrequencyMap = frequencyMap.find(targetValue)) != frequencyMap.end()){
		return itToFrequencyMap->second;
	}
	return 0;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getFrequencyOfValueFromFBST(iftNode *ptr,int targetValue){
	if(ptr == null){
		return 0;
	}
	if(ptr->value == targetValue){
		return ptr->frequency;
	}
	if(ptr->value > targetValue){
		return getFrequencyOfValueFromFBST(ptr->left,targetValue);
	}else{
		return getFrequencyOfValueFromFBST(ptr->right,targetValue);
	}
}


unsigned int frequencyOfIntInSillBST(sillNode *ptr,int targetValue){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	iftNode *rootBST = utils->getFBSTFromSill(ptr);
	return getFrequencyOfValueFromFBST(rootBST,targetValue);
}

#endif /* FREQUENCYOFINTINSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

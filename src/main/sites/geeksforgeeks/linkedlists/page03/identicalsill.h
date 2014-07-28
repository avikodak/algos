/****************************************************************************************************************************************************
 *  File Name   		: identicalsill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\identicalsill.h
 *  Created on			: May 1, 2014 :: 7:47:10 PM
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

#ifndef IDENTICALSILL_H_
#define IDENTICALSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool areSillsIdentical(sillNode *firstSill,sillNode *secondSill){
	if(firstSill = null && secondSill == null){
		return true;
	}
	if(firstSill == null || secondSill == null){
		return false;
	}
	return firstSill->value == secondSill->value && areSillsIdentical(firstSill->next,secondSill->next);
}

bool areSillsIdenticalIterative(sillNode *firstSill,sillNode *secondSill){
	if(firstSill = null && secondSill == null){
		return true;
	}
	if(firstSill == null || secondSill == null){
		return false;
	}
	while(firstSill != null && secondSill != null){
		if(firstSill->value != secondSill->value){
			return false;
		}
		firstSill = firstSill->next;
		secondSill = secondSill->next;
	}
	if(firstSill != null || secondSill != null){
		return false;
	}
	return true;
}

bool areSillsIdenticalHashmap(sillNode *firstSill,sillNode *secondSill){
	if(firstSill = null && secondSill == null){
		return true;
	}
	if(firstSill == null || secondSill == null){
		return false;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMapFirstSill = utils->getHashmapOfSILL(firstSill)->indexNodeMap;
	hash_map<unsigned int,sillNode *> indexNodeMapSecondSill = utils->getHashmapOfSILL(secondSill)->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMapFirstSill,itToIndexNodeMapSecondSill;
	if(indexNodeMapFirstSill.size() != indexNodeMapSecondSill.size()){
		return false;
	}
	for(itToIndexNodeMapFirstSill = indexNodeMapFirstSill.begin();itToIndexNodeMapFirstSill != indexNodeMapFirstSill.end();itToIndexNodeMapFirstSill++){
		itToIndexNodeMapSecondSill = indexNodeMapSecondSill.find(itToIndexNodeMapFirstSill->first);
		if(itToIndexNodeMapSecondSill == indexNodeMapSecondSill.end()){
			return false;
		}
		if(itToIndexNodeMapSecondSill->second->value != itToIndexNodeMapFirstSill->second->value){
			return false;
		}
	}
	return true;
}

#endif /* IDENTICALSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

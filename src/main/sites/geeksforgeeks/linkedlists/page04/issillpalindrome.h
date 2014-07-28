/****************************************************************************************************************************************************
 *  File Name   		: issillpalindrome.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\issillpalindrome.h
 *  Created on			: Apr 24, 2014 :: 11:58:43 PM
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
#ifndef ISSILLPALINDROME_H_
#define ISSILLPALINDROME_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isSillPalindromeMain(sillNode **frontCrawler,sillNode *crawler){
	if(*frontCrawler == null || crawler == null){
		return true;
	}
	bool truthValue = isSillPalindromeMain(frontCrawler,crawler->next);
	if(!truthValue || (*frontCrawler)->value != crawler->value){
		return false;
	}
	(*frontCrawler) = (*frontCrawler)->next;
	return true;
}

//Tested
bool isSillPalindrome(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	return isSillPalindromeMain(&ptr,ptr);
}

//Tested
bool isSillPalindromeAuxSpace(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<sillNode *> auxSpace;
	sillNode *traversalNode = ptr;
	while(traversalNode != null){
		auxSpace.push(traversalNode);
		traversalNode = traversalNode->next;
	}
	traversalNode = ptr;
	while(traversalNode != null && !auxSpace.empty()){
		if(traversalNode->value != auxSpace.top()->value){
			return false;
		}
		traversalNode = traversalNode->next;
		auxSpace.pop();
	}
	return true;
}

//Tested
bool isSillPalindromeReverseIdenticalCheck(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	sillutils *utils = new sillutils();
	sillNode *reverseList = utils->reverseSillNewList(ptr);
	return utils->areSillsIdentical(ptr,reverseList);
}

//Tested
bool isSillPalindromeHashmap(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getHashmapOfSILL(ptr)->indexNodeMap;
	hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	unsigned int counter = 0,sizeOfSill = indexNodeMap.size();
	sillNode *traversalNode = ptr;
	while(counter < sizeOfSill/2){
		itToIndexNodeMap = indexNodeMap.find(sizeOfSill-counter-1);
		if(itToIndexNodeMap == indexNodeMap.end()){
			throw "There don't exists node for given index";
		}
		if(itToIndexNodeMap->second->value != traversalNode->value){
			return false;
		}
		traversalNode = traversalNode->next;
		counter += 1;
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *pgetNodeAtIndex(sillNode *ptr,unsigned int index){
	if(ptr == null){
		return null;
	}
	if(index == 0){
		return ptr;
	}
	return getNodeAtIndex(ptr->next,index-1);
}

//Tested
bool isSillPalindromeON2(sillNode *ptr){
	if(ptr == null){
		return true;
	}
	unsigned int counter = 1;
	sillNode *traversalNode = ptr,*nodeFromEnd;
	unsigned int lengthOfSill = ((sillutils *)new sillutils())->lengthOfSILL(ptr);
	while(traversalNode != null && counter < lengthOfSill/2){
		nodeFromEnd = pgetNodeAtIndex(ptr,lengthOfSill-counter);
		if(nodeFromEnd->value != traversalNode->value){
			return false;
		}
		traversalNode = traversalNode->next;
		counter += 1;
	}
	return true;
}

#endif /* ISSILLPALINDROME_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

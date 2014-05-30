/****************************************************************************************************************************************************
 *  File Name   		: sillUtil.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\common\linkedlist\sillUtil.h
 *  Created on			: Apr 13, 2014 :: 10:07:06 PM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SILLUTIL_H_
#define SILLUTIL_H_

class sillutils {

private:
	//Tested
	sillNode *createSILLFromVectorMain(vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0 || currentIndex >= userInput.size()){
			return null;
		}
		sillNode *node = new sillNode(userInput[currentIndex]);
		node->next = createSILLFromVectorMain(userInput,currentIndex+1);
		return node;
	}

public:
	//Tested
	sillNode *createSILLFromVector(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		return createSILLFromVectorMain(userInput,0);
	}

	//Tested
	sillNode * createSILLFromVectorIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		sillNode *head = new sillNode(userInput[0]);
		sillNode *traversalNode = head;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			traversalNode->next = new sillNode(userInput[counter]);
			traversalNode = traversalNode->next;
		}
		traversalNode->next = null;
		return head;
	}

	//Tested
	void printSILL(sillNode *ptr){
		if(ptr == null){
			return;
		}
		printf("%d\t",ptr->value);
		printSILL(ptr->next);
	}

	unsigned int lengthOfSILL(sillNode *ptr){
		if(ptr == null){
			return 0;
		}
		return 1 + lengthOfSILL(ptr->next);
	}

	//Tested
	bool areSillsIdentical(sillNode *firstPtr,sillNode *secondPtr){
		if(firstPtr == null && secondPtr == null){
			return true;
		}
		if(firstPtr == null || secondPtr == null){
			return false;
		}
		return firstPtr->value == secondPtr->value && areSillsIdentical(firstPtr->next,secondPtr->next);
	}

	//Tested
	sillNode *reverseSillNewListMain(sillNode **revHead,sillNode *ptr){
		if(ptr == null){
			return null;
		}
		sillNode *remainingList = reverseSillNewListMain(revHead,ptr->next);
		sillNode *newNode = new sillNode(ptr->value);
		if(remainingList != null){
			remainingList->next = newNode;
		}else{
			*revHead = newNode;
		}
		return newNode;
	}

	//Tested
	sillNode *reverseSillNewList(sillNode *ptr){
		if(ptr == null){
			return null;
		}
		sillNode *revHead = null;
		reverseSillNewListMain(&revHead,ptr);
		return revHead;
	}

	//Tested
	sillHashmap *getHashmapOfSILL(sillNode *ptr){
		if(ptr == null){
			return null;
		}
		hash_map<unsigned int,sillNode *> indexNodeMap;
		hash_map<uint32_t,unsigned int> nodeIndexMap;
		hash_map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
		hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
		sillNode *traversalNode = ptr;
		unsigned int index = 0;
		while(traversalNode != null){
			indexNodeMap.insert(pair<unsigned int,sillNode *>(index,traversalNode));
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)traversalNode,index++));
			traversalNode = traversalNode->next;
		}
		/*for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
			printf("%d - %d\n",itToIndexNodeMap->first,itToIndexNodeMap->second->value);
		}
		for(itToNodeIndexMap = nodeIndexMap.begin();itToNodeIndexMap != nodeIndexMap.end();itToNodeIndexMap++){
			printf("%d - %d\n",((sillNode *)itToNodeIndexMap->first)->value,itToNodeIndexMap->second);
		}*/
		sillHashmap *hashMap = new sillHashmap();
		hashMap->indexNodeMap = indexNodeMap;
		hashMap->nodeIndexMap = nodeIndexMap;
		return hashMap;
	}

	sillNode *getTailOfSill(sillNode *ptr){
		if(ptr == null){
			return null;
		}
		while(ptr->next != null){
			ptr = ptr->next;
		}
		return ptr;
	}

	void selectionSortSill(sillNode *ptr,bool asc = true){

	}
};

#endif /* SILLUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

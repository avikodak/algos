/****************************************************************************************************************************************************
 *  File Name   		: reversesill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\reversesill.h
 *  Created on			: Apr 22, 2014 :: 4:50:58 PM
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

#ifndef REVERSESILL_H_
#define REVERSESILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reverseSill(sillNode **head,sillNode *crawler){
	if(crawler == null){
		return;
	}
	static sillNode *prevNode = null;
	if(crawler->next == null){
		(*head) = crawler;
		crawler->next = prevNode;
		return;
	}
	sillNode *restOfSill = crawler->next;
	crawler->next = prevNode;
	prevNode = crawler;
	reverseSill(head,restOfSill);
}

//Tested
void reverseSillIterative(sillNode **head){
	if(*head == null){
		return;
	}
	sillNode *crawler = *head,*restOfSill,*prevNode = null;
	while(crawler != null){
		restOfSill = crawler->next;
		crawler->next = prevNode;
		prevNode = crawler;
		crawler = restOfSill;

	}
	(*head) = prevNode;
}

//Tested
sillNode *reverseSillMain(sillNode **head,sillNode *crawler){
	if(crawler == null){
		return null;
	}
	if(crawler->next == null){
		(*head) = crawler;
		return crawler;
	}
	reverseSillMain(head,crawler->next);
	crawler->next->next = crawler;
	return crawler;
}

//Tested
void reverseSillDriver(sillNode **ptr){
	if(*ptr == null){
		return;
	}
	sillNode *lastNode = reverseSillMain(ptr,*ptr);
	lastNode->next = null;
}

//Tested
sillNode *reverseSillByNewListMainRearToFront(sillNode **head,sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *newNode = new sillNode(ptr->value);
	if(ptr->next == null){
		(*head) = newNode;
		return newNode;
	}
	sillNode *newReverseList = reverseSillByNewListMainRearToFront(head,ptr->next);
	newReverseList->next = newNode;
	return newNode;
}

//Tested
sillNode *reverseSillByNewListRearToFrontDriver(sillNode *head){
	if(head == null){
		return null;
	}
	sillNode *newNode = null;
	reverseSillByNewListMainRearToFront(&newNode,head);
	return newNode;
}

//Tested
sillNode *reverseSillByNewListFrontToRearMain(sillNode **newHeadList,sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *newNode = new sillNode(ptr->value);
	newNode->next = (*newHeadList);
	(*newHeadList) = newNode;
	reverseSillByNewListFrontToRearMain(newHeadList,ptr->next);
	return newNode;
}

//Tested
sillNode *reverseSillByNewListFrontToRearDriver(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *newNode = null;
	reverseSillByNewListFrontToRearMain(&newNode,ptr);
	return newNode;
}

//Tested
sillNode *reverseSillByCreatingNewListIterativeFTOR(sillNode *head){
	if(head == null){
		return null;
	}
	sillNode *ptr = head;
	sillNode *newListHead = null;
	while(ptr != null){
		sillNode *newNode = new sillNode(ptr->value);
		newNode->next = newListHead;
		newListHead = newNode;
		ptr = ptr->next;
	}
	return newListHead;
}

//Tested
void reverseValuesSill(sillNode *crawler){
	if(crawler == null){
		return;
	}
	static bool reverseFlag = true;
	static sillNode *frontCrawler = crawler;
	reverseValuesSill(crawler->next);
	if(frontCrawler == crawler){
		reverseFlag = false;
	}
	if(reverseFlag){
		int tempForSwap;
		tempForSwap = frontCrawler->value;
		frontCrawler->value = crawler->value;
		crawler->value = tempForSwap;
	}
	if(frontCrawler->next == crawler){
		reverseFlag = false;
	}else{
		frontCrawler = frontCrawler->next;
	}
}

//Tested
void reverseValueSillIterative(sillNode *ptr){
	if(ptr == null){
		return;
	}
	stack<int> auxSpace;
	sillNode *traversalNode = ptr;
	while(traversalNode != null){
		auxSpace.push(traversalNode->value);
		traversalNode = traversalNode->next;
	}
	traversalNode = ptr;
	while(traversalNode != null && !auxSpace.empty()){
		traversalNode->value = auxSpace.top();
		auxSpace.pop();
		traversalNode = traversalNode->next;
	}
}

//Tested
void reverseValueSillHashmap(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> indexNodeMap = utils->getHashmapOfSILL(ptr)->indexNodeMap;
	sillNode *requiredNode;
	int tempForSwap;
	unsigned int runningIndex = 0,lengthOfSill= indexNodeMap.size();
	sillNode *crawler = ptr;
	while(runningIndex < lengthOfSill/2){
		requiredNode = indexNodeMap.find(lengthOfSill - runningIndex - 1)->second;
		tempForSwap = requiredNode->value;
		requiredNode->value = crawler->value;
		crawler->value = tempForSwap;
		crawler = crawler->next;
		runningIndex++;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *getNodeAtIndex(sillNode *ptr,unsigned int index){
	if(ptr == null){
		return null;
	}
	if(index == 0){
		return ptr;
	}
	return getNodeAtIndex(ptr->next,index-1);
}

//Tested
void reverseValueSillUsingLengthON2Iterative(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	sillNode *crawler = ptr,*temp;
	int tempForSwap;
	unsigned int lengthOfSill = utils->lengthOfSILL(ptr),counter = 0;
	while(counter < lengthOfSill/2){
		temp = getNodeAtIndex(ptr,lengthOfSill-counter - 1);
		tempForSwap = temp->value;
		temp->value = crawler->value;
		crawler->value = tempForSwap;
		crawler = crawler->next;
		counter += 1;
	}

}

//Tested
void reverseValueSillUsingLengthON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	static unsigned int requiredIndex = utils->lengthOfSILL(ptr);
	static unsigned int lengthOfSill = utils->lengthOfSILL(ptr);
	static sillNode *head = ptr;
	if(requiredIndex > lengthOfSill/2){
		sillNode *requiredNode = getNodeAtIndex(head,requiredIndex-1);
		int temp = requiredNode->value;
		requiredNode->value = ptr->value;
		ptr->value = temp;
		requiredIndex--;
		reverseValueSillUsingLengthON2(ptr->next);
	}
}

void reverseSillUsingLengthON2Iterative(sillNode *ptr){

}

void reverseSillUsingLengthON2(sillNode *ptr){

}

#endif /* REVERSESILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

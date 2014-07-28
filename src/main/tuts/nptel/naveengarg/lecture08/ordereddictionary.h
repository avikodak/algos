/****************************************************************************************************************************************************
 *  File Name   		: ordereddictionary.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\ordereddictionary.h
 *  Created on			: Jun 4, 2014 :: 1:09:05 AM
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

#ifndef ORDEREDDICTIONARY_H_
#define ORDEREDDICTIONARY_H_

class orderedDictionary{
private:
	dillNode *head = null;
	dillNode *tail = null;
public:
	void insert(int value){
		if(head == null){
			head = new dillNode(value);
			tail = head;
		}else{
			dillNode *traversingNode = head;
			while(traversingNode != null && traversingNode->next != null && traversingNode->value < value){
				traversingNode = traversingNode->next;
			}
			dillNode *newNode = new dillNode(value);
			newNode->next = traversingNode->next;
			newNode->prev = traversingNode;
			traversingNode->next = newNode;
			newNode->next->prev = newNode;
			if(newNode->next == null){
				tail = newNode;
			}
		}
	}

	dillNode *search(int value){
		if(head == null){
			return null;
		}
		if(tail->value < value){
			return null;
		}
		dillNode *traversingNode = head;
		while(traversingNode != null && traversingNode->value != value){
			traversingNode = traversingNode->value;
		}
		return traversingNode;
	}

	dillNode *getPredecessor(int value){
		dillNode *ptr = search(value);
		if(ptr == null){
			return ptr;
		}
		return ptr->prev;
	}

	dillNode *getSuccessor(int value){
		dillNode *ptr = search(value);
		if(ptr == null){
			return ptr;
		}
		return ptr->next;
	}

	void deleteValue(int value){
		dillNode *ptr = search(value);
		if(ptr == null){
			return;
		}
		dillNode *nodeToBeDeleted;
		if(ptr == head){
			nodeToBeDeleted = head;
			head = head->next;
			if(head == null){
				tail = null;
			}
			free(nodeToBeDeleted);
		}else{
			if(ptr->next == null){
				tail = ptr->prev;
			}
			ptr->prev->next = null;
			free(ptr);
		}
	}

	dillNode *getMin(){
		return head;
	}

	dillNode *getMax(){
		return tail;
	}
};

#endif /* ORDEREDDICTIONARY_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

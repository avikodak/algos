/****************************************************************************************************************************************************
 *  File Name   		: dll.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture03\dll.h
 *  Created on			: May 31, 2014 :: 1:07:50 PM
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
#include <algos/utils/ds/linkedlist/linkedlist.h>
#include <algos/utils/ds/tree/treeds.h>
#include <algos/utils/common/tree/tree.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef DLL_H_
#define DLL_H_

class dll{
private:
	dillNode *head;
	unsigned int size = 0;

public:
	void insertNode(int value){
		dillNode *newNode = (dillNode *)malloc(sizeof(dillNode));
		newNode->value = value;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		size += 1;
	}

	unsigned int size(){
		return size;
	}

	void printDll(){
		dillNode *traversingNode = head;
		while(traversingNode != null){
			printf("%d\t",traversingNode->value);
			traversingNode = traversingNode->next;
		}
	}

	bool searchForNode(int value){
		dillNode *traversalNode = head;
		while(traversalNode != null){
			if(traversalNode->value == value){
				return true;
			}
		}
		return false;
	}

	void deleteValue(int value){
		dillNode *traversalNode = head;
		while(traversalNode != null && traversalNode->value != value){
			traversalNode = traversalNode->next;
		}
		if(traversalNode != null){
			dillNode *nodeToBeDeleted;
			if(traversalNode == head){
				nodeToBeDeleted = head;
				head = traversalNode->next;
				free(nodeToBeDeleted);
				head->prev = null;
			}else{
				traversalNode->prev->next = traversalNode->next;
				if(traversalNode->next != null){
					traversalNode->next->prev = traversalNode->prev;
				}
				free(traversalNode);
			}
			size -= 1;
		}
	}
};

#endif /* DLL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

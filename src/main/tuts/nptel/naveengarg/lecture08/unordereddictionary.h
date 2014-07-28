/****************************************************************************************************************************************************
 *  File Name   		: unordereddictionary.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\unordereddictionary.h
 *  Created on			: Jun 4, 2014 :: 1:08:55 AM
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

#ifndef UNORDEREDDICTIONARY_H_
#define UNORDEREDDICTIONARY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
class unorderedDictionary{
private:
	sillNode *head = null;
public:
	void insert(int value){
		if(head == null){
			head = new sillNode(value);
		}else{
			sillNode *newNode = new sillNode(value);
			newNode->next = head;
			head = newNode;
		}
	}

	sillNode *search(int value){
		if(head == null){
			return null;
		}
		sillNode *traversingNode = head;
		while(traversingNode != null){
			if(traversingNode->value == value){
				return traversingNode;
			}
			traversingNode = traversingNode->next;
		}
		return null;
	}

	void deleteVal(int value){
		if(head == null){
			return;
		}
		sillNode *nodeToBeDeleted,*traversingNode;
		if(head->value == value){
			nodeToBeDeleted = head;
			head = head->next;
			free(nodeToBeDeleted);
			return;
		}
		traversingNode = head;
		while(traversingNode->next != null){
			if(traversingNode->next->value == value){
				nodeToBeDeleted = traversingNode->next;
				traversingNode->next = traversingNode->next->next;
				free(nodeToBeDeleted);
				break;
			}
			traversingNode = traversingNode->next;
		}
	}

	sillNode *getSuccessor(int value){
		if(head == null){
			return null;
		}
		sillNode *successor = null,*traversingNode = head;
		while(traversingNode != null){
			if(traversingNode->value > value){
				if(successor == null){
					successor = traversingNode->value;
				}else{
					successor = successor->value > traversingNode->value?traversingNode:successor;
				}
			}
			traversingNode = traversingNode->next;
		}
		return successor;
	}

	sillNode *getPredecessor(int value){
		if(head == null){
			return null;
		}
		sillNode *predecessor = null,*traversingNode = head;
		while(traversingNode != null){
			if(traversingNode->value < value){
				if(predecessor == null){
					predecessor = traversingNode;
				}else{
					predecessor = predecessor->value <traversingNode->value?traversingNode:predecessor;
				}
			}
			traversingNode = traversingNode->next;
		}
		return predecessor;
	}

	sillNode *getMin(){
		if(head == null){
			return null;
		}
		sillNode *minNode = head,*traversingNode = head;
		while(traversingNode != null){
			if(minNode->value > traversingNode->value){
				minNode = traversingNode;
			}
			traversingNode = traversingNode->next;
		}
		return minNode;
	}

	sillNode *getMax(){
		if(head == null){
			return null;
		}
		sillNode *maxNode = head,*traversingNode = head;
		while(traversingNode != null){
			maxNode = maxNode->value < traversingNode->value?traversingNode:maxNode;
		}
		return maxNode;
	}
};

#endif /* UNORDEREDDICTIONARY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

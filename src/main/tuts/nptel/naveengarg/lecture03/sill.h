/****************************************************************************************************************************************************
 *  File Name   		: sill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture03\sill.h
 *  Created on			: Jun 2, 2014 :: 12:42:35 AM
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

#ifndef SILL_H_
#define SILL_H_

class sill{
private:
	sillNode *head = null;
	unsigned int size = 0;
public:
	void insertValueIntoSill(int userInput){
		sillNode *newNode = new sillNode();
		newNode->value = userInput;
		newNode->next = head;
		head = newNode;
		size += 1;
	}

	unsigned int sizeOfSill(){
		return size;
	}

	void printSill(){
		sillNode *traversingNode = head;
		while(traversingNode != null){
			printf("%d\t",traversingNode->value);
			traversingNode = traversingNode->next;
		}
	}

	void deleteFromSill(int value){
		sillNode *nodeToBeDeleted;
		if(head->value == value){
			nodeToBeDeleted = head;
			head = head->next;
			free(nodeToBeDeleted);
		}else{
			sillNode *traversalNode = head;
			while(traversalNode->next != null && traversalNode->next->value != value){
				traversalNode = traversalNode->next;
			}
			if(traversalNode->next != null){
				nodeToBeDeleted = traversalNode->next;
				traversalNode->next = traversalNode->next->next;
				free(nodeToBeDeleted);
			}
		}
	}

};

#endif /* SILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

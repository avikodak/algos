/****************************************************************************************************************************************************
 *  File Name   		: treeds.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\ds\tree\treeds.h
 *  Created on			: Apr 10, 2014 :: 3:04:12 AM
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
/* 															TREE DATA STRUCTURES START 																*/
/****************************************************************************************************************************************************/

#ifndef TREEDS_H_
#define TREEDS_H_

struct itNode{
	int value;
	itNode *left;
	itNode *right;

	itNode(){

	}

	itNode(int userInput){
		value = userInput;
		left = NULL;
		right = NULL;
	}
};

struct iptNode{
	int value;
	iptNode *left;
	iptNode *right;
	iptNode *parent;

	iptNode(){

	}

	iptNode(int userInput){
		value = userInput;
		left = null;
		right = null;
		parent = null;
	}
};

struct iTernaryTreeNode{
	char ch;
	bool isLeafNode;
	iTernaryTreeNode *left;
	iTernaryTreeNode *equal;
	iTernaryTreeNode *right;

	iTernaryTreeNode(){

	}

	iTernaryTreeNode(char inputCh){
		ch = inputCh;
		isLeafNode = false;
		left = null;
		equal = null;
		right = null;
	}
};

struct itNextRightNode{
	int value;
	itNextRightNode *left;
	itNextRightNode *right;
	itNextRightNode *nextRight;

	itNextRightNode(){

	}

	itNextRightNode(int userInput){
		value = userInput;
		left = null;
		right = null;
		nextRight = null;
	}
};

struct iftNode{
	int value;
	unsigned int frequency;
	iftNode *left;
	iftNode *right;

	iftNode(){

	}

	iftNode(int userInput){
		value = userInput;
		left = null;
		right = null;
		frequency = 1;
	}
};

struct iltNode{
	int value;
	unsigned int level;
	iltNode *left;
	iltNode *right;

	iltNode(){

	}

	iltNode(int userInput){
		value = userInput;
		left =  null;
		right = null;
		level = 0;
	}
};

struct itHashmap{
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
};

struct itNodeValueHashmap{
	hash_map<uint32_t,int> nodeValueMap;
	hash_map<int,vector<itNode *> > valueNodesMap;
};

#endif /* TREEDS_H_ */

/****************************************************************************************************************************************************/
/* 															TREE DATA STRUCTURES END 																*/
/****************************************************************************************************************************************************/

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

struct cftNode{
	char ch;
	unsigned int frequency;
	cftNode *left;
	cftNode *right;

	cftNode(){

	}

	cftNode(char userInput){
		ch = userInput;
		frequency = 1;
		left = null;
		right = null;
	}
};

struct ifptNode{
	int value;
	unsigned int frequency;
	ifptNode *left;
	ifptNode *right;
	ifptNode *parent;

	ifptNode(){

	}

	ifptNode(int value){
		this->value = value;
		frequency = 1;
		left = null;
		right = null;
		parent = null;
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

struct iavltNode{
	int value;
	unsigned int height;
	iavltNode *left;
	iavltNode *parent;
	iavltNode *right;

	iavltNode(){

	}

	iavltNode(int value){
		this->value = value;
		height = 1;
		left = null;
		parent = null;
		right = null;
	}
};

struct ifavltNode{
	int value;
	unsigned int height;
	unsigned int frequency;
	ifavltNode *left;
	ifavltNode *parent;
	ifavltNode *right;

	ifavltNode(){

	}

	ifavltNode(int value){
		this->value = value;
		height = 1;
		frequency = 1;
		left = null;
		right = null;
		parent = null;
	}
};

struct cfavltNode{
	char ch;
	unsigned int frequency;
	unsigned int height;
	cfavltNode *parent;
	cfavltNode *left;
	cfavltNode *right;

	cfavltNode(){

	}

	cfavltNode(char userInput){
		ch = userInput;
		frequency = 1;
		height = 1;
		parent = null;
		left = null;
		right = null;
	}
};

struct iRedBlackNode{
	int value;
	bool isRedNode;
	iRedBlackNode *left;
	iRedBlackNode *right;
	iRedBlackNode *parent;

	iRedBlackNode(){

	}

	iRedBlackNode(int value){
		this->value = value;
		isRedNode = true;
		left = null;
		right = null;
		parent = null;
	}
};

struct ifRedBlackNode{
	int value;
	unsigned int frequency;
	bool isRedNode;
	ifRedBlackNode *left;
	ifRedBlackNode *right;
	ifRedBlackNode *parent;

	ifRedBlackNode(){

	}

	ifRedBlackNode(int value){
		this->value = value;
		this->frequency = 1;
		isRedNode = true;
		left = null;
		right = null;
		parent = null;
	}
};

struct ctrieNode{
	char ch;
	unsigned int noOfChildren;
	ctrieNode *parent;
	ctrieNode *children[26];

	ctrieNode(){

	}

	ctrieNode(char userInput){
		ch = userInput;
		noOfChildren = 0;
		parent = null;
	}
};

struct i24Node{
	int values[3];
	unsigned int fillCount;
	i24Node *parent;
	i24Node *children[4];

	i24Node(){
		fillCount = 0;
	}

	i24Node(int value){
		this->values[0] = value;
		fillCount = 1;
		parent = null;
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

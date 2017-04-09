#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <boost/concept_check.hpp>
#include <string.h>
// #include <string>
#include <bits/basic_string.h>
#include <list>
#include <vector>

using namespace std;
static int node_id = 0;
template <class Type>
class BinTreeNode{
public:
	BinTreeNode<Type> *LChild, *RChild;
	Type data;
};

template <class Type>
class BinaryTree{
private:
	BinTreeNode<Type> *root;
public:
	BinaryTree<Type>(BinTreeNode<Type>* rt){
		root = rt;
	}

};
template <class Type>
void linkLeaf(BinTreeNode<Type>* rt,vector<BinTreeNode<Type>* >& List){
	//if current node is a leaf
	if((rt->LChild == NULL) && (rt->RChild == NULL) ){
		List.push_back(rt);

		return ;
	}
	cerr<<"List "<<List.size()<<endl;
	linkLeaf(rt->LChild, List);
	linkLeaf(rt->RChild, List);
}
template <class Type>
void createBinTree(BinTreeNode<Type>*& T ){
	Type x;
	if(sizeof(Type) == sizeof(char)) {
		scanf("%c", &x);
		if(x == '#')
			return ;
	}
	if(sizeof(Type) == sizeof(int)){
		scanf("%d", &x);

		if(x < 0)
			return ;
	}
	T = (BinTreeNode<Type>*)malloc(sizeof(BinTreeNode<Type>));
	T->data = x;
	cerr<<"node "<<node_id++<<endl;
	 createBinTree<Type>(T->LChild);
	createBinTree<Type>(T->RChild);
	return ;

}

class base{
public:
	  void fun2(){
		cerr<<"base fun2"<<endl;
	}
	 void fun1(){
		base::fun2();
	}
	
};

class child : public base{
public:
// 	void fun1(){
// 		fun2();
// 	}
	void fun2(){
		cerr<<"child fun2*"<<endl;
	}
};


int main(){
	BinTreeNode<int>* root;
	string a = to_string(1.2);
/*	
	base* ba = new child();
	ba->fun1();
	ba->fun2();
	
	child* ca = new child();
	ca->fun1();
	ca->fun2();
// 	child::fun1();
	
	base* bb = new base();
	bb->fun1();
	
	child aaa;
	aaa.fun1();
	*/
	
	cerr<<"Create BinTree...\nPlease enter letters or integer numbers, end with '#' or a negative number..."<<endl;
	createBinTree<int>(root);
	BinaryTree<int > btree(root);
	
	cerr<<"Building tree done..."<<endl;
	cerr<<root->data<<" "<<root->LChild->data<<" "<<root->RChild->data<<endl;
	vector<BinTreeNode<int>* > leaveslist;
	linkLeaf(root, leaveslist);
	cerr<<"leaveList length "<<leaveslist.size()<<endl;
	for(int i  = 0; i<(leaveslist.size()-1); i++){
		cout << leaveslist[i]->data<<endl;
		leaveslist[i]->RChild = leaveslist[i+1];
	}
	BinTreeNode<int>* head;
	cerr<<"1"<<endl;
	head = leaveslist[0];
	BinTreeNode<int>* end;
	end = head;
	//show list
	cerr<<"show result"<<endl;
	while(end->RChild != NULL){
		cerr<<end->data<<" -> ";
		end = end->RChild;
	}
	cerr<<end->data<<endl;
	
}
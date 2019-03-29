#include<iostream>
using namespace std;
//class Node
class node{
	public:
	int data;
	node * right;
	node * left;
	node * parent;
	node(int value){
		data = value;
		right = NULL;
		left = NULL;
		parent = NULL;
		}
};
//class binary structure tree
class bst{
	public:
	node * root;
	bst(){
		root = NULL;
	}
	node * insert(int val){
		insert2(root, val);
	}
//insert helper
	node * insert2(node * curr, int val){
		if(root ==NULL){
			root = new node(val);
		}
		else if (val < curr->data)  {

            	if (curr->left == NULL) {
                	curr->left = new node(val);
                	curr->left->parent = curr;
            	}
             //recursive call
            	else insert2(curr->left, val);
        	}
        	else {

            	if (curr->right == NULL) {
            	    	curr->right = new node(val);
                	curr->right->parent = curr;
            }

            else insert2(curr->right, val);
        }
	}
//display
	void display(){
		display2(root);
		cout<<endl;
	}
//display helper
	void display2(node * curr){
		if(curr == NULL)
			return;
		display2(curr->left);
		cout<<curr->data<<",";
		display2(curr->right);
	}
	node * search(int val){
		search2(root,val);
	}
//search helper
	node * search2(node * curr, int val){
		if(curr == NULL)
			return curr;
		else if(curr->data == val)
			return curr;
		else if(val >= curr->data)
			search2(curr->right,val);
		else
			search2(curr->left, val);
	}
//find min of subtree
	node * find_min(node * parent){
		node * curr = parent;
		while(curr->left != NULL){
			curr = curr->left;
		}
		return curr;
	}
//replace at parent
	void replaceatparent(node * curr, node *temp){

		if(curr->parent->left == curr){

					curr->parent->left = temp;
					if(curr->left != NULL)
					curr->left->parent = curr->parent;
					}
				else{

					curr->parent->right = temp;
					if(curr->right != NULL)
					curr->right->parent = curr->parent;
				}

		delete curr;
		}
//Delete Node
	void del(int value){
	    //tree null
		if((root ==NULL)||(search(value) == NULL))
			return;
		else if (search(value) == root){
		    //right side tree
			if((root->left == NULL)&&(root->right != NULL)){
			node * temp = root;
			root = temp->right;
			root->parent = NULL;
			delete temp;
			}
			else if((root->left!= NULL)&&(root->right == NULL)){
			node * temp = root;
			root = temp->left;
			root->parent = NULL;
			delete temp;
			}
			else{
			    node * temp = root;
				node* min = find_min(temp->right);
				temp->data = min->data;

					replaceatparent(min, min->right);

		}}
		else{
			node* temp = search(value);
			if((search(value)->left == NULL)&&(search(value)->right == NULL)){
				replaceatparent(temp, NULL);
			}
			else if((search(value)->left!= NULL)&&(search(value)->right == NULL)){
				replaceatparent(temp, temp->left);
			}
			else if((search(value)->left == NULL)&&(search(value)->right != NULL)){

				replaceatparent(temp, temp->right);
			}
			else{
				node* min = find_min(search(value)->right);
				temp->data = min->data;

					replaceatparent(min, min->right);
				}
	}}
};
int main(){
bst b1;
b1.insert(2);
b1.insert(8);
b1.insert(4);
b1.insert(12);
b1.insert(60);
b1.insert(22);
b1.insert(24);
b1.insert(23);
b1.insert(18);
b1.insert(17);
b1.display();
node * a = b1.find_min(b1.search(4));
cout<<a->data<<endl;
b1.del(8);
b1.display();
b1.del(12);
b1.display();
b1.del(18);
b1.display();
return 0;
}

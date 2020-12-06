#include <iostream> 
#include<bits/stdc++.h>
using namespace std; 
class node 
{ 
	public:
	int data; 
	node *left, *right;
	node(int v){
		data=v;
		left=NULL;
		right = NULL; 
	}
}; 

vector <int> v;

void KDistanceNodesDown(node* root, int k)
{
        if (root == NULL || k < 0)
            return;
        if (k == 0)
        {   
            v.push_back(root->data);
            return;
        }
        KDistanceNodesDown(root->left, k-1);
        KDistanceNodesDown(root->right, k-1);
}
    
int Distance(node* root, int target , int k)
{
        if (root == NULL || k < 0)
            return -1;
        if (root->data == target)
        {
            KDistanceNodesDown(root, k);
            return 0;
        }       
        int dl = Distance(root->left, target, k);
        if (dl != -1)
        {
            if (dl + 1 == k)
                v.push_back(root->data);
            else 
                KDistanceNodesDown(root->right, k-dl-2);
            return dl + 1;    
        }
        int dr = Distance(root->right, target, k);
        if (dr != -1)
        {
            if (dr + 1 == k)
                v.push_back(root->data);
            else 
                KDistanceNodesDown(root->left, k-dr-2);
            return dr + 1;    
        }
        return -1;
}
    
vector <int> KDistanceNodes(node* root, int target , int k)
{
        v.clear();
        Distance(root, target, k);
        sort(v.begin(), v.end());
        return v;
}
    
int main() 
{ 
	node * root = new node(20); 
	root->left = new node(8); 
	root->right = new node(22); 
	root->left->left = new node(4); 
	root->left->right = new node(12); 
	root->left->right->left = new node(10); 
	root->left->right->right = new node(14); 
	int target, k;
    cin>> target >> k;
    vector <int> res = KDistanceNodes(root, target, k);
    for( int i=0; i<res.size(); i++ )
        cout<< res[i] << " ";
      
	return 0; 
}


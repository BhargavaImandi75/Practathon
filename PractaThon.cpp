#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
  
const int k = 100;
const int l=100;
const int q=100;
struct Node
{
    int point[k]; 
    struct Node *left, *right;
};
struct Node* newNode(int arr[])
{
    struct Node* temp = new Node;
  
    for (int i=0; i<k; i++)
       temp->point[i] = arr[i];
  
    temp->left = temp->right = NULL;
    return temp;
}
struct Node *insertRec(Node *root, int point[], unsigned depth)
{
    if (root == NULL)
       return newNode(point);
    unsigned cd = depth % k;
    if (point[cd] < (root->point[cd]))
        root->left  = insertRec(root->left, point, depth + 1);
    else
        root->right = insertRec(root->right, point, depth + 1);
    return root;
}
struct Node *insert(Node *root, int point[])
{
    return insertRec(root, point, 0);
}
long long int  dist(int x[],int y[]){
	long long int d=0;
	for(int i=0;i<l;i++){
		d=d+x[i]*y[i];
	}
	return d;
}
struct Node *closest(int x[],Node* p, Node* q){
	if(q==NULL) return p;
	if(p==NULL) return q;
	if(dist(x,p->point)<dist(x,q->point)) return p;
	else return q;
}
struct Node *near(Node* root,int point[],int depth){
	struct Node *next,*other;
	if(root==NULL) return NULL;
	if(point[depth%k]<root->point[depth%k]){
		next=root->left;
		other=root->right;
	}
	else{
		other=root->left;
		next=root->right;		
	}
	struct Node* temp = near(next,point,depth+1);
	struct Node* best = closest(point,temp,root);
	long long int   radius=dist(point,best->point);
	long dis = point[depth%k]-root->point[depth%k];
	if(radius>=dis*dis){
		temp=near(other,point,depth+1);	
		best=closest(point,temp,best);
	}
	return best;
}
int main()
{
    struct Node *root = NULL,*temp=NULL;
    int points[100];
    for(long long int i=0;i<10000000;i++){
    	for(int j=0;j<l;j++){
    		points[j]=rand()%201 - 100;
		}
		root=insert(root,points);
	}
	for(int i=0;i<l;i++){
		points[i]=rand()%201 - 100;
	}
	cout<<"\n";
	temp=near(root,points,0);
}

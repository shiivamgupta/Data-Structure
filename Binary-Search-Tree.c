#include<stdio.h>
#include<stdlib.h>
struct BinaryTreeNode
{
int data;
struct BinaryTreeNode* left;
struct BinaryTreeNode* right;
};
struct llnode
{
struct BinaryTreeNode*r;
struct llnode*next;
};
struct BinaryTreeNode* root=NULL;
struct llnode*front=NULL;
struct llnode*rear=NULL;

void delete_anynode(struct BinaryTreeNode*root,int key) 
{
struct BinaryTreeNode* ptr;
struct BinaryTreeNode *succ,*par,*child;
ptr=root;
while(ptr!=NULL)
{                              //CODE TO FIND OUT THE LOCATION OF DESIRED KEY AND IT PARENT IN THE TREE
	if(key==ptr->data)
{
		break;
}
	par=ptr;

	if(key < ptr->data)
	ptr=ptr->left;
	else 
	ptr=ptr->right;
}

    if(ptr==NULL)
	printf("Key not found");

    if(ptr->left!=NULL && ptr->right!=NULL)
{                //CASE WHERE THE NODE TO BE DELETED HAS TWO CHILDREN 
    succ=ptr->right;
    while(succ->left!=NULL)
{
    succ=succ->left;
}
    ptr->data=succ->data;
}
    if(ptr->left!=NULL){                                  //CASE WHERE THE NODE TO BE DELETED HAS ONE OR NO CHILDREN
    child=ptr->left;
}
    else
{
    child=ptr->right;
}
    if(ptr==par->left)
{
    par->left=child;
}
	else
{
    par->right=child;
}
    free(ptr);
}
    int height(struct BinaryTreeNode* ptr){
    if(ptr==NULL)
{                       //Condition to terminate the recursion
    return 0;       //this will be terminated at the leaf of the tree
}

    int h_left=height(ptr->left);//For every node we will find out the height of left and right sub-tree
    int h_right=height(ptr->right);
    if(h_left>h_right){//if the height of left subtree is more we will add 1 to it and return that value to the value
    return h_left+1;   //to its parent node if  not then we will do the same thing to the right subtree
}
    else
    return h_right+1;
}
    void levelorder(struct  BinaryTreeNode* temp ){
	while(1)
{
    	   if(front==NULL && rear==NULL)
{
           struct llnode*n=(struct llnode*)malloc(sizeof(struct llnode));
           n->r=temp;
    	   n->next=NULL;
    	   front=n;
    	   rear=n;
}	
        	if(temp->left!=NULL)
{
            struct llnode*n=(struct llnode*)malloc(sizeof(struct llnode));	
             n->r=temp->left;
    	     n->next=NULL;
    	     rear->next=n;
    	     rear=rear->next;
}
        	if(temp->right!=NULL)
{
            struct llnode*n=(struct llnode*)malloc(sizeof(struct llnode));
             n->r=temp->right;
             n->next=NULL;
    	     rear->next=n;
    	     rear=rear->next;
}
             printf("%d",front->r->data);
             front=front->next;
          if(front==NULL)
{
          rear=NULL;
}
          if(front==NULL&&rear==NULL)
{
          break;
}      
       temp=front->r;
}	
}
        void insert(struct BinaryTreeNode* temp){
        printf("Enter the value you want to insert\n");
        int d;
        scanf("%d",&d);   
	    struct BinaryTreeNode *n=(struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	    n->left=NULL;
	    n->right=NULL;
        n->data=d;      
        if(root==NULL)
{
        root=n;
}
        else 
{
       while(1)
{
       if(temp->data >d)
{
       if(temp->left==NULL)
{
             temp->left=n;
             break;
}
       temp=temp->left;      
}
       else if(temp->data<d)
{
       if(temp->right==NULL)
{
	  temp->right=n;
      break;
}
      temp=temp->right;
}
}
}
}
      void Inorder(struct BinaryTreeNode*temp){
      if(temp)
{
      Inorder(temp->left);
      printf("%d",temp->data);
      Inorder(temp->right);
}  
}             
      void Preorder(struct BinaryTreeNode * temp){
	  if(temp)
{
    	printf("%d",temp->data);
	    Preorder(temp->left);
	   Preorder(temp->right);
}
}
        void PostOrder(struct BinaryTreeNode *temp){
        if(temp)
{
    	PostOrder(temp->left);
    	PostOrder(temp->right);
        printf("%d",temp->data);
}
}
int main()
{
    while(1)
{
	int choice;
	printf("\nPress 1 to insert node in BinarySearchTree\n");
    printf("Press 2 to print the value in Inorder\n");
	printf("Press 3 to print the value in PreOrder\n");
    printf("Press 4 to print the value in Postorder\n");
	printf("Press 5 to print the values in levelorder\n");
    printf("Press 6 to find the height of the tree\n");
	printf("Press 7 to delete any node\n");
	scanf("%d",&choice);
        
    switch(choice){
	    case 1:
		insert(root);
                break;
        case 2:
		Inorder(root);
                break;
	    case 3:
	        Preorder(root);
	        break;	
	    case 4:
	       PostOrder(root);	
	       break;
        case 5:
	       levelorder(root);
	       break; 
	    case 6:  
	      printf("%d\n",height(root));      
          break;
        case 7:
	      printf("Enter the value you want to delete \n");
	      int key;
	      scanf("%d",&key);
	      delete_anynode(root,key);
	      break;
}
}
}

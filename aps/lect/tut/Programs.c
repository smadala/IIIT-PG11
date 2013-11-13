
void in_order_traversal_iterative(Node *root) {
  stack<Node*> s;
  Node *current = root;
  bool done = false;
  while (!done) {
    if (current) {
      s.push(current);
      current = current->left;
    } else {
	      if (s.empty()) {
		done = true;
	      } 
	      else {
		current = s.top();
		s.pop();
		cout << current->data << " ";
		current = current->right;
	      }
    }
  }
}







int height(struct node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left 
      height and right heights */   
   return 1 + max(height(node->left), height(node->right));
} 

int diameter(struct node * tree)
{
   /* base case where tree is empty */
   if (tree == 0)
     return 0;

  /* get the height of left and right sub-trees */
  int lheight = height(tree->left);
  int rheight = height(tree->right);

  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(tree->left);
  int rdiameter = diameter(tree->right);

  /* Return max of following three
   1) Diameter of left subtree
   2) Diameter of right subtree
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 





void mirror(struct node* node) 
{
  if (node==NULL) 
    return;  
  else
  {
    struct node* temp;
     
    /* do the subtrees */
    mirror(node->left);
    mirror(node->right);
 
    /* swap the pointers in this node */
    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
} 
 





bool isFoldable(struct node *root)
{
  bool res;
 
  /* base case */
  if(root == NULL)
    return true;
 
  /* convert left subtree to its mirror */
  mirror(root->left);
 
  /* Compare the structures of the right subtree and mirrored
    left subtree */
  res = isStructSame(root->left, root->right);
 
  /* Get the originial tree back */
  mirror(root->left);
 
  return res;
}
 
 
bool isStructSame(struct node *a, struct node *b)
{
  if (a == NULL && b == NULL)
  {  return true; }
  if ( a != NULL && b != NULL &&
       isStructSame(a->left, b->left) &&
       isStructSame(a->right, b->right)
     )
  {  return true; }
 
  return false;
}




bool IsFoldable(struct node *n1, struct node *n2)
{
    /* If both left and right subtrees are NULL,
      then return true */
    if (n1 == NULL && n2 == NULL)
    {  return true;  }
 
    /* If one of the trees is NULL and other is not,
      then return false */
    if (n1 == NULL || n2 == NULL)
    {  return false; }
 
    /* Otherwise check if left and right subtrees are mirrors of
       their counterparts */
    return IsFoldable(n1->left, n2->right) &&
           IsFoldable(n1->right, n2->left);
}



 





/* Returns true if a binary tree is a binary search tree */
int isBST(struct node* node) 
{ 
  if (node == NULL) 
    return(true); 
     
  /* false if the max of the left is > than us */
  if (node->left!=NULL && maxValue(node->left) > node->data) 
    return(false); 
     
  /* false if the min of the right is <= than us */
  if (node->right!=NULL && minValue(node->right) < node->data) 
    return(false); 
   
  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left) || !isBST(node->right)) 
    return(false); 
     
  /* passing all that, it's a BST */
  return(true); 
} 





int isBST(struct node* node, int min, int max) 
{ 
 
  /* an empty tree is BST */
  if (node==NULL) 
     return 1;
       
  /* false if this node violates the min/max constraint */ 
  if (node->data < min || node->data > max) 
     return 0; 
 
  /* otherwise check the subtrees recursively, 
   tightening the min or max constraint */
  return
    isBST(node->left, min, node->data-1) &&  // Allow only distinct values
    isBST(node->right, node->data+1, max);  // Allow only distinct values
} 
 



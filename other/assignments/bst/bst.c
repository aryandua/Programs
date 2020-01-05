#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// structure: 
struct node {
  int number;
  struct node *left;
  struct node *right;
  struct node *parent;
};
typedef struct node t_node;

t_node *head; // head node
FILE *fptr;   // file to read from
FILE *c2;
int printon;

//functions:
void main(int argc, char *argv[]);
void options(FILE *fptr, int n);
void insert(int val);
void delete(int val);
int search(int val);
void printtree(t_node *root, int level);
void plainprinttree(t_node *root);
int n;

void main(int argc, char *argv[]) {
  head=NULL;
    if(argc != 4) {
    printf("Usage: Rad <filename> <printon> <size>\n");
    exit(1);
  }
  printon = atoi(argv[2]);
  n = atoi(argv[3]);

  if(printon != 0 && printon != 1) {
    printf("ERROR! third argument can only be 0 or 1\n");
    exit(1);
  }

  fptr = fopen(argv[1], "r");
  c2 = fopen("check2.txt", "w");
  options(fptr, n);
  plainprinttree(head);
  
}

void options(FILE *fptr, int n) {
  
  char opt = '0';
  int val;
  int i;

  for(i=0;i < n;i++) {
    fscanf(fptr, "%c ",&opt);
    fscanf(fptr, "%d\n",&val);
  

    if(opt == 'I') {
      printf("Inserting %d:",val);
      insert(val);
      printf("Succesful\n");
      
      if(printon)
	printtree(head, 0);
    }
    
    else if(opt == 'D') {
      
      printf("Deleting %d: ",val);
      delete(val);
      
      if(printon) {
	printtree(head, 0);
      }
    }
    
    else if(opt == 'S') {
      
      printf("Searching for %d: ",val);
      search(val);
      if(printon) {
	printtree(head,0);
      }
    }
    
  }
}
void insert(int val) {
  
  t_node *tmp;
  
  if(head == NULL) {
    head = (t_node *) malloc(sizeof(t_node));
    head->right=NULL;
    head->left=NULL;
    head->parent = head;
    head->number = val;
    return;
  }

  tmp = head;

  while(tmp != NULL) {
    
    if(val > tmp->number) {
      if(tmp->right == NULL) {
	tmp->right = (t_node *) malloc(sizeof(t_node));
	tmp->right->number = val;
	tmp->right->parent = tmp;
	return;
      }
      else 
	tmp = tmp->right;
    }
    
    else if(val <= tmp->number) {
      if(tmp->left == NULL) {
	tmp->left = (t_node *) malloc(sizeof(t_node));
	tmp->left->number = val;
	tmp->left->parent = tmp;
	return;
      }
      else {
	tmp = tmp->left;
      }
    }
  }
}


void delete(int val) {
  
  t_node *del;
  t_node *min;
  t_node *tmp;

  int noc = 0;
  int newhead;
  
  
  del=head;
  
  while(del->number != val) {
    
    if(del->number < val)
      del = del->right;
    
    else if(del->number > val) 
      del = del->left;

    if(del == NULL) {
      printf("Cannot delete a node if it doesn't exist\n");
      return;
    }
  }


  if(del == head) {
    tmp = head->right;
    while(tmp->left != NULL) {
      tmp = tmp->left;
    }

    newhead = tmp->number;
    delete(tmp->number);
    head->number = newhead;
    
  }

  if(del->left != NULL)
    noc++;
  if(del->right != NULL)
    noc++;

  if(noc == 0) {
  
    tmp=del->parent;
    
    if(tmp->right == del) 
      tmp->right = NULL;
    
    else if(tmp->left == del) 
      tmp->left = NULL;

      return;
  }

  else if(noc == 1) {
    tmp = del->parent;
    if(tmp -> right == del) {
      
      if(del->right != NULL) {
	tmp->right = del->right;
	del->right->parent = tmp;
      }

      else if(del->left != NULL) {
	tmp->right = del->left;
	del->left->parent = tmp;
      }
    }

    else if(tmp->left == del) {
      
      if(del->right != NULL) {
	tmp->left = del->right;
	del->right->parent = tmp;
      }
      
      else if(del->left != NULL) {
	tmp->left = del->left;
	del->left->parent = tmp;
      }	
    }
  }
  

 else {
   min = del->right;
   
   while(min->left != NULL)
     min = min->left;

   printf("min = %d\n",min->number);
   del->number = min->number;

  tmp = min->parent;
  
  if(tmp->right == min)
    tmp->right = NULL;
  
  else if(tmp->left == min)
    tmp->left = NULL;
  
  else {
    printf("ERROR!\n");
  }
 }
  printf("SUCCESS\n");
}

int search(int val) {
  t_node *tmp;
  tmp=head;

  while(tmp != NULL) {
    if(tmp->number < val) {
      tmp=tmp->right;
    }
    else if(tmp->number > val) {
      tmp=tmp->left;
    }
    else if(tmp -> number == val) {
      printf("Search Successful\n");
      return 1;
    }
  }
  printf("NODE does not exist\n");
  return 0;
}



void padding (char ch, int n) {
  int i;
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void printtree ( t_node *root, int level ) {
  int i;
  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  }
  else {
    printtree ( root->right, level + 1 );
    padding ( '\t', level );
    printf ( "%d\n", root->number);
    printtree ( root->left, level + 1 );
  }
}

void plainprinttree(t_node *root) {
  if(root== NULL) {
    return;
  }
    plainprinttree ( root->right);
    fprintf (c2, "%d\n", root->number);
    plainprinttree ( root->left); 
}

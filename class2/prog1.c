#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
  return a > b ? a : b;
}

typedef struct _Node Node;

typedef struct _Node {
  Node *left;
  Node *right;
  int value;
} Node;

Node *t_Create() {
  Node *n = malloc(sizeof(Node));
  memset(n, 0, sizeof(Node));
  return n;
}

#define TRAVERSAL_PREORDER (0)
#define TRAVERSAL_INORDER (1)
#define TRAVERSAL_POSTORDER (2)

void t_Display(Node *root, int traversal) {
  if(root == NULL) return;
  if(traversal == TRAVERSAL_PREORDER)
    printf("%d ", root->value);
  t_Display(root->left, traversal);
  if(traversal == TRAVERSAL_INORDER)
    printf("%d ", root->value);
  t_Display(root->right, traversal);
  if(traversal == TRAVERSAL_POSTORDER)
    printf("%d ", root->value);
}

void t_Insert(Node **root, Node *value) {
  if(*root == NULL) {
    *root = value;
    return;
  } else {
    if(value->value < (*root)->value) {
      t_Insert(&(*root)->left, value); 
    } else {
      t_Insert(&(*root)->right, value);
    }
  }
}

int t_Delete(Node **root, int value) {
  if(*root == NULL) return 0;
  
  if((*root)->value == value) {
    Node *right = (*root)->right;
    *root = (*root)->left;
    t_Insert(root, right);
    return 1;
  } else if (value < (*root)->value) {
    return t_Delete(&(*root)->left, value);
  } else {
    return t_Delete(&(*root)->right, value);
  }
}

int t_ComputeHeight(Node *node, int height) {
  if(node == NULL) return height;
  return max(t_ComputeHeight(node->left, height + 1), t_ComputeHeight(node->right, height + 1));
}

int t_Find(Node *root, int value) {
  if(root == NULL) return 0;
  else if(root->value == value) {
    return 1;
  }
  else if (value < root->value) {
    return t_Find(root->left, value);
  } else {
    return t_Find(root->right, value);
  }
}

char* M[] = {
  "not found",
  "found"
};

int main(int argc, char *argv[]) {
  int ch;
  Node *tree = NULL;
  do {
    printf("%s", "1. Insert Value\n"
    "2. Display (preorder)\n"
    "3. Display (inorder)\n"
    "4. Display (postorder)\n"
    "5. Delete\n"
    "6. Compute Height\n"
    "7. Search\n"
    "q. Quit\n"
    "=> ");
    for(ch = getchar(); ch == '\n'; ch = getchar());
    switch(ch) {
      case '1': {
        int v;
        scanf("%d", &v);
        Node *n = t_Create();
        n->value = v;
        t_Insert(&tree, n);
        break;
      }
      case '2': case '3': case '4': {
        t_Display(tree, ch - '2');
        putchar('\n');
      } break;
      case '5': {
        int v;
        scanf("%d", &v);
        int d = t_Delete(&tree, v);
        printf("Deleted %d node(s)\n", d);
        break;
      }
      case '6': {
        printf("Height => %d\n", t_ComputeHeight(tree, 0));
        break;
      }
      case '7': {
        int v;
        scanf("%d", &v);
        printf("%s\n", M[t_Find(tree, v)]);
        break;
      }
    }
  } while (ch != 'q');
  return EXIT_SUCCESS;
}


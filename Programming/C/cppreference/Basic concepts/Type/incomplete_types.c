extern char a[]; // the type of a is incomplete
char a[10]; // the type of a is now complete

struct node {
    struct node* next; // struct node is incomplete at this point
}; // struct node is complete at this point

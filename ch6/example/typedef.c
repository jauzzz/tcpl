typedef struct tnode *Treeptr;
typedef struct tnode
{                        /* the tree node: */
    char *word;          /* points to the text */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
} Treenode;

Treeptr talloc(void)
{
    return (Treeptr)malloc(sizeof(Treenode));
}

union u_tag {
    int ival;
    float fval;
    char *sval;
} u;
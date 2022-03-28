#include "akenator.h"

int CtorTreeListing (FILE* file, struct item* root, int* count)
{
    assert (file);
    assert (root);

    if (!count)
    {
        count = new int;
        *count = 0;
    }

    fprintf (file, "%*s", *count * 4 + 1, "{");
    (*count)++;
    fprintf (file, "%s", root->data);

    if ((root->left) || (root->right))
        fprintf (file, "\n");

    if (root->left)
        CtorTreeListing (file, root->left, count);

    if (root->right)
        CtorTreeListing (file, root->right, count);
    
    
    
    if (!(root->left) && !(root->right))
        fprintf (file, "}\n");

    else
        fprintf (file, "%*s\n", (*count - 1) * 4 + 1, "}");
    
    (*count)--;

    return NOMISTAKE;
}

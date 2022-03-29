#include "akinator.h"

CTree CtorTreeFromFile (const char* fileName)
{
    assert (fileName); 

    int sizeBuf = (int) GetSizeBuf (fileName);
    char* buffer = CreateBuf (&sizeBuf, fileName);

    CTree tree;
    int index = 0;

    CtorItmFromFile (tree, buffer, index, sizeBuf);

    return tree;
}

int CtorItmFromFile (CTree tree, char* buffer, int index, int sizeBuf)
{
    

    return NOMISTAKE;
}

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

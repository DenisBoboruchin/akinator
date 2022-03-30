#include "akinator.h"

CTree CtorTreeFromFile (const char* fileName)
{
    assert (fileName); 

    int sizeBuf = (int) GetSizeBuf (fileName);
    char* buffer = CreateBuf (&sizeBuf, fileName);

    CTree tree;
    int index = 0;
    struct item* node = nullptr;


    while ((index < sizeBuf) && (*(buffer + index) != '\0'))
    {
        if (*(buffer + index) == '{')
            node = tree.addItm (nullptr, buffer + index + 1);
        

        if (*(buffer + index) == '}')
            return tree; 

        index++;
    }
    index++;

    if (!node)
    {
        printf ("Empty tree\n");
        return tree;
    }

    node->left  = CtorItmFromFile (tree, node, buffer, &index, sizeBuf);
    node->right = CtorItmFromFile (tree, node, buffer, &index, sizeBuf);

    return tree;
}

item* CtorItmFromFile (CTree tree, item* node, char* buffer, int* index, int sizeBuf)
{ 
    assert (buffer);
    assert (index);
    assert (*index  >= 0);
    assert (sizeBuf >= 0);

    item* newNode = nullptr;

    while ((*index < sizeBuf) && (*(buffer + *index) != '\0'))
    {
        if ((*(buffer + *index) == '{'))
        {
            if (*(buffer + *index + 1) != '}')
            {
                newNode = new item;

                newNode->data = buffer + *index + 1;
            }
        }

        if (*(buffer + *index) == '}')
        {
            (*index)++;
            return node; 
        }

        (*index)++;
    }
    (*index)++;

    if (newNode)
    {
        newNode->left  = CtorItmFromFile (tree, newNode, buffer, index, sizeBuf);
        newNode->right = CtorItmFromFile (tree, newNode, buffer, index, sizeBuf);
    }

    //CtorItmFromFile ()

    return node;
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
    {
        fprintf (file, "\n");

        if (root->left)
        {   
            CtorTreeListing (file, root->left, count);

            if (!(root->right))
                fprintf (file, "%*s", *count * 4 + 3, "{}\n"); 
        }
        
        if (root->right)
        {
            if (!(root->left))
                fprintf (file, "%*s", *count * 4 + 3, "{}\n"); 
            
            CtorTreeListing (file, root->right, count);
        }
    } 
    
    if (!(root->left) && !(root->right))
        fprintf (file, "}\n");

    else
        fprintf (file, "%*s\n", (*count - 1) * 4 + 1, "}");
    
    (*count)--;

    return NOMISTAKE;
}

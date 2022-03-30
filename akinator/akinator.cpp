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
        {
            printf ("create: %d\n", index);
            node = tree.addItm (nullptr, buffer + index + 1);
        }

        if (*(buffer + index) == '}')
            return tree; 

        index++;
    }
    index++;
    printf ("%d\n", index);

    if (!node)
    {
        printf ("Empty tree\n");
        return tree;
    }

    node->left  = CtorItmFromFile (tree, buffer, &index, sizeBuf);
    printf ("ctorctorctor\n");
    node->right = CtorItmFromFile (tree, buffer, &index, sizeBuf);

    return tree;
}

item* CtorItmFromFile (CTree tree, char* buffer, int* index, int sizeBuf)
{ 
    printf ("sss\n");
    assert (buffer);
    assert (index);
    assert (*index  >= 0);
    assert (sizeBuf >= 0);

    printf ("index = %d\n", *index);
    item* newNode = nullptr;
    printf ("item create\n");

    while ((*index < sizeBuf) && (*(buffer + *index) != '\0'))
    {
        printf ("начал\n");
        if ((*(buffer + *index) == '{'))
        {
            printf ("нашееел\n");
            if (*(buffer + *index + 1) != '}')
            {
                printf ("create \"%s\"\n", buffer + *index + 1);
                newNode = new item;

                newNode->data = buffer + *index + 1;
            }
            else
            {
                *index += 2;
                return newNode;
            }
        }

        if (*(buffer + *index) == '}')
        {
            *(buffer + *index) = '\0';
            *index += 2;
            printf ("UUUUUUUUUUUUUUUUUUUUUUU\n");
            return nullptr; 
        }
        
        (*index)++;

        printf ("%d\n", *index);
    }
    (*index)++;

    if (newNode)
    {
        printf ("Меня вызвал %s\n", newNode->data);
        newNode->left  = CtorItmFromFile (tree, buffer, index, sizeBuf);
        
        printf ("середина\n");

        printf ("Меня вызвал %s\n", newNode->data);        
        newNode->right = CtorItmFromFile (tree, buffer, index, sizeBuf);
    }
    
    while (*(buffer + *index) != '}')
    {
        (*index)++;
    }
    *index += 2;

    return newNode;
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

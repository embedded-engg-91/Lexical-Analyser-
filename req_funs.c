#include "lexical.h"

Status token_type(char *token)
{
    
    
    int i=0;
    while(reserved[i]!=NULL)
    {
        if(strcmp(reserved[i], token) == 0)
        {
            return RES;
        }
        i++;
    }
    
    i=0; 
    while(non_reserved[i]!=NULL)
    {
        if(strcmp(non_reserved[i], token) == 0)
        {
            return NONRES;
        }
        i++;
    }
    
    
    
    return IDEN;
}
Status is_operator(char token)
{
    int i=0; 
    while(operators[i]!=NULL)
    {
        if(operators[i][0] == token)
        {
            return TRUE;
        }
        i++;
    }
    return FALSE;
}
Status is_brace(char token)
{
    int i=0; 
    while(braces[i]!=NULL)
    {
        if(braces[i][0] == token)
        {
            return TRUE;
        }
        i++;
    }
    return FALSE;
}

Status is_delim(char token)
{
    int i=0; 
    while(delimiter[i]!=NULL)
    {
        if(delimiter[i][0] == token)
        {
            return TRUE;
        }
        i++;
    }
    return FALSE;
}


Status is_directives(char *token)
{
    int i=0; 
    while(preprocessor_directives[i]!=NULL)
    {
        if(strcmp(preprocessor_directives[i], token) == 0)
        {
            return TRUE;
        }
        i++;
    }
    return FALSE;
}

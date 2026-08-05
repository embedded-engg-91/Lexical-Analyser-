#include "lexical.h"
 Status tokeniser(char *buffer)
 {
    
    
    
    
    
    

    char *temp=buffer;
    int i=0;
    char token[100];
    int ind=0;
    while(temp[i] != '\0')
    {
        if(temp[i]==' ')
        {
            i++;
            continue;
        }
        else if(temp[i]=='#')
        {
            
            ind=0;
            while (!isspace((unsigned char)temp[i]) && temp[i] != '\0')
            {
                token[ind++]=temp[i++];
            }
            token[ind]='\0';
            if(is_directives(token)==TRUE)
            {
                printf("%s is a Preprocessor Directive\n", token);
            }
            
            while(temp[i]==' ')
            {
                i++;
            }
            ind=0;
            if(temp[i]=='<')
            {
                
                i++; 
                while(temp[i]!='>'  && temp[i] != '\0')
                {
                    token[ind++]=temp[i];
                    i++;
                }
                token[ind]='\0';

                if (temp[i] == '>')
                    i++;    
                printf("%s is a Header\n",token);
            }
            else if(temp[i]=='"')
            {
                
                
                i++; 
                while(temp[i]!='"' && temp[i] != '\0')
                {
                    token[ind++]=temp[i];
                    i++;
                }
                token[ind]='\0';

                if (temp[i] == '"')
                i++;    

                printf("%s is a Header\n",token);
            }
            
        }
        else if ((temp[i]>='a' && temp[i]<='z') || (temp[i]>='A' && temp[i]<='Z') || temp[i]== '_') 
        {
            
            ind=0;
            while(isalnum(temp[i]) || temp[i]=='_')
            {
                token[ind++]=temp[i++];
            }
            token[ind]='\0'; 

            
            if(token_type(token)==RES)
            {
                printf("%s is an Reserved Keyword\n",token);
            }
            else if(token_type(token)==NONRES)
            {
                printf("%s is a Non Reserved Keyword\n",token);
            }
            else
            {
                
                
                printf("%s is an Identifier\n",token);
            }
        }
        else if ((temp[i]>='0' && temp[i]<='9') ) 
        {
            
            int num=0;
            while(isdigit(temp[i]))
            {
                num=num*10+ temp[i]-'0';
                i++;
            }

            
            printf("%d is an Constant\n",num);
            return SUCCESS;
        }
        else if(is_operator(temp[i])==TRUE)
        {
            
            printf("%c is an Operator\n",temp[i]);
            i++;

        }
        else if(is_brace(temp[i])==TRUE)
        {
            
            printf("%c is a Brace\n",temp[i]);
            i++;
            
        }
        else if(is_delim(temp[i])==TRUE)
        {
            
            printf("%c is an Delimiter\n",temp[i]);
            i++;
        }
        else
        {
            
            
            i++; 
            
        }
    }    
    return SUCCESS;
 }

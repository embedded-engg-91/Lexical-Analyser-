#include "lexical.h"

const char *reserved[]={"const", "volatile", "extern", "auto", "register",
"static", "signed", "unsigned", "short", "long", "double", "char",
"int", "float", "struct", "union", "enum", "void", "typedef", NULL};


const char *non_reserved[]={"goto", "return", "continue", "break", "if",
"else", "for", "while", "do", "switch", "case", "default", NULL};

const char *operators[]={"~", "+", "-", "*", "/", "%", "=", "<", ">", "-", "&",",", "!", "^", "|", NULL};
const char *braces[]={ "{", "}", "(", ")", "[", "]", NULL};
const char *delimiter[]={";", NULL}; 

const char *preprocessor_directives[] =
{
    "#include",
    "#define",
    "#undef",
    "#if",
    "#ifdef",
    "#ifndef",
    "#elif",
    "#else",
    "#endif",
    "#error",
    "#pragma",
    "#line",

    NULL
};
Status validate(int argc, char *argv[])
{
    if (argc != 2)
    {
        return FAILURE;
    }

    
    char *pos = strrchr(argv[1], '.');
    if(pos==NULL) return FAILURE; 
    if (strcmp(pos, ".c") == 0) 
    {
        return SUCCESS;
    }
    return FAILURE;
}
int main(int argc, char *argv[])
{
    if(validate(argc, argv)==SUCCESS)
    {
        FILE *fptr;
        if(file_handler(&fptr, argv[1])==FILE_FOUND) 
        {
            
            
            char buffer[1000];
            while(fgets(buffer, sizeof(buffer), fptr)!=NULL)
            {
                
                
                tokeniser(buffer);
            }
            fclose(fptr); 
        }
        else
        {
            printf("The file does not exist.\nPlease enter a valid file name.\n");
        }
    }
    else
    {
        printf("Invalid Input Argments\nPlease Try Again\n");
        
    }
    
    
    return 0;
}

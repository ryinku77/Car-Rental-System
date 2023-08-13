#include<stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);
    
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
    {
    switch(ch)
    {
    case 'A': case 'a': case 'E': case 'e': case 'I': case 'i': case 'O': case 'o': case 'U': case 'u':
    printf("it  is a Vowel");
    break;
    default: 
    printf("it is a Consonant");  
    }
    }
    else
    {
    printf("it is Something Else");
    }
    
    return 0;
}

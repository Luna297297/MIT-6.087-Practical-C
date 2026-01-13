#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strpos(const char *, const char ch);
unsigned int my_strspn(const char *, const char *);
unsigned int my_strcspn(const char *, const char *); 
char * strtok(char *, const char *);

int main(){
    char sen[] = "Happy Happy Happy!!!";
    char delims[] = " ,.?!";
    char *token;

    token = strtok(sen, delims);
    // Grab the start of the first token.

    while(token != NULL){
        printf("Token: %s\n", token);
        token = strtok(NULL, delims); 
        // Carry on with the same string.
    }
    return 0;
}

int strpos(const char *delims, const char ch){
    // Spot if the character is a delimiter.
    while(*delims != '\0'){
        if (ch == *(delims)){
            return 1;
        }
        delims++;
        }
    return -1;
}

unsigned int my_strspn(const char *text, const char *delims){
    int i = 0;
    int res = 0;
    while(*text != '\0'){
        res = strpos(delims, *text);
        if (res == 1){
            i++;
            text ++;
            continue;
        // It's a delimiter—hop over it and keep moving.
        }else break;
    }
    return i;
}

unsigned int my_strcspn(const char *text, const char *delims){
    int i = 0;
    int res = 0;
    while(*text != '\0'){
        res = strpos(delims, *text);
        if(res == -1){
            i ++;
            text ++;
            continue;
        // Not a delimiter—keep walking.
        }else break;
    }
    return i;
}

char * strtok(char *text, const char *delims){
    static char *next; // The bookmark.

    /*Initialize*/
    if (!text) text = next;
    // No new string? Pick up where we left off.

    /*Finding the start of token*/
    text += my_strspn(text, delims); 
    // Skip the leading rubbish to find the token's head.
    
    /*Edge Case: bumping into the end of the line*/
    if (*text == '\0') return NULL;
    
    /*Finding where this token ends*/
    next = text + my_strcspn(text, delims); 
    // Locate the end of the current token.

    /*Leaving the bookmark*/
    if(*next != '\0') *next++ = '\0';
    // Snip it with a '\0' and shift the bookmark forward.

    return text;
}
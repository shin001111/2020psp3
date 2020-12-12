#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start=0;
    int pos =0;
    int text_len=strlen(text);
    int key_len=strlen(key);
    for(start=0; start<text_len-key_len; start++){
        for(pos=0;pos<key_len;pos++)
            if (text[start+pos]==key[pos]){
                if(pos+1==key_len){
                    return &text[start];
                }
            }else break;
    }
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int pos;
    int i;
    int text_len=strlen(text);
    int key_len=strlen(key);
    int start=key_len-1;
    int table[256];
    for(i=0;i<256;i++){
        table[i]=key_len;
    }
    for(i=0;i<key_len;i++){
        table[(int)key[i]]=key_len-i-1;
    }
    while(start<text_len)
     {
        for(pos=key_len-1;pos>=0;pos--){
            if(text[start-key_len+pos+1]==key[pos]){
                if(pos==0){
                    return &text[start-key_len+pos+1];
        }
            }else{
                break; 
            }
        }
       int start2=start;
        start=start-key_len+pos+1+table[(int)text[start-key_len+pos+1]];
        if(start<=start2){
            start=start2+1;
        }

}
return NULL;
}
int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}
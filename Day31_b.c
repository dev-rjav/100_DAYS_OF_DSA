   #include<stdio.h>
int isValid(char* s){
    int n = strlen(s);
    if(n%2!=0)return 0;
    char stack[n];
    int top=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')stack[++top]=s[i];
         else if(top!=-1 && stack[top]==match(s[i]))top--;
         else return 0;
    }
    return top==-1;
}
char match(char c){
   switch(c){
      case ')':return '(';
      case '}':return '{';
      case ']':return '[';
      default: return '\0';
   }
}
int main(){
   char str[100];
   scanf("%s",str);
   if(isValid(str))printf("true");
   else printf("false");
   return 0;
}
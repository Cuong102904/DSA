/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void check1(char *arr, int Open, int Close,int n, int index){
    if(index == n*2){
        return;
    }  
    if(Open<n){
        arr[index]='(';
        check1(arr,Open+1,Close,n,index+1);
    }
    if(Open>Close){
        arr[index]=')';
        check1(arr,Open,Close+1,n,index+1);
    }
} 
char ** generateParenthesis(int n, int* returnSize){
    char **arr = (char**)malloc(sizeof(char)*(2*n +1));
    for (int i=0; i<2*n+1; i++) {
    arr[i] = (char*)malloc(sizeof(char)*(n*2+1));
}
    check1(arr,0,0,n,0);
    *returnSize=2*n;
    return arr;    
}



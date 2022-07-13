#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    char num[n]; 
    scanf("%s", num);

    int result = 0;
    for (int i = 0; i < n; i++){
        result += num[i] - '0';
    }

    printf("%d", result);
}
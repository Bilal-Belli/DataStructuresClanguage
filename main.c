#include <stdio.h>
#include <stdlib.h>
void fl2(void) {

    int n=11;
    for (int i = 1; i <= n; i++)
    {   // le premier shape
     //   for (int j = 1; j <= n; j++){if ((i == 1 || i == n / 2 || i == n / 2 + 2 || i == n ||j == 1 || j == n / 2 || j == n / 2 + 2 || j == n)&& j != n /2 + 1 && i != n /2 + 1){printf("X ");}else{printf("  ");}}
        // le deuxieme shape
     //   for (int j = 1; j <= n; j++){if ((i == 1 || i == n || j == n / 2 || j == n / 2 + 2 || j == i || j == n - i + 1)&& i != n / 2 + 1 && j != n / 2 + 1){printf("X ");}else{printf("  ");}}
        // le troisieme shape
    //    for (int j = 1; j <= n; j++){if ((j == 1 || j == n || i == n / 2 || i == n / 2 + 2 || j == i || j == n - i + 1)&& i != n / 2 + 1 && j != n / 2 + 1){printf("X ");}else{printf("  ");}}
        //le QUATRIEME shape
     //   for (int j = 1; j <= n; j++){if (i == 1 || i == n || i == j || j == n - i + 1){printf("X ");}else{printf("  ");}}
        // le CINQIEME shape
        for( int j=1; j<=n; j++ ){if( i==j || j==n-i+1 ) {printf("  ");}else {printf("* ");}}
        // le SIIEME shape
      //  if( i<=n/2 ){for( int k=1; k<(n/2)-i+2; k++ ){printf("- ");}printf("* ");for ( int k=1; k<(i*2)-2; k++ ){printf("  ");}if( i!=1 ){printf("* ");}for( int k=1; k<(n/2)-i+2; k++ ){printf("- ");}}else{for( int k=1; k<i-(n/2); k++ ){printf("- ");}printf("* ");for ( int k=1; k<(n*2)-(i*2); k++ ){printf("  ");}if( i!=n ){printf("* ");}for( int k=1; k<i-(n/2); k++ ){printf("- ");}}
        printf("\n");
    }
}
int main()
{
    fl2();
    return 0;
}

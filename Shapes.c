#include <stdio.h>
#include <stdlib.h>

void sh1(void) {
  int n = 11;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++){
      if ((i == 1 || i == n / 2 || i == n / 2 + 2 || i == n ||j == 1 || j == n / 2 || j == n / 2 + 2 || j == n)&& j != n /2 + 1 && i != n /2 + 1){
        printf("X ");
        } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}
void sh2(void) {
  int n = 11;
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= n; j++){
      if ((i == 1 || i == n || j == n / 2 || j == n / 2 + 2 || j == i || j == n - i + 1)&& i != n / 2 + 1 && j != n / 2 + 1){
        printf("X ");
      }else{
        printf("  ");
      }
    }
    printf("\n");
  }
}
void sh3(void) {
  int n = 11;
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= n; j++){if ((j == 1 || j == n || i == n / 2 || i == n / 2 + 2 || j == i || j == n - i + 1)&& i != n / 2 + 1 && j != n / 2 + 1){printf("X ");}else{printf("  ");}}
    printf("\n");
  }
}
void sh4(void) {
  int n = 11;
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= n; j++){if (i == 1 || i == n || i == j || j == n - i + 1){printf("X ");}else{printf("  ");}}
    printf("\n");
  }
}
void sh5(void) {
  int n = 11;
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= n; j++) {
      if (i == j || j == n - i + 1) {
            printf("  ");
      } else {
          printf("* ");
      }
    }
    printf("\n");
  }
}
void sh6(void) {
  int n = 11;
  for (int i = 1; i <= n; i++) { 
    if( i<=n/2 ){for( int k=1; k<(n/2)-i+2; k++ ){printf("- ");}printf("* ");for ( int k=1; k<(i*2)-2; k++ ){printf("  ");}if( i!=1 ){printf("* ");}for( int k=1; k<(n/2)-i+2; k++ ){printf("- ");}}else{for( int k=1; k<i-(n/2); k++ ){printf("- ");}printf("* ");for ( int k=1; k<(n*2)-(i*2); k++ ){printf("  ");}if( i!=n ){printf("* ");}for( int k=1; k<i-(n/2); k++ ){printf("- ");}}
    printf("\n");
  }
}

int main() {
  sh1();printf("\n");
  sh2();printf("\n");
  sh3();printf("\n");
  sh4();printf("\n");
  sh5();printf("\n");
  sh6();
  return 0;
}
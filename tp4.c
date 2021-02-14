#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"



int puissance(int e){
  if(e<=0){
     return 1;     
  }
  return 2<<(e-1);
}

long unsigned anf(long unsigned fb){
  
  int i = Log2n(Log2n(fb))+1;
  int sf = puissance(i)/2;
    print_binary(fb);    
  for(;i;i--){
    printf("sf = %d\n",sf);
    fb ^= (fb >> sf);
    print_binary(fb);
    sf/=2;
  }     
  return fb;
}

void anfb(int * fb, int n){
  int s = 2<<(n-1);
  int * anf = malloc(s*sizeof (int));
  anf = fb;
  int d = (s>>1);
  int v = d-1;
  
  for(int i = n ; i>0 ; i--){
    int ind = 0;    
    for(int j = 0; j<(s>>1); j+=1){
       *(anf + ind) = anf[ind];
       *(anf + (ind + d)) = *(anf + ind) ^ *(anf + (ind + d));
       if(ind == v && ind < s){
         ind += puissance(i-1) + 1;
         v += (d<<1);
       } else {
         ind++;
       }
     }
    d>>=1;
    v = d-1;
  }
}

   
    
int poids(unsigned x){

  unsigned int i = Log2n(x) + 1;
  int poids = 0;
  for(;i;i--)
  {
    if((x >> i) & 1){
      poids++;
    }
  }
  if(x%2 == 1) poids++;
  return poids;
}
/*
 x=(x&0x55555555)+((x>>1)&0x55555555);
 x=(x&0x33333333)+((x>>2)&0x33333333);
 x=(x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f);
 x=(x&0x00ff00ff)+((x>>8)&0x00ff00ff);
*/


int main(){


  int f[16] = {0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,1};
  unsigned int x = 0x65;
//  printf("mamamamam  %d\n", (2<<1-1)+1);
//  anf_bin(f,4);
   anfb(f,4);
   for(int z = 0; z<16; z+=1){
      
       printf("\nvc %d , %d",f[z], z);

   }
  anfb(f,4);
   for(int z = 0; z<16; z+=1){
      
       printf("\nvc %d , %d",f[z], z);

   }
     
   printf("\npoids de %u est %d",0,poids(0));
   printf("\npoids de %u est %d",1,poids(1));
   printf("\npoids de %u est %d",9,poids(9));

  return 0;
}

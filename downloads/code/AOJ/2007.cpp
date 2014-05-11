#include <cstdio>
int i,n,c[4],m[4],a[4]={10,50,100,500},f;
main(){
    while(scanf("%d",&n),n=-n){
        for(i=0;i<4;n+=c[i]*a[i++])scanf("%d",c+i);
        for(i=3;i>=0;n-=m[i]*a[i--])m[i]=n/a[i];f=f?puts(""):1;
        for(i=0;i<4;i++)if(c[i]>m[i])printf("%d %d\n",a[i],c[i]-m[i]);
    }
}
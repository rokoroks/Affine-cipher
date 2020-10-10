#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/* made by rokoroks*/
int encrypt(int a, int b,char slovo)
{
int d,num;

if (slovo >= 'A' && slovo <= 'Z')
     num = slovo - 'A';
else if (slovo >= 'a' && slovo <= 'z')
     num = slovo - 'a';

    d=(a*num+b)%26;

    return d;
}

int encrypt2(int a, int b, char slovo)
{
int num,d;

if (slovo >= 'A' && slovo <= 'Z')
     num = slovo - 'A';
else if (slovo >= 'a' && slovo <= 'z')
     num = slovo - 'a';

    d=(a*(num-b))%26;
if(d<0) d=26+d;
    return d;
}

int inverse(int i)
{
    float k;
    int j;
    for(j=1;j<10000;j++)
    {
        k=(j*26+1)%i;
        if(k==0) break;
    }
    k=(j*26+1)/i;
    if(j==10000) return 0;
    return k;
}

int decrypt(int a)
{
char slovo;
slovo=a+'a';

return slovo;
}

int relprost(int a, int b)
{
int c,i,je;
    if(a<b) c=a;
        else c=b;
je=1;
for(i=c;i>1;i--)
  if(a%i==0 && b%i==0) je=0;

if (je==1) return 1;
         else return 0;
}


int main ()
{

int a,b,encr,length,i,j,*novi,inv,k,redak;
char koji,*kon;
char tekst[15000],enter;


printf("\nAffine cipher. Alphabet: English\n\nFor encrypting press 1, for decrypting anything else:\n\n");
scanf("%c",&koji);
printf("\n\n");
if(koji=='1') encr=1;
            else encr=0;

if(encr==1) {
scanf("%c",&enter);
printf("Type in the text that you want to encrypt:\n\n");

scanf("%[^\n]",tekst);
scanf("%c",&enter);

printf("\n\nType a:   ");
while (1)
{
    scanf("%d",&a);
    if (relprost(a,26)==0 || a>25) printf("\nError in selection of \"a\"\n\nTry again:  ");
    else break;
}
printf("\n\nType b:   ");  scanf("%d",&b);
if (b>25) printf("\nB integer from 0 to 25, b converted to %d",b%26);
printf("\n\n");
length=strlen(tekst);

novi=(int*)malloc((length+1)*sizeof(int));
kon=(char*)malloc((length+1)*sizeof(char));

for(i=0;i<length;i++)
{
    if (tekst[i]==' ') novi[i]=-1;
    else novi[i]=encrypt(a,b,tekst[i]);
}
for (i=0;i<length;i++)
{
    if(novi[i]==-1) kon[i]=' ';
    else kon[i]=decrypt(novi[i]);
    printf("%c",kon[i]);
}

    printf("\n\n");
}         /*if*/
else {
redak=1;
scanf("%c",&enter);
printf("Type in the text that you want to decrypt:\n\n");

scanf("%[^\n]",tekst);
scanf("%c",&enter);
length=strlen(tekst);

novi=(int*)malloc((length+1)*sizeof(int));
kon=(char*)malloc((length+1)*sizeof(char));

for(i=1;i<26;i++)
{
    if(relprost(i,26)==0) continue;
inv=inverse(i);

for(k=0;k<26;k++)
{

     for(j=0;j<length;j++)
     {
        if (tekst[j]==' ') novi[j]=-1;
        else novi[j]=encrypt2(inv,k,tekst[j]);
     }
    for(j=0;j<length;j++)
    {
        if (novi[j]==-1) kon[j]=' ';
        else kon[j]=decrypt(novi[j]);
    }
    printf("L:%3d,a=%2d,b=%2d: ",redak,i,k);
   for(j=0;j<length;j++)
    {
    printf("%c",kon[j]);
    }
    printf("\n");
    redak++;
}   /* for b */

}   /* for a */

}   /* else */
free(novi);
free(kon);

    return 0;
}

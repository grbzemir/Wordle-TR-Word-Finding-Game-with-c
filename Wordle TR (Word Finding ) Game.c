#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>   
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<stddef.h>

char kelimeler[][5] = {"ARMUT","KEMAL","KUBRA","FATMA","MURAT","MESUT","YALIM","BILGE","AYDAN","EREN"};
char kelime[5];
char tahmin[5];
char bilinenHarfler[5];
char tablo[6][5];
int indis;
int index;
int sonuc;


void kelimeUret()
{
   
    srand(time(0));
    indis = rand() % 10;
    int i;
    i=0;
    while(i<5)
    {
        kelime[i]=kelimeler[indis][i];
        i++;
    }
    index=0;
    sonuc=0;
    printf("kelime: %s \n\n",kelime);
     

}

void yesilRenk()
{

HANDLE yesilRenk = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(yesilRenk,FOREGROUND_GREEN);


}

void normalRenk()
{

 HANDLE normalRenk = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(normalRenk,FOREGROUND_RED);

}


int tabloDoldur()
{
  
  int sonuc;
  int i;
  sonuc=1;
  for(i=0;i<5;i++)
  {

    if(tahmin[i] != kelime[i])

    {
        sonuc=0;
        bilinenHarfler[i]=-'-';
    }

    else

       bilinenHarfler[i]=tahmin[i];
    

    tablo[index][i] =  tahmin[i]; //tahmin edilen kelimeyi tabloya ekle
     
  }


   index++;

   return sonuc;


}

void tabloYazdir()
{

   int i;
   int j;
   system("cls");
   printf("\n\nKELIME BULMA OYUNU\n\n");

   for(i=0;i<6;i++)

   {

    printf("\t\t");
    for (j=0;j<5;j++)
    {
        
          if (i==index -1)
          {
            if (tahmin[j]==kelime[j])
            {
                printf(" [" );
                yesilRenk();
                printf("%c",tahmin[j]);
                normalRenk();
                printf("] ");
            }

            else
            
                printf(" [%c]",tahmin[j]);
            
          }

            else
            
            printf(" [%c]",tablo[i][j]);
            normalRenk();
                
            }

    printf("\n\n");
    
   }

   yesilRenk();
   normalRenk();
        
}

    

int main ()
{

    int sayac=0;
    int n;
    int sonuc;
    tabloYazdir();
    kelimeUret();

 while(sayac<6)

  {

    printf("%d. Tahmininiz: ",(sayac+1));
    scanf("%s",tahmin);
    strupr(tahmin); //küçük harfleri büyük harfe çevirir strupr fonksiyonu
    
    n=strlen(tahmin);
    
    if (n!=5)

    {
        printf("Kelime 5 harfli olmalidir. Tekrar deneyiniz.\n");
        continue;
        

    }
    
    sonuc=tabloDoldur();
    tabloYazdir();

    if(sonuc==1)
    break;

    sayac++;

    }

    if(sonuc==1)

    {
        printf("Tebrikler kazandiniz.\n");
        printf("Gizli kelime: \n ");
        yesilRenk();
        printf("%s",kelime);
        normalRenk();

    }

    else

    {
        printf("Kaybettiniz.\n");
        printf("Gizli kelime: %s",kelime);
        yesilRenk();
        printf("%s",kelime);
        normalRenk();
        
    }


    return 0;
}
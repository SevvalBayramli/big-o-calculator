#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
int forSayisi=0;
int sayac=0;
int sayac2=0;
int max=0;
int dizi[100];
int icice=0;
int esittir=0;
int whileSayisi=0;
int parantezSayisi=0;
int parantezSayisi2=0;
int NlogN=0;
int NlogN_=0;
char *f="for";
char *w="while";


FILE *fp;
FILE *sa;
char *int_="int";
char *float_="float";
char *double_="double";
char *long_="long";
char *char_="char";
char *printf_="printf";

int yerKarmasikligi=0;
int intSayisi=0;
int floatSayisi=0;
int doubleSayisi=0;
int longSayisi=0;
int charSayisi=0;
int logN;

int zaman=0;
int bigonotasyonunkare()
{
    int t;
    for(int i=0; i<sayac; i++)
    {
        for(int j=0; j<sayac; j++)
        {
            if(dizi[j]<=dizi[i])
            {
                t=dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=t;
            }
        }
    }


    if(dizi[0]==0)
        return 0;
    else
        return dizi[0]+1;


}

int ParantezKontrol(char c[250])
{
    parantezSayisi=1;
    for(int i=0; i<strlen(c); i++)
    {
        if(c[i]=='{')
        {
            parantezSayisi++;

        }
        else if(c[i]=='}')
        {
            parantezSayisi--;

        }

    }
    if(parantezSayisi==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ParantezKontrol2(char c[255])
{
    //parantezSayisi2=1;
    for(int i=0; i<strlen(c); i++)
    {
        if(c[i]=='(')
        {
            parantezSayisi2++;

        }
        else if(c[i]==')')
        {
            parantezSayisi2--;
        }

    }
    if(parantezSayisi2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void iciceDongu()
{

    int i=0;

    if(icice!=0)
    {
        dizi[sayac]=icice;
    }
    sayac++;
}
int parantezici(char c[255])
{

    while(!feof(fp))
    {


        if(strstr(c,"=")!=0)
        {
            esittir++;
        }
        if(strstr(c,"*")!=0)
        {
            logN++;

        }
        if(strstr(c,"/")!=0)
        {
            logN++;
        }


        fscanf(fp,"%s",c);

        if(ParantezKontrol2(c)==1)
        {

            break;
        }
    }


}


void ZamanKarmasikligiYazdirma()
{
    if(bigonotasyonunkare()>0)
        printf("\nZaman karmasikligi: O(n^%d)",bigonotasyonunkare());
    else if(NlogN>0)
        printf("\nZaman karmasikligi: O(nlogn)");
    else if(dizi[0]==0&&logN==0&&forSayisi>0||whileSayisi>0)
        printf("\nZaman karmasikligi: O(n) ");
    else if(dizi[0]==0&&forSayisi==1&&whileSayisi==0&&logN==1)
        printf("\nZaman karmasikligi: O(logn)");
    else
        printf("\nZaman karmasikligi: O(1)");

}


void YerKarmasikligiYazdirma()
{
    if(dizi[0]!=0)
    {
        if(esittir==0)
            printf("\nyer karmasikligi: n^%d+%d",bigonotasyonunkare(),yerKarmasikligi);
        else
            printf("\nyer karmasikligi: %dn^%d+%d",esittir,bigonotasyonunkare(),yerKarmasikligi);
    }

    else if(dizi[0]==0||forSayisi>0||whileSayisi>0)
        if(esittir==0)
            printf("\nyer karmasikligi: n^%d+%d",bigonotasyonunkare()+1,yerKarmasikligi);
        else
            printf("\nyer karmasikligi: %dn^%d+%d O(n^%d)",esittir,bigonotasyonunkare()+1,yerKarmasikligi,bigonotasyonunkare()+1);

}

void nlogN()
{
    icice--;
    NlogN_++;
    NlogN=NlogN_;
}

void forDongusu(char *c)
{

    while(!feof(fp))
    {

        fscanf(fp,"%s",c);


        char *p=c;
        if(sayac2<1)
        {
            sayac2++;
            parantezici(c);
        }
        if(strstr(p,"=")!=0)
        {
            esittir++;
        }
        if(strstr(p,f)!=0)
        {

            icice++;
            sayac2=0;
            forDongusu(c);
            if(icice==1&&logN>0)
            {
                nlogN();
            }
            logN=0;
        }
        if(strstr(p,w)!=0)
        {
            icice++;
            sayac2=0;
            whileDongusu(c);

        }

        if(ParantezKontrol(c)==1)
        {
            break;
        }
    }
}
void whileDongusu(char *c)
{

    while(!feof(fp))
    {

        fscanf(fp,"%s",c);

        char *p=c;
        if(sayac2<1)
        {
            sayac2++;
            parantezici(c);
        }
        if(strstr(p,"=")!=0)
        {
            esittir++;
        }
        if(strstr(p,f)!=0)
        {
            icice++;
            sayac2=0;
            forDongusu(c);
        }
        if(strstr(p,w)!=0)
        {
            icice++;
            sayac2=0;
            whileDongusu(c);
        }

        if(ParantezKontrol(c)==1)
        {
            break;
        }
    }
}
void dowhileDongusu(char *c)
{
    esittir++;
    while(!feof(fp))
    {
        fscanf(fp,"%s",c);

        char *p=c;
        if(sayac2<1)
        {
            sayac2++;
            parantezici(c);
        }
        if(strstr(p,"=")!=0)
        {
            esittir++;
        }
        if(strstr(p,f)!=0)
        {
            icice++;
            forDongusu(c);
        }
        if(strstr(p,"do")!=0)
        {
            icice++;
            dowhileDongusu(c);
        }
        if(ParantezKontrol(c)==1)
        {
            break;
        }
    }
}
int main()
{
    clock_t start_t, end_t;
    system("color b");
    int i=0;
    int konum;
    char c[255];
    fp=fopen("dosya.txt","r+");

    if(fp==NULL)
    {
        printf("dosya acilamadi");
    }
    else
    {
        while(!feof(fp))
        {

            fscanf(fp,"%s",c);

            char *p=c;

            if(strstr(p,f)!=0)
            {
                forSayisi++;
                forDongusu(c);
                iciceDongu();
                icice=0;
            }
            if(strstr(p,"do")!=0)
            {

                dowhileDongusu(c);
                iciceDongu();
                icice=0;

            }
            if(strstr(p,w)!=0)
            {
                whileSayisi++;
                whileDongusu(c);
                iciceDongu();
                icice=0;

            }
        }
        ZamanKarmasikligiYazdirma();
    }

    fclose(fp);




    char a[255];
    char b[255];
    fp=fopen("dosya.txt","r+");
    if(fp==NULL)
    {
        printf("dosya acilamadi");
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s",a);


            char *p2=a;

            if(strstr(p2,int_)!=0)
            {
                if(strstr(p2,printf_)==0)
                {
                    intSayisi++;

                    fscanf(fp,"%s",b);

                    if(strstr(b,"main")!=0)
                    {
                        intSayisi--;
                    }
                }
            }
            if(strstr(p2,float_)!=0)
            {
                yerKarmasikligi=yerKarmasikligi+sizeof(float);
                floatSayisi++;
            }
            if(strstr(p2,double_)!=0)
            {
                yerKarmasikligi=yerKarmasikligi+sizeof(double);
                doubleSayisi++;
            }
            if(strstr(p2,long_)!=0)
            {
                yerKarmasikligi=yerKarmasikligi+sizeof(long);
                longSayisi++;
            }
            if(strstr(p2,char_)!=0)
            {
                yerKarmasikligi=yerKarmasikligi+sizeof(char);
                charSayisi++;
            }
        }

        yerKarmasikligi=yerKarmasikligi+intSayisi*sizeof(int);
        YerKarmasikligiYazdirma();


    }
    fclose(fp);

    start_t = clock();
    system("gcc kod.c -o kod");
    end_t = clock();

    printf("\nKodun Calisma Zamani %f saniyedir.", (double)(end_t - start_t) / CLOCKS_PER_SEC);

    return 0;
}

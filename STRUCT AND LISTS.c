//erayskywalker'ın katkılarıyla//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>w 
struct student
{
	char no[10];
	char ad[20];
	int vize;
	int final;
	float ort;
	struct student *next;
};
int kisi=0;
float sinifort=0;
typedef struct student node;
node *head,*p;
int main() 
{
	int n,k;

	printf("listede olacak ogrenci sayisini giriniz = ");
	scanf("%d",&n);
	kisi=n;
	for(k=0;k<n;k++)
	{
		if(k==0)
		{
			head=(node*)malloc(sizeof(node));
			p=head;
		}
		else
		{
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
		}
		printf("%d. ogrencinin no giriniz = ",k+1); scanf("%s",p->no);
		printf("%d. ogrencinin ad giriniz = ",k+1); scanf("%s",p->ad);
		printf("%d. ogrencinin vize notunu giriniz = ",k+1); scanf("%d",&p->vize);
		printf("%d. ogrencinin final notunu giriniz = ",k+1); scanf("%d",&p->final);
		p->ort=(p->vize*0.4)+(p->final*0.6);
	}
	p->next=NULL;
	
	int secim;
	
	while(secim!=-1)
	{
		printf("1-KAYIT EKLEME\n2-KAYIT LISTELEME\n3-KAYIT GUNCELLEME\n4-KAYIT SILME\n5-SINIF ORTALAMA HESAPLA\n6-ORTALAMAYA GORE EN BASARILI OGRENCI BILGISINI GOSTER\n\n\nCIKIS ICIN -1 TUSLAYINIZ.");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
			{
				yenikayit();
				break;
			}
			case 2:
			{
				listeleme();
				break;
			}
			case 3:
			{
				KayitGuncelle();
				break;
			}
			case 4:
			{
				KayitSil();
				break;
			}
			case 5:
			{
				SinifOrtalamasi();
				break;
			}
			case 6:
			{
				Eniyiler();
				break;
			}
		}
	}
	return 0;
}
void yenikayit()
{
	p->next=(node*)malloc(sizeof(node));
	p=p->next;
	kisi++;
	
	printf("Kaydedilecek ogrencinin no = ");
	scanf("%s",p->no);
	printf("Kaydedilecek ogrencinin ad = ");
	scanf("%s",p->ad);
	printf("Kaydedilecek ogrencinin vize notu = ");
	scanf("%d",&p->vize);
	printf("Kaydedilecek ogrencinin final notu = ");
	scanf("%d",&p->final);
	p->ort=(p->vize*0.4)+(p->final*0.6);
	
	getchar();
	p->next=NULL;
}
void listeleme()
{
	node *p;
	p=head;
	char ogrno[10];
	char isim[20];
	float not;
	printf("***Listeleme Secenekleri***\n1-Numaraya gore ara\n2-Isme gore ara\n3-Girilen basari puaninin uzerinde olanlari listele\nsecim..:");
        int secenek = 0;
        scanf("%d", &secenek);

        switch (secenek)
        {
        case 1:
		    printf("ogrenci numarasi giriniz..:");
            scanf("%s",ogrno);
			int i = 0;
            for ( i=0;i<kisi;i++)
            {
                if (strcmp(ogrno, p->no) == 0)
                {
                    printf("Ogrenci no: %s\n", p->no);
                    printf("Ogrenci adi: %s\n", p->ad);
                    printf("Ogrenci vize notu: %d\n", p->vize);
                    printf("Ogrenci final notu: %d\n", p->final);
                    printf("Ogrenci ortalama: %0.2f\n", p->ort);
                    p = p->next;
                }
                else
                    p = p->next;
            }
            break;

        case 2:
            printf("isim giriniz:");
            fflush(stdin);
            gets(isim);
			int j=0;
            for (j= 0;j<kisi;j++)
            {
                if (strcmp(isim, p->ad) == 0)
                {
                    printf("Ogrenci no: %s\n", p->no);
                    printf("Ogrenci adi: %s\n", p->ad);
                    printf("Ogrenci vize notu: %d\n", p->vize);
                    printf("Ogrenci final notu: %d\n", p->final);
                    printf("Ogrenci ortalama: %0.2f\n", p->ort);
                    p = p->next;
                }
                else
                    p = p->next;
            }
            break;

        case 3:
            printf("Basari puani:");
            scanf("%f", &not );
            int k=0;
            for (k=0;k<kisi;k++)
            {
                if (not <= p->ort)
                {
                    printf("Ogrenci no..: %s\n", p->no);
                    printf("Ogrenci adi..: %s\n", p->ad);
                    printf("Ogrenci vize notu..: %d\n", p->vize);
                    printf("Ogrenci final notu..: %d\n", p->final);
                    printf("Ogrenci ortalama..: %0.2f\n", p->ort);
                    p = p->next;
                }
                else
                    p = p->next;
            }
            break;

        default:
            printf("boyle bir islem bulunamadi..!");
            break;
        }
    }
void KayitGuncelle()
{
	char ogrno[10];
	printf("Hangi no'lu ogrenciyi guncellemek istiyorsunuz..:");
    
    fflush(stdin);
    gets(ogrno);
    
	int degisiklikVarMi = 0;
    node *gecici;
    gecici = head;

    while (gecici != NULL)
    {
        if (strcmp(gecici->no, ogrno) == 0)
        {
            fflush(stdin);

            printf("Ogrenci numarasi:");
            gets(gecici->no);

            printf("Ogrencinin adi:");
            gets(gecici->ad);

            printf("Ogrencinin vize notu:");
            scanf("%d", &gecici->vize);

            printf("Ogrencinin final notu:");
            scanf("%d", &gecici->final);
            gecici->ort = (gecici->vize * 0.4) + (gecici->final * 0.6);
            
            degisiklikVarMi++;
        }
        gecici = gecici->next;
    }
}
void KayitSil()
{
    printf("Hangi no'lu ogrenciyi silmek istiyorsunuz:");

    char c[10];
    fflush(stdin);
    gets(c);

    node *gecici, *q;
    gecici = head;

    if (strcmp(gecici->no, c) == 0)
    {
        head = gecici->next;
        free(gecici);
        kisi--;
    }
    else
    {
        while (gecici != NULL && strcmp(gecici->no, c) != 0)
        {
            q = gecici;
            gecici = gecici->next;
        }
        if (strcmp(gecici->no, c) == 0)
        {
            q->next = gecici->next;
            free(gecici);
           kisi--;
        }

        else if (gecici->next == NULL)
        {
            printf("boyle bir ogrenci bulunamadi..!");
        }
    }
}
void SinifOrtalamasi()
{
    sinifort = 0;
    node *p;
    p = head;
	int i = 0;
    for ( i = 0; i < kisi; i++)
    {
        sinifort += p->ort;
        p = p->next;
    }
    sinifort /= kisi;
    printf("%0.2f\n", sinifort);
}
void Eniyiler()
{
    node *p;
    p = head;
	int i = 0;
    for ( i = 0; i < kisi; i++)
    {
        if (p->ort >= sinifort)
        {
            printf("%s %s\n",p->no);
        }
        p = p->next;
    }
}


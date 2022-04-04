#include <stdio.h>
#include <stdlib.h>

struct queue{

	struct queue *next;
	int oncelik_id;
	int ucak_id;
	int talep_edilen_inis_saati;
	int inis_saati;
	int gecikme_suresi;
	int kalkis_saati;

};

typedef struct queue node;
node *yerlestir(node *r,node *listedeki);
node * add(node* kuyruk,node *eklenecek);
int c=0;
node *front;
node *inis_pisti_kullanim_sirasi;
node *kalkis_pisti_kullanim_sirasi;
node *end;
FILE *indexdosyasi;
FILE *outputdosyasi;
node *son;
node *active;


node *dolas(node *r,node *listedeki){
	if((r->talep_edilen_inis_saati+r->gecikme_suresi) == (listedeki->talep_edilen_inis_saati+listedeki->gecikme_suresi)){
		if(listedeki->oncelik_id < r->oncelik_id){
			r->gecikme_suresi++;
			listedeki->next=r->next;
			listedeki->inis_saati=listedeki->talep_edilen_inis_saati+listedeki->gecikme_suresi;
      if(active->ucak_id==listedeki->ucak_id){
        printf("\n%d nolu ucaga inis izni verilmistir.\n",active->ucak_id);
      }
			listedeki=add(listedeki,r);
			return listedeki;
		}else {
			listedeki->gecikme_suresi++;
			r=add(r,listedeki);
			return r;
			}

	}else{
		node *iter;
    node *temp = (node *)malloc(sizeof(node));
		iter=r;
		if(listedeki->oncelik_id < iter->next->oncelik_id){
			iter->next->gecikme_suresi++;
			listedeki->inis_saati=listedeki->talep_edilen_inis_saati+listedeki->gecikme_suresi;
			if(iter->next->gecikme_suresi==4){
				iter->next->inis_saati=-1;
        listedeki->next=iter->next->next;
        temp=iter->next;
        printf("\n%d numarali ucagin dikkatine,acil inis yapmasi gereken %d ucagi nedeniyle inis izniniz iptal edilmistir.\nInis icin Sabiha Gokcen Havalimani'na yonlendiriliyorsunuz.\n",iter->next->ucak_id,listedeki->ucak_id);
  			iter->next=listedeki;
				return r;
			}
			listedeki->next=iter->next->next;
      temp=iter->next;
			iter->next=listedeki;
      if(active->ucak_id==listedeki->ucak_id){
        printf("\n%d nolu ucaga inis izni verilmistir.\n",active->ucak_id);
      }
			r=add(r,temp);
			return r;
		}else if(listedeki->oncelik_id == iter->next->oncelik_id){
			if(listedeki->ucak_id < iter->next->ucak_id){
				iter->next->gecikme_suresi++;
				iter->next->inis_saati=iter->next->talep_edilen_inis_saati+iter->next->gecikme_suresi;
				listedeki->inis_saati=listedeki->talep_edilen_inis_saati+listedeki->gecikme_suresi;
				if(iter->next->gecikme_suresi==4){
          iter->next->inis_saati=-1;
          temp=iter->next;
  				listedeki->next=iter->next->next;
          printf("\n%d numarali ucagin dikkatine,acil inis yapmasi gereken %d ucagi nedeniyle inis izniniz iptal edilmistir.\nInis icin Sabiha Gokcen Havalimani'na yonlendiriliyorsunuz.\n",iter->next->ucak_id,listedeki->ucak_id);
  				iter->next=listedeki;
					return r;
				}
        temp=iter->next;
				listedeki->next=iter->next->next;
				iter->next=listedeki;
				temp->next=NULL;
				r=add(r,temp);
				return r;
			}else{
				listedeki->gecikme_suresi++;
				if(listedeki->gecikme_suresi==4){
					listedeki->inis_saati=-1;
          if(active->ucak_id==listedeki->ucak_id){
            printf("\n%d numarali ucaga uygun inis saati bulunamadigindan izin verilememektedir.\n",listedeki->ucak_id);
            return r;
          }
          printf("\n%d numarali ucagin dikkatine,acil inis yapmasi gereken %d ucagi nedeniyle inis izniniz iptal edilmistir.\nInis icin Sabiha Gokcen Havalimani'na yonlendiriliyorsunuz.\n",listedeki->ucak_id,iter->next->ucak_id);
					return r;
				}
				r=add(r,listedeki);
				return r;
			}
		}else{
			listedeki->gecikme_suresi++;
			if(listedeki->gecikme_suresi==4){
        listedeki->inis_saati=-1;
        if(active->ucak_id==listedeki->ucak_id){
          printf("\n%d numarali ucaga uygun inis saati bulunamadigindan izin verilememektedir.\n",listedeki->ucak_id);
          return r;
        }
        printf("\n%d numarali ucagin dikkatine,acil inis yapmasi gereken %d ucagi nedeniyle inis izniniz iptal edilmistir.\nInis icin Sabiha Gokcen Havalimani'na yonlendiriliyorsunuz.\n",listedeki->ucak_id,iter->next->ucak_id);
				return r;
			}
			r=add(r,listedeki);
			return r;
			}
	}
}

node * add(node* kuyruk,node *eklenecek){
	node *iter;
	node *gezici;
	iter=kuyruk;
  if((eklenecek->talep_edilen_inis_saati+eklenecek->gecikme_suresi)>10){
    return kuyruk;
  }
	if(kuyruk->ucak_id==-1){
    node * kuyruk2 = (node *)malloc(sizeof(node));
		kuyruk2->ucak_id=eklenecek->ucak_id;
		kuyruk2->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
		kuyruk2->gecikme_suresi=eklenecek->gecikme_suresi;
		kuyruk2->oncelik_id=eklenecek->oncelik_id;
		kuyruk2->inis_saati=kuyruk->talep_edilen_inis_saati+kuyruk->gecikme_suresi;
		kuyruk2->next = NULL;
    if(active->ucak_id==kuyruk2->ucak_id){
      printf("\n%d nolu ucaga inis izni verilmistir.\n",active->ucak_id);
    }
		return kuyruk2;
	}
	if((kuyruk->talep_edilen_inis_saati+kuyruk->gecikme_suresi)>(eklenecek->talep_edilen_inis_saati+eklenecek->gecikme_suresi)){
		node * yenikuyruk = (node *)malloc(sizeof(node));
		yenikuyruk->ucak_id=eklenecek->ucak_id;
		yenikuyruk->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
		yenikuyruk->gecikme_suresi=eklenecek->gecikme_suresi;
		yenikuyruk->oncelik_id=eklenecek->oncelik_id;
		yenikuyruk->next=kuyruk;
		yenikuyruk->inis_saati=yenikuyruk->talep_edilen_inis_saati+yenikuyruk->gecikme_suresi;
    if(active->ucak_id==yenikuyruk->ucak_id){
      printf("\n%d nolu ucaga inis izni verilmistir.\n",active->ucak_id);
    }
		return yenikuyruk;
	}else{
		int i=0;
		if((kuyruk->talep_edilen_inis_saati+kuyruk->gecikme_suresi)==(eklenecek->talep_edilen_inis_saati+eklenecek->gecikme_suresi)){
			node *temp =(node *)malloc(sizeof(node));
			temp->ucak_id=eklenecek->ucak_id;
			temp->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
			temp->gecikme_suresi=eklenecek->gecikme_suresi;
			temp->oncelik_id=eklenecek->oncelik_id;
			temp->inis_saati=eklenecek->inis_saati;
			temp->next=NULL;
			kuyruk=dolas(kuyruk,temp);
			return kuyruk;
		}
		int aaaa=0;
		iter=kuyruk;
		while(iter->next!=NULL&&(iter->next->talep_edilen_inis_saati+iter->next->gecikme_suresi)<(eklenecek->talep_edilen_inis_saati+eklenecek->gecikme_suresi)){
			iter=iter->next;

			if(iter->next==NULL){
				break;
			}
		}
		if(iter->next==NULL){
			gezici=(node *)malloc(sizeof(node));
			gezici->ucak_id=eklenecek->ucak_id;
			gezici->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
			gezici->gecikme_suresi=eklenecek->gecikme_suresi;
			gezici->oncelik_id=eklenecek->oncelik_id;
			gezici->next=NULL;
			iter->next=gezici;
			gezici->inis_saati=gezici->talep_edilen_inis_saati+gezici->gecikme_suresi;
      end=gezici;
      if(active->ucak_id==gezici->ucak_id){
        printf("\n%d nolu ucaga inis izni verilmistir.\n",active->ucak_id);
      }
			return kuyruk;
		}
		if((iter->next->talep_edilen_inis_saati+iter->next->gecikme_suresi)==(eklenecek->talep_edilen_inis_saati+eklenecek->gecikme_suresi)){
			if(iter->next->gecikme_suresi==3){
				if((eklenecek->gecikme_suresi==3) && (iter->next->ucak_id > eklenecek->ucak_id)){
					node *temp =(node *)malloc(sizeof(node));
					temp->ucak_id=eklenecek->ucak_id;
					temp->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
					temp->gecikme_suresi=eklenecek->gecikme_suresi;
					temp->oncelik_id=eklenecek->oncelik_id;
					temp->inis_saati=temp->talep_edilen_inis_saati+temp->gecikme_suresi;
					printf("\n%d nolu ucagin ertelenme limiti doldugu icin, %d nolu ucagin inis izni iptal edilip baska havalimanina yonlendiriliyor.\n",eklenecek->ucak_id,iter->next->ucak_id);
					temp->next=iter->next->next;
					iter->next=temp;
					return kuyruk;
				}if(eklenecek->gecikme_suresi==3){
          if(eklenecek->inis_saati!=-1){
            printf("\nAcil inis yapmasi gereken %d ucagi nedeniyle, %d nolu ucagin inis izni iptal edilip baska havalimanina yonlendiriliyor.\n",active->ucak_id,eklenecek->ucak_id);
            return kuyruk;
          }
					printf("\n%d nolu ucagin ertelenme limiti doldugu icin, %d nolu ucaga inis izni verilememektedir.\n",iter->next->ucak_id,eklenecek->ucak_id);
					return kuyruk;
				}
				node *temp =(node *)malloc(sizeof(node));
				temp->ucak_id=eklenecek->ucak_id;
				temp->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
				temp->gecikme_suresi=eklenecek->gecikme_suresi;
				temp->oncelik_id=eklenecek->oncelik_id;
				temp->inis_saati=eklenecek->inis_saati;
				if(iter->next->oncelik_id > temp->oncelik_id && iter->next->oncelik_id == temp->oncelik_id){
					temp->gecikme_suresi++;
					kuyruk=add(kuyruk,temp);
					return kuyruk;
				}
				temp->gecikme_suresi++;
				kuyruk=add(kuyruk,temp);
				return kuyruk;

			}if((eklenecek->gecikme_suresi==3) && (eklenecek->inis_saati!=-1)){
				node *temp =(node *)malloc(sizeof(node));
				temp->ucak_id=eklenecek->ucak_id;
				temp->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
				temp->gecikme_suresi=eklenecek->gecikme_suresi;
				temp->oncelik_id=eklenecek->oncelik_id;
				temp->inis_saati=temp->talep_edilen_inis_saati+temp->gecikme_suresi;
				temp->next=iter->next->next;
		//		printf("%d inis icin onay alamamistir.",iter->next->ucak_id);
				node *arayakoy =(node *)malloc(sizeof(node));
				arayakoy->ucak_id=iter->next->ucak_id;
				arayakoy->talep_edilen_inis_saati=iter->next->talep_edilen_inis_saati;
				arayakoy->gecikme_suresi=iter->next->gecikme_suresi;
				arayakoy->oncelik_id=iter->next->oncelik_id;
				arayakoy->next=NULL;
				arayakoy->gecikme_suresi++;
				iter->next=temp;
        if(active->ucak_id==temp->ucak_id){
          printf("\n%d nolu ucaga inis izni verilmistir.\n",active->ucak_id);
        }if(iter->next->next!=NULL){
          iter->next=dolas(iter->next,arayakoy);
  				return kuyruk;
        }
				kuyruk=add(kuyruk,arayakoy);
				return kuyruk;
			}
			node *temp =(node *)malloc(sizeof(node));
			temp->ucak_id=eklenecek->ucak_id;
			temp->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
			temp->gecikme_suresi=eklenecek->gecikme_suresi;
			temp->oncelik_id=eklenecek->oncelik_id;
			temp->inis_saati=eklenecek->inis_saati;
			temp->next=NULL;
			iter=dolas(iter,temp);
			return kuyruk;
		}
		else{
			node *arayakoy =(node *)malloc(sizeof(node));
			node *temp =(node *)malloc(sizeof(node));
			temp=iter->next;
			arayakoy->ucak_id=eklenecek->ucak_id;
			arayakoy->talep_edilen_inis_saati=eklenecek->talep_edilen_inis_saati;
			arayakoy->gecikme_suresi=eklenecek->gecikme_suresi;
			arayakoy->oncelik_id=eklenecek->oncelik_id;
			arayakoy->inis_saati=arayakoy->talep_edilen_inis_saati+arayakoy->gecikme_suresi;
			iter->next=arayakoy;
			arayakoy->next=temp;
      if(active->ucak_id==arayakoy->ucak_id){
        printf("\n%d nolu ucaga inis izni verilmistir.\n",active->ucak_id);
      }
			return kuyruk;
		}
	}
}

void txtyaz(node *yazilacak){
	node *iter2;
	outputdosyasi = fopen("output.txt","w");
	if (outputdosyasi == NULL){
	printf("\noutput dosyasi olusturulamadi\n");}else{
	printf("\n\noutput dosyasi olusturuldu!\n");
	iter2=yazilacak;
	fprintf(outputdosyasi,"oncelik_id ucak_id talep_edilen_inis_saati inis_saati gecikme_suresi kalkis_saati");
	if (iter2 != NULL){
		iter2->inis_saati=iter2->talep_edilen_inis_saati+iter2->gecikme_suresi;
		iter2->kalkis_saati=iter2->inis_saati+1;
		fprintf(outputdosyasi,"\n%d %d %d %d %d %d",iter2->oncelik_id,iter2->ucak_id,iter2->talep_edilen_inis_saati,iter2->inis_saati,iter2->gecikme_suresi,iter2->kalkis_saati);
	}
	if(iter2->next != NULL){
//		fprintf(indexdosyasi,"%d %d %d %d %d %d\n",iter2->oncelik_id,iter2->talep_edilen_inis_saati,iter2->gecikme_suresi,iter2->inis_saati,iter2->kalkis_saati);
		while (iter2->next != NULL){
			iter2= iter2->next;
      iter2->inis_saati=iter2->talep_edilen_inis_saati+iter2->gecikme_suresi;
      iter2->kalkis_saati=iter2->inis_saati+1;
			if(iter2==NULL){
				fprintf(outputdosyasi,"%d %d %d %d %d %d",iter2->oncelik_id,iter2->ucak_id,iter2->talep_edilen_inis_saati,iter2->inis_saati,iter2->gecikme_suresi,iter2->kalkis_saati);
				break;
			}
			fprintf(outputdosyasi,"\n%d %d %d %d %d %d",iter2->oncelik_id,iter2->ucak_id,iter2->talep_edilen_inis_saati,iter2->inis_saati,iter2->gecikme_suresi,iter2->kalkis_saati);
		}
	}
	kalkis_pisti_kullanim_sirasi=yazilacak;
	node *gezz=kalkis_pisti_kullanim_sirasi;
	printf("\n");
	while(gezz != NULL){
    printf("%d	%d	%d	%d	%d	%d\n",gezz->oncelik_id,gezz->ucak_id,gezz->talep_edilen_inis_saati,gezz->inis_saati,gezz->gecikme_suresi,gezz->kalkis_saati);
    gezz=gezz->next;
  }
	printf("\n\n");
	fclose(outputdosyasi);
	}
}

int main(){
  int kesici;
  node * kuyruk = (node *)malloc(sizeof(node));
  kuyruk->ucak_id=-1;
	node * r = (node *)malloc(sizeof(node));
	node * iter;
	node *temp;
	r->next = NULL;
	char kelime[500],kelime2[500],kelime3[500];
	int offset;
	iter = r;
	int x,y,z;
	indexdosyasi = fopen("input.txt","r");
	if (indexdosyasi == NULL){
	printf("dosya okunamadi");}else{
		fscanf(indexdosyasi,"%s %s %s",&kelime,&kelime2,&kelime3);
	 	while(! feof(indexdosyasi)){
   			 fscanf(indexdosyasi,"%d %d %d",&x,&y,&z);
   			 iter->oncelik_id=x;
   			 iter->ucak_id=y;
   			 iter->talep_edilen_inis_saati=z;
				 iter->gecikme_suresi=0;
				 iter->inis_saati=-1;
				 printf("Okunan input : %d\t%d\t%d\n",x,y,z);
   			 temp=iter;
				 active=iter;
         kuyruk=add(kuyruk,iter);
				 inis_pisti_kullanim_sirasi=kuyruk;
         front=kuyruk;
         txtyaz(kuyruk);

  		}
	}
	temp->next=NULL;
  fclose(indexdosyasi);
  printf("Sorunsuz calisti.");
	return 0;
}


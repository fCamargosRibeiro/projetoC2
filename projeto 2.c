#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>

#define  BACKSPACE 8  
#define  ENTER 13 
#define  ESC 27 
#define  INSERT 82
#define  DELET 83

#define  CIMA 72
#define  ESQ 75
#define  DIR 77
#define  BAIXO 80
/*----------------------------------------------------------------------------*/
/*funçoes a emplementar:
          adicionarlinha
          adicionarcoluna


*/


typedef struct noh{
        char letra;
        int col;
        int lin;
        struct noh* cima;
        struct noh* baixo;
        struct noh* esq;
        struct noh* dir;
}noh;
/*----------------------------------------------------------------------------*/
typedef struct slinha{
        int num;
        noh* info;
        struct slinha* next;
        struct slinha* back;
}linha;
/*----------------------------------------------------------------------------*/
typedef struct scoluna{
        int num;
        noh* info;
        struct scoluna* next;
        struct scoluna* back;
}coluna;
/*----------------------------------------------------------------------------*/
typedef struct exterior{
        noh* atual;
        noh* fim;
        linha* linhaat;
        coluna* colunaat;
}externo;
/*----------------------------------------------------------------------------*/
void gotoxy(int x, int y) 
{   
  COORD coord;   
  HANDLE handle;   
  handle = GetStdHandle(STD_OUTPUT_HANDLE);
  coord.X = x;   
  coord.Y = y;   
  SetConsoleCursorPosition(handle, coord);
}
/*----------------------------------------------------------------------------*/
void inicializarponteiros(externo** ponteiro){// inicializarponteiros(&ponteiro);   externo ponteiro
     (*ponteiro)->atual = NULL;     
     (*ponteiro)->fim = NULL;
     (*ponteiro)-> linhaat = NULL;
     (*ponteiro)-> colunaat;
}
/*----------------------------------------------------------------------------*/
void getnode(noh** aux){
     *aux=(noh*)malloc(sizeof(noh));
     (*aux)->letra=' ';
     (*aux)->col=-1;
     (*aux)->lin=-1;
     (*aux)->cima=NULL;
     (*aux)->baixo=NULL;
     (*aux)->esq=NULL;
     (*aux)->dir=NULL;

}
/*----------------------------------------------------------------------------*/
void getlinha(linha** linh){
     *linh=(linha*)malloc(sizeof(linha));
     (*linh)->num=-1;
     (*linh)->info='';
     (*linh)->next=NULL;
     (*linh)->back=NULL;
}
/*----------------------------------------------------------------------------*/
void getcoluna(coluna** colun){
     *colun=(coluna*)malloc(sizeof(coluna));
     (*colun)->num= -1;
     (*colun)->info='';
     (*colun)->next=NULL;
     (*colun)->back=NULL;
}
/*----------------------------------------------------------------------------*/
void enter(noh** atual,linha** lin){
     if((*atual)->dir == NULL){
        linha* auxlin;
        noh* noaux;
        getlinha(&auxlin);
        getnode(&noaux);
        adicionarlinha(&*lin,&auxlin);
     }
}
/*----------------------------------------------------------------------------*/
//void digitar(exterior** ponteiros){// digitar(&exterior)
    //noh*aux;
     //getnode(&aux);
     
     //(*ponteiros)->atual)
     //((*ponteiros)->atual)->letra=getch;
     
    // }
/*----------------------------------------------------------------------------*/
void add_linhaInicio(externo** ex){//inserir linha no meio 
    linha** aux;
    noh** no;
    linha* x;
    getlinha(&x);
    if((x->back)==NULL){
         x->info=(*no);
         x->back=NULL;
         (*aux)->back=x;
         x->next=(*aux); 
    }
    (*aux)=x;
    for(x->num=0; x->next==NULL; x->num++){
        x=x->next;    
    }
}
/*----------------------------------------------------------------------------*/
void add_linhaFinal(externo** ex){//inserir final
    linha** aux;
    noh** no;
    linha* x;
    getlinha(&x);
    if((x->next)==NULL){
    x->info=(*no);
    x->next=NULL;
    (*aux)->next=x;
    x->back=(*aux);
    }
    x->num=((*aux)->num++);
}    
/*----------------------------------------------------------------------------*/
void add_linhaMeio (externo** ex){//inserir  meio
    linha** aux;
    noh** no;
    linha* x;
    getlinha(&x);
    if(((x->next)!=NULL) && ((x->back)!=NULL)){
    x->info=(*no);
    x->next=(*aux)->back;
    x->back=(*aux)->next;                        
    }     
    for(x->num=(*aux)->num++; x->next==NULL; x->num++){
        x=x->next;    
    }
}
/*----------------------------------------------------------------------------*/
void add_linha(externo** ex){//função para saber onde que vai inserir a nova linha
    if(((*ex)->atual)->lin==0 && ((*ex)->atual)->col==0){
        add_linhaInicio(ex);
    }
    else if (((*ex)->atual)->dir==NULL){
        add_linhaFinal(ex);     
    }
    else{
        add_linhaMeio(ex);     
    }
}


void sete_cima(externo** ponteiro){
    int seta;
    seta=getch();
    while(seta==72){               
       while(((*ponteiro)->atual)->cima==NULL){
           (*ponteiro)->atual=((*ponteiro)->atual)->esq;
           (*ponteiro)->colunaat=((*ponteiro)->colunaat)->back;   
       }
       (*ponteiro)->atual=((*ponteiro)->atual)->cima;
       (*ponteiro)->linhaat=((*ponteiro)->linhaat)->back;
       gotoxy(((*ponteiro)->linhaat)->num,((*ponteiro)->colunaat)->num);
       seta=getch(); 
    }
}     
/*----------------------------------------------------------------------------*/     
int main(){
    externo* ponteiro;   
    inicializarponteiros(&ponteiro);
    sete_cima(ponteiro);
                                    
    
    
    
}

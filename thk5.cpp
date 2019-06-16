#include <iostream>
using namespace std;

class DadosChave{
public:
    string chave;
    int tam;
};

// --------------------Implementação Nó Lista
template <class T>
class NoLista{
private:
    T item;
    NoLista *prox;
    NoLista *ant;
public:
    NoLista();
    NoLista(T);
    void setProx(NoLista<T>*);
    void setAnt(NoLista<T>*);
    void setItem(T);
    NoLista<T>* getProx();
    NoLista<T>* getAnt();
    T getItem();
};

template <class T>
NoLista<T>::NoLista(){
    prox = NULL;
    ant = NULL;
}
template <class T>
NoLista<T>::NoLista(T item){
    this->item = item;
    prox = NULL;
    ant = NULL;
}

template <class T>
void NoLista<T>::setProx(NoLista<T> *prox){
    this->prox = prox;
}
template <class T>
void NoLista<T>::setAnt(NoLista<T> *ant){
    this->ant = ant;
}
template <class T>
void NoLista<T>::setItem(T item){
    this->item = item;
}

template <class T>
NoLista<T>* NoLista<T>::getProx(){
    return prox;
}
template <class T>
NoLista<T>* NoLista<T>::getAnt(){
    return ant;
}
template <class T>
T NoLista<T>::getItem(){
    return item;
}
//------------------ fim Nó Lista

// ------------------INício LIsta
template <class T>
class Lista{
public:
    NoLista<T> *prim;    
    NoLista<T> *ult;    
public:
    Lista();
    void insere(T);
    NoLista<T>* busca(string);
    void remover(NoLista<T>*);
    void print();
};

template<class T>
Lista<T>::Lista(){
    prim = new NoLista<T>();
    ult = prim;
}

template<class T>
void Lista<T>::insere(T item){
    NoLista<T>* aux = new NoLista<T>(item);
    ult->setProx(aux);
    aux->setAnt(ult);
    ult = aux;
}

template <class T>
NoLista<T>* Lista<T>::busca(string item){
    NoLista<T>* p = prim->getProx();
    while((p!=NULL)&&(p->getItem() != item)){
        p = p->getProx();
    }
    return p;
}

template <class T>
void Lista<T>::remover(NoLista<T> *NoListaParaRemover){
    if((NoListaParaRemover==NULL)&&(NoListaParaRemover==prim)){
        cout<<"Impossivel remocao"<<endl;
    }
    else{
        NoLista<T> *p = NoListaParaRemover->getAnt();
        p->setProx(NoListaParaRemover->getProx());
        if(p->getProx()==NULL){
            ult = p;
        }
        if((p==prim)&&(p->getProx()==ult)){
            ult = prim;
        }
        delete NoListaParaRemover;
    }
}

void imprimeTabela(DadosChave item){
    cout<<item.chave<<" - "<<item.tam<<endl;
}

template<class T>
void Lista<T>::print(){
    NoLista<T> *p = prim->getProx();
    while(p!=NULL){
        imprimeTabela(p->getItem());
        p = p->getProx();
    }
}
//------------------ fim Lista

//------------------ Início Tabela Hash
class TabHash{
private:
	Lista<DadosChave> *tabela;
public:
	TabHash();
	void insere(DadosChave);
	unsigned long long int pow(int, int);
	unsigned long long int converterChaveStringParaNatural(string);
	int funcaoHash(string);
	void print();
    DadosChave codigo;
};

TabHash::TabHash(){
    tabela = new Lista<DadosChave>[11];
}

void TabHash::insere(DadosChave item){
    int indice = funcaoHash(item.chave);
    tabela[indice].insere(item);
}

unsigned long long int TabHash::pow(int num, int expoente){
    unsigned long long int potencia = 1;
    for(int i = 1;i<=expoente;++i){
        potencia *= num;
    }
    return potencia;
}

void TabHash::print(){
	for(int i = 0;i<11;++i){
		cout<<"\tPosicao "<<i<<" :\n";
		tabela[i].print();
	}
}

unsigned long long int TabHash::converterChaveStringParaNatural(string chave){
    int tam = chave.size();
    unsigned long long int soma = 0;
    for(int i = 0;i<tam;++i){
        soma += ((int)chave[i])*pow(31,tam-1-i);
    }
    return soma;
}

int TabHash::funcaoHash( string chave ){
    unsigned long long int k = converterChaveStringParaNatural(chave);
    int valorHash = k%11;
    return valorHash;
}
//------------------ fim tabela hash

//------------------ início nó árvore
template <class T>
class NoArvore{
private:
    T item;
    int fb;
    NoArvore *esq, *dir;
public: 
    NoArvore();
    NoArvore(T);
    void setItem(T);    
    void setEsq(NoArvore<T>*);    
    void setDir(NoArvore<T>*);
    void setFb(int);
    T getItem();
    NoArvore<T>*& getEsq();    
    NoArvore<T>*& getDir();
    int getFb();    
};

template <class T>
NoArvore<T>::NoArvore(){
    this->esq = NULL;
    this->dir = NULL;
    this->fb = 0;
}
template <class T>
NoArvore<T>::NoArvore(T item){
    this->item = item;
    this->esq = NULL;
    this->dir = NULL;
    this->fb = 0;
}

template <class T>
void NoArvore<T>::setItem(T item){
    this->item = item;
}
template <class T>
void NoArvore<T>::setEsq(NoArvore<T> *esq){
    this->esq = esq;
}
template <class T>
void NoArvore<T>::setDir(NoArvore<T> *dir){
    this->dir = dir;
}
template <class T>
void NoArvore<T>::setFb(int fb){
    this->fb = fb;
}

template <class T>
T NoArvore<T>::getItem(){
    return item;
}
template <class T>
NoArvore<T>*& NoArvore<T>::getEsq(){
    return esq;
}
template <class T>
NoArvore<T>*& NoArvore<T>::getDir(){
    return dir;
}
template <class T>
int NoArvore<T>::getFb(){
    return fb;
}
// --------------- fim nó árvore

//------------------ início arvore
template <class T>
class AVL{
private:
    NoArvore<T> *raiz;
    int insere(T, NoArvore<T> *&);
    void percorrePreOrdem(NoArvore<T>*);
    void percorreCentral(NoArvore<T>*);
    void percorrePosOrdem(NoArvore<T>*);
    void RSE(NoArvore<T> *&);
    void RSD(NoArvore<T> *&);
    void RDD(NoArvore<T> *&);
    void RDE(NoArvore<T> *&);
public:
    AVL();
    void insere(T);
    void percorrePreOrdem();
    void percorreCentral();
    void percorrePosOrdem();
};

template <class T>
AVL<T>::AVL(){
    this->raiz = NULL;
}

template <class T>
void AVL<T>::RSE(NoArvore<T> *&noDesce){
    NoArvore<T> *noSobe = noDesce->getDir();
    noDesce->setDir( noSobe->getEsq());
    noSobe->setEsq(noDesce);
    noDesce->setFb(0);
    noDesce = noSobe;
}
template <class T>
void AVL<T>::RSD(NoArvore<T> *&noDesce){
    NoArvore<T> *noSobe = noDesce->getEsq();
    noDesce->setEsq( noSobe->getDir());
    noSobe->setDir(noDesce);
    noDesce->setFb(0);
    noDesce = noSobe;
}

template <class T>
void AVL<T>::RDE(NoArvore<T> *&no){
    // cout<<"Entrou no RDE\n";
    NoArvore<T> *p1 = no->getDir();
    NoArvore<T> *p2 = p1->getEsq();
    p1->setEsq( p2->getDir());
    p2->setDir(p1);
    no->setDir( p2->getEsq());
    p2->setEsq(no);
    if(p2->getFb()==1){
        no->setFb(-1);
    }
    else{
        no->setFb(0);
    }
    if(p2->getFb()==-1){
        p1->setFb(1);
    }
    else{
        p1->setFb(0);
    }
    no = p2;
}
template <class T>
void AVL<T>::RDD(NoArvore<T> *&no){
    NoArvore<T> *p1 = no->getEsq();
    NoArvore<T> *p2 = p1->getDir();
    p1->setDir( p2->getEsq());
    p2->setEsq(p1);
    no->setEsq( p2->getDir());
    p2->setDir(no);
    if(p2->getFb()==-1){
        no->setFb(1);
    }
    else{
        no->setFb(0);
    }
    if(p2->getFb()==1){
        no->setFb(-1);
    }
    else{
        p1->setFb(0);
    }
    no = p2;
}

template <class T>
int AVL<T>::insere(T item, NoArvore<T> *&no){
    if(no==NULL){//insere
        no = new NoArvore<T>(item);
        return 1;
    }
    else if(no->getItem().codigo.tam > item.codigo.tam){
        int h = insere(item,no->getEsq());
        if(h==1){// sub-arvore esquerda cresceu
            if(no->getFb()==1){
                no->setFb(0);
                return 0;
            }
            else if(no->getFb()==0){
                no->setFb(-1);
            }
            else{
                if(no->getEsq()->getFb()==-1){
                    RSD(no);
                }
                else{
                    RDD(no);
                }
                no->setFb(0);
                return 0;
            }
            return 1;
        }
    }
    else if(no->getItem().codigo.tam < item.codigo.tam){
        int h = insere(item,no->getDir());
        if(h==1){//sub-arvore direita cresceu
            if(no->getFb()==-1){
                no->setFb(0);
                return 0;
            }
            else if(no->getFb()==0){
                no->setFb(1);
            }
            else{
                if(no->getDir()->getFb()==1){
                    RSE(no);
                }
                else{
                    RDE(no);
                }
                no->setFb(0);
                return 0;
            }
            return 1;
        }
    }
    else{
        // cout<<"Item ja esta na arvore\n";
        return 0;
    }
    return 0;
}
template <class T>
void AVL<T>::insere(T item){
    insere(item,raiz);
}

template <class T>
void AVL<T>::percorrePreOrdem(NoArvore<T> *no){
    if(no!=NULL){
        // cout<<no->getItem()<<endl;
        no->getItem().print();
        percorrePreOrdem(no->getEsq());
        percorrePreOrdem(no->getDir());
    }
}
template <class T>
void AVL<T>::percorreCentral(NoArvore<T> *no){
    if(no!=NULL){
        percorreCentral(no->getEsq());
        cout<<no->getItem()<<endl;
        percorreCentral(no->getDir());
    }
}
template <class T>
void AVL<T>::percorrePosOrdem(NoArvore<T> *no){
    if(no!=NULL){
        percorrePosOrdem(no->getEsq());
        percorrePosOrdem(no->getDir());
        cout<<no->getItem()<<endl;
    }
}

template <class T>
void AVL<T>::percorrePreOrdem(){
    percorrePreOrdem(raiz);
}
template <class T>
void AVL<T>::percorreCentral(){
    percorreCentral(raiz);
}
template <class T>
void AVL<T>::percorrePosOrdem(){
    percorrePosOrdem(raiz);
}
//----------------- fim implementação Árvore

int main(){
    AVL<TabHash> arvore;
	TabHash table;
    DadosChave a;//b,c;
    a.chave = "tkek kelk";
    a.tam = a.chave.size();
    table.codigo = a;
    // imprimeTabela(table.codigo);
    // b.chave = "tkek yy ykelk";    
    // b.tam = b.chave.size();
    // c.chave = "tkek kelk hhh";    
    // c.tam = c.chave.size();
    arvore.insere(table);
    // arvore.insere(b);
    // arvore.insere(c);
    // table.print();
    arvore.percorrePreOrdem();    
	return 0;
}
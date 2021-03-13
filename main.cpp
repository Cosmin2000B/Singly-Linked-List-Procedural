#include <iostream>

using namespace std;

struct Nod
{
    int info;
    Nod* link;
};

void citire(int &n,Nod* &Head)
{
cout << "Cate elemente are lista?" << endl << "n = ";
 cin >> n;

 Nod *p, *q = NULL;
 Head = NULL;

  for(int i=1; i<=n; i++)
  {

   cout <<"Elementul al "<<i<<"-lea este: ";

   p = new Nod;

   cin >> p->info;
   cout << endl;

   p->link = NULL;
     if(i == 1)
        Head = p;
     else
        q->link = p;

     q = p;
  }

  cout << endl;
}


void inserareLaInceput(Nod* &Head,int a)  // Incep inserarile
{
 Nod* p =new Nod;
 p->info = a;
 p->link = NULL;

   if(Head == NULL)
    {
     Head = p;
     return;
    }

p->link = Head;
Head = p;
}

void inserareDupaElement(Nod* &Head,int x,int a)
{
    // dupa val x
    // se insereaza val a

 Nod* iter = new Nod;
   if(Head == NULL)
   {
    cout<<"Lista este vida"<<endl;
    return;
   }

   iter = Head;
   while(iter != NULL && iter->info != x ) iter = iter->link;

   if(iter == NULL)
   {
    cout<<"Elementul cu valoarea "<<x<<" nu se gaseste in lista"<<endl;
    return;
   }

   Nod* p = new Nod;

   if(p == NULL)
   {
    cout<<"Overflow \n";
    return ;
   }

   p->info = a;
   p->link = NULL;

   p->link = iter->link;
   iter->link = p;
}

void inserareSfarsit(Nod* &Head,int a)
{
  Nod* p =new Nod;
  p->info = a;
  p->link = NULL;

    if(Head == NULL)
    {
        Head = p;
        return;
    }

  Nod* iter = new Nod;
  iter = Head;
    while(iter->link != 0) iter = iter->link;
  iter->link = p;
}                            //Se termina inserariile


void Stergere_Inceput(Nod* &Head)  // Incep stergerile
{
  if(Head == NULL)
  {
   cout<<"Underflow"<<endl;
   return;
  }

  Nod* p =new Nod;
  p = Head;

  Head = Head->link;
  cout<<"Nodul cu valoarea " << p->info << " a fost sters!"<<endl;

  delete p;
}

 void Stergere_Element_Dat(Nod* &Head, int x)
{
    Nod* iter = new Nod;
    iter = Head;

    if(Head == NULL)  // lista goala
    {
      cout<<"Underflow"<<endl;
      return;
    }

    if(Head->info == x) //valoarea este pe prima poz
    {
     cout << "Elementul "<< Head->info
     << " a fost sters" << endl;
     Head = Head->link;
     return;
    }

     while(iter->link !=NULL && iter->link->info != x)
        iter = iter->link;

     if(iter == NULL)
     {
      cout<<"Valoarea "<< x <<" nu se gaseste in lista"<<endl;
      return;
     }
     else
     {
     Nod* p = iter->link;
     iter->link = iter->link->link;

     cout <<"Elementul " << p->info << " a fost sters";

     delete p;
     }

  cout << endl;

}

void Stergere_Finalul_Listei(Nod* &Head)
{
   if(Head == NULL)
   {
    cout << "Underflow" << endl;
    return;
   }

   Nod* iter = Head;

    while(iter->link != NULL && iter->link->link != NULL)
        iter = iter->link;

    if(iter->link == NULL) // un singur element
        {
         cout << "S-a sters elementul" << Head->info << endl;
         Head = NULL;
        }
    else
    {
     cout << "Elementul sters este "<<iter->link->info<<endl;
     iter->link = NULL;

    }
}                       // Se termina stergerile


Nod* accesare(Nod* Head, int poz, int n)
{

  if(n < poz) // pozitia nu se afla in lista
  return NULL;

  if (poz == 1) // se afla pe prima pozitie
   return Head;

  Nod* iter = new Nod;
  iter = Head;

  for(int i=1; i <= poz-1; i++)  // pt ca porneste de pe
        iter = iter -> link;     // poz primului element

   return iter;
}

void Modificare_Element(Nod* Head,int n)  // Implementata citirea
{
    int poz,val;

    cout << "Pozitia elementului pe care-l modificam este: ";
    cin >> poz;

    cout << endl;

    cout << "Valoarea dorita este: ";
    cin >> val;

    cout << endl;

    if(n < poz)
    {
     cout << "Lista are mai putine elemente"<<endl;
     return;
    }

    Nod* iter = Head;

    for(int i=0; i<poz-1; i++)
        iter = iter -> link;

    iter->info = val;
}

Nod* Cautare_Elem(int val, Nod* Head)
{
    if(Head == NULL) //lista vida
      return NULL;

    Nod* iter = new Nod;
    iter = Head;


   while(iter->info != val && iter->link != NULL)
    iter = iter->link;

    if(iter->info == val)
        return iter;
    else
        return NULL; // nu a gasit val in lista

    delete iter;
}

void afisare(int n, Nod* Head)
{
  Nod* p = Head;

  cout << "Lista este: ";

  for(int i=0; i<n; i++)
  {
   cout  << p->info <<" ";
   p = p->link;
  }

  cout << endl;

}

// -------------------------------------- //

//Urmeaza implementarea meniului:

void Meniu(int &alegere)  // meniu principal
{
  cout << endl;
  cout << "------- Meniu -------" << endl;
  cout << "Alegeti operatia dorita din lista de mai jos:"
  << endl;
  cout << "1. Introducere element" << endl;
  cout << "2. Stergere element" << endl;
  cout << "3. Accesare element" << endl;
  cout << "4. Modificare element" << endl;
  cout << "5. Cautare element" << endl;
  cout << "6. Creare lista" << endl;
  cout << "7. Afisare lista" << endl;
  cout<<endl;
  cout<<"(!) Pentru a iesi din meniu introduceti -1";
  cout<<endl;

  cin >> alegere;
}

void Meniu_Inserari(int& alegere) // meniu inserari
{
    cout << "Unde doriti sa inserati noul element?" << endl;
    cout << "1. La inceputul listei" << endl;
    cout << "2. Dupa un element dat" << endl;
    cout << "3. La sfarsitul listei" << endl;

    cin >> alegere;
}

void Meniu_Stergeri(int& alegere) // meniu stergeri
{
    cout << "Ce element doriti sa stergeti?" << endl;
    cout << "1. Primul element al listei" << endl;
    cout << "2. Un nod cu o anumita valoare" << endl;
    cout << "3. Ultimul element al listei" << endl;

    cin >> alegere;
}

int main()
{
    Nod* Head = new Nod;
    Head = NULL;

    int n;
    int alegere; // pentru meniul principal

    // pentru meniurile secundare
    int alegere_insearare,alegere_stergere;

    Meniu(alegere);


   while (0 < 1) // loop-ul principal
   {

     if(alegere < 1 || alegere > 7)
        return 0;

     switch (alegere)
     {
  case 1:  // 1. Introducere element
      {
        n++; // marim dimensiunea, altfel crapa
             // functiile dependete de val lui n

       Meniu_Inserari(alegere_insearare);

      switch (alegere_insearare)
      {
   case 1:         // la inceputul listei
       {
      cout << "Ce valoare doriti sa inserati? a=";
      int a_case_1;
      cin >> a_case_1;
      inserareLaInceput(Head,a_case_1);
      break;
       }

   case 2:
       {
       int x,a_case_2;
      cout << "Dupa ce valoare doriti sa introduceti? x=";
      cin >> x;

      cout << endl;

      cout << "Ce valoare doriti sa introduceti? a=";
      cin >> a_case_2;

      inserareDupaElement(Head,x,a_case_2);
      break;
       }

   case 3:
       {
      cout << "Ce valoare doriti sa inserati? a=";
      int a_case_3;
      cin >> a_case_3;

      inserareSfarsit(Head,a_case_3);
      break;
       }

     }
  break;  // terminat case(1) - inserari
      }

  case 2: // Stergeri element
      {
       n--; // modificam dimensiunea nodului
            // pt functiile dependente de n

      Meniu_Stergeri(alegere_stergere);

      switch(alegere_stergere)
      {
   case 1:
       {
       Stergere_Inceput(Head);
       break;
       }

   case 2:
       {
       int val;
       cout << "Ce valoare doriti sa stergeti? val=";
       cin >> val;
       Stergere_Element_Dat(Head,val);
       break;
       }

   case 3:
       {
       Stergere_Finalul_Listei(Head);
       break;
       }

      }
   break; // terminat case(2) - stergeri
      }

   case 3: // accesare element
       {
    Nod* accesat = new Nod;
    int poz;

    cout << "Pozitia elementului este: poz=";
    cin >> poz;

    accesat = accesare(Head,poz,n);

     if(accesat != NULL)
    cout << "Nodul cu valoarea " << accesat->info
    << " a fost accesat!" << endl;
     else
    cout << "Nodul cautat nu a putut fi accesat!"
    << endl;

    break; // terminat case(3) - accesare
       }

   case 4: // modificare element
       {

    Modificare_Element(Head,n);

    break; // terminat case(4) - modificare nod
       }

   case 5:  // cautare element
      {
     int val_case_5;

     cout << "Valoarea nodului cautat este val= ";
     cin >> val_case_5;

     Nod* caut = new Nod;

     caut = Cautare_Elem(val_case_5,Head);

     if(caut == NULL)
        cout << "Elementul cautat nu se gaseste in lista!"
        << endl;
     else
        cout << "Elementul cautat a fost gasit in lista!"
        << endl;

    break; // terminat case(5) - cautare nod
      }

   case 6: // creare lista
       {
     citire(n,Head);
    break; // terminat case(6) - creare lista
       }

   case 7: // afisare lista
       {
     afisare(n,Head);

    break; // terminat case(7) - afisare lista
       }

   } // switch-ul de alegere - meniu principal

    cout << endl;
    cout << "Ce operatie mai doriti sa efectuati: ";
    cin >> alegere;
    cout << endl;

   } // loop principal

   delete Head;

   return 0;
}

//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
#include <string.h>

//---------------------------------------------------------------------------                                                                                           void _fastcall HashTable::DisplayList(UnicodeString newtermin, unsigned int newpage,unsigned int key){

#pragma package(smart_init)

unsigned int HashTable::GetKey(UnicodeString word)
{
	int sum = 0;
	for (int i = 1; i <= word.Length(); i++) {
	  sum += word[i];
	}
	return sum % SIZE;
}

TItem* _fastcall HashTable::AddItem(TItem *Prev,UnicodeString newtermin, unsigned int newpage){
   TItem *temp;
   if (Prev==NULL) {
   unsigned key = GetKey(newtermin);
   temp = list[key];
	   if (temp != NULL) {
		   while(temp->Next != NULL){
		   temp = temp->Next;
		   }
	   temp->Next = new TItem;
	   temp= temp->Next;
	   }
	   else {
	   temp= new TItem;
	   list[key]=temp;
	   }
   temp->Page  = new Tpg;
   temp->Above = NULL;
   temp->Termin = newtermin;
   temp->Page->Page = newpage;
   temp->Subtermin = NULL;
   temp->Next = NULL;
   temp->Page->Above = temp;
   return temp;
   }
   else
   {   temp = Prev->Subtermin;
	   if (temp != NULL) {
		   while(temp->Next != NULL){
		   temp = temp->Next;
		   }
	   temp->Next = new TItem;
	   temp = temp->Next;
	   }
	   else {
	   temp = new TItem;
	   Prev->Subtermin=temp;
	   }
   temp->Above = Prev;
   temp->Page  = new Tpg;
   temp->Termin = newtermin;
   temp->Page->Page = newpage;
   temp->Subtermin = NULL;
   temp->Next = NULL;
   temp->Page->Above = temp;
   return temp;
   }
}

std::vector <TItem*> HashTable::LinkAll(TItem* Head ){
std::vector <TItem*> Arr;
Arr.clear();
Arr.resize(SIZE);


int j = 0;
  if (Head == NULL) {
  TItem* temp;
	for (int i = 0; i < SIZE; i++) {
	 if (list[i]!=NULL) {
		 temp = list[i];
		 while (temp != NULL){
			 if (j > (Arr.size()+1)) {
				Arr.resize(Arr.size()*2);
			 }
		   Arr[j] = temp;
		   temp = temp->Next;
		   j++;
		 }
	 }
	}
  }
  else{
	 TItem* temp = Head;
	 while (temp != NULL){
			 if (j > (Arr.size()+1)) {
				Arr.resize(Arr.size()*2);
			 }
		   Arr[j] = temp;
		   temp = temp->Next;
		   j++;
	 }
  }
  int i;
  for (i =0 ; Arr[i] !=NULL; i++) {
  }
  Arr.resize(i);
return Arr;
}

std::vector <TItem*>  SortAlphabet(std::vector <TItem*> arr, int size){
TItem* temp;
arr.resize(size);
int i = 0;
int j = 0;
	for (i = 0; i < arr.size(); i++) {
		for (j = arr.size() - 1; j > i; j--) {
			if (arr[j-1]->Termin > arr[j]->Termin) {
				temp =arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
	return arr;
}

std::vector <TItem*>  SortPage(std::vector <TItem*> arr, int size){
TItem* temp;
arr.resize(size);
int i = 0;
int j = 0;
	for (i = 0; i < arr.size(); i++) {
		for (j = arr.size() - 1; j > i; j--) {
			if (arr[j-1]->Page->Page > arr[j]->Page->Page) {
				temp =arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
	return arr;
}

std::vector <TItem*> HashTable::SortAllName(){
   std::vector <TItem*> arr;
   std::vector <TItem*> temparr;
   arr.resize(SIZE);
   arr = LinkAll();
   arr = SortAlphabet(arr,arr.size());
   for (int i = 0; i < arr.size(); i++) {
	   TItem tmp = *arr[i];
	   if (arr[i]->Subtermin != NULL) {
		  temparr =  LinkAll(arr[i]->Subtermin);
          temparr = SortAlphabet(temparr,temparr.size());
		  arr.resize(arr.size()+temparr.size());
		  for (int j = arr.size(); j > 2+i; j--) {
			 TItem tmp = *arr[j-1-temparr.size()];
			  arr[j-1] = arr[j-1-temparr.size()];
		  }
		  for (int j = 0; j < temparr.size(); j++) {
            arr[i+j+1] = temparr[j];
		  }
	   }
   }
   return arr;
}

std::vector <TItem*> HashTable::SortAllPage(){
   std::vector <TItem*> arr;
   std::vector <TItem*> temparr;
   arr.resize(SIZE);
   arr = LinkAll();
   arr = SortPage(arr,arr.size());
   for (int i = 0; i < arr.size(); i++) {
	   TItem tmp = *arr[i];
	   if (arr[i]->Subtermin != NULL) {
		  temparr =  LinkAll(arr[i]->Subtermin);
          temparr = SortPage(temparr,temparr.size());
		  arr.resize(arr.size()+temparr.size());
		  for (int j = arr.size(); j > 2+i; j--) {
			 TItem tmp = *arr[j-1-temparr.size()];
			  arr[j-1] = arr[j-1-temparr.size()];
		  }
		  for (int j = 0; j < temparr.size(); j++) {
            arr[i+j+1] = temparr[j];
		  }
	   }
   }
   return arr;
}

TItem* HashTable::FindTermin(){
 std::vector <TItem*> arr;
   std::vector <TItem*> temparr;
   arr.resize(SIZE);
   arr = LinkAll();
   for (int i = 0; i < arr.size(); i++) {
	   TItem tmp = *arr[i];
	   if (arr[i]->Subtermin != NULL) {
		  temparr =  LinkAll(arr[i]->Subtermin);
		  arr.resize(arr.size()+temparr.size());
		  for (int j = arr.size(); j > 2+i; j--) {
			 TItem tmp = *arr[j-1-temparr.size()];
			  arr[j-1] = arr[j-1-temparr.size()];
		  }
		  for (int j = 0; j < temparr.size(); j++) {
            arr[i+j+1] = temparr[j];
		  }
	   }
   }
}

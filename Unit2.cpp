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
   temp->Termin = newtermin;
   temp->Page->Page = newpage;
   temp->Subtermin = NULL;
   temp->Next = NULL;
   temp->Page->Above = temp;
   return temp;
   }
}

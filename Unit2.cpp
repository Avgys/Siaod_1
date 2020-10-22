//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
#include <string.h>

//---------------------------------------------------------------------------                                                                                           void _fastcall HashTable::DisplayList(UnicodeString newtermin, unsigned int newpage,unsigned int key){

#pragma package(smart_init)

unsigned int GetKey(UnicodeString word)
{
	int sum = 0;
	for (int i = 1; i <= word.Length(); i++) {
	  sum += word[i];
	}
	return sum % 20;
}

TItem* _fastcall HashTable::AddItem(UnicodeString newtermin, unsigned int newpage){
   TItem *temp ;
   unsigned key = GetKey(newtermin);
   if (list[key]->Next == NULL){
   list[key] = new TItem ;
   temp = list[key];
   }
	else
   {
	temp = list[key];
	while (temp->Next == NULL){
	 temp = temp->Next;
	}
   }
   temp->Page  = new Tpg;
   temp->Termin = newtermin;
   temp->Page->Page = newpage;
   temp->Subtermin = NULL;
   temp->Next = NULL;
   temp->Page->Above = temp;
   return temp;
}

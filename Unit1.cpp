//---------------------------------------------------------------------------

#include <vcl.h>
#include "Unit1.h"
#include "Unit2.h"
#pragma hdrstop
#include <iostream>
#include <vector>
#include <ustring.h>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


HashTable *hashtable;


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{  hashtable = new HashTable;

}



//TItem* _fastcall HashTable::AddItem(UnicodeString newtermin, unsigned int newpage){
//   TItem *temp ;
//   unsigned key = GetKey(newtermin);
//   if (hashtable[key] == NULL){
//   hashtable[key] = new TItem ;
//   temp = hashtable[key];
//   }
//	else
//   {
//	temp = hashtable[key];
//	while (temp->Next == NULL){
//	 temp = temp->Next;
//	}
//   }
//   temp->Page  = new Tpg;
//   temp->Termin = newtermin;
//   temp->Page->Page = newpage;
//   temp->Subtermin = NULL;
//   temp->Next = NULL;
//   temp->Page->Above = temp;
//   return temp;
//}



void __fastcall TForm1::Exit1Click(TObject *Sender)
{
  Close();
}

void __fastcall TForm1::Addbtn(TObject *Sender){
//    if (Termin->Text > 0 && Page->Text > 0){
//	unsigned int key = GetKey(Termin->Text);
//	AddItem(Termin->Text,StrToInt(Page->Text));
//	Memo->Lines->Add (Termin->Text + "  " + Page->Text);
//
//	 Termin->Text = "";
//	 Page->Text = "";
//    }
}

void __fastcall TForm1::LoadFromFile(TObject *Sender)
{
using namespace std;
    Memo->Clear();
	ifstream file;
	string line;
	String templine;
	UnicodeString filename;
	if (OpenTextFileDialog1->Execute()) {
		std::ifstream in(OpenTextFileDialog1->FileName.c_str());
		while (getline(in, line)){
		Memo->Lines->Add(line.c_str());
		}
	}
}
void __fastcall TForm1::Refresh(TObject *Sender)
{
	for (int i = 0; i < SIZE; i++) {
//		 delete	hashtable[i];
	}
	String line;
	for(int j = 0; Memo->Lines->Strings[j+1] > "" ;j++){
	line = Memo->Lines->Strings[j];
	int i = line.Pos(' ');
	String termin = line.SubString(0,i-1);
    int	page = StrToInt(line.SubString(i,line.Length()-i+1));
	Page->Text = page;
	Termin->Text = termin;
//	AddItem(termin,page);
	}
}

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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


HashTable *hashtable;

std::vector <TItem*> TItemArr;


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{    TItemArr.resize(SIZE);
	 hashtable = new HashTable;
//   for(int i=0; i < 20;i++){
//   hashtable->list[i] = new TItem;
//   hashtable->list[i]->Termin = L"";
//   hashtable->list[i]->Page->Page = 0;
//   hashtable->list[i]->Subtermin = NULL;
//   hashtable->list[i]->Next = NULL;
//   hashtable->list[i]->Page->Above = NULL;
//   }
}



void __fastcall TForm1::Exit1Click(TObject *Sender)
{
  Close();
}

void __fastcall TForm1::Addbtn(TObject *Sender){
	if (Termin->Text > 0 && Page->Text > 0){
	TItem* Prev = NULL;
	Prev = hashtable->AddItem(Prev,Termin->Text,StrToInt(Page->Text));
	Memo->Lines->Add (Termin->Text + "  " + Page->Text);
	 Termin->Text = "";
	 Page->Text = "";
	}
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
{	 delete	hashtable;
	hashtable = new HashTable;
	String line;
	std::vector <TItem*> ArrPrev;
    TItem* Prev = NULL;
    ArrPrev.resize(2);
	for(int j = 0; Memo->Lines->Strings[j] > "" ;j++){

	line = Memo->Lines->Strings[j];
	int i = line.Pos(' ');
	String termin = line.SubString(0,i-1);
	int	page = StrToInt(line.SubString(i,line.Length()-i+1));
	Page->Text = page;
	Termin->Text = termin;
	Prev = hashtable->AddItem(Prev,termin,page);
	}
    ArrPrev.clear();
}


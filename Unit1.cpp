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
#ifndef SIZE
#define SIZE 20
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using uint = unsigned int;

HashTable *hashtable;
std::vector <TPage*> PageArr;
std::vector <TItem*> SortItemArr;
std::vector <TItem*> TItemArr;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{    TItemArr.resize(SIZE);
	 SortItemArr.resize(SIZE);
	 PageArr.resize(SIZE);
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
//	TForm1::Refresh(Memo);
}


uint cifra(char word){
	int i;
//	WideChar left = '0';
//	WideChar Right = '9';
//	String line = word.c_str();

	if (word < '0'|| word > '9') {
	  return  1;
	}else return   0;
}

void __fastcall TForm1::Refresh(TObject *Sender)
{	delete hashtable;
	TItemArr.clear();
	TItemArr.resize(SIZE);
	hashtable = new HashTable;
	for (int i = 0; i < SIZE; i++) {
	  hashtable->list[i] = NULL;
	}
	UnicodeString line;
	TItem* ArrPrev[5];
	TItem* PrevMain = NULL;
//	ArrPrev.resize(5);
	int PrevLevel = 0;
	for (int i = 0; i < 4; i++) {
       ArrPrev[i]=NULL;
	}
	for(int j = 0; Memo->Lines->Strings[j] > "" ;j++){
	line = Memo->Lines->Strings[j];
	line = line.Trim();
	int CurrLevel = 0;
		while (Pos('/',line,CurrLevel+1)){
		 CurrLevel++;
		}
	PrevMain = ArrPrev[CurrLevel];
	PrevLevel = CurrLevel;
	int i = line.Pos0(' ');
	UnicodeString page = "";
	String termin = line.SubString(0,i);

	page = line.SubString(i+1,line.Length()-i);
	uint flag = 1;
		try{
		StrToInt(page);
		} catch(...){
        flag = 0;
		}

		if (i>0 && flag ) {
		PrevMain = hashtable->AddItem(PrevMain,termin,StrToInt(page));
		if (ArrPrev[CurrLevel+1] != NULL) {
         ArrPrev[CurrLevel+1]->Page->Next = PrevMain->Page;
		}
		ArrPrev[CurrLevel+1]=PrevMain;
		}
	Page->Text = page;
	Termin->Text = termin;
	}
//	SortItemArr = hashtable->LinkAll();
//	ArrPrev.clear();
}




void __fastcall TForm1::View(TObject *Sender){
 Memo->Clear();
 int flag = 0;
 for (int i = 0; i < SIZE; i++) {
  if (hashtable->list[i] != NULL){
    flag = 1;
  }
 }
 if (flag) {


 int way;
	 if (Viewbox->Text == "Hash View") {
		way = 0;
	 }
	 if (Viewbox->Text == "Alphabet Sort") {
		way = 1;
	 }
	 if (Viewbox->Text == "Page Sort") {
		way = 2;
	 }
	switch (way) {
	case 0 :
			for (int i=0; i < SIZE; i++) {
				 if (hashtable->list[i] != NULL){
				TItem* temp[5];
				for (int j = 0; j < 5; j++) {
				   temp[j]=NULL;
				}
				temp[0] = hashtable->list[i];
				int level = 0;
					while (temp[level] != NULL && level >= 0) {
					 Memo->Lines->Add(temp[level]->Termin +" "+ (temp[level]->Page->Page));
					 if (temp[level]->Subtermin != NULL) {
						 temp[level+1] =  temp[level]->Subtermin;
						 temp[level] = temp[level]->Next;
						 level++;
					 }
					 else {temp[level] = temp[level]->Next;
					 }
					 if (temp[level] == NULL) {
					  level--;
					 }
					}
				}
			}break;
	case 1 :{
			int i = 0;
			SortItemArr = hashtable->SortAllName();
			int count = SortItemArr.size();
			for (i=0; SortItemArr[i] != NULL && i < count; i++){
			  UnicodeString temp = SortItemArr[i]->Termin+" ";
			  temp += IntToStr(SortItemArr[i]->Page->Page);
			  Memo->Lines->Add(temp);
			}
			break;
			}
	case 2:
			int i = 0;
			SortItemArr = hashtable->SortAllPage();
			int count = SortItemArr.size();
			for (i=0; SortItemArr[i] != NULL && i < count; i++){
			  UnicodeString temp = SortItemArr[i]->Termin+" ";
			  temp += IntToStr(SortItemArr[i]->Page->Page);
			  Memo->Lines->Add(temp);
			}
			break;
	}
 }
}
void __fastcall TForm1::FindSub(TObject *Sender)
{
	if (FindTermin->Text > "") {Memo->Clear();
	 TItem* temp;
	  SortItemArr = hashtable->SortAllName();
	  for(int i = 0; i < SortItemArr.size(); i++){
		 if (FindTermin->Text == SortItemArr[i]->Termin){

		   Memo->Lines->Add(SortItemArr[i]->Termin+" "+SortItemArr[i]->Page->Page);
		   temp = SortItemArr[i]->Subtermin;;
		   while (temp != NULL){
		   Memo->Lines->Add(temp->Termin+" "+temp->Page->Page);
		   temp = temp->Next;
		   }
		 }
	  }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FindTerm(TObject *Sender){
	if (FindTermin->Text > "") {
	Memo->Clear();
	  TItem* temp;
	  SortItemArr = hashtable->SortAllName();
	  for(int i = 0; i < SortItemArr.size(); i++){
		 if (FindTermin->Text == SortItemArr[i]->Termin) {
		   Memo->Lines->Add(SortItemArr[i]->Above->Termin+" "+SortItemArr[i]->Above->Page->Page);
		   temp = SortItemArr[i];
           Memo->Lines->Add(temp->Termin+" "+temp->Page->Page);
		 }
	  }

	}
}
//---------------------------------------------------------------------------

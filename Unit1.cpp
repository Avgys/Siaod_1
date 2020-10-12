//---------------------------------------------------------------------------

#include <vcl.h>
#include "Unit1.h"
#pragma hdrstop
#include <iostream>
#include <vector>
#include <ustring.h>


#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{   Ttermin arr[20];

}
//---------------------------------------------------------------------------


unsigned int GetKey(UnicodeString word)
{ unsigned int key=5;
	key= (word[1]) %30;

  return key;
}


void __fastcall TForm1::Exit1Click(TObject *Sender)
{
  Close();
}

//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{   int i =0;
	while (StringGrid->Cells[0][i] > 0){
	i++;
	};
	StringGrid->Cells[0][i] = Termin->Text;
	StringGrid->Cells[1][i] = Page->Text;
	unsigned int key = GetKey(Termin->Text);

	StringGrid->Cells[2][i] = key;



	 Termin->Text = "";
     Page->Text = "";
}

//---------------------------------------------------------------------------





//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>

#include <vector>
#include <string>
#include <ustring.h>
//---------------------------------------------------------------------------



class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TEdit *Termin;
	TEdit *Page;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TPopupMenu *PopupMenu1;
	TMenuItem *dsaf1;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TLabel *Label2;
	TComboBox *Viewbox;
	TMemo *Memo;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TButton *Button4;
	TMenuItem *LoadFromFile1;
	TButton *Button5;
	TEdit *FindTermin;
	TLabel *Label3;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Addbtn(TObject *Sender);
	void __fastcall LoadFromFile(TObject *Sender);
	void __fastcall Refresh(TObject *Sender);
	void __fastcall View(TObject *Sender);
	void __fastcall FindSub(TObject *Sender);
	void __fastcall FindTerm(TObject *Sender);
private:	// User declarations
public:     // User declarations
//TItem* __fastcall AddItem(UnicodeString newtermin, unsigned int newpage);
//void __fastcall DisplayList(UnicodeString newtermin, unsigned int newpage,unsigned int key);
//void __fastcall LoadFromFile1Click(TObject *Sender);
//unsigned int GetKey(int ptr);

	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;


//---------------------------------------------------------------------------
#endif

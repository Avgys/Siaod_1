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

#include <vector>
#include <string>
#include <ustring.h>
//---------------------------------------------------------------------------
typedef struct  _Tpage{
	unsigned int page;
	_Tpage* ptrpage;
}Tpage;

typedef struct  _Ttermin{
	char termin[20];
	_Tpage* ptrpage;
	_Ttermin* ptrtermin;
	_Ttermin* ptrpodtermin;
}Ttermin;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid;
	TButton *Button1;
	TMainMenu *MainMenu1;
	TEdit *Termin;
	TEdit *Page;
	TMenuItem *N1;
	TMenuItem *LoadFromFile1;
	TMenuItem *Exit1;
	TButton *Button2;
	TButton *Button3;
	TPopupMenu *PopupMenu1;
	TMenuItem *dsaf1;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
//unsigned int GetKey(int ptr);

	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;


//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "trayicon.h"
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TCategoryPanelGroup *CategoryPanelGroup1;
	TCategoryPanel *CategoryPanel1;
	TCategoryPanel *CategoryPanel2;
	TLabel *Label1;
	TLabel *Label2;
	TPopupMenu *PopupMenu1;
	TMenuItem *PopupMenu11;
	TTrayIcon *TrayIcon1;
	TButton *Button1;
	TLabel *Label3;
	TTimer *Timer1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall Label2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

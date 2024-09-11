//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.WinXCalendars.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *ADD_OR_EDIT;
	TEdit *number;
	TComboBox *nom;
	TEdit *from;
	TEdit *ish;
	TEdit *sod;
	TEdit *komu;
	TEdit *ishn;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label11;
	TComboBox *isp;
	TDateTimePicker *date;
	TDateTimePicker *dateisp;
	TCheckBox *CheckBox1;
	TLabel *ID;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TOpenDialog *OpenDialog1;
	TLabel *FileName;
	TLabel *FilePatch;
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall FileNameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif

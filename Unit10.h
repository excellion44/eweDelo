//---------------------------------------------------------------------------

#ifndef Unit10H
#define Unit10H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TEdit *FIO;
	TDateTimePicker *date;
	TEdit *ADRES;
	TEdit *TEMA;
	TComboBox *ISP;
	TMemo *Memo1;
	TButton *Button1;
	TButton *Button2;
	TCheckBox *CheckBox1;
	TLabel *ADD_OR_EDIT;
	TEdit *number;
	TImage *Image1;
	TOpenDialog *OpenDialog1;
	TLabel *FileName;
	TLabel *FilePatch;
	TLabel *ID;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm10(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif

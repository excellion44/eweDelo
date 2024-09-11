//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TLabel *ADD_OR_EDIT;
	TEdit *number;
	TDateTimePicker *data;
	TComboBox *nom;
	TBitBtn *BitBtn1;
	TComboBox *isp;
	TBitBtn *BitBtn2;
	TComboBox *otpr;
	TEdit *about;
	TEdit *prim;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TBitBtn *Add_Or_Edit_Btn;
	TBitBtn *BitBtn4;
	TLabel *ID;
	void __fastcall Add_Or_Edit_BtnClick(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif

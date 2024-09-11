//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::BitBtn2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::BitBtn1Click(TObject *Sender)
{
		 Form2->ADOQuery1->SQL->Text="UPDATE vhod SET ishn ='"+Edit1->Text+"', ispflag ='0' WHERE number IN ("+ID->Caption+") ";
		 Form2->ADOQuery1->ExecSQL();

			Form2->ADOQuery1->Active = false;
			Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			Form2->ADOQuery1->Active = true;
			Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;

		 Form5->Close();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Add_Or_Edit_BtnClick(TObject *Sender)
{
	if(ADD_OR_EDIT->Caption == "ADD")
	{
			Form6->ADOQuery1->SQL->Text = "INSERT INTO ish VALUES (dmax('index', 'ish')+1, "+number->Text+",'"+data->Date+"','"+nom->Text+"','"+about->Text+"','"+otpr->Text+"','"+isp->Text+"','"+prim->Text+"','marki') ";
			Form6->ADOQuery1->ExecSQL();


			Form6->ADOQuery1->Active = false;
			Form6->ADOQuery1->SQL->Text = "SELECT * FROM ish ORDER BY number";
			Form6->ADOQuery1->Active = true;
			Form6->StatusBar1->Panels->Items[1]->Text = Form6->ADOQuery1->RecordCount;

		Form7->Close();
	}
    else if(ADD_OR_EDIT->Caption == "EDIT")
	{




		 Form6->ADOQuery1->SQL->Text="UPDATE ish SET  nom ='"+nom->Text+"', data ='"+data->Date+"', isp ='"+isp->Text+"', otpr ='"+otpr->Text+"', about ='"+about->Text+"', prim ='"+prim->Text+"' WHERE number IN ("+ID->Caption+") ";
		 Form6->ADOQuery1->ExecSQL();

			Form6->ADOQuery1->Active = false;
			Form6->ADOQuery1->SQL->Text = "SELECT * FROM ish ORDER BY number";
			Form6->ADOQuery1->Active = true;
			Form6->StatusBar1->Panels->Items[1]->Text = Form6->ADOQuery1->RecordCount;

		 Form7->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm7::BitBtn4Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit2.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BitBtn1Click(TObject *Sender)
{
	Form7->number->Text = ADOQuery1->RecordCount + 1;
	Form7->nom->Text = "";
	Form7->isp->Text = "";
	Form7->otpr->Text = "";
	Form7->about->Clear();
    Form7->prim->Clear();
	Form7->ADD_OR_EDIT->Caption = "ADD";
	Form7->Add_Or_Edit_Btn->Caption = "Добавить";
	Form7->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn2Click(TObject *Sender)
{
	Form7->ADD_OR_EDIT->Caption = "EDIT";
	Form7->ID->Caption = ADOQuery1->FieldByName("number")->Value;
	Form7->number->Text = ADOQuery1->FieldByName("number")->Value;
	Form7->data->Date = ADOQuery1->FieldByName("data")->Value;
	Form7->nom->Text = ADOQuery1->FieldByName("nom")->Value;
	Form7->nom->Items->LoadFromFile("journal.ewe");
	Form7->isp->Text = ADOQuery1->FieldByName("isp")->Value;
	Form7->otpr->Text = ADOQuery1->FieldByName("otpr")->Value;
	Form7->about->Text = ADOQuery1->FieldByName("about")->Value;
	Form7->prim->Text = ADOQuery1->FieldByName("prim")->Value;

	Form7->Add_Or_Edit_Btn->Caption = "Редактировать";

	Form7->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn3Click(TObject *Sender)
{
	if(MessageDlg("Действительно хотите удалить запись?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		String DELETED = ADOQuery1->FieldByName("number")->Value;

		ADOQuery1->SQL->Text = "DELETE FROM ish WHERE number IN ("+DELETED+") ";
		ADOQuery1->ExecSQL();

		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM ish ORDER BY number";
		ADOQuery1->Active = true;
		StatusBar1->Panels->Items[1]->Text = ADOQuery1->RecordCount;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::DBGrid1DblClick(TObject *Sender)
{
    BitBtn2->Click();
}
//---------------------------------------------------------------------------


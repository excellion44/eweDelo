//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit6.h"
#include "ComObj.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
	Form6->Close();
	Form2->Parent = this;
	Form2->SetBounds(3,3,300,150);
	Form2->Align = alClient;
	Form2->BorderStyle = bsNone;
	Form2->DBGrid1->Align = alClient;
	Form2->DBGrid1->BorderStyle = bsNone;
	Form2->RadioButton1->Checked = true;
	Form2->SearchNom->Items->Clear();
	Form2->SearchNom->Items->LoadFromFile("journal.ewe");
	Form2->Visible = true;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Label2Click(TObject *Sender)
{
    Form2->Close();
	Form6->Parent = this;
	Form6->SetBounds(3,3,300,150);
	Form6->Align = alClient;
	Form6->BorderStyle = bsNone;
	Form6->DBGrid1->Align = alClient;
	Form6->DBGrid1->BorderStyle = bsNone;
	Form6->ADOQuery1->Active = false;
	Form6->ADOQuery1->SQL->Text = "SELECT * FROM ish ORDER BY number";
	Form6->ADOQuery1->Active = true;
	Form6->StatusBar1->Panels->Items[1]->Text = Form6->ADOQuery1->RecordCount;
	Form6->Visible = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Label5->Caption = DateToStr(Date())+" "+Time();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{

	Form2->ADOQuery1->Active = false;
	Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
	Form2->ADOQuery1->Active = true;
	Label7->Caption = Form2->ADOQuery1->RecordCount;


    Form2->ADOQuery1->Active = false;
	Form2->ADOQuery1->SQL->Text = "select* from vhod where ispflag=1 order by number";
	Form2->ADOQuery1->Active = true;
	Label9->Caption = Form2->ADOQuery1->RecordCount;


    Form2->ADOQuery1->Active = false;
	Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod where dateisp < NOW() AND ispflag = 1 ORDER BY number";
	Form2->ADOQuery1->Active = true;
	Label11->Caption = Form2->ADOQuery1->RecordCount;
}
//---------------------------------------------------------------------------






//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit10.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button2Click(TObject *Sender)
{
    Form10->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button1Click(TObject *Sender)
{
	String CheckIsp;

	if(ADD_OR_EDIT->Caption == "ADD")
	{


        if(CheckBox1->Checked == true)
		{
			CheckIsp = 1;
		}
		else
		{
			CheckIsp = 0;

		}


		if(FileName->Caption == "No_File")
		{
			Form9->ADOQuery1->SQL->Text = "INSERT INTO obr VALUES (dmax('vindex', 'obr')+1, "+number->Text+",'"+date->Date+"','"+FIO->Text+"','"+ADRES->Text+"','"+ISP->Text+"','','rez','','No_File','"+Memo1->Text+"','"+TEMA->Text+"','"+CheckIsp+"') ";
			Form9->ADOQuery1->ExecSQL();
		}
		else
		{
			 Form9->ADOQuery1->SQL->Text = "INSERT INTO obr VALUES (dmax('vindex', 'obr')+1, "+number->Text+",'"+date->Date+"','"+FIO->Text+"','"+ADRES->Text+"','"+ISP->Text+"','','rez',:BlobValue,'"+FileName->Caption+"','"+Memo1->Text+"','"+TEMA->Text+"','"+CheckIsp+"') ";
			 Form9->ADOQuery1->Parameters->ParamByName("BlobValue")->LoadFromFile(FilePatch->Caption,ftBlob);
			 Form9->ADOQuery1->ExecSQL();
		}


			Form9->ADOQuery1->Active = false;
			Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr ORDER BY number";
			Form9->ADOQuery1->Active = true;


		Form10->Close();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm10::Image1Click(TObject *Sender)
{
    if(FileName->Caption == "No_File")
	 {

			if(OpenDialog1->Execute())
			{
				FilePatch->Caption = OpenDialog1->FileName;
				FileName->Caption = ExtractFileName(OpenDialog1->FileName);
			}
			else
			{

			}
	 }
	 else
	 {
		((TBlobField*)Form9->ADOQuery1->FieldByName("file"))->SaveToFile(ExtractFilePath(ParamStr(0))+FileName->Caption);
			char* OpenFileName;
			AnsiString  f = FileName->Caption;
			OpenFileName = f.c_str();
			ShellExecuteA(Handle, "open", OpenFileName, NULL, NULL, SW_SHOWNORMAL);

	 }
}
//---------------------------------------------------------------------------


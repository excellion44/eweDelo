//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include <windows.h>
#include "IniFiles.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
String ADD_OR_EDIT;
TForm4 *Form4;
TIniFile *ini = new TIniFile (ExtractFilePath(ParamStr(0))+"EWEsetting.ini");
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm4::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked == true)
	{
	   dateisp->Enabled = true;
	   isp->Enabled = true;
	}
	else
	{
	   dateisp->Enabled = false;
       isp->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{
    if(CheckBox1->Checked == true)
	{
	   dateisp->Enabled = true;
	   isp->Enabled = true;
	}
	else
	{
	   dateisp->Enabled = false;
	   isp->Enabled = false;
	}
	if(ADD_OR_EDIT->Caption == "EDIT")
	{
		BitBtn1->Caption = "Редактировать";
	}
	else if(ADD_OR_EDIT->Caption == "ADD")
	{
		BitBtn1->Caption = "Добавить";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn2Click(TObject *Sender)
{
    Form4->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn1Click(TObject *Sender)
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

		if(dateisp->Enabled == false && FileName->Caption != "No_File")
		{
			//ShowMessage("1");
			Form2->ADOQuery1->SQL->Text = "INSERT INTO vhod VALUES (dmax('vindex', 'vhod')+1, "+number->Text+",'"+date->Date+"','"+from->Text+"','"+ish->Text+"','"+sod->Text+"','"+komu->Text+"','"+isp->Text+"', null ,'"+CheckIsp+"','"+nom->Text+"','"+ishn->Text+"','rez',:BlobValue,'"+FileName->Caption+"') ";
			Form2->ADOQuery1->Parameters->ParamByName("BlobValue")->LoadFromFile(FilePatch->Caption,ftBlob);
			Form2->ADOQuery1->ExecSQL();
		}
		else if(dateisp->Enabled == true && FileName->Caption != "No_File")
		{
			//ShowMessage("2");
			Form2->ADOQuery1->SQL->Text = "INSERT INTO vhod VALUES (dmax('vindex', 'vhod')+1, "+number->Text+",'"+date->Date+"','"+from->Text+"','"+ish->Text+"','"+sod->Text+"','"+komu->Text+"','"+isp->Text+"','"+dateisp->Date+"','"+CheckIsp+"','"+nom->Text+"','"+ishn->Text+"','rez',:BlobValue,'"+FileName->Caption+"') ";
			Form2->ADOQuery1->Parameters->ParamByName("BlobValue")->LoadFromFile(FilePatch->Caption,ftBlob);
			Form2->ADOQuery1->ExecSQL();
		}
		else if(dateisp->Enabled == false && FileName->Caption == "No_File")
		{
			//ShowMessage("3");
			Form2->ADOQuery1->SQL->Text = "INSERT INTO vhod VALUES (dmax('vindex', 'vhod')+1, "+number->Text+",'"+date->Date+"','"+from->Text+"','"+ish->Text+"','"+sod->Text+"','"+komu->Text+"','"+isp->Text+"',null,'"+CheckIsp+"','"+nom->Text+"','"+ishn->Text+"','rez',Null,'No_File') ";
			Form2->ADOQuery1->ExecSQL();
		}
		else if(dateisp->Enabled == true && FileName->Caption == "No_File")
		{
			//ShowMessage("4");
			Form2->ADOQuery1->SQL->Text = "INSERT INTO vhod VALUES (dmax('vindex', 'vhod')+1, "+number->Text+",'"+date->Date+"','"+from->Text+"','"+ish->Text+"','"+sod->Text+"','"+komu->Text+"','"+isp->Text+"','"+dateisp->Date+"','"+CheckIsp+"','"+nom->Text+"','"+ishn->Text+"','rez',Null,'No_File') ";
			Form2->ADOQuery1->ExecSQL();
		}





			Form2->ADOQuery1->Active = false;
			Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			Form2->ADOQuery1->Active = true;
			Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;

		Form4->Close();
	}
	else if(ADD_OR_EDIT->Caption == "EDIT")
	{

		if(CheckBox1->Checked == true)
		{
			CheckIsp = 1;
		}
		else
		{
			  CheckIsp = 0;
		}

		//ShowMessage(Form2->ADOQuery1->FieldByName("file_name")->Value);


		if(dateisp->Enabled == false)
		{

		}

		if((Form2->ADOQuery1->FieldByName("file_name")->Value == "No_File" || Form2->ADOQuery1->FieldByName("file_name")->Value == "" || Form2->ADOQuery1->FieldByName("file_name")->Value == "Нет файла") && dateisp->Enabled == false && FileName->Caption != "No_File")
		{
			  //ShowMessage("1");
			 Form2->ADOQuery1->SQL->Text="UPDATE vhod SET nom ='"+nom->Text+"', data ='"+date->Date+"',frome ='"+from->Text+"', ish ='"+ish->Text+"', sod ='"+sod->Text+"', komu ='"+komu->Text+"', isp ='"+isp->Text+"', dateisp =Null, ispflag ='"+CheckIsp+"',rez ='rez', file =:BlobValue, file_name ='"+FileName->Caption+"' WHERE number IN ("+ID->Caption+") ";
			 Form2->ADOQuery1->Parameters->ParamByName("BlobValue")->LoadFromFile(FilePatch->Caption,ftBlob);
			 Form2->ADOQuery1->ExecSQL();
             Form2->ADOQuery1->Active = false;
			 //ShowMessage("1-1");
			Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			Form2->ADOQuery1->Active = true;
			Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;

			 Form4->Close();
			 return;

		}
		if((Form2->ADOQuery1->FieldByName("file_name")->Value == "No_File" || Form2->ADOQuery1->FieldByName("file_name")->Value == "" || Form2->ADOQuery1->FieldByName("file_name")->Value == "Нет файла") && dateisp->Enabled == true && FileName->Caption !="No_File")
		{
			 //ShowMessage("2");
			 Form2->ADOQuery1->SQL->Text="UPDATE vhod SET nom ='"+nom->Text+"', data ='"+date->Date+"',frome ='"+from->Text+"', ish ='"+ish->Text+"', sod ='"+sod->Text+"', komu ='"+komu->Text+"', isp ='"+isp->Text+"', dateisp ='"+dateisp->Date+"', ispflag ='"+CheckIsp+"',rez ='rez', file =:BlobValue, file_name ='"+FileName->Caption+"' WHERE number IN ("+ID->Caption+") ";
			 Form2->ADOQuery1->Parameters->ParamByName("BlobValue")->LoadFromFile(FilePatch->Caption,ftBlob);
			 Form2->ADOQuery1->ExecSQL();
             Form2->ADOQuery1->Active = false;
			//ShowMessage("1-2");
			Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			Form2->ADOQuery1->Active = true;
			Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;

			 Form4->Close();
			 return;
		}
		else if(dateisp->Enabled == false && Form2->ADOQuery1->FieldByName("ishn")->Value == "")
		{
			 //ShowMessage("3");
			 Form2->ADOQuery1->SQL->Text="UPDATE vhod SET nom ='"+nom->Text+"', data ='"+date->Date+"',frome ='"+from->Text+"', ish ='"+ish->Text+"', sod ='"+sod->Text+"', komu ='"+komu->Text+"', isp ='"+isp->Text+"', dateisp = Null, ispflag ='"+CheckIsp+"' WHERE number IN ("+ID->Caption+") ";
			 Form2->ADOQuery1->ExecSQL();
             Form2->ADOQuery1->Active = false;
			//ShowMessage("1-3");
			Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			Form2->ADOQuery1->Active = true;
			Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;

			 Form4->Close();
			 return;
		}
		else if(dateisp->Enabled == false && Form2->ADOQuery1->FieldByName("ishn")->Value != "")
		{
			 //ShowMessage("5");
			 Form2->ADOQuery1->SQL->Text="UPDATE vhod SET nom ='"+nom->Text+"', data ='"+date->Date+"',frome ='"+from->Text+"', ish ='"+ish->Text+"', sod ='"+sod->Text+"', komu ='"+komu->Text+"', isp ='"+isp->Text+"', dateisp ='"+dateisp->Date+"', ispflag ='"+CheckIsp+"' WHERE number IN ("+ID->Caption+") ";
			 Form2->ADOQuery1->ExecSQL();
             Form2->ADOQuery1->Active = false;
			//ShowMessage("1-4");
			Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			Form2->ADOQuery1->Active = true;
			Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;

			 Form4->Close();
			 return;
		}
		else if(dateisp->Enabled == true)
		{
			 //ShowMessage("4");
			 Form2->ADOQuery1->SQL->Text="UPDATE vhod SET nom ='"+nom->Text+"', data ='"+date->Date+"',frome ='"+from->Text+"', ish ='"+ish->Text+"', sod ='"+sod->Text+"', komu ='"+komu->Text+"', isp ='"+isp->Text+"', dateisp ='"+dateisp->Date+"', ispflag ='"+CheckIsp+"' WHERE number IN ("+ID->Caption+") ";
			 Form2->ADOQuery1->ExecSQL();
             Form2->ADOQuery1->Active = false;
			//ShowMessage("1-5");
			Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			Form2->ADOQuery1->Active = true;
			Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;

			 Form4->Close();
             return;
		}


	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn3Click(TObject *Sender)
{
  if(isp->Text != "")
  {

	Form2->IspList->SQL->Text = "INSERT INTO isplist VALUES ('"+isp->Text+"') ";
	Form2->IspList->ExecSQL();

	//---------Загружаем список исполнителей в комбобокс--------------------
		Form2->IspList->Active = false;
		Form2->IspList->SQL->Text = "SELECT * FROM isplist ORDER BY ispname";
		Form2->IspList->Active = true;
		Form2->IspList->First();
		Form4->isp->Items->Clear();

		for(int i=Form2->IspList->RecordCount; i>0; i--)
		{
				Form4->isp->Items->Add(Form2->IspList->FieldByName("ispname")->Value);
				Form2->IspList->Next();
		}
  }
  else
  {
		ShowMessage("Нельзя добавить пустое поле");
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn4Click(TObject *Sender)
{
		Form2->IspList->SQL->Text = "DELETE FROM isplist WHERE ispname = '"+isp->Text+"'";
		Form2->IspList->ExecSQL();
		isp->Clear();

        //---------Загружаем список исполнителей в комбобокс--------------------
		Form2->IspList->Active = false;
		Form2->IspList->SQL->Text = "SELECT * FROM isplist ORDER BY ispname";
		Form2->IspList->Active = true;
		Form2->IspList->First();
		Form4->isp->Items->Clear();

		for(int i=Form2->IspList->RecordCount; i>0; i--)
		{
				Form4->isp->Items->Add(Form2->IspList->FieldByName("ispname")->Value);
				Form2->IspList->Next();
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FileNameClick(TObject *Sender)
{

	 if(FilePatch->Caption == "-" || FileName->Caption == "Нет файла" || FileName->Caption == "No_File")
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
		((TBlobField*)Form2->ADOQuery1->FieldByName("file"))->SaveToFile(ini->ReadString("OTHERSETTING","SaveDownloadFiles","")+"\\"+FileName->Caption);
			char* OpenFileName;
			AnsiString  f = FileName->Caption;
			f = ini->ReadString("OTHERSETTING","SaveDownloadFiles","")+"\\"+f;
			ShowMessage(f);
			OpenFileName = f.c_str();
			ShellExecuteA(Handle, "open", OpenFileName, NULL, NULL, SW_SHOWNORMAL);

	 }


}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit10.h"
#include "Unit9.h"
#include "Unit1.h"
#include "IniFiles.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
TIniFile *ini = new TIniFile (ExtractFilePath(ParamStr(0))+"EWEsetting.ini");
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
}
//----------------------[Перевод цветов из HEX в RGB]--------------------------------------
TColor HexToColor(const String& hex)
{
    int r = StrToInt("0x" + hex.SubString(2, 2)); // 2 символа после #
    int g = StrToInt("0x" + hex.SubString(4, 2)); // 2 символа после #
    int b = StrToInt("0x" + hex.SubString(6, 2)); // 2 символа после #

    return TColor(RGB(r, g, b));
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


			if(Form1->Label19->Caption == "ОБЩИЙ")
			{
				Form9->ADOQuery1->Active = false;
				Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr ORDER BY number";
				Form9->ADOQuery1->Active = true;
			}
			else
			{
				Form9->ADOQuery1->Active = false;
				Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE isp ='"+Form1->Label19->Caption+"' ORDER BY number";
				Form9->ADOQuery1->Active = true;
			}


		Form10->Close();
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


		if(Form9->ADOQuery1->FieldByName("file_name")->Value == "No_File" && FileName->Caption != "No_File")
		{

			 Form9->ADOQuery1->SQL->Text = "UPDATE obr SET   data = :data, fio = :fio, adres = :adres, isp = :isp, flag = :flag, file =:BlobValue, file_name = :file_name, tema = :tema, primechanie = :primechanie WHERE number IN (:id)";
			 Form9->ADOQuery1->Parameters->ParamByName("BlobValue")->LoadFromFile(FilePatch->Caption,ftBlob);
			 Form9->ADOQuery1->Parameters->ParamByName("file_name")->Value = FileName->Caption;
			 Form9->ADOQuery1->Parameters->ParamByName("data")->Value = date->Date;
			 Form9->ADOQuery1->Parameters->ParamByName("fio")->Value = FIO->Text;
			 Form9->ADOQuery1->Parameters->ParamByName("adres")->Value = ADRES->Text;
			 Form9->ADOQuery1->Parameters->ParamByName("isp")->Value = ISP->Text;
			 Form9->ADOQuery1->Parameters->ParamByName("flag")->Value = CheckIsp;
			 Form9->ADOQuery1->Parameters->ParamByName("tema")->Value = TEMA->Text;
			 Form9->ADOQuery1->Parameters->ParamByName("primechanie")->Value = Memo1->Text;
			 Form9->ADOQuery1->Parameters->ParamByName("id")->Value = ID->Caption;
			 Form9->ADOQuery1->ExecSQL();



		}
		else
		{

			Form9->ADOQuery1->SQL->Text = "UPDATE obr SET   data = :data, fio = :fio, adres = :adres, isp = :isp, flag = :flag, tema = :tema, primechanie = :primechanie WHERE number IN (:id)";


			Form9->ADOQuery1->Parameters->ParamByName("data")->Value = date->Date;
			Form9->ADOQuery1->Parameters->ParamByName("fio")->Value = FIO->Text;
			Form9->ADOQuery1->Parameters->ParamByName("adres")->Value = ADRES->Text;
			Form9->ADOQuery1->Parameters->ParamByName("isp")->Value = ISP->Text;
			Form9->ADOQuery1->Parameters->ParamByName("flag")->Value = CheckIsp;
			Form9->ADOQuery1->Parameters->ParamByName("tema")->Value = TEMA->Text;
			Form9->ADOQuery1->Parameters->ParamByName("primechanie")->Value = Memo1->Text;
			Form9->ADOQuery1->Parameters->ParamByName("id")->Value = ID->Caption;
			Form9->ADOQuery1->ExecSQL();



		}

			if(Form1->Label19->Caption == "ОБЩИЙ")
			{
				Form9->ADOQuery1->Active = false;
				Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr ORDER BY number";
				Form9->ADOQuery1->Active = true;
			}
			else
			{
				Form9->ADOQuery1->Active = false;
				Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE isp ='"+Form1->Label19->Caption+"' ORDER BY number";
				Form9->ADOQuery1->Active = true;
			}

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
			ADOQuery1->Active = false;

			ADOQuery1->SQL->Text = "SELECT file from obr WHERE number IN ("+ID->Caption+")";
			//ADOQuery1->Parameters->ParamByName("id")->Value = ID->Caption;
			ADOQuery1->Active = true;
            //ADOQuery1->ExecSQL();


		((TBlobField*)ADOQuery1->FieldByName("file"))->SaveToFile(ExtractFilePath(ParamStr(0))+FileName->Caption);
			char* OpenFileName;
			AnsiString  f = FileName->Caption;
			OpenFileName = f.c_str();
			ShellExecuteA(Handle, "open", OpenFileName, NULL, NULL, SW_SHOWNORMAL);

	 }
}
//---------------------------------------------------------------------------


void __fastcall TForm10::FormShow(TObject *Sender)
{
	Form10->Color = HexToColor(ini->ReadString("COLORSETTING","Form10","#608D98"));
}
//---------------------------------------------------------------------------

void __fastcall TForm10::N2Click(TObject *Sender)
{

	if(MessageDlg("Действительно хотите удалить файл?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		Form9->ADOQuery1->SQL->Text = "UPDATE obr SET  file = Null, file_name = 'No_File' WHERE number IN (:id)";
        Form9->ADOQuery1->Parameters->ParamByName("id")->Value = ID->Caption;
		Form9->ADOQuery1->ExecSQL();

		FileName->Caption = "No_File";

		    if(Form1->Label19->Caption == "ОБЩИЙ")
			{
				Form9->ADOQuery1->Active = false;
				Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr ORDER BY number";
				Form9->ADOQuery1->Active = true;
			}
			else
			{
				Form9->ADOQuery1->Active = false;
				Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE isp ='"+Form1->Label19->Caption+"' ORDER BY number";
				Form9->ADOQuery1->Active = true;
			}
	}

}
//---------------------------------------------------------------------------


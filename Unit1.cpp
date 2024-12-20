//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#include <System.SysUtils.hpp>
#include <Dialogs.hpp>
#include <Vcl.FileCtrl.hpp>
#include "IniFiles.hpp"
#include <Vcl.Themes.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit6.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit11.h"
#include "ComObj.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma link "cgrid"
#pragma resource "*.dfm"
TForm1 *Form1;
String selectedDir;
TIniFile *ini = new TIniFile (ExtractFilePath(ParamStr(0))+"EWEsetting.ini");
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//----------------------[������� ������ �� HEX � RGB]--------------------------------------
TColor HexToColor(const String& hex)
{
    int r = StrToInt("0x" + hex.SubString(2, 2)); // 2 ������� ����� #
    int g = StrToInt("0x" + hex.SubString(4, 2)); // 2 ������� ����� #
    int b = StrToInt("0x" + hex.SubString(6, 2)); // 2 ������� ����� #

    return TColor(RGB(r, g, b));
}
//---------------------------------------------------------------------------
void ChangeDataSource(String DBName, String DBpath)
{
	 Form2->ADOConnection1->Close();

	// ��������� ������� ������ �����������
	String currentConnectionString = Form2->ADOConnection1->ConnectionString;

	// ����� �������� ������
	String newDataSource = DBpath + "\\" + DBName;

	String newConnectionString = currentConnectionString.SubString(1, 59)  + newDataSource + ";" + currentConnectionString.SubString(currentConnectionString.Pos("Mode="), currentConnectionString.Length());


	// �������� ������ ����������� �������
	Form2->ADOConnection1->ConnectionString = newConnectionString;
	Form1->Edit1->Text = newConnectionString;


	// �� ������ ������� ����������, ���� ��� ����������
	 Form2->ADOConnection1->Open();
}
//---------------------------------------------------------------------------
void ChangeDataSourceIsh(String DBName, String DBpath)
{
	 Form6->ADOConnection1->Close();

	// ��������� ������� ������ �����������
	String currentConnectionString = Form6->ADOConnection1->ConnectionString;

	// ����� �������� ������
	String newDataSource = DBpath + "\\" + DBName;



	String newConnectionString = currentConnectionString.SubString(1, 59)  + newDataSource + ";" + currentConnectionString.SubString(currentConnectionString.Pos("Mode="), currentConnectionString.Length());


	// �������� ������ ����������� �������
	Form6->ADOConnection1->ConnectionString = newConnectionString;
	Form1->Edit3->Text = Form6->ADOConnection1->ConnectionString;


	// �� ������ ������� ����������, ���� ��� ����������
	 Form6->ADOConnection1->Open();
	  //Form1->Edit3->Text = Form6->ADOConnection1->ConnectionString;
}
//---------------------------------------------------------------------------
void ChangeDataSourceObr(String DBName, String DBpath)
{
	 Form9->ADOConnection1->Close();

	// ��������� ������� ������ �����������
	String currentConnectionString = Form9->ADOConnection1->ConnectionString;

	// ����� �������� ������
	String newDataSource = DBpath + "\\" + DBName;



	String newConnectionString = currentConnectionString.SubString(1, 59)  + newDataSource + ";" + currentConnectionString.SubString(currentConnectionString.Pos("Mode="), currentConnectionString.Length());


	// �������� ������ ����������� �������
	Form9->ADOConnection1->ConnectionString = newConnectionString;
	//Form1->Edit3->Text = Form6->ADOConnection1->ConnectionString;


	// �� ������ ������� ����������, ���� ��� ����������
	 Form9->ADOConnection1->Open();
	  //Form1->Edit3->Text = Form6->ADOConnection1->ConnectionString;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
	Form6->Close();
    Form9->Close();
	Form2->Parent = this;
	Form2->SetBounds(3,3,300,150);
	Form2->Align = alClient;
	Form2->BorderStyle = bsNone;
	Form2->DBGrid1->Align = alClient;
	Form2->DBGrid1->BorderStyle = bsNone;
	Form2->RadioButton1->Checked = true;
	ChangeDataSource(ComboBox1->Text, ini->ReadString("SETTINGBASE","DBVhod",""));
	Form2->SearchNom->Items->Clear();
	Form2->SearchNom->Items->LoadFromFile("journal.ewe");
    Form2->ADOQuery1->Active = false;
	Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
	Form2->ADOQuery1->Active = true;
	Form2->Visible = true;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Label2Click(TObject *Sender)
{
	Form2->Close();
    Form9->Close();
	Form6->Parent = this;
	Form6->SetBounds(3,3,300,150);
	Form6->Align = alClient;
	Form6->BorderStyle = bsNone;
	Form6->DBGrid1->Align = alClient;
	Form6->DBGrid1->BorderStyle = bsNone;
	ChangeDataSourceIsh(ComboBox2->Text, ini->ReadString("SETTINGBASE","DBIsh",""));
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


	ChangeDataSource(ini->ReadString("SETTINGBASE","DefaultDB",""), ini->ReadString("SETTINGBASE","DBVhod",""));
	ChangeDataSourceIsh(ini->ReadString("SETTINGBASE","DefaultDBIsh",""), ini->ReadString("SETTINGBASE","DBIsh",""));
	ChangeDataSourceObr(ini->ReadString("SETTINGBASE","DefaultDBObr",""), ini->ReadString("SETTINGBASE","DBObrasheniya",""));
    //------------------�������� �����������---------------------------------
	Label19->Caption  = ini->ReadString("SETTINGUSER","User","not-authorized");

	if(Label19->Caption == "not-authorized" || Label19->Caption == "" )
	{
		ShowMessage("��������� ���������, �� �� ������������");
        Application->Terminate();
	}
    //-------------------------------------------------------------------------
	Button1->Click();

	Label5->Caption = DateToStr(Date())+" "+Time();

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

    //��� ���������
	if(Label19->Caption == "�����")
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr ORDER BY number";
		Form9->ADOQuery1->Active = true;
		Label23->Caption = Form9->ADOQuery1->RecordCount;
	}
	else
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE isp ='"+Label19->Caption+"' ORDER BY number";
		Form9->ADOQuery1->Active = true;
		Label23->Caption = Form9->ADOQuery1->RecordCount;
	}

	//����� ����
	if(Label19->Caption == "�����")
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE data < DATEADD('d', -25, Date()) AND flag = 0 ORDER BY number";
		Form9->ADOQuery1->Active = true;
		Label27->Caption = Form9->ADOQuery1->RecordCount;
	}
	else
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE data < DATEADD('d', -25, Date()) AND flag = 0 AND isp ='"+Label19->Caption+"' ORDER BY number";
		Form9->ADOQuery1->Active = true;
		Label27->Caption = Form9->ADOQuery1->RecordCount;
	}

	//�������� ����
	if(Label19->Caption == "�����")
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE data < DATEADD('d', -15, Date()) AND data >= DATEADD('d', -25, Date()) AND flag = 0 ORDER BY number";
		Form9->ADOQuery1->Active = true;
		Label25->Caption = Form9->ADOQuery1->RecordCount;
	}
	else
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE data < DATEADD('d', -15, Date()) AND data >= DATEADD('d', -25, Date()) AND flag = 0 AND isp ='"+Label19->Caption+"' ORDER BY number";
		Form9->ADOQuery1->Active = true;
        Label25->Caption = Form9->ADOQuery1->RecordCount;
	}







	Label1->Font->Color = HexToColor("#e06214");
	Label16->Font->Color = HexToColor("#e06214");
	Label2->Font->Color = HexToColor("#e06214");
	Label20->Font->Color = HexToColor("#e06214");




	//-------------------- ��� Combobox -------------------------------------
	//ComboBox1->Font->Color = HexToColor("#8c00ff");
   //	ComboBox2->Font->Color = HexToColor("#8c00ff");




}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button1Click(TObject *Sender)
{
			String searchPath;
			int result;

			// ������� ComboBox ����� ����������� ����� ���������
			ComboBox1->Clear();

			// ���������� ��� ������ ������
			TSearchRec searchRec;
			 searchPath = ini->ReadString("SETTINGBASE","DBVhod","") +"\\*.mdb"; // ���� � ������

			// ������ ������ ������
			 result = FindFirst(searchPath, faArchive, searchRec);

			// ���������, ������� �� �����
			if (result == 0) // ���� ����� �������
			{
				do {
					// ��������� ��� ����� (��� ����) � ComboBox
					ComboBox1->Items->Add(searchRec.Name);

					// ��������� � ���������� �����
					result = FindNext(searchRec);
				} while (result == 0);



				ComboBox1->ItemIndex = ComboBox1->Items->IndexOf(ini->ReadString("SETTINGBASE","DefaultDB","2024.mdb"));

			}
			else // ���� ����� �� �������
			{
				ShowMessage("����� � ����������� .mdb �� ������� �������� ");
			}

			// ����������� �������
			FindClose(searchRec);
			//---------------------���������--------------------------

            // ������� ComboBox ����� ����������� ����� ���������
			ComboBox2->Clear();

			 searchPath = ini->ReadString("SETTINGBASE","DBIsh","") +"\\*.mdb"; // ���� � ������

			// ������ ������ ������
			 result = FindFirst(searchPath, faArchive, searchRec);

			// ���������, ������� �� �����
			if (result == 0) // ���� ����� �������
			{
				do {
					// ��������� ��� ����� (��� ����) � ComboBox
					ComboBox2->Items->Add(searchRec.Name);

					// ��������� � ���������� �����
					result = FindNext(searchRec);
				} while (result == 0);

			ComboBox2->ItemIndex = ComboBox2->Items->IndexOf(ini->ReadString("SETTINGBASE","DefaultDBIsh","2024.mdb"));
			}
			else // ���� ����� �� �������
			{
				ShowMessage("����� � ����������� .mdb �� ������� ��������� ");
			}

			// ����������� �������
			FindClose(searchRec);
			//---------------------���������--------------------------

            // ������� ComboBox ����� ����������� ����� ���������
			ComboBox3->Clear();

			 searchPath = ini->ReadString("SETTINGBASE","DBObrasheniya","") +"\\*.mdb"; // ���� � ������

			// ������ ������ ������
			 result = FindFirst(searchPath, faArchive, searchRec);

			// ���������, ������� �� �����
			if (result == 0) // ���� ����� �������
			{
				do {
					// ��������� ��� ����� (��� ����) � ComboBox
					ComboBox3->Items->Add(searchRec.Name);

					// ��������� � ���������� �����
					result = FindNext(searchRec);
				} while (result == 0);

			ComboBox3->ItemIndex = ComboBox3->Items->IndexOf(ini->ReadString("SETTINGBASE","DefaultDBObr","2024.mdb"));
			}
			else // ���� ����� �� �������
			{
				ShowMessage("����� � ����������� .mdb �� ������� ��������� ");
			}

			// ����������� �������
			FindClose(searchRec);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label16Click(TObject *Sender)
{
	Form6->Close();
	Form2->Close();
    Form9->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   TFileOpenDialog *Dialog = new TFileOpenDialog(this);
	Dialog->Title = "�������� �������";
	Dialog->Options << fdoPickFolders; // ������������� ����� ������ �����
	Dialog->DefaultFolder = "Desktop"; // ������������� ��������� �����

	// ���������� ������ ������
	if (Dialog->Execute())
	{
		// �������� ��������� �������
		selectedDir = Dialog->FileName;
		ShowMessage("��������� �������: " + selectedDir);
	}

	delete Dialog; // ����������� ������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Edit1->Text = Form2->ADOConnection1->ConnectionString;

	String currentConnectionString = Form2->ADOConnection1->ConnectionString;
	String newDataSource = ComboBox1->Text;

	String newConnectionString = currentConnectionString.SubString(1, 59)  + newDataSource + ";" + currentConnectionString.SubString(currentConnectionString.Pos("Mode="), currentConnectionString.Length());
	Edit2->Text =  newConnectionString;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::N3Click(TObject *Sender)
{
	Form8->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	ini->WriteString("SETTINGBASE","DefaultDB",ComboBox1->Items->Strings[ComboBox1->ItemIndex]);

    ChangeDataSource(ini->ReadString("SETTINGBASE","DefaultDB",""), ini->ReadString("SETTINGBASE","DBVhod",""));

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

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
	ini->WriteString("SETTINGBASE","DefaultDBIsh",ComboBox2->Items->Strings[ComboBox2->ItemIndex]);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Label20Click(TObject *Sender)
{
	Form2->Close();
	Form6->Close();
	Form9->Parent = this;
	Form9->SetBounds(3,3,300,150);
	Form9->Align = alClient;
	Form9->BorderStyle = bsNone;
	Form9->DBGrid1->Align = alClient;
	Form9->DBGrid1->BorderStyle = bsNone;
	ChangeDataSourceObr(ComboBox3->Text, ini->ReadString("SETTINGBASE","DBObrasheniya",""));

	if(Label19->Caption == "�����")
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr ORDER BY number";
		Form9->ADOQuery1->Active = true;
	}
	else
	{
        Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT number, data, fio, adres, tema, isp, ishn, flag, primechanie, file_name FROM obr WHERE isp ='"+Label19->Caption+"' ORDER BY number";
		Form9->ADOQuery1->Active = true;
	}



    Form9->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::IT1Click(TObject *Sender)
{
			char* OpenFileName;
			AnsiString  f = "EWESetting.ini";
			OpenFileName = f.c_str();
			ShellExecuteA(Handle, "open", OpenFileName, NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PopupMenu11Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AquaLightSlate1Click(TObject *Sender)
{
	TStyleManager::SetStyle("Aqua Light Slate");
	ini->WriteString("STYLESETTING","DefaultStyle","Aqua Light Slate");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Glow1Click(TObject *Sender)
{
	  TStyleManager::SetStyle("Glow");
	  ini->WriteString("STYLESETTING","DefaultStyle","Glow");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IcebergClassico1Click(TObject *Sender)
{
	   TStyleManager::SetStyle("Iceberg Classico");
	   ini->WriteString("STYLESETTING","DefaultStyle","Iceberg Classico");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LavenderClassico1Click(TObject *Sender)
{
	  TStyleManager::SetStyle("Lavender Classico");
	  ini->WriteString("STYLESETTING","DefaultStyle","Lavender Classico");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Sky1Click(TObject *Sender)
{
	  TStyleManager::SetStyle("Sky");
	  ini->WriteString("STYLESETTING","DefaultStyle","Sky");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SlateClassico1Click(TObject *Sender)
{
	  TStyleManager::SetStyle("Slate Classico");
	  ini->WriteString("STYLESETTING","DefaultStyle","Slate Classico");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::abletDark1Click(TObject *Sender)
{
	 TStyleManager::SetStyle("Tablet Dark");
	 ini->WriteString("STYLESETTING","DefaultStyle","Tablet Dark");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::abletLight1Click(TObject *Sender)
{
	TStyleManager::SetStyle("Tablet Light");
	ini->WriteString("STYLESETTING","DefaultStyle","Tablet Light");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Amakrits1Click(TObject *Sender)
{
	 TStyleManager::SetStyle("Amakrits");
	 ini->WriteString("STYLESETTING","DefaultStyle","Amakrits");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AmethystKamri1Click(TObject *Sender)
{
	 TStyleManager::SetStyle("Amethyst Kamri");
	 ini->WriteString("STYLESETTING","DefaultStyle","Amethyst Kamri");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AquaGraphite1Click(TObject *Sender)
{
	TStyleManager::SetStyle("Aqua Graphite");
	ini->WriteString("STYLESETTING","DefaultStyle","Aqua Graphite");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Auric1Click(TObject *Sender)
{
	TStyleManager::SetStyle("Auric");
	ini->WriteString("STYLESETTING","DefaultStyle","Auric");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CobaltXEMedia1Click(TObject *Sender)
{
	TStyleManager::SetStyle("Cobalt XEMedia");
	ini->WriteString("STYLESETTING","DefaultStyle","Cobalt XEMedia");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CyanDusk1Click(TObject *Sender)
{
	TStyleManager::SetStyle("Cyan Dusk");
	ini->WriteString("STYLESETTING","DefaultStyle","Cyan Dusk");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TStyleManager::SetStyle(ini->ReadString("STYLESETTING","DefaultStyle","Window"));
    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
     Form11->ShowModal();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit11.h"
#include "IniFiles.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
TIniFile *ini = new TIniFile (ExtractFilePath(ParamStr(0))+"EWEsetting.ini");
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm11::Button1Click(TObject *Sender)
{
    String selectedDir;
	TFileOpenDialog *Dialog = new TFileOpenDialog(this);
	Dialog->Title = "�������� ���� ����������";
	Dialog->Options << fdoPickFolders; // ������������� ����� ������ �����
	Dialog->DefaultFolder = "Desktop"; // ������������� ��������� �����

	// ���������� ������ ������
	if (Dialog->Execute())
	{
		// �������� ��������� �������
		selectedDir = Dialog->FileName;
		ini->WriteString("OTHERSETTING","SaveDownloadFiles",selectedDir);
		Edit1->Text = selectedDir;
	}

	delete Dialog; // ����������� ������
}
//---------------------------------------------------------------------------
void __fastcall TForm11::FormShow(TObject *Sender)
{
	Edit1->Text = ini->ReadString("OTHERSETTING","SaveDownloadFiles","");
}
//---------------------------------------------------------------------------

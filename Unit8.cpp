//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit1.h"
#include "IniFiles.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
TIniFile *ini = new TIniFile (ExtractFilePath(ParamStr(0))+"EWEsetting.ini");
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
	String selectedDir;
	TFileOpenDialog *Dialog = new TFileOpenDialog(this);
	Dialog->Title = "Выберите каталог где находится базы входящих";
	Dialog->Options << fdoPickFolders; // Устанавливаем опцию выбора папок
	Dialog->DefaultFolder = "Desktop"; // Устанавливаем начальную папку

	// Показываем диалог выбора
	if (Dialog->Execute())
	{
		// Получаем выбранный каталог
		selectedDir = Dialog->FileName;
		ini->WriteString("SETTINGBASE","DBVhod",selectedDir);
		Edit1->Text = selectedDir;
	}

	delete Dialog; // Освобождаем память
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormShow(TObject *Sender)
{
	Edit1->Text = ini->ReadString("SETTINGBASE","DBVhod","");
	Edit2->Text = ini->ReadString("SETTINGBASE","DBIsh","");
	Edit3->Text = ini->ReadString("SETTINGBASE","DBObrasheniya","");
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
	String selectedDir;
	TFileOpenDialog *Dialog = new TFileOpenDialog(this);
	Dialog->Title = "Выберите каталог где находится базы входящих";
	Dialog->Options << fdoPickFolders; // Устанавливаем опцию выбора папок
	Dialog->DefaultFolder = "Desktop"; // Устанавливаем начальную папку

	// Показываем диалог выбора
	if (Dialog->Execute())
	{
		// Получаем выбранный каталог
		selectedDir = Dialog->FileName;
		ini->WriteString("SETTINGBASE","DBIsh",selectedDir);
		Edit2->Text = selectedDir;
	}

	delete Dialog; // Освобождаем память
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormClose(TObject *Sender, TCloseAction &Action)
{
      Form1->Button1->Click();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button3Click(TObject *Sender)
{
    String selectedDir;
	TFileOpenDialog *Dialog = new TFileOpenDialog(this);
	Dialog->Title = "Выберите каталог где находится базы Обращений";
	Dialog->Options << fdoPickFolders; // Устанавливаем опцию выбора папок
	Dialog->DefaultFolder = "Desktop"; // Устанавливаем начальную папку

	// Показываем диалог выбора
	if (Dialog->Execute())
	{
		// Получаем выбранный каталог
		selectedDir = Dialog->FileName;
		ini->WriteString("SETTINGBASE","DBObrasheniya",selectedDir);
		Edit3->Text = selectedDir;
	}

	delete Dialog; // Освобождаем память
}
//---------------------------------------------------------------------------


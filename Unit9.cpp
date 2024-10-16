//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit10.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
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

void __fastcall TForm9::BitBtn1Click(TObject *Sender)
{
	Form10->ADD_OR_EDIT->Caption = "ADD";
    Form10->date->Date = Date();
	Form10->ISP->Items->LoadFromFile("ipsobrlist.ewe");
	Form10->FIO->Clear();
	Form10->ISP->Text = "";
	Form10->ADRES->Clear();
	Form10->TEMA->Clear();
	Form10->Memo1->Clear();
	Form10->CheckBox1->Checked = false;
	Form10->FilePatch->Caption = "-";
	Form10->FileName->Caption = "No_File";
    Form10->number->Text = ADOQuery1->RecordCount +1;
	Form10->ShowModal();

}
//---------------------------------------------------------------------------


void __fastcall TForm9::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{

		 try
		 {
				TDateTime dt =  ADOQuery1->FieldByName("data")->Value;
				int i = Date() - dt;
				 //ShowMessage(i);
				 String COL_DAY_RED = "25";
				 String COL_DAY_YEL = "15";



				if (i  >= COL_DAY_YEL && i <= 24 && ADOQuery1->FieldByName("flag")->Value == 0)
				{
						TDBGrid *dbg = (TDBGrid*)Sender;
						dbg->Canvas->Brush->Color = HexToColor("#DDDB53");
						dbg->Canvas->FillRect(Rect);
						dbg->Canvas->Font->Color = clBlack;
                        dbg->DefaultDrawColumnCell(Rect, DataCol, Column, State);
                }

				if (i  >= COL_DAY_RED && ADOQuery1->FieldByName("flag")->Value == 0)
                {
						TDBGrid *dbg = (TDBGrid*)Sender;
						dbg->Canvas->Brush->Color = HexToColor("#D94545");
						dbg->Canvas->FillRect(Rect);
						dbg->Canvas->Font->Color = clWhite;
						dbg->DefaultDrawColumnCell(Rect, DataCol, Column, State);
				}

				if (ADOQuery1->FieldByName("flag")->Value == 1)
                {
						TDBGrid *dbg = (TDBGrid*)Sender;
						dbg->Canvas->Brush->Color = HexToColor("#32E19A");
						dbg->Canvas->FillRect(Rect);
						dbg->Canvas->Font->Color = clBlack;
						dbg->DefaultDrawColumnCell(Rect, DataCol, Column, State);
				}
		 }
		 catch(Exception &e)
		 {

		 }

}
//---------------------------------------------------------------------------

void __fastcall TForm9::BitBtn2Click(TObject *Sender)
{
	Form10->ADD_OR_EDIT->Caption = "EDIT";
	Form10->number->Text = ADOQuery1->FieldByName("number")->Value;
	Form10->FIO->Text = ADOQuery1->FieldByName("fio")->Value;
	Form10->date->Date = ADOQuery1->FieldByName("data")->Value;
	Form10->ISP->Items->LoadFromFile("ipsobrlist.ewe");
	Form10->ISP->Text = ADOQuery1->FieldByName("isp")->Value;
	Form10->ADRES->Text = ADOQuery1->FieldByName("adres")->Value;
	Form10->TEMA->Text = ADOQuery1->FieldByName("tema")->Value;
	Form10->Memo1->Text = ADOQuery1->FieldByName("primechanie")->Value;
	Form10->ID->Caption = ADOQuery1->FieldByName("number")->Value;

	Form10->FileName->Caption = ADOQuery1->FieldByName("file_name")->Value;

	if(ADOQuery1->FieldByName("flag")->Value == "1")
	{
		Form10->CheckBox1->Checked = true;
	}
	else
	{
		Form10->CheckBox1->Checked = false;
	}

    Form10->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::DBGrid1DblClick(TObject *Sender)
{
    BitBtn2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Edit1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE fio like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value="%"+Edit1->Text+"%";
		ADOQuery1->Active = true;

		if(Edit1->Text.Length() == 0)
		{
			  if(Form1->Label19->Caption == "�����")
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
				else
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE isp ='"+Form1->Label19->Caption+"' ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Edit2KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
    ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE adres like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value="%"+Edit2->Text+"%";
		ADOQuery1->Active = true;

		if(Edit2->Text.Length() == 0)
		{
			  if(Form1->Label19->Caption == "�����")
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
				else
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE isp ='"+Form1->Label19->Caption+"' ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Edit3KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE tema like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value="%"+Edit3->Text+"%";
		ADOQuery1->Active = true;

		if(Edit3->Text.Length() == 0)
		{
			  if(Form1->Label19->Caption == "�����")
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
				else
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE isp ='"+Form1->Label19->Caption+"' ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Edit4KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE isp like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value="%"+Edit4->Text+"%";
		ADOQuery1->Active = true;

		if(Edit4->Text.Length() == 0)
		{
			  if(Form1->Label19->Caption == "�����")
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
				else
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE isp ='"+Form1->Label19->Caption+"' ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Edit5KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE ishn like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value="%"+Edit5->Text+"%";
		ADOQuery1->Active = true;

		if(Edit5->Text.Length() == 0)
		{
				if(Form1->Label19->Caption == "�����")
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
				else
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE isp ='"+Form1->Label19->Caption+"' ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}
		}
}
//---------------------------------------------------------------------------


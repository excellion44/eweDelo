//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit10.h"
#include "Unit1.h"
#include "IniFiles.hpp"

#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdURI.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
TIniFile *ini = new TIniFile (ExtractFilePath(ParamStr(0))+"EWEsetting.ini");
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

void SendTelegramMessage(const String &Token, const String &ChatID, const String &MessageText)
{
    TIdHTTP *IdHTTP = new TIdHTTP(nullptr);
    TIdSSLIOHandlerSocketOpenSSL *SSLHandler = new TIdSSLIOHandlerSocketOpenSSL(nullptr);
    String URL;
    String Response;

    try
    {
        // ���������� ������ SSL
        SSLHandler->SSLOptions->Method = sslvSSLv23; // ��� ����� ����� ���� sslvTLSv1_2 ��� ������ ��������
		//SSLHandler->SSLOptions->VerifyMode = sslvrfNone; // ���� �� ������ ��������� ����������
        IdHTTP->IOHandler = SSLHandler;

        // ��������� URL ��� �������� ���������
        URL = Format("https://api.telegram.org/bot%s/sendMessage?chat_id=%s&text=%s",
                     ARRAYOFCONST((Token, ChatID, TIdURI::ParamsEncode(MessageText))));

        // ��������� GET ������
        Response = IdHTTP->Get(URL);

        // �����������: ������� �����
        //ShowMessage(Response);
    }
    __finally
    {
        delete SSLHandler;
        delete IdHTTP;
    }
}
//---------------------------------------------------------------------------
String GetEnding(int number, String singular, String plural, String genitive)
{
    int lastDigit = number % 10;
    int lastTwoDigits = number % 100;

    if (lastTwoDigits >= 11 && lastTwoDigits <= 19) {
        return plural; // ��� ����� 11-19 ������������ ����� �������������� �����
    } else if (lastDigit == 1) {
        return singular; // ��� �����, �������������� �� 1
    } else if (lastDigit >= 2 && lastDigit <= 4) {
        return genitive; // ��� �����, �������������� �� 2-4
    } else {
        return plural; // ��� ���������
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BitBtn1Click(TObject *Sender)
{
	Form10->ADD_OR_EDIT->Caption = "ADD";
	Form10->date->Date = Date();
	Form10->ISP->Items->LoadFromFile(ExtractFilePath(ParamStr(0))+"ipsobrlist.ewe");
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
						dbg->Canvas->Brush->Color = HexToColor(ini->ReadString("COLORSETTING","Form9ColDayYel","#DDDB53"));
						dbg->Canvas->FillRect(Rect);
						dbg->Canvas->Font->Color = clBlack;
                        dbg->DefaultDrawColumnCell(Rect, DataCol, Column, State);
                }

				if (i  >= COL_DAY_RED && ADOQuery1->FieldByName("flag")->Value == 0)
                {
						TDBGrid *dbg = (TDBGrid*)Sender;
						dbg->Canvas->Brush->Color = HexToColor(ini->ReadString("COLORSETTING","Form9ColDayRed","#D94545"));
						dbg->Canvas->FillRect(Rect);
						dbg->Canvas->Font->Color = clWhite;
						dbg->DefaultDrawColumnCell(Rect, DataCol, Column, State);
				}
				//���� ��� ������������� �����
				if (ADOQuery1->FieldByName("flag")->Value == 1)
                {
						TDBGrid *dbg = (TDBGrid*)Sender;
						dbg->Canvas->Brush->Color = HexToColor(ini->ReadString("COLORSETTING","Form9ColFlag","#D5F5E3"));
						dbg->Canvas->FillRect(Rect);
						dbg->Canvas->Font->Color = clBlack;
						dbg->DefaultDrawColumnCell(Rect, DataCol, Column, State);
				}
				//���� ��������� �������
				if (ADOQuery1->FieldByName("flag")->Value == 2)
                {
						TDBGrid *dbg = (TDBGrid*)Sender;
						dbg->Canvas->Brush->Color = HexToColor(ini->ReadString("COLORSETTING","Form9ColIspTrue","#32E19A"));
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
	Form10->ISP->Items->LoadFromFile(ExtractFilePath(ParamStr(0))+"ipsobrlist.ewe");
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

void __fastcall TForm9::BitBtn3Click(TObject *Sender)
{
	if(MessageDlg("������������� ������ ������� ������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		String DELETED = ADOQuery1->FieldByName("number")->Value;

		ADOQuery1->SQL->Text = "DELETE FROM obr WHERE number IN ("+DELETED+") ";
		ADOQuery1->ExecSQL();

		if(Form1->Label19->Caption == "�����")
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

void __fastcall TForm9::N3Click(TObject *Sender)
{
    BitBtn3->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::N1Click(TObject *Sender)
{
    BitBtn2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Image1Click(TObject *Sender)
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
//---------------------------------------------------------------------------

void __fastcall TForm9::Button1Click(TObject *Sender)
{

		 if(FilePatch->Caption !="FilePatch")
		 {
			 Form9->ADOQuery1->SQL->Text = "UPDATE obr SET  file =:BlobValue, file_name = :file_name, flag = :flag, ishn = :ishn WHERE number IN (:id)";
			 Form9->ADOQuery1->Parameters->ParamByName("BlobValue")->LoadFromFile(FilePatch->Caption,ftBlob);
			 Form9->ADOQuery1->Parameters->ParamByName("file_name")->Value = FileName->Caption;
			 Form9->ADOQuery1->Parameters->ParamByName("flag")->Value = "2";
			 Form9->ADOQuery1->Parameters->ParamByName("ishn")->Value = ISHN->Text;
			 Form9->ADOQuery1->Parameters->ParamByName("id")->Value = ID->Caption;
			 Form9->ADOQuery1->ExecSQL();

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

                Panel2->Visible = false;
		 }
		 else
		 {
				ShowMessage("�� �� ���������� �����!");
		 }
}
//---------------------------------------------------------------------------

void __fastcall TForm9::BitBtn5Click(TObject *Sender)
{

	int FLAG = ADOQuery1->FieldByName("flag")->Value;

	if(FLAG == 2)
	{
		ShowMessage("������ ������ ��� ���������");
        return;
	}
	ISHN->Clear();
    FilePatch->Caption = "FilePatch";
	ID->Caption = ADOQuery1->FieldByName("number")->Value;
    Form9->Panel2->Color = HexToColor(ini->ReadString("COLORSETTING","Panel2ColIsp","#DDDB53"));
    // ������������� Panel1 �������
	 Panel2->Visible = true;

    // ��������� ������� � ������� ��� �������������
	int panelWidth = Panel2->Width;
	int panelHeight = Panel2->Height;

	// ������������� �� X
	Panel2->Left = (ClientWidth - panelWidth) / 2;

    // ������������� �� Y
	Panel2->Top = (ClientHeight - panelHeight) / 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm9::N2Click(TObject *Sender)
{
    BitBtn5->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::RadioButton3Click(TObject *Sender)
{
				if(Form1->Label19->Caption == "�����")
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE data < DATEADD('d', -15, Date()) AND data >= DATEADD('d', -25, Date()) AND flag = 0 ORDER BY number";
					Form9->ADOQuery1->Active = true;

				}
				else
				{
					Form9->ADOQuery1->Active = false;
					Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE data < DATEADD('d', -15, Date()) AND data >= DATEADD('d', -25, Date()) AND flag = 0 AND isp ='"+Form1->Label19->Caption+"' ORDER BY number";
					Form9->ADOQuery1->Active = true;
				}

}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button2Click(TObject *Sender)
{
    Panel2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm9::RadioButton4Click(TObject *Sender)
{
	if(Form1->Label19->Caption == "�����")
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
//---------------------------------------------------------------------------

void __fastcall TForm9::RadioButton1Click(TObject *Sender)
{
    if(Form1->Label19->Caption == "�����")
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE data < DATEADD('d', -25, Date()) AND flag = 0 ORDER BY number";
		Form9->ADOQuery1->Active = true;
	}
	else
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE data < DATEADD('d', -25, Date()) AND flag = 0 AND isp ='"+Form1->Label19->Caption+"' ORDER BY number";
		Form9->ADOQuery1->Active = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::RadioButton2Click(TObject *Sender)
{
	if(Form1->Label19->Caption == "�����")
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr where flag =1 ORDER BY number";
		Form9->ADOQuery1->Active = true;
	}
	else
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE flag =1 AND isp ='"+Form1->Label19->Caption+"' ORDER BY number";
		Form9->ADOQuery1->Active = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::FormResize(TObject *Sender)
{
	// �������� ������ DBGrid
    int totalWidth = DBGrid1->Width-40;

    // ������������� ������������� ������ ��� ������� 1, 5, 6 � 7
    int fixedWidths[] = {50, 100, 0, 0, 0, 100, 100}; // ������ ������������� ����� ��� ������� 1, 5, 6 � 7
    int totalFixedWidth = 0;

    // ��������� ����� ������������� ������
    for (int i = 0; i < 7; ++i) {
        totalFixedWidth += fixedWidths[i]; // ��������� ������������� ������
    }

    // ���������� ������, ��������� ��� ������� 2, 3 � 4
    int availableWidth = totalWidth - totalFixedWidth;

    // ��������� ���������� �������, ������� �� ����� ��������
	int startIndex = 2; // ������ ��� ������� 2
	int endIndex = 4;   // ������ ��� ������� 4
    int columnCount = endIndex - startIndex + 1; // ���������� ������� (2, 3 � 4)

    // ����������� ������ ��� �������
    int minColumnWidth = 50; // ���������� ����������� ������ �� ������ ����������
    int totalMinWidth = minColumnWidth * columnCount; // ����� ����������� ������

    // ���� ��������� ������ ������ �����������, ������������� ����������� ������
    if (availableWidth < totalMinWidth) {
        availableWidth = totalMinWidth;
    }

    // ��������� ������ ������ �������
    int columnWidth = availableWidth / columnCount;

    // ������������� ������ ������ ��� ������� 2, 3 � 4
    for (int i = startIndex; i <= endIndex; ++i) {
        DBGrid1->Columns->Items[i]->Width = columnWidth;
    }

    // ������������� ������������� ������ ��� ��������� �������
    for (int i = 0; i < 7; ++i) {
        if (fixedWidths[i] > 0) {
            DBGrid1->Columns->Items[i]->Width = fixedWidths[i];
        }
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button3Click(TObject *Sender)
{
	String message;
	String prosrocheno;
	String istekaet;

	if(Form1->Label19->Caption == "�����")
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE data < DATEADD('d', -25, Date()) AND flag = 0 ORDER BY number";
		Form9->ADOQuery1->Active = true;
		 message = "��������! � ��� ������� "+IntToStr(ADOQuery1->RecordCount)+" ����������� ���������! ����� ��� ����� =) ";
		//ShowMessage(message);


	}
	else
	{
		Form9->ADOQuery1->Active = false;
		Form9->ADOQuery1->SQL->Text = "SELECT * FROM obr WHERE data < DATEADD('d', -25, Date()) AND flag = 0 AND isp ='"+Form1->Label19->Caption+"' ORDER BY number";
		Form9->ADOQuery1->Active = true;
	}








	SendTelegramMessage("1877723958:AAHh1nURo4sssu-JQ0Y4idsgZy3L-WaIz9Y", "1663304412", message);
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button4Click(TObject *Sender)
{
	int number;

    // ������� ������������� ����� �� Edit1 � �����
	if (TryStrToInt("24", number))
	{
		String ending = GetEnding(number, "���������", "���������", "���������");
		ShowMessage("� ��� ���� " + IntToStr(number) + " " + ending.c_str() + ".");
	}
	else
	{
        // ���� ������� �� �����, ������� ��������� �� ������
		ShowMessage("������� ���������� �����.");
	}
}
//---------------------------------------------------------------------------


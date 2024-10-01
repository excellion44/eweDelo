//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit5.h"
#include <DateUtils.hpp>
#include <windows.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "ComObj.hpp"
TForm2 *Form2;
String WORD_CELL;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm2::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{


		 try
		 {
				TDateTime dt =  ADOQuery1->FieldByName("dateisp")->Value;
				int i = Date() - dt;
				 //ShowMessage(i);
				 String COL_DAY_RED = "1";
				 String COL_DAY_YEL = "10";



				if (i  <= COL_DAY_YEL && ADOQuery1->FieldByName("ispflag")->Value == 1)
				{
						TDBGrid *dbg = (TDBGrid*)Sender;
                        dbg->Canvas->Brush->Color = clYellow;
                        dbg->Canvas->FillRect(Rect);
                        dbg->DefaultDrawColumnCell(Rect, DataCol, Column, State);
                }

				if (i  >= COL_DAY_RED && ADOQuery1->FieldByName("ispflag")->Value == 1)
                {
						TDBGrid *dbg = (TDBGrid*)Sender;
						dbg->Canvas->Brush->Color = clRed;
						dbg->Canvas->FillRect(Rect);
						dbg->Canvas->Font->Color = clWhite;
						dbg->DefaultDrawColumnCell(Rect, DataCol, Column, State);
				}
		 }
		 catch(Exception &e)
		 {
              //хз пока как тут избавиться от ошибки пустой даты
		 }






}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
	Form2->ADOQuery1->Active = false;
	Form2->ADOQuery1->SQL->Text = "select* from vhod where ispflag=1 order by number";
	Form2->ADOQuery1->Active = true;
	StatusBar1->Panels->Items[1]->Text = ADOQuery1->RecordCount;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
	Form2->ADOQuery1->Active = false;
	Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
	Form2->ADOQuery1->Active = true;
	Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
	Form2->ADOQuery1->Active = false;
	Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod where nom = '02-08' ORDER BY number";
	Form2->ADOQuery1->Active = true;
	Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton4Click(TObject *Sender)
{
	Form2->ADOQuery1->Active = false;
	Form2->ADOQuery1->SQL->Text = "SELECT * FROM vhod where dateisp < NOW() AND ispflag = 1 ORDER BY number";
	Form2->ADOQuery1->Active = true;
	Form2->StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{


	 DBGrid1->Visible = false;
	 int cout_otchet;


	if(ADOQuery1->RecNo !=1)
	{
		cout_otchet =  ADOQuery1->RecordCount - ADOQuery1->RecNo +1;
	}
	else
	{
		cout_otchet = ADOQuery1->RecordCount;
	}

		//ShowMessage(cout_otchet);
		Memo2->Lines->LoadFromFile("upload_code.html");



		 for (cout_otchet; cout_otchet > 0; cout_otchet--)
		 {

				 Memo2->Lines->Add("<tr>");
				String column[10] = {"number","nom","data","frome","ish","sod","komu","dateisp","isp","ishn"};
				int column_nom=0;



				for(int b=10; b >0; b--)
				{

					String FIRST_HTML = "<td width='62' height='27'><p align='center'><span style='font-size:10pt;'><font face='Times New Roman'>&nbsp;</font></span></p></td>";
					FIRST_HTML   = StringReplace(FIRST_HTML,"&nbsp;",VarToStr(ADOQuery1->FieldByName(column[column_nom])->Value),TReplaceFlags()<<rfReplaceAll);
					Memo2->Lines->Add(FIRST_HTML);
					column_nom++;
				}

				Memo2->Lines->Add("</tr>");
				//StatusBar1->Panels->Items[3]->Text = IntToStr((ADOQuery1->RecNo * 100) / (cout_otchet)) +" %";    //  показываем % выгрузки
				ADOQuery1->Next();

		 }

		 Memo2->Lines->Add("</table><p>&nbsp;</p></body></html>");
		 Memo2->Lines->SaveToFile("otchet.html");
		 ShellExecuteA(Handle, "open", "otchet.html", NULL, NULL, SW_SHOWNORMAL);







	DBGrid1->Visible = true;







































  /*       ВЫВОД В ВОРД - РАБОТАЕ ПРОСТО ПОКА ОТКЛЮЧИЛ

	 Variant Word, Document, Table, var, Cell, R, v;   // создаем объекты
	 String CellText[10];

		//ProgressBar1->Visible = true;
	   //ProgressBar1->Position = 0;

	   //Panel6->Visible = true;
	   DBGrid1->Visible = false;
	   int cout_otchet;

		Word = CreateOleObject("Word.Application"); //—оздаем объект ворда

        Word.OlePropertyGet("Documents").OleProcedure("Add"); //открываем ворд и создаем новый документ

        Document = Word.OlePropertyGet("Documents").OleFunction("Item", 1);  // получаешь содержимое этого контейнера по индексу 1, чтобы иметь возможность работать с документом
	Document.OlePropertyGet("PageSetup").OlePropertySet("Orientation", 1);  //делаем лист альбомным
		  //ShowMessage("1");


				if(ADOQuery1->RecNo !=1)
				{
						cout_otchet =  ADOQuery1->RecordCount - ADOQuery1->RecNo +1;
				}
				else
				{
						cout_otchet = ADOQuery1->RecordCount;
				}
			   //ShowMessage("2");
		Document.OlePropertyGet("Tables").OleProcedure("Add", Document.OleFunction("Range"), cout_otchet, 10, 2, 2);  //рисуем таблицу в зависимости от того сколько у нас в базе на данный момент записей т.е. сколько сейчас отображаетс¤ в DBGrid или же с того места где стоит курсор
        Table = Document.OlePropertyGet("Tables").OleFunction("Item", 1); // получаем содержимое этого контейнера по индексу 1, чтобы иметь возможность работать с таблицей.

		//----------------------------------------------------------------------


				Cell = Table.OleFunction("Cell",1,1);
				Cell.OleFunction("Select");
				CellText[0]="№";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[0]));


				Cell = Table.OleFunction("Cell",1,2);
				Cell.OleFunction("Select");
				CellText[1]="Журнал";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[1]));


				Cell = Table.OleFunction("Cell",1,3);
				Cell.OleFunction("Select");
				CellText[2]="Дата";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[2]));


				Cell = Table.OleFunction("Cell",1,4);
				Cell.OleFunction("Select");
				CellText[3]="Источник";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[3]));

				Cell = Table.OleFunction("Cell",1,5);
				Cell.OleFunction("Select");
				CellText[4]="ВН №";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[4]));


				Cell = Table.OleFunction("Cell",1,6);
				Cell.OleFunction("Select");
				CellText[5]="Краткое содержание";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[5]));


				Cell = Table.OleFunction("Cell",1,7);
				Cell.OleFunction("Select");
				CellText[6]="Назначение";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[6]));


				Cell = Table.OleFunction("Cell",1,8);
				Cell.OleFunction("Select");
				CellText[7]="Дата исп.";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[7]));


				Cell = Table.OleFunction("Cell",1,9);
				Cell.OleFunction("Select");
				CellText[7]="Исполнитель";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[8]));


				Cell = Table.OleFunction("Cell",1,10);
				Cell.OleFunction("Select");
				CellText[9]="Исх. номер";
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(CellText[9]));

		//----------------------------------------------------------------------
		int a=2, b=10;

		for(b; b >0; b--)
		{
		   Cell = Table.OleFunction("Cell",a,b);
		   Cell.OleFunction("Select");
			//ShowMessage("3");
			if(b==10)
				WORD_CELL = "ishn";
			else if(b==9)
				WORD_CELL = "isp";
			else if(b==8)
				WORD_CELL = "dateisp";
			else if(b==7)
				WORD_CELL = "komu";
			else if(b==6)
				WORD_CELL = "sod";
			else if(b==5)
				WORD_CELL = "ish";
			else if(b==4)
				WORD_CELL = "frome";
			else if(b==3)
				WORD_CELL = "data";
            else if(b==2)
				WORD_CELL = "nom";
            else if(b==1)
				WORD_CELL = "number";
			  Memo1->Lines->Add(WORD_CELL);
			try
			{
				String text=ADOQuery1->FieldByName(WORD_CELL)->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text));
			}
			catch(Exception &e)
			{
				 //ShowMessage(e.Message);
			}


		   StatusBar1->Panels->Items[3]->Text = IntToStr((ADOQuery1->RecNo * 100) / (cout_otchet-1)) +" %";    //  показываем % выгрузки

		   if (b==1)
		   {
				Memo1->Lines->Add(a);
				ADOQuery1->Next();
				b = 10;
				a ++;
           }
		   // вывода последней строки
		  if (ADOQuery1->RecNo == ADOQuery1->RecordCount)
           {

			   try{
				Cell = Table.OleFunction("Cell",a,1);
				Cell.OleFunction("Select");
				String text1=ADOQuery1->FieldByName("nom")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text1));
				Cell = Table.OleFunction("Cell",a,2);
				Cell.OleFunction("Select");
				String text2=ADOQuery1->FieldByName("number")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text2));
				Cell = Table.OleFunction("Cell",a,3);
				Cell.OleFunction("Select");
				String text3=ADOQuery1->FieldByName("data")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text3));
				Cell = Table.OleFunction("Cell",a,4);
				Cell.OleFunction("Select");
				String text4=ADOQuery1->FieldByName("frome")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text4));

				Cell = Table.OleFunction("Cell",a,5);
				Cell.OleFunction("Select");
				String text5=ADOQuery1->FieldByName("ish")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text5));

				Cell = Table.OleFunction("Cell",a,6);
				Cell.OleFunction("Select");
				String text6=ADOQuery1->FieldByName("sod")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text6));

				Cell = Table.OleFunction("Cell",a,7);
				Cell.OleFunction("Select");
				String text7=ADOQuery1->FieldByName("komu")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text7));

				Cell = Table.OleFunction("Cell",a,8);
				Cell.OleFunction("Select");
				String text8=ADOQuery1->FieldByName("dateisp")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text8));

				Cell = Table.OleFunction("Cell",a,9);
				Cell.OleFunction("Select");
				String text9=ADOQuery1->FieldByName("isp")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text9));

				Cell = Table.OleFunction("Cell",a,10);
				Cell.OleFunction("Select");
				String text10=ADOQuery1->FieldByName("ishn")->Value;
				Cell.OlePropertyGet("Range").OlePropertySet("Text",WideString(text10));
			   }
			   catch(Exception &e)
			   {

			   }
				break;
		   }
		}

	   //Panel6->Visible = false;
       Word.OlePropertySet("Visible", true);  // Делаем ворд видимым
	   DBGrid1->Visible = true;
       ADOQuery1->First();
	   //ProgressBar1->Visible = false;
		   */

}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{

	Form4->ADD_OR_EDIT->Caption = "ADD";


	Form4->number->Text = ADOQuery1->RecordCount +1;
	Form4->nom->Text="02-07";
	Form4->nom->Items->LoadFromFile("journal.ewe");
	Form4->date->Date = Date();
	Form4->from->Clear();
	Form4->ish->Clear();
	Form4->sod->Clear();
	Form4->komu->Clear();
	Form4->ishn->Clear();
	Form4->FilePatch->Caption = "-";
	Form4->FileName->Caption = "No_File";
	//---------Загружаем список исполнителей в комбобокс--------------------
		IspList->Active = false;
		IspList->SQL->Text = "SELECT * FROM isplist ORDER BY ispname";
		IspList->Active = true;
		IspList->First();
		Form4->isp->Items->Clear();

		for(int i=IspList->RecordCount; i>0; i--)
		{
				Form4->isp->Items->Add(IspList->FieldByName("ispname")->Value);
				IspList->Next();
		}
	//---------КОНЕЦ Загружаем список исполнителей в комбобокс--------------------


    Form4->isp->Text = "";
	Form4->CheckBox1->Checked = false;
    //Form4->OpenDialog1->Execute() = false;
	Form4->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn3Click(TObject *Sender)
{
	Form4->ADD_OR_EDIT->Caption = "EDIT";
	Form4->number->Text = ADOQuery1->FieldByName("number")->Value;
	Form4->nom->Text = ADOQuery1->FieldByName("nom")->Value;
	Form4->nom->Items->LoadFromFile("journal.ewe");
	Form4->date->Date = ADOQuery1->FieldByName("data")->Value;
	Form4->from->Text = ADOQuery1->FieldByName("frome")->Value;
	Form4->ish->Text = ADOQuery1->FieldByName("ish")->Value;
	Form4->sod->Text = ADOQuery1->FieldByName("sod")->Value;
	Form4->komu->Text = ADOQuery1->FieldByName("komu")->Value;
	Form4->ID->Caption = ADOQuery1->FieldByName("number")->Value;

	try
	{
		Form4->isp->Text = ADOQuery1->FieldByName("isp")->Value;
		//---------Загружаем список исполнителей в комбобокс--------------------
		IspList->Active = false;
		IspList->SQL->Text = "SELECT * FROM isplist ORDER BY ispname";
		IspList->Active = true;
		IspList->First();
		Form4->isp->Items->Clear();

		for(int i=IspList->RecordCount; i>0; i--)
		{
				Form4->isp->Items->Add(IspList->FieldByName("ispname")->Value);
				IspList->Next();
		}
		//---------КОНЕЦ Загружаем список исполнителей в комбобокс--------------------
	}
	catch(Exception &e)
	{

	}
    try
	{
		Form4->FileName->Caption = ADOQuery1->FieldByName("file_name")->Value;
	}
	catch(Exception &e)
	{
		  Form4->FileName->Caption = "Нет файла";

	}

	try
	{
		Form4->dateisp->Date = ADOQuery1->FieldByName("dateisp")->Value;
	}
	catch(Exception &e)
	{
		   Form4->dateisp->Date =Date();
	}

    try
	{
		Form4->ishn->Text = ADOQuery1->FieldByName("ishn")->Value;
	}
	catch(Exception &e)
	{
		 Form4->ishn->Text ="";
	}

	if(ADOQuery1->FieldByName("ispflag")->Value == "1")
	{
		Form4->CheckBox1->Checked = true;
	}
	else
	{
		Form4->CheckBox1->Checked = false;
	}

	Form4->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DBGrid1DblClick(TObject *Sender)
{
	BitBtn3->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn4Click(TObject *Sender)
{

	if(MessageDlg("Действительно хотите удалить запись?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		String DELETED = ADOQuery1->FieldByName("number")->Value;

		ADOQuery1->SQL->Text = "DELETE FROM vhod WHERE number IN ("+DELETED+") ";
		ADOQuery1->ExecSQL();

		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
		ADOQuery1->Active = true;
		StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn5Click(TObject *Sender)
{
	if(ADOQuery1->FieldByName("ispflag")->Value == "1")
	{
        Form5->ID->Caption = ADOQuery1->FieldByName("number")->Value;
		Form5->ShowModal();
	}
	else
	{
        ShowMessage("Нельзя исполнить документ не поставленный на исполнение");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SearchNumberKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM vhod WHERE number like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value=SearchNumber->Text;
		ADOQuery1->Active = true;

		if(SearchNumber->Text.Length() == 0)
		{
			  ADOQuery1->Active = false;
			  ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			  ADOQuery1->Active = true;
			  StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;
		}



}
//---------------------------------------------------------------------------

void __fastcall TForm2::SearchIspKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM vhod WHERE isp like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value="%"+SearchIsp->Text+"%";
		ADOQuery1->Active = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::SearchNomKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM vhod WHERE nom like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value=SearchNom->Text;
		ADOQuery1->Active = true;

		if(SearchNom->Text.Length() == 0)
		{
			  ADOQuery1->Active = false;
			  ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			  ADOQuery1->Active = true;
			  StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SearchNomSelect(TObject *Sender)
{
    	ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM vhod WHERE nom like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value=SearchNom->Text;
		ADOQuery1->Active = true;

		if(SearchNom->Text.Length() == 0)
		{
			  ADOQuery1->Active = false;
			  ADOQuery1->SQL->Text = "SELECT * FROM vhod ORDER BY number";
			  ADOQuery1->Active = true;
			  StatusBar1->Panels->Items[1]->Text = Form2->ADOQuery1->RecordCount;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SearchIshKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM vhod WHERE ish like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value="%"+SearchIsh->Text+"%";
		ADOQuery1->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SearchSodKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Text = "SELECT * FROM vhod WHERE sod like p ORDER BY number";
		ADOQuery1->Parameters->ParamByName("p")->Value="%"+SearchSod->Text+"%";
		ADOQuery1->Active = true;
}
//---------------------------------------------------------------------------



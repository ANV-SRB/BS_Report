//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <string>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm1 *Form1;
#define COINCIDENSE_NONE  0
#define COINCIDENSE_FULL  1
#define COINCIDENSE_WU  2

String defFilePath="";
String mainFilePath="";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	MemoRead->Lines->Clear();
	//MemoRead->Lines->LoadFromFile("C:\\Users\\AAA\\Saved Games\\Desktop\\def" );
	Application->Title="BaltSystem Reporter";
	//Form1->CanResize=false;
	report_p_num->Caption= 0;
	report_t_num->Caption= 0;
	report_c_num->Caption= 0;
	String defFilePath="";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	AnsiString 	p_string;
	AnsiString	StringLine;
	AnsiString	Rpt_String;
	int    		Pos_SymbolCommentPos ;
	int 		p_report_cnt=0;


	//анализ переменных P
	P_Memo->Lines->Clear();
	//P_Memo->Lines->BeginUpdate();
	Rpt_String="";
	Label8->Caption="Выполнение";

	bool was_found;
	int p_used_cnt;

	for( int p_counter=0;p_counter<100;p_counter++)
	{
		was_found	=false;
		p_used_cnt	=0;
		p_string	='P';
		p_string	=p_string+IntToStr(p_counter);
		p_string	=p_string+'=';

		//сформировали строку "P1=", ищу его в коде

		for(unsigned int i=0;i<MemoRead->Lines->Count;i++)
		{
			//текущая строка
			Pos_SymbolCommentPos=0;
			StringLine=  MemoRead->Lines->Strings[i];       //чтение текущей строки из начального MemoRead
			StringLine= TrimLeft(StringLine);               //убираю начальные пробелы

			Pos_SymbolCommentPos=StringLine.Pos(';');       //ищу символ ";"-комментарии, в них поиск не производится
			if (Pos_SymbolCommentPos!=1)                    //прочитанная строка не закомментирована
			{
				if (StringLine.Pos(p_string)==1)            //поиск строки "Px=" в текущей строке
				{
					//MemoResult->Lines->Insert(p_counter-1,StringLine);   //найдена, добавляю в итоговый MemoResult
					P_Memo->Lines->Add(StringLine);
					p_report_cnt++;
					was_found=true;

					p_used_cnt++;
				}
			}
		}
		if (p_used_cnt>1)// MessageDlg("Повторение P"+IntToStr(p_counter),mtInformation , TMsgDlgButtons() << mbOK, 0);
		Rpt_String=Rpt_String+" "+IntToStr(p_counter);
		//ShowMessage("Повторение P"+IntToStr(p_counter));
		if (!was_found)
		{
			P_Memo->Lines->Add("");
		}
	}
	if (Rpt_String!="")ShowMessage("Повторение P:"+Rpt_String);

	report_p_num->Caption= IntToStr( p_report_cnt);
	if (p_report_cnt)
	{  //записываю в файл P_report
		P_Memo->Lines->SaveToFile("D:\\p_results.txt" );
	}
	P_Memo->SelStart=0;
	P_Memo->SelLength=0;
	//P_Memo->Lines->EndUpdate();
	Label8->Caption=" ";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	ReadFileLinsNum->Caption= IntToStr( MemoRead->Lines->Count);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{  //кнопка отчета по Таймерам

	AnsiString 	t_string="";
	AnsiString	StringLine;
	AnsiString	Rpt_String;
	int    		Pos_SymbolCommentPos ;
	int 		t_report_cnt=0;

	Label9->Caption="Выполнение";
	//анализ переменных P
	T_Memo->Lines->Clear();
	Rpt_String="";

	bool was_found;
	int t_used_cnt;

	for( int t_counter=0;t_counter<256;t_counter++)
	{
		was_found	=false;
		t_used_cnt	=0;
		t_string	="T";
		t_string	=t_string+IntToStr(t_counter);
		t_string	=t_string+"I(";

		//ShowMessage(t_string);
		//сформировали строку "TxI=", ищу его в коде

		for(unsigned int i=0;i<MemoRead->Lines->Count;i++)
		{
			//текущая строка
			Pos_SymbolCommentPos=0;
			StringLine=  MemoRead->Lines->Strings[i];       //чтение текущей строки из начального MemoRead
			StringLine= TrimLeft(StringLine);               //убираю начальные пробелы

			Pos_SymbolCommentPos=StringLine.Pos(';');       //ищу символ ";"-комментарии, в них поиск не производится
			if (Pos_SymbolCommentPos!=1)                    //прочитанная строка не закомментирована
			{
				if (StringLine.Pos(t_string)==1)            //поиск строки "Px=" в текущей строке
				{
					T_Memo->Lines->Add(StringLine);
					t_report_cnt++;
					was_found=true;

					t_used_cnt++;
				}
			}
		}
		if (t_used_cnt>1) Rpt_String=Rpt_String+" "+IntToStr(t_counter);

		if (!was_found)
		{
			T_Memo->Lines->Add("");
		}
	}
	if (Rpt_String!="")ShowMessage("Повторение T:"+Rpt_String);

	report_t_num->Caption= IntToStr( t_report_cnt);
	if (t_report_cnt)
	{  //записываю в файл P_report
		T_Memo->Lines->SaveToFile("D:\\t_results.txt" );
	}
	T_Memo->SelStart=0;
	T_Memo->SelLength=0;
	Label9->Caption=" ";
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{  //кнопка отчета по Счетчикам

	AnsiString 	c_string="";
	AnsiString	StringLine;
	AnsiString	Rpt_String;
	int    		Pos_SymbolCommentPos ;
	int 		c_report_cnt=0;


	//анализ переменных C
	C_Memo->Lines->Clear();
	Rpt_String="";

	bool was_found;
	int c_used_cnt;

	for( int c_counter=0;c_counter<100;c_counter++)
	{
		was_found	=false;
		c_used_cnt	=0;
		c_string	="C";
		c_string	=c_string+IntToStr(c_counter);
		c_string	=c_string+"I(";

		//ShowMessage(c_string);
		//сформировали строку "CxI=", ищу его в коде

		for(unsigned int i=0;i<MemoRead->Lines->Count;i++)
		{
			//текущая строка
			Pos_SymbolCommentPos=0;
			StringLine=  MemoRead->Lines->Strings[i];       //чтение текущей строки из начального MemoRead
			StringLine= TrimLeft(StringLine);               //убираю начальные пробелы

			Pos_SymbolCommentPos=StringLine.Pos(';');       //ищу символ ";"-комментарии, в них поиск не производится
			if (Pos_SymbolCommentPos!=1)                    //прочитанная строка не закомментирована
			{
				if (StringLine.Pos(c_string)==1)            //поиск строки "CxI(" в текущей строке
				{
					C_Memo->Lines->Add(StringLine);
					c_report_cnt++;
					was_found=true;

					c_used_cnt++;
				}
			}
		}
		if (c_used_cnt>1) Rpt_String=Rpt_String+" "+IntToStr(c_counter);

		if (!was_found)
		{
			C_Memo->Lines->Add("");
		}
	}
	if (Rpt_String!="")ShowMessage("Повторение C:"+Rpt_String);

	report_c_num->Caption= IntToStr( c_report_cnt);
	if (c_report_cnt)
	{  //записываю в файл P_report
		C_Memo->Lines->SaveToFile("D:\\c_results.txt" );
	}
	C_Memo->SelStart=0;
	C_Memo->SelLength=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   OpenDialog1->InitialDir="D:\\";

  // bool fileWasOpened=false;
   OpenDialog1->Filter="ALL |*.*";
   //fileWasOpened=OpenDialog1->Execute();

	if( OpenDialog1->Execute() )
	{
		mainFilePath=OpenDialog1->FileName;
		AnsiString dir=ExtractFileDir(mainFilePath);
		AnsiString name=ExtractFileName(mainFilePath);

		MemoRead->Lines->LoadFromFile( mainFilePath );
		lblMainFilePath->Caption="Файл " + mainFilePath;
	}
	report_p_num->Caption= 0;
	report_t_num->Caption= 0;
	report_c_num->Caption= 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
//открытие файла описания типа def
   OpenDialog2->InitialDir="D:\\";

   //bool fileWasOpened=false;
   OpenDialog2->Filter="ALL |*.*";
   bool fileWasOpened=OpenDialog2->Execute();

   if(fileWasOpened)
   {
	AnsiString dir=ExtractFileDir(OpenDialog2->FileName);
	AnsiString name=ExtractFileName(OpenDialog2->FileName);

	defFilePath=OpenDialog2->FileName;
	MemoDef->Lines->LoadFromFile( defFilePath );
	def_file_lines_num->Caption=MemoDef->Lines->Count;
	lblDefFilePath->Caption="Файл " + defFilePath;

   }
   else{
	 lblDefFilePath->Caption="Файл не открыт";
   }
   if((MemoDef->Lines->Count)!=0) btnCheckDef->Click();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnCheckDefClick(TObject *Sender)
{
//проверка на совпадения адресов в файле описания DEF
  int defFileLines = MemoDef->Lines->Count;

  bool isCoincidences=false;
  int coincidencesNum=0;
  int coincidencesType=COINCIDENSE_NONE;

  MemoDefResults->Lines->Clear();
  LblСoincid->Caption="0";
  LblСoincid->Color= clBtnFace;

  lblCoincidencesTitle->Visible = false;
  lblCoincidencesTitle->Color= clBtnFace;
  MemoDefResults->Visible = false ;

  //проверка на совпадение адреса
  for(int i=0; i < defFileLines; i++){
  //просматриваю все записи от 0 до  MemoDef->Lines->Count
	//поиск позиции, с которой начинается символ "="
	AnsiString readLine=MemoDef->Lines->Strings[i];
	int charEquelPosInLine = readLine.Pos('=');
	//ShowMessage(IntToStr(charEquelPosInLine));
	//ShowMessage("Строка: "+readLine);
	if( charEquelPosInLine !=0 ){
	//в текущей строке есть символ =, считываю следующие 10 символов, в них - адрес
	  AnsiString SelectedVariableName = readLine.SubString(charEquelPosInLine+1,10).TrimRight();

	  for(int j=i+1;j < defFileLines;j++)
	  { //просматриваю все записи от текущей до  MemoDef->Lines->Count
		//поиск позиции, с которой начинается символ "="
		AnsiString readLineNext=   	MemoDef->Lines->Strings[j];
		int charEquelPosInNextLine=	readLineNext.Pos('=');

		if(charEquelPosInNextLine!=0)
		{ //в текущей строке есть символ =, считываю следующие 10 символов, в них - адрес

		  AnsiString VariableNameNext=readLineNext.SubString(charEquelPosInNextLine+1,10).TrimRight();
		  // !!! повторение адреса
		  if (VariableNameNext == SelectedVariableName)
		  {
			//ShowMessage( SelectedVariableName );
			 //добавляю в лист MemoDefResults найденное совпадение
			 MemoDefResults->Lines->Add( UpperCase( MemoDef->Lines->Strings[j]) );

			 isCoincidences=true;
			 coincidencesNum++;
			 coincidencesType=COINCIDENSE_FULL;
		  }
		}
	  }
	}
  }
  //проверка на совпадение бита K в байте W
  for(int i=0; i < defFileLines; i++){
	AnsiString readLine=UpperCase( MemoDef->Lines->Strings[i] );
	int charEqPosInLine = readLine.Pos('=');
	int charWPosInLine = readLine.Pos('W');
	int charKPosInLine = readLine.Pos('K');

	bool charSelWKDist = false;
	if( charEqPosInLine !=0
	&& charEqPosInLine < charWPosInLine
	&& charKPosInLine > charWPosInLine
	&& (charKPosInLine-charWPosInLine)<=4
	&& (charKPosInLine-charWPosInLine)>=2 ) charSelWKDist=true;
	if( charSelWKDist ){
		//ShowMessage(readLine+ " =: " + IntToStr(charEqPosInLine));
	//в текущей строке есть символ =, считываю следующие 3 символов, в них - адрес
	  AnsiString selWName = readLine.SubString(charWPosInLine+1,6).TrimRight();
	  AnsiString selWAdr =  readLine.SubString(charWPosInLine+1,(charKPosInLine-charWPosInLine-1)).TrimRight();
	  AnsiString selWBite =  readLine.SubString(charKPosInLine+1,2).TrimRight();
	  //ShowMessage("Name: "+selWName +" Adr: "+selWAdr );

	  for(int j=0;j < defFileLines;j++) {
		String nextLine=UpperCase( MemoDef->Lines->Strings[j] );
		//ShowMessage(nextLine);
		int charEqPosInNextLine = nextLine.Pos('=');
		int charUPosInNextLine = nextLine.Pos('U');
		int charKPosInNextLine = nextLine.Pos('K');
		bool charNextUKDist = false;

		if( charEqPosInNextLine !=0
			&& charEqPosInNextLine < charUPosInNextLine
			&& charKPosInNextLine > charUPosInNextLine
			&& (charKPosInNextLine-charUPosInNextLine)<=4
			&& (charKPosInNextLine-charUPosInNextLine)>=2 ) charNextUKDist=true;

		if( charNextUKDist ){
			//ShowMessage(nextLine+ " =: " + IntToStr(charEqPosInNextLine));
			String nextUName = nextLine.SubString(charUPosInNextLine+1,6).TrimRight();
			String nextUAdr =  nextLine.SubString(charUPosInNextLine+1,(charKPosInNextLine-charUPosInNextLine-1)).TrimRight();
			String nextUBite =  nextLine.SubString(charKPosInNextLine+1,2).TrimRight();
			//ShowMessage(" selWAdr: " +selWAdr+" nextWName: "+nextWName+" nextWAdr: " + nextWAdr);
			int  selWAdrInt = StrToInt(selWAdr);
			int  selWBiteInt = StrToInt(selWBite);
			int  nextUAdrInt = StrToInt(nextUAdr);
			int  nextUBiteInt = StrToInt(nextUBite);

			if( selWAdrInt == nextUAdrInt) {
				if(		(selWBiteInt==0 && (nextUBiteInt>=0  && nextUBiteInt<8))
					 || (selWBiteInt==1 && (nextUBiteInt>=8  && nextUBiteInt<16))
					 || (selWBiteInt==2 && (nextUBiteInt>=16 && nextUBiteInt<24))
					 || (selWBiteInt==3 && (nextUBiteInt>=24 && nextUBiteInt<32)) ){
				   /*	ShowMessage("readLine: "+  readLine +" nextLine: "+  nextLine +'\n'
							+ "selWAdrInt: "+  selWAdrInt +" nextUAdrInt: "+  nextUAdrInt +'\n'
							+ "selWBite: "+  selWBite +" nextUBite: "+  nextUBite	);  */
					MemoDefResults->Lines->Add( UpperCase( MemoDef->Lines->Strings[i]) );
					MemoDefResults->Lines->Add( UpperCase( MemoDef->Lines->Strings[j]) );
					coincidencesNum++;
					isCoincidences=true;
					coincidencesType=COINCIDENSE_WU;
				}
			}
		}
	  }
	}
  }

  if ( isCoincidences ) {
  //найдены совпадения
	// показываю совпадения, отображаю дополнительный лист с совпадениями
	lblCoincidencesTitle->Visible = true ;
	lblCoincidencesTitle->Color= clRed;
	MemoDefResults->Visible = true;


	LblСoincid->Caption=IntToStr(coincidencesNum);
	if(coincidencesNum!=0)  LblСoincid->Color= clRed;

	String UserCoincidencesMsg;
	if(coincidencesType==COINCIDENSE_FULL){
		UserCoincidencesMsg="Повторение полного адреса";
	}
	if(coincidencesType==COINCIDENSE_WU){
		UserCoincidencesMsg="Повторение частичного адреса (W-U)";
	}
	if(coincidencesType==COINCIDENSE_FULL && coincidencesType==COINCIDENSE_WU){
		UserCoincidencesMsg="Повторение полного и частичного адреса";
	}

	ShowMessage( UserCoincidencesMsg+ '\n'+"Совпадений: " + IntToStr(coincidencesNum) );
  }
  else {
	ShowMessage("Прроверка выполнена, совпадений не найдено");
  }
}
//---------------------------------------------------------------------------
//Double click на форму DEF
void __fastcall TForm1::MemoDefDblClick(TObject *Sender)
{
	// MemoDef->Lines->LoadFromFile("D:\\DEF" );
	if(defFilePath !=""){
		try{
			MemoDef->Lines->LoadFromFile( defFilePath );
			//ShowMessage("Открыт заново: "+defFilePath );
			//Application->MessageBox( L"Открыт заново", L"Открыт файл",MB_OK);

			MemoDef->Lines->LoadFromFile( defFilePath );
			def_file_lines_num->Caption=MemoDef->Lines->Count;
			lblDefFilePath->Caption="Файл " + defFilePath;
			btnCheckDef->Click();
		}
		catch(...){
			Application->MessageBox(L"Файл не проверен", L"Внимание",MB_ICONERROR);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::defAdrSelectorBtnClick(TObject *Sender){
   //вывод списка использованных битов по адресу переменной
   //ввод адреса в поле  defAdrSelEdit

	defAdrList->Lines->Clear();
	int inpAdrValue=100;
	try {
		inpAdrValue = defAdrSelEdit->Value;
	}
	catch(...){
		defAdrSelEdit->Value=0;
	}

	if(inpAdrValue<0 && inpAdrValue>255){
		defAdrList->Lines->Add( "Adress error" );
	}
	else
	{
		//из списка MemoDef ищем каждый адрес и ставим его на соответствующее место в MemoDef
		int defFileLines = MemoDef->Lines->Count;
		bool wasFound=false;
		String outfullAdrMas[32];


		for( int  i=0; i<defFileLines; i++){
			//просмотр каждой строки
			String readLine = UpperCase( MemoDef->Lines->Strings[i] );
			//поиск адреса inpAdrValue
			//обрезаю строки, получаю =U115k19
			String strAfterEq =  readLine.SubString(11,8).TrimRight();
			//ShowMessage(strAfterEq);
			//ищем символ = и отсекаем левую часть строки
			int charEqPosInLine = strAfterEq.Pos('=');
			//ShowMessage(charEqPosInLine);
			int charUPosInLine = strAfterEq.Pos('U');
			int charKPosInLine = strAfterEq.Pos('K');
			int charWPosInLine = strAfterEq.Pos('W');

			bool UKFound = false;
			bool WKFound = false;

			if(		charEqPosInLine ==1
				&& 	charUPosInLine ==2
				&& 	charKPosInLine ==6){
				//найдены символы: = U K
					//ShowMessage(strAfterEq);
					UKFound=true;
					WKFound=false;
				}
			if(		charEqPosInLine ==1
				&&  charWPosInLine ==2
				&&  charKPosInLine ==6){
					//найдены символы: = W K
					//ShowMessage(strAfterEq);
					UKFound=false;
					WKFound=true;
				}


			if(UKFound){
			//в текущей строке найден какой-то адрес, между символами U K
			//найденный адрес:
				String byteAdrStr =  strAfterEq.SubString(3,3).TrimRight();
				String biteAdrStr =  strAfterEq.SubString(7,2).TrimRight();
				int byteAdr = StrToInt(byteAdrStr);
				int biteAdr = StrToInt(biteAdrStr);
				//String fStr="str:"+strAfterEq + "byte:" + byteAdrStr + "bit:"+biteAdrStr ;
				//ShowMessage(fStr);

				//нашли переменную, соответствующую заданному адресу
				if(byteAdr==inpAdrValue){
					//ShowMessage(byteAdr);
					//сохраняю ее в массив String по индексу бита
					if(biteAdr< ARRAYSIZE(outfullAdrMas)){
						outfullAdrMas[biteAdr]=readLine;
						wasFound=true;
					}
				}
			}
			if(WKFound){
			//в текущей строке найден какой-то адрес, между символами W K
				String byteAdrStr =  strAfterEq.SubString(3,3).TrimRight();
				String biteAdrStr =  strAfterEq.SubString(7,2).TrimRight();
				int byteAdr = StrToInt(byteAdrStr);
				int biteAdr = StrToInt(biteAdrStr);
				//String fStr="str:"+strAfterEq + "byte:" + byteAdrStr + "bit:"+biteAdrStr ;
				//ShowMessage(fStr);

				//нашли переменную, соответствующую заданному адресу
				if(byteAdr==inpAdrValue){
					//сохраняю ее в массив String по индексу бита
					if(biteAdr< ARRAYSIZE(outfullAdrMas)){
						outfullAdrMas[biteAdr]=readLine;
						wasFound=true;
					}
				}
			}
		}

		//заполняю Memo  из массива outfullAdrMas
		if(wasFound){
			for(int i=0; i<32; i++)defAdrList->Lines->Add(outfullAdrMas[i]);
		}
	}
}
//---------------------------------------------------------------------------

/*void __fastcall TForm1::SpinEdit1Change(TObject *Sender)
{
   int inpAdrValue;
	try {
		inpAdrValue =  defAdrSelEdit->Value ;
		if(inpAdrValue>0 && inpAdrValue<=255){
			defAdrSelectorBtn->Click();
		}
	}

	catch (...) {
		//Application->MessageBox(L"Ай-ай-ай, это не циферко!", L"Внимание",MB_ICONWARNING);
		defAdrSelEdit->Value=0;
	}
}   */
//---------------------------------------------------------------------------

void __fastcall TForm1::defAdrSelEditChange(TObject *Sender)
{
   int inpAdrValue;
	try {
		inpAdrValue =  defAdrSelEdit->Value ;
		if(inpAdrValue>=0 && inpAdrValue<=255){
			defAdrSelectorBtn->Click();
		}
	}

	catch (...) {
		//Application->MessageBox(L"Ай-ай-ай, это не циферко!", L"Внимание",MB_ICONWARNING);
		defAdrSelEdit->Value=0;
	}
}
//---------------------------------------------------------------------------

/*void __fastcall TForm1::cbUWSelectorChange(TObject *Sender)
{
	//выбрали W или U
	String newVarUW;
	if(cbUWSelector->ItemIndex==1 ) {
		newVarBiteVal->MaxValue = 3;
		if(newVarBiteVal->Value > 3) newVarBiteVal->Value=3;
		newVarUW="W";
	}
	if(cbUWSelector->ItemIndex==0 ) {
		newVarBiteVal->MaxValue = 31;
		newVarUW="U";
	}
	String varText = newVarUW + IntToStr(newVarByteVal->Value)+"K"+ IntToStr(newVarBiteVal->Value);
	newVarText->Caption = varText;
} */
//---------------------------------------------------------------------------

void __fastcall TForm1::MemoReadDblClick(TObject *Sender)
{
//mainFilePath
	if(mainFilePath !=""){
		try{
			MemoRead->Lines->LoadFromFile( mainFilePath );

			lblMainFilePath->Caption="Файл " + mainFilePath;
            Application->MessageBox(L"Файл открыт повторно", L"Внимание",MB_OK);
			//проверка P
			Button2->Click();
			//проверка T
			Button3->Click();
			//проверка C
			Button4->Click();

		}
		catch(...){
			Application->MessageBox(L"Файл не проверен", L"Внимание",MB_ICONERROR);
		}
	}
}
//---------------------------------------------------------------------------






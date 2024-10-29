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


	//������ ���������� P
	P_Memo->Lines->Clear();
	//P_Memo->Lines->BeginUpdate();
	Rpt_String="";
	Label8->Caption="����������";

	bool was_found;
	int p_used_cnt;

	for( int p_counter=0;p_counter<100;p_counter++)
	{
		was_found	=false;
		p_used_cnt	=0;
		p_string	='P';
		p_string	=p_string+IntToStr(p_counter);
		p_string	=p_string+'=';

		//������������ ������ "P1=", ��� ��� � ����

		for(unsigned int i=0;i<MemoRead->Lines->Count;i++)
		{
			//������� ������
			Pos_SymbolCommentPos=0;
			StringLine=  MemoRead->Lines->Strings[i];       //������ ������� ������ �� ���������� MemoRead
			StringLine= TrimLeft(StringLine);               //������ ��������� �������

			Pos_SymbolCommentPos=StringLine.Pos(';');       //��� ������ ";"-�����������, � ��� ����� �� ������������
			if (Pos_SymbolCommentPos!=1)                    //����������� ������ �� ����������������
			{
				if (StringLine.Pos(p_string)==1)            //����� ������ "Px=" � ������� ������
				{
					//MemoResult->Lines->Insert(p_counter-1,StringLine);   //�������, �������� � �������� MemoResult
					P_Memo->Lines->Add(StringLine);
					p_report_cnt++;
					was_found=true;

					p_used_cnt++;
				}
			}
		}
		if (p_used_cnt>1)// MessageDlg("���������� P"+IntToStr(p_counter),mtInformation , TMsgDlgButtons() << mbOK, 0);
		Rpt_String=Rpt_String+" "+IntToStr(p_counter);
		//ShowMessage("���������� P"+IntToStr(p_counter));
		if (!was_found)
		{
			P_Memo->Lines->Add("");
		}
	}
	if (Rpt_String!="")ShowMessage("���������� P:"+Rpt_String);

	report_p_num->Caption= IntToStr( p_report_cnt);
	if (p_report_cnt)
	{  //��������� � ���� P_report
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
{  //������ ������ �� ��������

	AnsiString 	t_string="";
	AnsiString	StringLine;
	AnsiString	Rpt_String;
	int    		Pos_SymbolCommentPos ;
	int 		t_report_cnt=0;

	Label9->Caption="����������";
	//������ ���������� P
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
		//������������ ������ "TxI=", ��� ��� � ����

		for(unsigned int i=0;i<MemoRead->Lines->Count;i++)
		{
			//������� ������
			Pos_SymbolCommentPos=0;
			StringLine=  MemoRead->Lines->Strings[i];       //������ ������� ������ �� ���������� MemoRead
			StringLine= TrimLeft(StringLine);               //������ ��������� �������

			Pos_SymbolCommentPos=StringLine.Pos(';');       //��� ������ ";"-�����������, � ��� ����� �� ������������
			if (Pos_SymbolCommentPos!=1)                    //����������� ������ �� ����������������
			{
				if (StringLine.Pos(t_string)==1)            //����� ������ "Px=" � ������� ������
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
	if (Rpt_String!="")ShowMessage("���������� T:"+Rpt_String);

	report_t_num->Caption= IntToStr( t_report_cnt);
	if (t_report_cnt)
	{  //��������� � ���� P_report
		T_Memo->Lines->SaveToFile("D:\\t_results.txt" );
	}
	T_Memo->SelStart=0;
	T_Memo->SelLength=0;
	Label9->Caption=" ";
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{  //������ ������ �� ���������

	AnsiString 	c_string="";
	AnsiString	StringLine;
	AnsiString	Rpt_String;
	int    		Pos_SymbolCommentPos ;
	int 		c_report_cnt=0;


	//������ ���������� C
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
		//������������ ������ "CxI=", ��� ��� � ����

		for(unsigned int i=0;i<MemoRead->Lines->Count;i++)
		{
			//������� ������
			Pos_SymbolCommentPos=0;
			StringLine=  MemoRead->Lines->Strings[i];       //������ ������� ������ �� ���������� MemoRead
			StringLine= TrimLeft(StringLine);               //������ ��������� �������

			Pos_SymbolCommentPos=StringLine.Pos(';');       //��� ������ ";"-�����������, � ��� ����� �� ������������
			if (Pos_SymbolCommentPos!=1)                    //����������� ������ �� ����������������
			{
				if (StringLine.Pos(c_string)==1)            //����� ������ "CxI(" � ������� ������
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
	if (Rpt_String!="")ShowMessage("���������� C:"+Rpt_String);

	report_c_num->Caption= IntToStr( c_report_cnt);
	if (c_report_cnt)
	{  //��������� � ���� P_report
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
		lblMainFilePath->Caption="���� " + mainFilePath;
	}
	report_p_num->Caption= 0;
	report_t_num->Caption= 0;
	report_c_num->Caption= 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
//�������� ����� �������� ���� def
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
	lblDefFilePath->Caption="���� " + defFilePath;

   }
   else{
	 lblDefFilePath->Caption="���� �� ������";
   }
   if((MemoDef->Lines->Count)!=0) btnCheckDef->Click();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnCheckDefClick(TObject *Sender)
{
//�������� �� ���������� ������� � ����� �������� DEF
  int defFileLines = MemoDef->Lines->Count;

  bool isCoincidences=false;
  int coincidencesNum=0;
  int coincidencesType=COINCIDENSE_NONE;

  MemoDefResults->Lines->Clear();
  Lbl�oincid->Caption="0";
  Lbl�oincid->Color= clBtnFace;

  lblCoincidencesTitle->Visible = false;
  lblCoincidencesTitle->Color= clBtnFace;
  MemoDefResults->Visible = false ;

  //�������� �� ���������� ������
  for(int i=0; i < defFileLines; i++){
  //������������ ��� ������ �� 0 ��  MemoDef->Lines->Count
	//����� �������, � ������� ���������� ������ "="
	AnsiString readLine=MemoDef->Lines->Strings[i];
	int charEquelPosInLine = readLine.Pos('=');
	//ShowMessage(IntToStr(charEquelPosInLine));
	//ShowMessage("������: "+readLine);
	if( charEquelPosInLine !=0 ){
	//� ������� ������ ���� ������ =, �������� ��������� 10 ��������, � ��� - �����
	  AnsiString SelectedVariableName = readLine.SubString(charEquelPosInLine+1,10).TrimRight();

	  for(int j=i+1;j < defFileLines;j++)
	  { //������������ ��� ������ �� ������� ��  MemoDef->Lines->Count
		//����� �������, � ������� ���������� ������ "="
		AnsiString readLineNext=   	MemoDef->Lines->Strings[j];
		int charEquelPosInNextLine=	readLineNext.Pos('=');

		if(charEquelPosInNextLine!=0)
		{ //� ������� ������ ���� ������ =, �������� ��������� 10 ��������, � ��� - �����

		  AnsiString VariableNameNext=readLineNext.SubString(charEquelPosInNextLine+1,10).TrimRight();
		  // !!! ���������� ������
		  if (VariableNameNext == SelectedVariableName)
		  {
			//ShowMessage( SelectedVariableName );
			 //�������� � ���� MemoDefResults ��������� ����������
			 MemoDefResults->Lines->Add( UpperCase( MemoDef->Lines->Strings[j]) );

			 isCoincidences=true;
			 coincidencesNum++;
			 coincidencesType=COINCIDENSE_FULL;
		  }
		}
	  }
	}
  }
  //�������� �� ���������� ���� K � ����� W
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
	//� ������� ������ ���� ������ =, �������� ��������� 3 ��������, � ��� - �����
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
  //������� ����������
	// ��������� ����������, ��������� �������������� ���� � ������������
	lblCoincidencesTitle->Visible = true ;
	lblCoincidencesTitle->Color= clRed;
	MemoDefResults->Visible = true;


	Lbl�oincid->Caption=IntToStr(coincidencesNum);
	if(coincidencesNum!=0)  Lbl�oincid->Color= clRed;

	String UserCoincidencesMsg;
	if(coincidencesType==COINCIDENSE_FULL){
		UserCoincidencesMsg="���������� ������� ������";
	}
	if(coincidencesType==COINCIDENSE_WU){
		UserCoincidencesMsg="���������� ���������� ������ (W-U)";
	}
	if(coincidencesType==COINCIDENSE_FULL && coincidencesType==COINCIDENSE_WU){
		UserCoincidencesMsg="���������� ������� � ���������� ������";
	}

	ShowMessage( UserCoincidencesMsg+ '\n'+"����������: " + IntToStr(coincidencesNum) );
  }
  else {
	ShowMessage("��������� ���������, ���������� �� �������");
  }
}
//---------------------------------------------------------------------------
//Double click �� ����� DEF
void __fastcall TForm1::MemoDefDblClick(TObject *Sender)
{
	// MemoDef->Lines->LoadFromFile("D:\\DEF" );
	if(defFilePath !=""){
		try{
			MemoDef->Lines->LoadFromFile( defFilePath );
			//ShowMessage("������ ������: "+defFilePath );
			//Application->MessageBox( L"������ ������", L"������ ����",MB_OK);

			MemoDef->Lines->LoadFromFile( defFilePath );
			def_file_lines_num->Caption=MemoDef->Lines->Count;
			lblDefFilePath->Caption="���� " + defFilePath;
			btnCheckDef->Click();
		}
		catch(...){
			Application->MessageBox(L"���� �� ��������", L"��������",MB_ICONERROR);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::defAdrSelectorBtnClick(TObject *Sender){
   //����� ������ �������������� ����� �� ������ ����������
   //���� ������ � ����  defAdrSelEdit

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
		//�� ������ MemoDef ���� ������ ����� � ������ ��� �� ��������������� ����� � MemoDef
		int defFileLines = MemoDef->Lines->Count;
		bool wasFound=false;
		String outfullAdrMas[32];


		for( int  i=0; i<defFileLines; i++){
			//�������� ������ ������
			String readLine = UpperCase( MemoDef->Lines->Strings[i] );
			//����� ������ inpAdrValue
			//������� ������, ������� =U115k19
			String strAfterEq =  readLine.SubString(11,8).TrimRight();
			//ShowMessage(strAfterEq);
			//���� ������ = � �������� ����� ����� ������
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
				//������� �������: = U K
					//ShowMessage(strAfterEq);
					UKFound=true;
					WKFound=false;
				}
			if(		charEqPosInLine ==1
				&&  charWPosInLine ==2
				&&  charKPosInLine ==6){
					//������� �������: = W K
					//ShowMessage(strAfterEq);
					UKFound=false;
					WKFound=true;
				}


			if(UKFound){
			//� ������� ������ ������ �����-�� �����, ����� ��������� U K
			//��������� �����:
				String byteAdrStr =  strAfterEq.SubString(3,3).TrimRight();
				String biteAdrStr =  strAfterEq.SubString(7,2).TrimRight();
				int byteAdr = StrToInt(byteAdrStr);
				int biteAdr = StrToInt(biteAdrStr);
				//String fStr="str:"+strAfterEq + "byte:" + byteAdrStr + "bit:"+biteAdrStr ;
				//ShowMessage(fStr);

				//����� ����������, ��������������� ��������� ������
				if(byteAdr==inpAdrValue){
					//ShowMessage(byteAdr);
					//�������� �� � ������ String �� ������� ����
					if(biteAdr< ARRAYSIZE(outfullAdrMas)){
						outfullAdrMas[biteAdr]=readLine;
						wasFound=true;
					}
				}
			}
			if(WKFound){
			//� ������� ������ ������ �����-�� �����, ����� ��������� W K
				String byteAdrStr =  strAfterEq.SubString(3,3).TrimRight();
				String biteAdrStr =  strAfterEq.SubString(7,2).TrimRight();
				int byteAdr = StrToInt(byteAdrStr);
				int biteAdr = StrToInt(biteAdrStr);
				//String fStr="str:"+strAfterEq + "byte:" + byteAdrStr + "bit:"+biteAdrStr ;
				//ShowMessage(fStr);

				//����� ����������, ��������������� ��������� ������
				if(byteAdr==inpAdrValue){
					//�������� �� � ������ String �� ������� ����
					if(biteAdr< ARRAYSIZE(outfullAdrMas)){
						outfullAdrMas[biteAdr]=readLine;
						wasFound=true;
					}
				}
			}
		}

		//�������� Memo  �� ������� outfullAdrMas
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
		//Application->MessageBox(L"��-��-��, ��� �� �������!", L"��������",MB_ICONWARNING);
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
		//Application->MessageBox(L"��-��-��, ��� �� �������!", L"��������",MB_ICONWARNING);
		defAdrSelEdit->Value=0;
	}
}
//---------------------------------------------------------------------------

/*void __fastcall TForm1::cbUWSelectorChange(TObject *Sender)
{
	//������� W ��� U
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

			lblMainFilePath->Caption="���� " + mainFilePath;
            Application->MessageBox(L"���� ������ ��������", L"��������",MB_OK);
			//�������� P
			Button2->Click();
			//�������� T
			Button3->Click();
			//�������� C
			Button4->Click();

		}
		catch(...){
			Application->MessageBox(L"���� �� ��������", L"��������",MB_ICONERROR);
		}
	}
}
//---------------------------------------------------------------------------






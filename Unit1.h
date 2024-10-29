//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.TeCanvas.hpp>
#include <VCLTee.TeePenDlg.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include "cspin.h"
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label8;
	TLabel *Label9;
	TOpenDialog *OpenDialog1;
	TTimer *Timer1;
	TOpenDialog *OpenDialog2;
	TOpenDialog *OpenDialog3;
	TTimer *Timer2;
	TOpenDialog *OpenDialog4;
	TPageControl *TabSheet;
	TTabSheet *TabSheet1;
	TMemo *MemoRead;
	TMemo *P_Memo;
	TMemo *T_Memo;
	TMemo *C_Memo;
	TTabSheet *TabSheet2;
	TLabel *lblCoincidencesTitle;
	TMemo *MemoDef;
	TMemo *MemoDefResults;
	TMemo *defAdrList;
	TLabel *lblDefFilePath;
	TLabel *lblMainFilePath;
	TPanel *Panel1;
	TBitBtn *BitBtn1;
	TLabel *Label1;
	TLabel *ReadFileLinsNum;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *report_p_num;
	TLabel *Label4;
	TLabel *report_t_num;
	TLabel *Label5;
	TLabel *report_c_num;
	TPanel *Panel2;
	TBitBtn *BitBtn4;
	TLabel *Label6;
	TLabel *def_file_lines_num;
	TBitBtn *btnCheckDef;
	TLabel *Label7;
	TLabel *Lbl—oincid;
	TPanel *Panel3;
	TLabel *Label11;
	TLabel *Label10;
	TSpinEdit *defAdrSelEdit;
	TButton *defAdrSelectorBtn;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall btnCheckDefClick(TObject *Sender);
	void __fastcall MemoDefDblClick(TObject *Sender);
	void __fastcall defAdrSelectorBtnClick(TObject *Sender);
	void __fastcall defAdrSelEditChange(TObject *Sender);
	void __fastcall MemoReadDblClick(TObject *Sender);
	//void __fastcall cbUWSelectorChange(TObject *Sender);
	//void __fastcall defAdrSelEditChange(TObject *Sender);
	//void __fastcall CSpinEdit1Change(TObject *Sender);
   //	void __fastcall SpinEdit1Change(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <fstream>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TButton *Button4;
	TButton *Button5;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall OnExit(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
    AnsiString nom, ruta, nomIdx;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
    long int BusAlumCod(Word codB);
};
struct TFecha{
	Word dia;
	Word mes;
	Word año;
};
struct RegAlumno{
	Word cod;
	char nom[30];
	TFecha fecha;
};
struct RegIdxCod{
	Word cod;
	Cardinal pos;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif

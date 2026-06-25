//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
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
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label4;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TLabel *Label5;
	TEdit *Edit6;
	TButton *Button7;
	TLabel *Label6;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
private:	// User declarations
	AnsiString ruta, nom, nomIdx, nomIdxNom;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	long int BusAlumCod(Word codB);
	void SelectionSort();
};
struct TFecha{
	byte dia;
	byte mes;
	Word año;
}; // 4b
//  Registro antiguo
struct RegAlumnoAnt{
	Word cod;
	char nom[22];
	TFecha fecha;
}; // 28b

//  Evita que el compilador deje huecos en el struct
//  funciona desde la anterior linea en adelante
#pragma pack(1)
//  Registro nuevo
struct RegAlumno{
	char marca;       //    ' ' | '*'
	Word cod;
	char nom[30];
	TFecha fecha;
	Cardinal telf;
}; //   41b

//  Index por codigo
struct RegIdxCod{
	Word cod;
	Cardinal pos;
};  //  6b

//  Index por nombre
struct RegIdxNom{
	char nom[30];
	Cardinal pos;
};	//  34b

//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif

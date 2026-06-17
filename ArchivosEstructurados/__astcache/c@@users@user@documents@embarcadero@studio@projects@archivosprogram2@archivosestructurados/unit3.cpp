//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	RegAlumno reg, reg2;
	AnsiString aux;
	bool hallado = false;

	reg.cod = StrToInt(Edit1->Text);
	aux = Edit2->Text;
	strcpy(reg.nom, aux.c_str());
	reg.fecha.dia = StrToInt(Edit3->Text);
	reg.fecha.mes = StrToInt(Edit4->Text);
	reg.fecha.año = StrToInt(Edit5->Text);

	fstream f(nom.c_str(), ios::binary | ios::in | ios::out);
	if(!f.fail())
	{
		while(!f.eof() && !hallado)
		{
			f.read((char*)& reg2, sizeof(reg2));
			if(!f.eof())
				hallado = (reg2.cod == reg.cod);
		}
		if(hallado)
		{
			f.seekg(-sizeof(reg), ios::cur);
			f.write((char*)&reg, sizeof(reg));
		}
		else
		{
			f.close();
			f.open(nom.c_str(), ios::binary | ios::app);
			f.write((char*)& reg, sizeof(reg));
		}
		f.close();

		Edit1->Text = "0";
		Edit2->Text = "";
		Edit3->Text = "";
		Edit4->Text = "";
		Edit5->Text = "";
		ShowMessage("Datos Guardados");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	ruta = "C:\\Users\\User\\Documents\\Embarcadero\\Studio\\Projects\\ArchivosProgram2\\ArchivosEstructurados\\Dat\\";
	nom = ruta + "Alumnos.dat";
	fstream f(nom.c_str(), ios::binary | ios::in);
	if(f.fail())
	{
		f.open(nom.c_str(), ios::binary | ios::out);
	}
	f.close();
}

//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	RegAlumno reg;
	AnsiString linea, lis;
	fstream f(nom.c_str(), ios::binary | ios::in);
	lis = ruta + "Listado.csv";
	fstream t(lis.c_str(), ios::out);
	if(!f.fail())
	{
		linea = "";
		while(!f.eof())
		{
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
				linea = IntToStr(reg.cod) + "," + reg.nom + "," + reg.fecha.dia
						+ "," + reg.fecha.mes + "," + reg.fecha.año;
				byte n = linea.Length();
				for(byte i = 1; i <= n; i++)
					t.put(linea[i]);
				t.put('\n');
			}
		}
		f.close();
        t.close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1Exit(TObject *Sender)
{
	RegAlumno reg;
	Word cod;
	bool hallado = false;

	fstream f(nom.c_str(), ios::binary | ios::in);
	if(!f.fail())
	{
		cod = StrToInt(Edit1->Text);
		while(!f.eof() && !hallado)
		{
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
				hallado = (cod == reg.cod);
			}
		}
		if(hallado)
		{
			Edit2->Text = reg.nom;
			Edit3->Text = reg.fecha.dia;
			Edit4->Text = reg.fecha.mes;
			Edit5->Text = reg.fecha.año;
		}
		else
		{
			Edit2->Text = "";
			Edit3->Text = "";
			Edit4->Text = "";
			Edit5->Text = "";

		}
        f.close();
    }
}
//---------------------------------------------------------------------------
 // ñÑáéíóúü╡É╓αΘÜ
 // ñÑáéíóúüÁÉÍÓÚÜ

//  Convierte texto en mayusculas
AnsiString Mayusculas(AnsiString x)
{
	AnsiString min = "qwertyuiopasdfghjklñzxcvbnmáéíóúü";
	AnsiString may = "QWERTYUIOPASDFGHJKLÑZXCVBNMÁÉÍÓÚÜ";
	byte i, p, n = x.Length();
	for(i = 1; i <= n; i++)
	{
		p = min.Pos(x[i]);
		if(p > 0)
			x[i] = may[p];
	}
	return x;
}
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	RegAlumno reg;
	AnsiString x;
	fstream f(nom.c_str(), ios::binary | ios::in | ios::out);
	if(!f.fail())
	{
		while(!f.eof())
		{
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
				x = Mayusculas(reg.nom);
				strcpy(reg.nom, x.c_str());
				f.seekg(-sizeof(reg), ios::cur);
				f.write((char*)& reg, sizeof(reg));
				f.seekg(sizeof(reg), ios::cur);
				f.seekg(-sizeof(reg), ios::cur);
			}
		}
		f.close();
		ShowMessage("Datos modificados");
	}
}
//---------------------------------------------------------------------------
AnsiString Minusculas(AnsiString x)
{
	AnsiString min = "qwertyuiopasdfghjklñzxcvbnmáéíóúü";
	AnsiString may = "QWERTYUIOPASDFGHJKLÑZXCVBNMÁÉÍÓÚÜ";
	byte i, p, n = x.Length();
	for(i = 1; i <= n; i++)
	{
		p = may.Pos(x[i]);
		if(p > 0)
			x[i] = min[p];
	}
	return x;
}
void __fastcall TForm3::Button4Click(TObject *Sender)
{
	RegAlumno reg;
	AnsiString x;
	fstream f(nom.c_str(), ios::binary | ios::in | ios::out);
	if(!f.fail())
	{
		while(!f.eof())
		{
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
				if(reg.fecha.mes == 7)
				{
					x = Minusculas(reg.nom);
					strcpy(reg.nom, x.c_str());
					f.seekg(-sizeof(reg), ios::cur);
					f.write((char*)& reg, sizeof(reg));
					f.seekg(sizeof(reg), ios::cur);
					f.seekg(-sizeof(reg), ios::cur);
				}
			}
		}
		f.close();
		ShowMessage("Datos modificados");
	}
}
//---------------------------------------------------------------------------
//  Tarea: Elimnar los registros de los alumnos que tengan al menos 2 'o' en
//         su nombre.

//  Verifica si la cadena contiene 2 o mas 'o'
bool Verif2o(AnsiString nom)
{
	bool oo = false;
	byte c = 0;
	Cardinal n = nom.Length();
	Cardinal i = 1;
	while((i <= n) && !oo)
	{
		if(nom[i] == 'O')
			c++;
		if(nom[i] == 'o')
			c++;
		if(c >= 2)
			oo = true;
		i++;
	}
    return oo;
}
void __fastcall TForm3::Button5Click(TObject *Sender)
{
	RegAlumno reg;
	AnsiString aux;
	AnsiString rutaTemporal = ruta + "temporal.dat";
	fstream f(nom.c_str(), ios::binary | ios::in);
	fstream t(rutaTemporal.c_str(), ios::binary | ios::out);
	if(!f.fail())
	{
		while(!f.eof())
		{
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
                aux = reg.nom;
				if(!Verif2o(aux))
				{
					t.write((char*)& reg, sizeof(reg));
				}
            }
		}
		f.close();
		t.close();
	}
	remove(nom.c_str());
    rename(rutaTemporal.c_str(), nom.c_str());
}
//---------------------------------------------------------------------------


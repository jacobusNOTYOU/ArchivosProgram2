//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
	fstream f(nom.c_str(), ios::binary | ios::in | ios::out);
	if(!f.fail())
	{
		reg.cod = StrToInt(Edit1->Text);
		aux = Edit2->Text;
		strcpy(reg.nom, aux.c_str());
		reg.nom[sizeof(reg.nom) - 1] = 0;
		aux = Edit3->Text;
		strcpy(reg.dir, aux.c_str());
		reg.dir[sizeof(reg.dir) - 1] = 0;
		reg.fecha.dia = StrToInt(Edit4->Text);
		reg.fecha.mes = StrToInt(Edit5->Text);
		reg.fecha.aÒo = StrToInt(Edit6->Text);
		reg.telf = StrToInt(Edit7->Text);

		while(!f.eof() && !hallado)
		{
			f.read((char*)& reg2, sizeof(reg2));
			if(!f.eof())
			{
				hallado = (reg2.cod == reg.cod);
			}
		}
		if(!hallado)
		{
			f.close();
			f.open(nom.c_str(), ios::binary | ios::app);
			f.write((char*)& reg, sizeof(reg));
			f.close();
		}
		else
		{
			f.seekg(-sizeof(reg), ios::cur);
			f.write((char*)& reg, sizeof(reg));
			f.close();
		}
        ShowMessage("Guardado.");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	ruta = "C:\\Users\\User\\Desktop\\ModelosProgram2Final\\modelo1\\Dat\\";
	nom = ruta + "Alumnos.dat";
	fstream f(nom.c_str(), ios::binary | ios::in);
	if(f.fail())
	{
		f.close();
		f.open(nom.c_str(), ios::binary | ios::out);
	}
	f.close();

	idxNom = ruta + "IdxNom.idx";
	fstream i(idxNom.c_str(), ios::binary | ios::in);
	if(i.fail())
	{
		i.close();
		i.open(idxNom.c_str(), ios::binary | ios::out);
	}
    i.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	RegAlumno reg;
	fstream f(nom.c_str(), ios::binary | ios::in);
	AnsiString lis = ruta + "Listado.txt";
	fstream t(lis.c_str(), ios::out);
    lis = "\tLISTADO DE ALUMNOS\n";
	for(byte i = 1; i <= lis.Length(); i++)
		t.put(lis[i]);
	if(!f.fail())
	{
		while(!f.eof())
		{
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
				lis = "" + AnsiString(reg.cod) + "," + (AnsiString)reg.nom + ","
				+ reg.dir + ","
					+ reg.fecha.dia + "/" + reg.fecha.mes + "/" + reg.fecha.aÒo
					+ "," + reg.telf;
				for(int i = 1; i <= lis.Length(); i++)
					t.put(lis[i]);
				t.put('\n');
			}
		}
		f.close();
		t.close();
		ShowMessage("Listado listo.");
    }
}
//---------------------------------------------------------------------------
//  Ejercicio 1
//  Verifica si cumple la condicion
bool verificar(AnsiString str)
{
	bool primeraCondicion = false;
	bool segundaCondicion = false;
	AnsiString con = "qwrtypsdfghjklÒzxcvbnmQWRTYPSDFGHJKL—ZXCVBNM";
	AnsiString voc = "aeiou·ÈÌÛ˙AEIOU¡…Õ”⁄¸‹yY";
	int pos = con.Pos(str[1]);
	if(pos > 0)
		primeraCondicion = true;
	pos = voc.Pos(str[str.Length()]);
	if(pos > 0)
		segundaCondicion = true;

	return (primeraCondicion && segundaCondicion);
}
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	RegAlumno reg;
	fstream f(nom.c_str(), ios::binary | ios:: in | ios::out);
	if(!f.fail())
	{
		while(!f.eof())
		{
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
				if(verificar(reg.nom))
				{
					reg.cod = reg.cod + 5;
					f.seekg(-sizeof(reg), ios::cur);
					f.write((char*)& reg, sizeof(reg));
					f.seekg(sizeof(reg), ios::cur);
					f.seekg(-sizeof(reg), ios::cur);
				}
			}
		}
		f.close();
        ShowMessage("Datos modificados.");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
	RegAlumno reg;
	IdxNom ri;
	fstream f(nom.c_str(), ios::binary | ios::in);
	fstream i(idxNom.c_str(), ios::binary | ios::out);
	if(!f.fail())
	{
		while(!f.eof())
		{
			ri.pos = f.tellg();
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
				strcpy(ri.nom, reg.nom);
				i.write((char*)& ri, sizeof(ri));
			}
		}
		f.close();
		i.close();
        ShowMessage("Indice creado.");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button5Click(TObject *Sender)
{
	IdxNom reg;
	fstream f(idxNom.c_str(), ios::binary | ios::in);
	AnsiString lis = ruta + "LisIdxNom.txt";
	fstream t(lis.c_str(), ios::out);
	if(!f.fail())
	{
		while(!f.eof())
		{
			f.read((char*)& reg, sizeof(reg));
			if(!f.eof())
			{
				lis = (AnsiString)reg.nom + "," + (AnsiString)reg.pos;
				for(int i = 1; i <= lis.Length(); i++)
					t.put(lis[i]);
				t.put('\n');
			}
		}
		f.close();
		t.close();
		ShowMessage("Listado listo.");
	}
}
//---------------------------------------------------------------------------
//  Devuelve verdadero si a es menor a b
AnsiString nomMenor(AnsiString a, AnsiString b)
{
	AnsiString chars = "Aa¡·BbCcDdEe…ÈFfGgHhIiÕÌJjKkLlMmNn—ÒOo”ÛPpQqRrSsTtUu⁄˙‹¸VvXxYyZz";
	AnsiString r;

	bool hallado = false;
	int i = 1;
	while((i <= a.Length()) && (i <= b.Length()) && !hallado)
	{
		if(chars.Pos(a[i]) < chars.Pos(b[i]))
		{
			hallado = true;
			r = a;
		}
		else if(chars.Pos(a[i]) > chars.Pos(b[i]))
		{
			hallado = true;
			r = b;
		}
		i++;
	}
	if((a.Length() < b.Length()) && !hallado)
	{
		r = a;
	}
	else if(!hallado)
	{
		r = b;
	}
	return r;
}

void TForm3::IdxSort()
{
	IdxNom ri1, ri2, ri3;
	Cardinal a, b, c;
	long n;
	fstream i(idxNom.c_str(), ios::binary | ios::in | ios::out | ios::ate);
	if(!i.fail())
	{
		n = i.tellg();
		n = n - sizeof(ri1);
		a = 0;
		while(a < n)
		{
			i.seekg(a);\
			i.read((char*)& ri1, sizeof(ri1));
			c = a;
			ri2 = ri1;
			b = c + sizeof(ri1);
			while(b <= n)
			{
				i.read((char*)& ri3, sizeof(ri3));
				if(nomMenor(ri2.nom, ri3.nom) == ri2.nom)
				{
					c = b;
					ri2 = ri3;
				}
				b = b + sizeof(ri3);
			}
			if(a != c)
			{
				i.seekg(a);
				i.write((char*)& ri2, sizeof(ri2));
				i.seekg(c);
				i.write((char*)& ri1, sizeof(ri1));
			}
			a = a + sizeof(ri1);
		}
		i.close();
	}
}
// convierte en mayuscula
AnsiString May(AnsiString str)
{
	int pos;
	AnsiString may = "QWERTYUIOPASDFGHJKL—ZXCVBNM¡…Õ”⁄‹";
	AnsiString men = "qwertyuiopasdfghjklÒzxcvbnm·ÈÌÛ˙¸";
	for(int i = 1; i <= str.Length(); i++)
	{	
		pos = men.Pos(str[i]);
		if(pos > 0)
			str[i] = may[pos];
	}
	return str;
}
//	convierte en minuscula
AnsiString Min(AnsiString str)
{
	int pos;
	AnsiString may = "QWERTYUIOPASDFGHJKL—ZXCVBNM¡…Õ”⁄‹";
	AnsiString men = "qwertyuiopasdfghjklÒzxcvbnm·ÈÌÛ˙¸";
	for(int i = 1; i <= str.Length(); i++)
	{	
		pos = may.Pos(str[i]);
		if(pos > 0)
			str[i] = men[pos];
	}
	return str;
}
void __fastcall TForm3::Button6Click(TObject *Sender)
{
	IdxSort();
	IdxNom ri;
	fstream fi(idxNom.c_str(), ios::binary | ios::in);
	AnsiString lis = ruta + "ListadoEjer2.txt";
	fstream t(lis.c_str(), ios::out);
	lis = "\tLISTADO EXAMEN\n";
	for(byte i = 1; i <= lis.Length(); i++)
		t.put(lis[i]);
	RegAlumno reg;
	fstream f(nom.c_str(), ios::binary | ios::in);	
	if(!fi.fail())
	{
		while(!fi.eof())
		{
			fi.read((char*)& ri, sizeof(ri));
			if(!fi.eof())
			{
				f.seekg(ri.pos);
				f.read((char*)& reg, sizeof(reg));
				lis = (AnsiString)reg.cod + "," + May(reg.nom) + "," 
					+ Min(reg.dir) + "," + reg.fecha.dia + "," + reg.fecha.mes 
					+ "," + reg.fecha.aÒo + "," + reg.telf;
				for(byte i = 1; i <= lis.Length(); i++)
					t.put(lis[i]);
				t.put('\n');
			}
		}
		fi.close();
		f.close();
		t.close();
		ShowMessage("Listado listo.");	
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button7Click(TObject *Sender)
{
	AnsiString lis = ruta + "Listado.txt";
	fstream l(lis.c_str(), ios::in);
	RegAlumno reg;
	fstream f(nom.c_str(), ios::binary | ios::out);
	if(!l.fail())
	{
		l.getline(lis.c_str(), 100, '\n');
		while(!l.eof())
		{
			l.getline(lis.c_str(), 100, ',');
			if(!l.eof())
			{
				reg.cod = StrToInt(lis);
				l.getline(lis.c_str(), 100, ',');
				strcpy(reg.nom, lis.c_str());
				reg.nom[sizeof(reg.nom) - 1] = 0;
				l.getline(lis.c_str(), 100, ',');
				strcpy(reg.dir, lis.c_str());
				reg.dir[sizeof(reg.dir) - 1] = 0;
				l.getline(lis.c_str(), 100, '/');
				reg.fecha.dia = StrToInt(lis);
				l.getline(lis.c_str(), 100, '/');
				reg.fecha.mes = StrToInt(lis);
				l.getline(lis.c_str(), 100, ',');
				reg.fecha.aÒo  = StrToInt(lis);
				l.getline(lis.c_str(), 100, '\n');
				reg.telf = StrToInt(lis);

				f.write((char*)& reg, sizeof(reg));
			}
		}
		l.close();
        f.close();
    }
}
//---------------------------------------------------------------------------


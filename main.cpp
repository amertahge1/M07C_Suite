//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{    client=new TelloClientUDP("172.20.21.14");

//Image1->Top=200;
//
//Image1->Left=400;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{     client->ModeCommande();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	client->Monter(TrackBar2->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	client->Gauche(TrackBar2->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	client->Avant(TrackBar2->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	client->Droite(TrackBar2->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	client->Arriere(TrackBar2->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	client->Descendre(TrackBar2->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	client->TournerTrigo(TrackBar1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	client->TournerHoraire(TrackBar1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	client->Decoller();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)
{	client->Atterrir();

}
//---------------------------------------------------------------------------





void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	  click=0;
	  Image1->Top=355;
	  Image1->Left=556;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
		click=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{



int haut = Image1->Top+Y-Image1->Height/2;
int gauche = Image1->Left+X-Image1->Width/2;

	if(click && gauche>Bevel1->Left
			 && haut>Bevel1->Top
			 && gauche+Image1->Width<Bevel1->Left+Bevel1->Width
			 && haut+Image1->Height<Bevel1->Top+Bevel1->Height) {

			 Image1->Top=haut;
		     Image1->Left=gauche;

		
																  }


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormButtonCopy.h"
#include "ProgrammableButtons.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmButtonCopy *frmButtonCopy = NULL;

//---------------------------------------------------------------------------
__fastcall TfrmButtonCopy::TfrmButtonCopy(TComponent* Owner)
	: TForm(Owner), buttons(buttons)
{

}

void TfrmButtonCopy::SetButtons(ProgrammableButtons *buttons)
{
	this->buttons = buttons;
	cbSource->Items->Clear();
	cbTarget->Items->Clear();
	cbTargetTo->Items->Clear();
	for (int i=0; i<buttons->btnConf.size(); i++) {
		AnsiString caption;
		ButtonConf &cfg = buttons->btnConf[i];
		if (cfg.caption != "")
			caption.sprintf("%d: %s", i, cfg.caption.c_str());
		else
			caption.sprintf("%d: [unnamed]", i);

		cbSource->Items->Add(caption);
		cbTarget->Items->Add(caption);
		cbTargetTo->Items->Add(caption);
	}
	cbSource->ItemIndex = 0;
	cbTarget->ItemIndex = 0;
	cbTargetTo->ItemIndex = 0;

	cbTargetType->OnChange(NULL);
}


//---------------------------------------------------------------------------
void __fastcall TfrmButtonCopy::btnApplyClick(TObject *Sender)
{
	int src = cbSource->ItemIndex;
	if (src < 0)
		return;
	if (cbTargetType->ItemIndex == 0)		// single button
	{
		int dst = cbTarget->ItemIndex;
		if (dst < 0)
			return;
		CopyButton(src, dst);
		cbTarget->ItemIndex = dst;		
	}
	else if (cbTargetType->ItemIndex == 1)	// all visible buttons
	{
		for (int i=0; i<cbTarget->Items->Count; i++)
		{
			int dst = i;
			ButtonConf &btnDst = buttons->btnConf[dst];
			if (btnDst.visible == false)
			{
				continue;
			}
			CopyButton(src, dst);
		}
		cbSource->ItemIndex = src;
	}
	else if (cbTargetType->ItemIndex == 2)	// button range
	{
		int start = cbTarget->ItemIndex;
		int end = cbTargetTo->ItemIndex;
		if (start < 0 || end < 0)
		{
			return;
		}
		for (int i=start; i<=end; i++)
		{
        	CopyButton(src, i);
		}
		cbTarget->ItemIndex = start;
		cbTargetTo->ItemIndex = end;
	}
	else									
	{
		for (int i=0; i<cbTarget->Items->Count; i++)
		{
			int dst = i;
			CopyButton(src, dst);
		}
		cbSource->ItemIndex = src;
	}
	buttons->Write();
}

//---------------------------------------------------------------------------
void __fastcall TfrmButtonCopy::btnCancelClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------

void TfrmButtonCopy::CopyButton(int src, int dst)
{
	const ButtonConf &btnSrc = buttons->btnConf[src];
	ButtonConf &btnDst = buttons->btnConf[dst];
	if (chbPosition->Checked)
	{
		btnDst.left = btnSrc.left;
		btnDst.top = btnSrc.top;
	}
	if (chbSize->Checked)
	{
		btnDst.width = btnSrc.width;
		btnDst.height = btnSrc.height;
	}
	if (chbCaption->Checked)
	{
		btnDst.caption = btnSrc.caption;
	}
	if (chbBehavior->Checked)
	{
		btnDst.type = btnSrc.type;
		btnDst.script = btnSrc.script;
		btnDst.number = btnSrc.number;
		btnDst.arg1 = btnSrc.arg1;
		btnDst.pagingTxWaveFile = btnSrc.pagingTxWaveFile;
		btnDst.pagingTxCodec = btnSrc.pagingTxCodec;
		btnDst.pagingTxPtime = btnSrc.pagingTxPtime;
		btnDst.audioTxMod = btnSrc.audioTxMod;
		btnDst.audioTxDev = btnSrc.audioTxDev;
		btnDst.audioRxMod = btnSrc.audioRxMod;
		btnDst.audioRxDev = btnSrc.audioRxDev;
		btnDst.videoRxMod = btnSrc.videoRxMod;
		btnDst.videoRxDev = btnSrc.videoRxDev;
	}
	if (chbFont->Checked)
	{
		btnDst.font = btnSrc.font;
		btnDst.fontLabel2 = btnSrc.fontLabel2;
	}
	if (chbColors->Checked)
	{
		memcpy(btnDst.colors, btnSrc.colors, sizeof(btnDst.colors));
	}
	if (chbVisible->Checked)
	{
		btnDst.visible = btnSrc.visible;
	}
	if (chbInactive->Checked)
	{
		btnDst.inactive = btnSrc.inactive;
	}
	if (chbImages->Checked)
	{
		btnDst.imgConfirmed = btnSrc.imgConfirmed;
		btnDst.imgEarly = btnSrc.imgEarly;
		btnDst.imgIdle = btnSrc.imgIdle;
		btnDst.imgTerminated = btnSrc.imgTerminated;
	}
	if (chbFrame->Checked)
	{
		btnDst.customFrame = btnSrc.customFrame;
		btnDst.bevelWidth = btnSrc.bevelWidth;
	}
	if (chbCenterTextHorizontally->Checked)
	{
		btnDst.labelCenterHorizontally = btnSrc.labelCenterHorizontally;
	}
	if (chbImageTransparent->Checked)
	{
        btnDst.imageTransparent = btnSrc.imageTransparent;
	}
	if (chbImagePosition->Checked)
	{
		btnDst.imageLeft = btnSrc.imageLeft;
		btnDst.imageTop = btnSrc.imageTop;
		btnDst.imageCenterVertically = btnSrc.imageCenterVertically;
	}
	if (chbLabelPosition->Checked)
	{
        btnDst.labelLeft = btnSrc.labelLeft;
		btnDst.labelTop = btnSrc.labelTop;
		btnDst.labelCenterVertically = btnSrc.labelCenterVertically;
		btnDst.label2Left = btnSrc.label2Left;
		btnDst.label2Top = btnSrc.label2Top;
	}

	AnsiString caption;
	if (btnDst.caption != "")
		caption.sprintf("%d: %s", dst, btnDst.caption.c_str());
	else
		caption.sprintf("%d: [unnamed]", dst);
	cbSource->Items->Strings[dst] = caption;
	cbTarget->Items->Strings[dst] = caption;
	cbTargetTo->Items->Strings[dst] = caption;
}

void __fastcall TfrmButtonCopy::cbTargetTypeChange(TObject *Sender)
{
	lblFrom->Visible = false;
	cbTarget->Visible = false;
	lblTo->Visible = false;
	cbTargetTo->Visible = false;

	switch (cbTargetType->ItemIndex)
	{
	case 0:
		lblFrom->Visible = true;
		cbTarget->Visible = true;
		break;
	case 2:
		lblFrom->Visible = true;
		cbTarget->Visible = true;
		lblTo->Visible = true;
		cbTargetTo->Visible = true;
		break;
	default:
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmButtonCopy::miSelectAllClick(TObject *Sender)
{
	SetCheckboxes(true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmButtonCopy::miDeselectAllClick(TObject *Sender)
{
	SetCheckboxes(false);
}
//---------------------------------------------------------------------------

void  TfrmButtonCopy::SetCheckboxes(bool state)
{
	chbPosition->Checked = state;
	chbSize->Checked = state;
	chbCaption->Checked = state;
	chbBehavior->Checked = state;
	chbFont->Checked = state;
	chbColors->Checked = state;
	chbVisible->Checked = state;
	chbInactive->Checked = state;
	chbImages->Checked = state;
	chbFrame->Checked = state;
	chbCenterTextHorizontally->Checked = state;
	chbImageTransparent->Checked = state;
}


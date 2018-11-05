object Form1: TForm1
  Left = 249
  Top = 153
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Enter protective code'
  ClientHeight = 45
  ClientWidth = 239
  Color = 12615680
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object MaskEdit1: TMaskEdit
    Left = 0
    Top = 0
    Width = 237
    Height = 21
    MaxLength = 10
    PasswordChar = '#'
    TabOrder = 0
    OnChange = MaskEdit1Change
  end
  object BitBtn1: TBitBtn
    Left = 164
    Top = 20
    Width = 75
    Height = 25
    Enabled = False
    TabOrder = 1
    OnClick = BitBtn1Click
    Kind = bkOK
  end
  object Timer1: TTimer
    Interval = 300
    OnTimer = Timer1Timer
    Left = 84
    Top = 24
  end
end

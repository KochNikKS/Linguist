object RegForm: TRegForm
  Left = 279
  Top = 238
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Registration'
  ClientHeight = 45
  ClientWidth = 221
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object MaskEdit1: TMaskEdit
    Left = 0
    Top = 0
    Width = 149
    Height = 21
    MaxLength = 10
    PasswordChar = '*'
    TabOrder = 0
    OnChange = MaskEdit1Change
  end
  object Edit1: TEdit
    Left = 0
    Top = 24
    Width = 149
    Height = 21
    Enabled = False
    MaxLength = 20
    TabOrder = 1
    Text = 'Unnamed'
  end
  object Button1: TButton
    Left = 152
    Top = 1
    Width = 69
    Height = 21
    Caption = 'Ok'
    Enabled = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 152
    Top = 24
    Width = 69
    Height = 21
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = Button2Click
  end
end

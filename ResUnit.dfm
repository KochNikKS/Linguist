object ResForm: TResForm
  Left = 117
  Top = 122
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Results'
  ClientHeight = 289
  ClientWidth = 607
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 344
    Top = 16
    Width = 253
    Height = 249
    Brush.Color = clAqua
    Shape = stCircle
  end
  object Label1: TLabel
    Left = 200
    Top = 272
    Width = 11
    Height = 13
    Caption = '¹'
  end
  object Pie1: TPie
    Left = 346
    Top = 16
    Width = 250
    Height = 249
    Angles.StartAngle = 180
    Angles.EndAngle = 90
    Brush.Color = clRed
  end
  object Label2: TLabel
    Left = 348
    Top = 272
    Width = 76
    Height = 13
    Caption = 'Correct answers'
  end
  object Label3: TLabel
    Left = 492
    Top = 273
    Width = 30
    Height = 13
    Caption = 'Errors:'
  end
  object Label4: TLabel
    Left = 472
    Top = 272
    Width = 8
    Height = 13
    Caption = '%'
  end
  object Label5: TLabel
    Left = 568
    Top = 272
    Width = 8
    Height = 13
    Caption = '%'
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 333
    Height = 265
    Lines.Strings = (
      '')
    TabOrder = 0
  end
  object BitBtn2: TBitBtn
    Left = 49
    Top = 268
    Width = 49
    Height = 21
    TabOrder = 1
    OnClick = BitBtn2Click
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333333333333333333333333333333333333333333333333333333333
      3333333333333333333333333333333333333333333FF3333333333333003333
      3333333333773FF3333333333309003333333333337F773FF333333333099900
      33333FFFFF7F33773FF30000000999990033777777733333773F099999999999
      99007FFFFFFF33333F7700000009999900337777777F333F7733333333099900
      33333333337F3F77333333333309003333333333337F77333333333333003333
      3333333333773333333333333333333333333333333333333333333333333333
      3333333333333333333333333333333333333333333333333333}
    NumGlyphs = 2
  end
  object Edit1: TEdit
    Left = 216
    Top = 268
    Width = 37
    Height = 21
    AutoSize = False
    TabOrder = 2
  end
  object BitBtn1: TBitBtn
    Left = 0
    Top = 268
    Width = 49
    Height = 21
    TabOrder = 3
    OnClick = BitBtn1Click
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333333333333333333333333333333333333333333333333333333333
      3333333333333FF3333333333333003333333333333F77F33333333333009033
      333333333F7737F333333333009990333333333F773337FFFFFF330099999000
      00003F773333377777770099999999999990773FF33333FFFFF7330099999000
      000033773FF33777777733330099903333333333773FF7F33333333333009033
      33333333337737F3333333333333003333333333333377333333333333333333
      3333333333333333333333333333333333333333333333333333333333333333
      3333333333333333333333333333333333333333333333333333}
    NumGlyphs = 2
  end
  object Button1: TButton
    Left = 256
    Top = 268
    Width = 75
    Height = 21
    Hint = 'Show record'
    Caption = 'Show'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    OnClick = Button1Click
  end
  object Panel1: TPanel
    Left = 432
    Top = 268
    Width = 37
    Height = 17
    BevelOuter = bvNone
    Color = clAqua
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object Panel2: TPanel
    Left = 528
    Top = 268
    Width = 37
    Height = 17
    BevelOuter = bvNone
    Color = clRed
    TabOrder = 6
  end
end

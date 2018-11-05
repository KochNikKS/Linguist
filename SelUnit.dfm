object SelForm: TSelForm
  Left = 64
  Top = 3
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Selector of expressions for interrogation'
  ClientHeight = 505
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  PrintScale = poNone
  Scaled = False
  OnHide = FormHide
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    Left = 300
    Top = 236
    Width = 29
    Height = 29
    Action = Action1
    BiDiMode = bdLeftToRight
    Caption = ' '
    Enabled = False
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
    Layout = blGlyphRight
    NumGlyphs = 2
    ParentShowHint = False
    ParentBiDiMode = False
    ShowHint = True
  end
  object SpeedButton2: TSpeedButton
    Left = 300
    Top = 260
    Width = 29
    Height = 29
    Action = Action2
    Caption = ' '
    Enabled = False
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
    ParentShowHint = False
    ShowHint = True
  end
  object Label1: TLabel
    Left = 4
    Top = 4
    Width = 71
    Height = 13
    Caption = 'Main dictionary'
    Transparent = True
  end
  object Label2: TLabel
    Left = 332
    Top = 4
    Width = 83
    Height = 13
    Caption = 'Special dictionary'
    Transparent = True
  end
  object ListBox1: TListBox
    Left = 328
    Top = 20
    Width = 300
    Height = 485
    ItemHeight = 13
    TabOrder = 1
    OnClick = ListBox1Click
    OnDblClick = Action2Execute
  end
  object ListBox2: TListBox
    Left = 0
    Top = 20
    Width = 300
    Height = 485
    ItemHeight = 13
    TabOrder = 0
    OnClick = ListBox2Click
    OnDblClick = Action1Execute
  end
  object ActionList1: TActionList
    Left = 300
    Top = 170
    object Action1: TAction
      Caption = 'Action1'
      ShortCut = 13
      OnExecute = Action1Execute
    end
    object Action2: TAction
      Caption = 'Action2'
      ShortCut = 46
      OnExecute = Action2Execute
    end
  end
  object MainMenu1: TMainMenu
    Left = 300
    Top = 296
    object Actions1: TMenuItem
      Caption = 'Actions'
      object Add1: TMenuItem
        Caption = 'Add'
      end
      object Delete1: TMenuItem
        Caption = 'Delete'
      end
      object Clear1: TMenuItem
        Caption = 'Clear'
      end
      object Run1: TMenuItem
        Caption = 'Auto select'
      end
      object Choosearange1: TMenuItem
        Caption = 'Choose a range'
      end
      object Runtraningexam1: TMenuItem
        Caption = 'Run traning/exam'
      end
      object Returntomainwindow1: TMenuItem
        Caption = 'Return to main window'
      end
    end
  end
end

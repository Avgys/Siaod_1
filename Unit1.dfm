object Form1: TForm1
  Left = 140
  Top = 145
  Caption = 'Form1'
  ClientHeight = 509
  ClientWidth = 567
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 408
    Top = 0
    Width = 159
    Height = 509
    Align = alRight
    Caption = 'Panel2'
    TabOrder = 0
    object Button3: TButton
      Left = 16
      Top = 65
      Width = 75
      Height = 25
      Caption = 'SortPage'
      PopupMenu = PopupMenu1
      TabOrder = 0
    end
    object Button2: TButton
      Left = 16
      Top = 96
      Width = 75
      Height = 25
      Caption = 'SortName'
      TabOrder = 1
    end
    object Button1: TButton
      Left = 16
      Top = 127
      Width = 75
      Height = 25
      Caption = 'AddToList'
      TabOrder = 2
      OnClick = Addbtn
    end
    object Button4: TButton
      Left = 16
      Top = 176
      Width = 75
      Height = 25
      Caption = 'Refresh'
      TabOrder = 3
      OnClick = Refresh
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 408
    Height = 509
    Align = alClient
    Caption = 'Panel3'
    TabOrder = 1
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 406
      Height = 152
      Align = alTop
      TabOrder = 0
      object Label1: TLabel
        Left = 55
        Top = 40
        Width = 32
        Height = 13
        Caption = 'Termin'
      end
      object Label2: TLabel
        Left = 208
        Top = 32
        Width = 24
        Height = 13
        Caption = 'Page'
      end
      object Termin: TEdit
        Left = 25
        Top = 66
        Width = 121
        Height = 21
        TabOrder = 0
      end
      object Page: TEdit
        Left = 185
        Top = 66
        Width = 121
        Height = 21
        TabOrder = 1
      end
      object Viewbox: TComboBox
        Left = 185
        Top = 116
        Width = 121
        Height = 21
        ItemIndex = 1
        TabOrder = 2
        Text = 'Nominal'
        Items.Strings = (
          'Hash view'
          'Nominal'
          'Alphabet sort'
          'Page Sort')
      end
    end
    object Memo: TMemo
      Left = 1
      Top = 153
      Width = 406
      Height = 355
      Align = alClient
      PopupMenu = PopupMenu1
      TabOrder = 1
    end
  end
  object MainMenu1: TMainMenu
    Left = 488
    Top = 8
    object N1: TMenuItem
      Caption = 'Prog'
      object LoadFromFile1: TMenuItem
        Caption = 'LoadFromFile'
        OnClick = LoadFromFile
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
  end
  object PopupMenu1: TPopupMenu
    OnPopup = Addbtn
    Left = 536
    Top = 8
    object dsaf1: TMenuItem
      Caption = 'Change'
    end
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    FileName = 'D:\Project_cpp\Siaod3\Unit1.h'
    FilterIndex = 0
    Encodings.Strings = (
      'ANSI'
      'ASCII'
      'Unicode'
      'Big Endian Unicode'
      'UTF-8'
      '')
    Left = 408
  end
end

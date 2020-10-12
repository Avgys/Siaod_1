object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 662
  ClientWidth = 567
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 408
    Top = 0
    Width = 159
    Height = 662
    Align = alRight
    Caption = 'Panel2'
    TabOrder = 0
    ExplicitLeft = 25
    ExplicitTop = 1
    ExplicitHeight = 39
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
      OnClick = Button1Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 408
    Height = 662
    Align = alClient
    Caption = 'Panel3'
    TabOrder = 1
    ExplicitLeft = 200
    ExplicitTop = 317
    ExplicitWidth = 185
    ExplicitHeight = 41
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 406
      Height = 152
      Align = alTop
      TabOrder = 0
      ExplicitLeft = -4
      ExplicitTop = 249
      ExplicitWidth = 411
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
    end
    object StringGrid: TStringGrid
      Left = 1
      Top = 153
      Width = 406
      Height = 508
      Align = alClient
      ColCount = 3
      DefaultColWidth = 133
      FixedCols = 0
      RowCount = 20
      FixedRows = 0
      PopupMenu = PopupMenu1
      TabOrder = 1
    end
  end
  object MainMenu1: TMainMenu
    Left = 360
    Top = 65528
    object N1: TMenuItem
      Caption = 'Prog'
      object LoadFromFile1: TMenuItem
        Caption = 'LoadFromFile'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
  end
  object PopupMenu1: TPopupMenu
    OnPopup = Button1Click
    Left = 320
    object dsaf1: TMenuItem
      Caption = 'Change'
    end
  end
end

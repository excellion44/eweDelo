object Form5: TForm5
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1059#1082#1072#1078#1080#1090#1077' '#1089#1093#1086#1076#1103#1097#1080#1081' '#1085#1086#1084#1077#1088
  ClientHeight = 76
  ClientWidth = 352
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 11
    Width = 156
    Height = 16
    Caption = #1059#1082#1072#1078#1080#1090#1077' '#1080#1089#1093#1086#1076#1103#1097#1080#1081' '#8470
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ID: TLabel
    Left = 160
    Top = 48
    Width = 11
    Height = 13
    Caption = 'ID'
  end
  object Edit1: TEdit
    Left = 170
    Top = 8
    Width = 173
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 8
    Top = 43
    Width = 113
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 229
    Top = 43
    Width = 115
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 2
    OnClick = BitBtn2Click
  end
end

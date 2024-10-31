object Form11: TForm11
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1088#1086#1095#1080#1077' '#1085#1072#1089#1088#1086#1081#1082#1080
  ClientHeight = 552
  ClientWidth = 718
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 5
    Width = 304
    Height = 13
    Caption = #1055#1091#1090#1100' '#1082#1091#1076#1072' '#1089#1086#1093#1088#1072#1085#1103#1090#1100' '#1086#1090#1082#1088#1099#1074#1072#1077#1084#1099#1077' '#1092#1072#1081#1083#1099' '#1080#1079' '#1073#1072#1079#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 641
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 655
    Top = 22
    Width = 42
    Height = 25
    Caption = '...'
    TabOrder = 1
    OnClick = Button1Click
  end
  object OpenDialog1: TOpenDialog
    Left = 656
    Top = 48
  end
end

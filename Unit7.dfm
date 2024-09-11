object Form7: TForm7
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1060#1086#1088#1084#1072' '#1076#1086#1073#1072#1074#1083#1077#1085#1080#1103'/'#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
  ClientHeight = 186
  ClientWidth = 618
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
  object ADD_OR_EDIT: TLabel
    Left = 600
    Top = 176
    Width = 71
    Height = 13
    Caption = 'ADD_OR_EDIT'
    Visible = False
  end
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 14
    Height = 13
    Caption = #8470
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 71
    Top = 8
    Width = 31
    Height = 13
    Caption = #1044#1072#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 184
    Top = 8
    Width = 86
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 302
    Top = 8
    Width = 76
    Height = 13
    Caption = #1048#1089#1087#1086#1083#1085#1080#1090#1077#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 461
    Top = 8
    Width = 57
    Height = 13
    Caption = #1054#1090#1087#1088#1072#1074#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 16
    Top = 58
    Width = 126
    Height = 13
    Caption = #1050#1088#1072#1090#1082#1086#1077' '#1089#1086#1076#1077#1088#1078#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 16
    Top = 105
    Width = 70
    Height = 13
    Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ID: TLabel
    Left = 520
    Top = 150
    Width = 11
    Height = 13
    Caption = 'ID'
    Visible = False
  end
  object number: TEdit
    Left = 16
    Top = 24
    Width = 49
    Height = 24
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    TextHint = #1053#1086#1084#1077#1088
  end
  object data: TDateTimePicker
    Left = 71
    Top = 24
    Width = 106
    Height = 24
    Date = 44694.000000000000000000
    Time = 0.400316921295598100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object nom: TComboBox
    Left = 183
    Top = 24
    Width = 89
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = 'nom'
  end
  object BitBtn1: TBitBtn
    Left = 278
    Top = 24
    Width = 24
    Height = 24
    Caption = '-'
    TabOrder = 4
  end
  object isp: TComboBox
    Left = 302
    Top = 24
    Width = 132
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Text = 'isp'
  end
  object BitBtn2: TBitBtn
    Left = 434
    Top = 24
    Width = 24
    Height = 24
    Caption = '+'
    TabOrder = 6
  end
  object otpr: TComboBox
    Left = 461
    Top = 24
    Width = 145
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    Text = 'otpr'
    Items.Strings = (
      #1055#1086#1095#1090#1072
      #1055#1086#1095#1090#1072' + '#1051#1086#1090#1091#1089
      'E-mail'
      #1053#1072' '#1088#1091#1082#1080
      #1060#1072#1082#1089)
  end
  object about: TEdit
    Left = 16
    Top = 72
    Width = 590
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    TextHint = #1050#1088#1072#1090#1082#1086#1077' '#1089#1086#1076#1077#1088#1078#1072#1085#1080#1077
  end
  object prim: TEdit
    Left = 16
    Top = 120
    Width = 590
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    TextHint = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077
  end
  object Add_Or_Edit_Btn: TBitBtn
    Left = 144
    Top = 150
    Width = 145
    Height = 25
    Caption = 'Add_Or_Edit_Btn'
    TabOrder = 0
    OnClick = Add_Or_Edit_BtnClick
  end
  object BitBtn4: TBitBtn
    Left = 303
    Top = 150
    Width = 155
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 10
    OnClick = BitBtn4Click
  end
end

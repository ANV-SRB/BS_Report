object Form1: TForm1
  Left = 343
  Top = 154
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1054#1090#1095#1077#1090' '#1087#1086' '#1092#1072#1081#1083#1091' '#1083#1086#1075#1080#1082#1080' BSYSTEM'
  ClientHeight = 620
  ClientWidth = 1051
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  SnapBuffer = 5
  OnCreate = FormCreate
  PixelsPerInch = 240
  TextHeight = 16
  object Label8: TLabel
    Left = 375
    Top = 8
    Width = 16
    Height = 16
    Caption = '    '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 559
    Top = 8
    Width = 16
    Height = 16
    Caption = '    '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object TabSheet: TPageControl
    AlignWithMargins = True
    Left = 0
    Top = 0
    Width = 1049
    Height = 673
    ActivePage = TabSheet2
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'MAIN'
      object lblMainFilePath: TLabel
        Left = 111
        Top = 2
        Width = 40
        Height = 16
        Caption = #1060#1072#1081#1083': '
      end
      object MemoRead: TMemo
        Left = 111
        Top = 24
        Width = 309
        Height = 561
        Lines.Strings = (
          'MAIN')
        ScrollBars = ssBoth
        TabOrder = 0
        OnDblClick = MemoReadDblClick
      end
      object P_Memo: TMemo
        Left = 426
        Top = 24
        Width = 200
        Height = 561
        Lines.Strings = (
          'P_Report')
        ScrollBars = ssBoth
        TabOrder = 1
      end
      object T_Memo: TMemo
        Left = 632
        Top = 24
        Width = 200
        Height = 561
        Lines.Strings = (
          'T_Report')
        ScrollBars = ssBoth
        TabOrder = 2
      end
      object C_Memo: TMemo
        Left = 838
        Top = 24
        Width = 200
        Height = 561
        Lines.Strings = (
          'C_Report')
        ScrollBars = ssBoth
        TabOrder = 3
      end
      object Panel1: TPanel
        Left = 3
        Top = 24
        Width = 102
        Height = 561
        TabOrder = 4
        object Label1: TLabel
          Left = 10
          Top = 59
          Width = 43
          Height = 16
          Caption = #1057#1090#1088#1086#1082' :'
        end
        object ReadFileLinsNum: TLabel
          Left = 10
          Top = 81
          Width = 7
          Height = 16
          Caption = '0'
        end
        object Label2: TLabel
          Left = 5
          Top = 259
          Width = 88
          Height = 16
          Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1086':'
        end
        object Label3: TLabel
          Left = 10
          Top = 281
          Width = 12
          Height = 16
          Caption = 'P:'
        end
        object report_p_num: TLabel
          Left = 30
          Top = 281
          Width = 7
          Height = 16
          Caption = '0'
        end
        object Label4: TLabel
          Left = 10
          Top = 303
          Width = 13
          Height = 16
          Caption = 'T:'
        end
        object report_t_num: TLabel
          Left = 30
          Top = 303
          Width = 7
          Height = 16
          Caption = '0'
        end
        object Label5: TLabel
          Left = 10
          Top = 325
          Width = 13
          Height = 16
          Caption = 'C:'
        end
        object report_c_num: TLabel
          Left = 30
          Top = 325
          Width = 7
          Height = 16
          Caption = '0'
        end
        object BitBtn1: TBitBtn
          Left = 10
          Top = 21
          Width = 83
          Height = 32
          Caption = 'OpenMAIN'
          TabOrder = 0
          WordWrap = True
          OnClick = BitBtn1Click
        end
        object Button2: TButton
          Left = 10
          Top = 110
          Width = 83
          Height = 33
          Caption = #1054#1090#1095#1077#1090' P'
          TabOrder = 1
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 10
          Top = 160
          Width = 83
          Height = 33
          Caption = #1054#1090#1095#1077#1090' T'
          TabOrder = 2
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 10
          Top = 210
          Width = 83
          Height = 33
          Caption = #1054#1090#1095#1077#1090' C'
          TabOrder = 3
          OnClick = Button4Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'DEF'
      ImageIndex = 1
      object lblCoincidencesTitle: TLabel
        Left = 149
        Top = 415
        Width = 75
        Height = 16
        Caption = #1055#1086#1074#1090#1086#1088#1077#1085#1080#1103':'
        Visible = False
      end
      object lblDefFilePath: TLabel
        Left = 111
        Top = 3
        Width = 40
        Height = 16
        Caption = #1060#1072#1081#1083': '
      end
      object MemoDef: TMemo
        Left = 111
        Top = 25
        Width = 226
        Height = 386
        Lines.Strings = (
          'Memo DEF')
        ScrollBars = ssBoth
        TabOrder = 0
        OnDblClick = MemoDefDblClick
      end
      object MemoDefResults: TMemo
        Left = 111
        Top = 437
        Width = 226
        Height = 142
        Lines.Strings = (
          'Memo DEF')
        ScrollBars = ssBoth
        TabOrder = 1
        Visible = False
      end
      object defAdrList: TMemo
        Left = 507
        Top = 25
        Width = 222
        Height = 554
        Lines.Strings = (
          '')
        ScrollBars = ssBoth
        TabOrder = 2
      end
      object Panel2: TPanel
        Left = 3
        Top = 25
        Width = 102
        Height = 554
        Caption = ' '
        TabOrder = 3
        object Label6: TLabel
          Left = 11
          Top = 55
          Width = 39
          Height = 16
          Caption = #1057#1090#1088#1086#1082':'
        end
        object def_file_lines_num: TLabel
          Left = 11
          Top = 76
          Width = 7
          Height = 16
          Caption = '0'
        end
        object Label7: TLabel
          Left = 11
          Top = 153
          Width = 76
          Height = 16
          Caption = #1057#1086#1074#1087#1072#1076#1077#1085#1080#1081':'
        end
        object LblСoincid: TLabel
          Left = 11
          Top = 175
          Width = 7
          Height = 16
          Caption = '0'
        end
        object BitBtn4: TBitBtn
          Left = 11
          Top = 16
          Width = 83
          Height = 33
          Caption = 'OpenDEF'
          TabOrder = 0
          OnClick = BitBtn2Click
        end
        object btnCheckDef: TBitBtn
          Left = 11
          Top = 114
          Width = 83
          Height = 33
          Caption = #1055#1088#1086#1074#1077#1088#1082#1072
          TabOrder = 1
          OnClick = btnCheckDefClick
        end
      end
      object Panel3: TPanel
        Left = 356
        Top = 25
        Width = 145
        Height = 554
        Caption = ' '
        TabOrder = 4
        object Label11: TLabel
          Left = 9
          Top = 9
          Width = 96
          Height = 16
          Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1072#1076#1088#1077#1089#1091
        end
        object Label10: TLabel
          Left = 9
          Top = 31
          Width = 54
          Height = 16
          Caption = 'W '#1080#1083#1080' U:'
        end
        object defAdrSelEdit: TSpinEdit
          Left = 2
          Top = 53
          Width = 127
          Height = 28
          MaxValue = 255
          MinValue = 0
          TabOrder = 0
          Value = 0
          OnChange = defAdrSelEditChange
        end
        object defAdrSelectorBtn: TButton
          Left = 16
          Top = 98
          Width = 89
          Height = 33
          Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100
          TabOrder = 1
          OnClick = defAdrSelectorBtnClick
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 992
    Top = 138
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 992
    Top = 42
  end
  object OpenDialog2: TOpenDialog
    Left = 992
    Top = 186
  end
  object OpenDialog3: TOpenDialog
    Left = 992
    Top = 234
  end
  object Timer2: TTimer
    OnTimer = Timer1Timer
    Left = 992
    Top = 90
  end
  object OpenDialog4: TOpenDialog
    Left = 992
    Top = 282
  end
end

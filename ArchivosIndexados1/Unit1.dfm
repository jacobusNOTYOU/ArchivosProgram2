object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 536
  ClientWidth = 848
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Button1: TButton
    Left = 128
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 240
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 344
    Top = 248
    Width = 75
    Height = 25
    Caption = 'CrearIdx'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 120
    Top = 48
    Width = 121
    Height = 23
    TabOrder = 3
    Text = 'Edit1'
    OnExit = OnExit
  end
  object Edit2: TEdit
    Left = 120
    Top = 88
    Width = 121
    Height = 23
    TabOrder = 4
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 120
    Top = 128
    Width = 121
    Height = 23
    TabOrder = 5
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 264
    Top = 128
    Width = 121
    Height = 23
    TabOrder = 6
    Text = 'Edit4'
  end
  object Edit5: TEdit
    Left = 408
    Top = 128
    Width = 121
    Height = 23
    TabOrder = 7
    Text = 'Edit5'
  end
  object Button4: TButton
    Left = 448
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Ord.Idx'
    TabOrder = 8
  end
  object Button5: TButton
    Left = 544
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Busc.Binaria'
    TabOrder = 9
  end
end

object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 531
  ClientWidth = 941
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Button1: TButton
    Left = 216
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Guardar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 216
    Top = 56
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 216
    Top = 85
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 216
    Top = 114
    Width = 121
    Height = 23
    TabOrder = 3
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 343
    Top = 114
    Width = 121
    Height = 23
    TabOrder = 4
    Text = 'Edit4'
  end
  object Edit5: TEdit
    Left = 470
    Top = 114
    Width = 121
    Height = 23
    TabOrder = 5
    Text = 'Edit5'
  end
  object Button2: TButton
    Left = 297
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Listado'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 378
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 7
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 400
    Top = 488
  end
end

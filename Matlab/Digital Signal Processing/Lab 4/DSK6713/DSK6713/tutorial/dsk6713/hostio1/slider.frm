VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "COMCTL32.OCX"
Begin VB.Form slider 
   Caption         =   "Volume Slider"
   ClientHeight    =   1230
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   3330
   Icon            =   "slider.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   1230
   ScaleWidth      =   3330
   StartUpPosition =   3  'Windows Default
   Begin ComctlLib.Slider Slider1 
      Height          =   636
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   2772
      _ExtentX        =   4895
      _ExtentY        =   1111
      _Version        =   327682
   End
End
Attribute VB_Name = "slider"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

'
' VB code changes the volume variable on the target from a NI knob
' on the host using RTDX.
'
' Revision History
' ================
' 02-Sep-1998 po    Created.
'

                                            'RTDX OLE API Status Return codes
Const SUCCESS = &H0                         'Method call succussful
Const FAIL = &H80004005                     'Method call failure
Const ENoDataAvailable = &H8003001E         'No data is currently available
Const EEndOfLogFile = &H80030002            'End of log file

Dim rtdx As Object


Private Sub Form_Load()
Dim status As Long
    
    BoardProc_frm.Show 1

    ' Get application objects
    Set rtdx = CreateObject("RTDX")
    
    status = rtdx.SetProcessor(BoardProc_frm.CurrentSelectedBoard, _
                                BoardProc_frm.CurrentSelectedProcessor)
    If (status <> SUCCESS) Then
        MsgBox "Set Processor failed", vbCritical
        Exit Sub
    End If
                        
    ' open target's input channel
    status = rtdx.Open("control_channel", "W")
    Select Case status
    Case Is = SUCCESS
    Case Is = FAIL
        MsgBox "Unable to open control_channel", vbCritical, "Error"
        Exit Sub
    Case Else
        MsgBox "Unknown return value from control_channel open", vbInformation
        Exit Sub
    End Select
End Sub

Private Sub Form_Unload(Cancel As Integer)
    ' close target's input channel
    status = rtdx.Close()
    Select Case status
        Case Is = SUCCESS
        Case Is = FAIL
            MsgBox "Unable to close input channel", vbCritical, "Error"
        Case Else
            MsgBox "Unknown return value from input close", vbInformation
    End Select
  
    Set rtdx = Nothing                     ' kill RTDX OLE object
    Unload BoardProc_frm
End Sub

Private Sub Slider1_Change()
    Dim status As Long
    Dim dataI4 As Long
    Dim bufstate As Long
    ' write volume to target input channel
    dataI4 = Slider1.Value
    status = rtdx.WriteI4(dataI4, bufstate)
    
    Select Case status
        Case Is = SUCCESS
        Case Is = FAIL
            MsgBox "Error: Writing data failed" & dataI4
        Case Else
            MsgBox "Volume data backed up waiting for DSP to read it"
    End Select
End Sub


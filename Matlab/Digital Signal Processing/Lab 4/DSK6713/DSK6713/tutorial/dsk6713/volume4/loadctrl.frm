VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "COMCTL32.OCX"
Begin VB.Form loadctrl 
   Caption         =   "Load Control"
   ClientHeight    =   1365
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6435
   Icon            =   "loadctrl.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   1365
   ScaleWidth      =   6435
   StartUpPosition =   3  'Windows Default
   Begin ComctlLib.Slider Slider1 
      Height          =   630
      Left            =   360
      TabIndex        =   0
      Top             =   360
      Width           =   5655
      _ExtentX        =   9975
      _ExtentY        =   1111
      _Version        =   327682
      LargeChange     =   100
      SmallChange     =   50
      Max             =   2000
      TickFrequency   =   100
   End
End
Attribute VB_Name = "loadctrl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'#######################################################################
'    TTT         The Real-Time Data Exchange (RTDX) Displays
'    TTT i
'TTTTT  TiTTTT   The following display is used to demonstrate RTDX.
' T     -i-   T  This display was designed to use the Object Linking
'  TTT   i    T  And Embedding(OLE) interface to Texas Instruments'
'   T TT    TT   debugger (Code Composer).  The primary purpose for the
'       TT TT    display is to expose target transmitted data in
'         TTT    Real-Time.
'           TT
'                Copyright 1997-1998 Texas Instruments
'                RTDX is a trademark of Texas Instruments
'_______________________________________________________________________
' This display changes the load control variable on the target
' from a slider on the host using RTDX.
'#######################################################################

' RTDX OLE API Status Return codes
Const SUCCESS = &H0                      'Method call successful
Const FAIL = &H80004005                  'Method call failure
Const ENoDataAvailable = &H8003001E      'No data is currently available
Const EEndOfLogFile = &H80030002         'End of log file

Dim rtdx As Object
Dim bufstate As Long

Private Sub Form_Load()
  
  Dim status As Long
  
  ' Get application objects
  Set rtdx = CreateObject("RTDX")
  
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
      MsgBox "Unable to close control_channel", vbCritical, "Error"
    Case Else
      MsgBox "Unknown return value from control_channel close", vbInformation
  End Select
  
  Set rtdx = Nothing                     ' kill RTDX OLE object

End Sub
Private Sub Slider1_Change()

  Dim status As Long
  Dim dataI4 As Long

  ' write load to target input channel
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

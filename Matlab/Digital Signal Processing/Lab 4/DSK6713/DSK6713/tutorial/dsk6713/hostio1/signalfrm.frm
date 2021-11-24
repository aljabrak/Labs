VERSION 5.00
Object = "{65E121D4-0C60-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCHRT20.OCX"
Begin VB.Form signalfrm 
   BackColor       =   &H00404040&
   Caption         =   "signalprog"
   ClientHeight    =   5595
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   10080
   ForeColor       =   &H00000000&
   Icon            =   "signalfrm.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   5595
   ScaleWidth      =   10080
   StartUpPosition =   3  'Windows Default
   Begin MSChart20Lib.MSChart ReceivedSignal 
      Height          =   3015
      Left            =   0
      OleObjectBlob   =   "signalfrm.frx":030A
      TabIndex        =   1
      Top             =   2640
      Width           =   8655
   End
   Begin MSChart20Lib.MSChart TransmittedSignal 
      Height          =   2655
      Left            =   0
      OleObjectBlob   =   "signalfrm.frx":25A5
      TabIndex        =   0
      Top             =   0
      Width           =   8655
   End
   Begin VB.Timer tmr_MethodDispatch 
      Enabled         =   0   'False
      Interval        =   1
      Left            =   8640
      Top             =   4680
   End
   Begin VB.CommandButton cmd_Toggle 
      Caption         =   "Off"
      Height          =   1095
      Left            =   8640
      TabIndex        =   2
      Top             =   0
      Width           =   1095
   End
End
Attribute VB_Name = "signalfrm"
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
'                Copyright 1997-2000 Texas Instruments
'                RTDX is a trademark of Texas Instruments
'_______________________________________________________________________
' This display attempts to transmit 64 sample signal to the target.
' Depending on the transmission status, the display will then attempt to
' read a 64 sample signal.  Both signals with be displayed in a
' 2-dimensional chart.
'#######################################################################

' RTDX OLE API Status Return codes
Const SUCCESS = &H0                      'Method call succussful
Const FAIL = &H80004005                  'Method call failure
Const ENoDataAvailable = &H8003001E      'No data is currently available
Const EEndOfLogFile = &H80030002         'End of log file

Const SAMPLE_SIZE = 64                   '# of samples
Const Pi = 3.141592654                   'Pi

' Form and control orignal size and positions
Const FORM_START_WIDTH = 9870
Const FORM_START_HEIGHT = 5475
Const TRANSMITTED_CHART_START_WIDTH = 8655
Const TRANSMITTED_CHART_START_HEIGHT = 2535
Const TRANSMITTED_CHART_START_LEFT = 0
Const TRANSMITTED_CHART_START_TOP = 0
Const RECEIVED_CHART_START_WIDTH = 8655
Const RECEIVED_CHART_START_HEIGHT = 2535
Const RECEIVED_CHART_START_LEFT = 0
Const RECEIVED_CHART_START_TOP = 2520
Const TOGGLE_BUTTON_START_WIDTH = 1095
Const TOGGLE_BUTTON_START_HEIGHT = 1095
Const TOGGLE_BUTTON_START_LEFT = 8640
Const TOGGLE_BUTTON_START_TOP = 0

' Channel name constants

Const READ_CHANNEL = "D2A_channel"
Const WRITE_CHANNEL = "A2D_channel"

' Toggle constants
Const START_CAPTION = "Test ON"
Const STOP_CAPTION = "Test OFF"

Dim fromDSP As Object       ' Variable for RTDX object instantiation
Dim toDSP As Object         ' Variable for RTDX object instantiation
Dim status As Long          ' Method status variable

Public Sub Test_ON()
'#######################################################################
' This procedure is called by procedure, cmd_Toggle_Click().  Its job is
' instantiate the RTDX Exported Interface, open the channels, enable
' channels and enable the timer(tmr_MethodDispatch_Timer()).
'#######################################################################

    Dim response As Integer          ' Response variable for message box
    
    ' RTDX Exported Interface intstantiations
    Set toDSP = CreateObject("RTDX")   ' Create an instance of the RTDX
                                       '    Exported Interface for data
                                       '    transmission (write)
    On Error GoTo On_Error             ' Test object instantiation
    Set fromDSP = CreateObject("RTDX") ' Create an instance of the RTDX
                                       '    Exported Interface for data
                                       '    reception (read)
    On Error GoTo On_Error             ' Test object instantiation
    
    ' Set the desired board and processor
    status = fromDSP.SetProcessor(BoardProc_frm.CurrentSelectedBoard, _
                                    BoardProc_frm.CurrentSelectedProcessor)
    If status <> SUCCESS Then
        response = MsgBox("Error: SetProcessor failed ", vbCritical)
        Exit Sub
    End If
    
    status = toDSP.SetProcessor(BoardProc_frm.CurrentSelectedBoard, _
                                    BoardProc_frm.CurrentSelectedProcessor)
    If status <> SUCCESS Then
        response = MsgBox("Error: SetProcessor failed ", vbCritical)
        Exit Sub
    End If
    
    status = fromDSP.Open(READ_CHANNEL, "R") ' Open up the read channel
    If status <> SUCCESS Then          ' verify that channel is opened
        response = MsgBox("Error: Opening the channel " + _
                           READ_CHANNEL + " Failed", vbCritical)
        Exit Sub
    End If
    
    status = toDSP.Open(WRITE_CHANNEL, "W") ' Open up the write channel
    If status <> SUCCESS Then           ' verify that channel is opened
        response = MsgBox("Error: Opening the channel " + _
                           WRITE_CHANNEL + " Failed", vbCritical)
        Exit Sub
    End If
    
    status = toDSP.EnableChannel(WRITE_CHANNEL) ' Enable write channel
    If status <> SUCCESS Then          ' verify that channel is enabled
        response = MsgBox("Error: Enabling the channel " + _
                           WRITE_CHANNEL + " Failed", vbCritical)
        Exit Sub
    End If
    
    status = fromDSP.EnableChannel(READ_CHANNEL) ' Enable read channel
    If status <> SUCCESS Then          ' verify that channel is enabled
        response = MsgBox("Error: Enabling the channel " + _
                           READ_CHANNEL + " Failed", vbCritical)
        Exit Sub
    End If
    
    Clear_Charts ' Clear charts
    cmd_Toggle.Caption = STOP_CAPTION ' Change command button caption
    tmr_MethodDispatch.Enabled = True ' Enable timer method dispatch
    Exit Sub

On_Error:
    response = MsgBox("Error: Instantiation Failed", vbCritical)
    
End Sub

Public Sub Test_OFF()
'#######################################################################
' This procedure is called by procedure, cmd_Toggle_Click().  Its job is
' to close the channels, disable channels, release reference to RTDX
' object and disable the timer (tmr_MethodDispatch_Timer()).
'#######################################################################

    tmr_MethodDispatch.Enabled = False ' Disable timer methdo dispatch
    cmd_Toggle.Caption = START_CAPTION ' Change command button caption
    
    
    status = fromDSP.DisableChannel(READ_CHANNEL) ' Disable read channel
    If status <> SUCCESS Then          ' verify that channel is disabled
        response = MsgBox("Error: Disabling the channel " + _
                           READ_CHANNEL + " Failed", vbCritical)
        Exit Sub
    End If

    status = fromDSP.Close ' Close the read channel
    ' Was the closing of the read channel successful?
    If (status <> SUCCESS) Then
        response = MsgBox("Error: Closing of the " + READ_CHANNEL + _
                          " channel failed", vbCritical)
    End If
    Set fromDSP = Nothing  ' Release the reference to the RTDX Exported
                           '    Interface
    
    status = toDSP.DisableChannel(WRITE_CHANNEL) ' Disable write channel
    If status <> SUCCESS Then          ' verify that channel is disabled
        response = MsgBox("Error: Disabling the channel " + _
                           WRITE_CHANNEL + " Failed", vbCritical)
        Exit Sub
    End If
    
    status = toDSP.Close ' Close the write channel
    ' Was the closing of the write channel successful?
    If (status <> SUCCESS) Then
        response = MsgBox("Error: Closing of the " + WRITE_CHANNEL + _
                          " channel failed", vbCritical)
    End If
    Set toDSP = Nothing ' Release the reference to the RTDX Exported
                        '   Interface

End Sub

Public Sub Clear_Charts()
'#######################################################################
' This procedure is called by the procedure, Form_Load, and procedure,
' Test_On.  Its job is to erase the current signal on chart.
'#######################################################################

    Dim i As Integer ' index variable for loop
    
    For i = 1 To (SAMPLE_SIZE)
        TransmittedSignal.Row = i   ' set focus to row number i
        TransmittedSignal.Data = 0  ' clear data at row
        ReceivedSignal.Row = i
        ReceivedSignal.Data = 0
    Next i
End Sub

Private Function Transmit_Signal() As Long
'#######################################################################
' This fuction is called by the procedure, tmr_MethodDispatch_Timer().
' It's job is to generate a sine wave signal of a specified sample size
' and display it on the transmitted signal chart.  Afterwards, the
' function attempts to transmit the signal to the target.  The status of
' the method call, Write(), is returned to tmr_MethodDispatch().
'#######################################################################

    Dim i As Integer                      ' index variable for loop
    Dim samples(0 To (SAMPLE_SIZE - 1)) As Long ' array of 32-bit integer
                                                '   samples
    Dim bufferstate As Long               ' buffer State
    
    ' Gather samples and update "transmitted signal chart"
    For i = LBound(samples) To UBound(samples)
        samples(i) = Int(Sin(i * (Pi / 8)) * 100) ' generate sample
        TransmittedSignal.Row = i + 1 ' set focus to row number i + 1
        TransmittedSignal.Data = samples(i) ' clear data at row
    Next i
    
    status = toDSP.Write(CVar(samples), bufferstate) ' write array to target
    Transmit_Signal = status ' return status
    
End Function

Private Function Receive_Signal() As Long
'#######################################################################
' This function is called by the procedure, tmr_MethodDispatch_Timer().
' It's job is to read a signal from the target (DSP) and display it on
' the signal reception chart.  The status of the method call, ReadSAI4,
' is returned to tmr_MethodDispatch().
'#######################################################################

    Dim parray As Variant  ' pointer to SAFEARRAY
    Dim i As Long          ' index variable for loop
    
    status = fromDSP.ReadSAI4(parray) ' read data back from target
    
    If (status = SUCCESS) Then
        ' Update "received signal chart"
        For i = LBound(parray) To UBound(parray)
            ReceivedSignal.Row = i + 1 ' set focus to row number i + 1
            ReceivedSignal.Data = parray(i) ' clear data at row
        Next i
    End If
    
    ReceiveSignal = status ' return status
    
End Function
 
Private Sub cmd_Toggle_Click()
'#######################################################################
' This procedure is a handler for the command button control.  Its job
' is either to start or stop the test.
'#######################################################################

    ' Test caption for starting or stopping test
    If (cmd_Toggle.Caption = START_CAPTION) Then
        BoardProc_frm.Show 1
        Test_ON  ' start test
    Else
        Test_OFF  'stop test
    End If
    
End Sub

Private Sub Form_Load()
'#######################################################################
' This procedure is immediately called when the application is invoked
' or runned under the Visual Basic IDE.  Its job is to set up the
' display for running.
'#######################################################################

    ' Set form location
    Left = (Screen.Width - Width) / 2
    Top = (Screen.Height - Height) / 2
    
    ' Set the number of rows
    TransmittedSignal.RowCount = SAMPLE_SIZE
    ReceivedSignal.RowCount = SAMPLE_SIZE
    
    ' Set caption on toggle button
    cmd_Toggle.Caption = START_CAPTION
    
    ' Clear charts
    Clear_Charts

End Sub

Private Sub Form_Resize()
'#######################################################################
' This procedure is called if the form size if modifed. It's job is to
' re-size and re-position the Active-X controls according to scale.
'#######################################################################
    
    ' To resize controls:
    '
    ' current control [width/height] = ( current control [width/height] *
    '                                  original control [width/height]) /
    '                                  forms original [width/height]
    
    ' Grow/Shrink Controls
    TransmittedSignal.Width = (signalfrm.Width * _
                               TRANSMITTED_CHART_START_WIDTH) / _
                               FORM_START_WIDTH
    TransmittedSignal.Height = (signalfrm.Height * _
                                TRANSMITTED_CHART_START_HEIGHT) / _
                                FORM_START_HEIGHT
    ReceivedSignal.Width = (signalfrm.Width * _
                            RECEIVED_CHART_START_WIDTH) / _
                            FORM_START_WIDTH
    ReceivedSignal.Height = (signalfrm.Height * _
                             RECEIVED_CHART_START_HEIGHT) / _
                             FORM_START_HEIGHT
    cmd_Toggle.Width = (signalfrm.Width * _
                        TOGGLE_BUTTON_START_WIDTH) / _
                        FORM_START_WIDTH
    cmd_Toggle.Height = (signalfrm.Height * _
                         TOGGLE_BUTTON_START_HEIGHT) / _
                         FORM_START_HEIGHT

    ' To re-position controls:
    '
    ' current control [left/top] = ( original control [left/top] /
    '                              original control [width/height] ) *
    '                              current control [width/height]
    ' Note: However, we will multiply the original [left/top] position
    '       by the inverse of the original start [width/height] to
    '       protect us against division by zero.
    
    ' Re-position Controls
    TransmittedSignal.Left = (TRANSMITTED_CHART_START_LEFT * _
                             (1 / TRANSMITTED_CHART_START_WIDTH)) * _
                              TransmittedSignal.Width
    TransmittedSignal.Top = (TRANSMITTED_CHART_START_TOP * _
                            (1 / TRANSMITTED_CHART_START_HEIGHT)) * _
                             TransmittedSignal.Height
    ReceivedSignal.Left = (RECEIVED_CHART_START_LEFT * _
                          (1 / RECEIVED_CHART_START_WIDTH)) * _
                           ReceivedSignal.Width
    ReceivedSignal.Top = (RECEIVED_CHART_START_TOP * _
                         (1 / RECEIVED_CHART_START_HEIGHT)) * _
                          ReceivedSignal.Height
    cmd_Toggle.Left = (TOGGLE_BUTTON_START_LEFT * _
                      (1 / TOGGLE_BUTTON_START_WIDTH)) * _
                       cmd_Toggle.Width
    cmd_Toggle.Top = (TOGGLE_BUTTON_START_TOP * _
                     (1 / TOGGLE_BUTTON_START_WIDTH)) * _
                      cmd_Toggle.Height
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    If (tmr_MethodDispatch.Enabled = True) Then
        Test_OFF
    End If
    Unload BoardProc_frm
End Sub

Private Sub ReceivedSignal_ChartSelected(MouseFlags As Integer, Cancel As Integer)
       ' No handler is required
       ' The program is not configured to accept user input from the charts
End Sub

Private Sub tmr_MethodDispatch_Timer()
'#######################################################################
' This procedure is enabled(called repeatedly) when the user starts the
' the test.  It acts as a task and is not halted until the user disables
' the timer (i.e. tmr_MethodDispatch.Enable = "False").  This
' procedure's job is to call Transmit_Signal() and Receive_Signal()
'#######################################################################

    Dim func_status As Long  ' status of function call
    Dim response As Integer  ' variable for response from messagebox
    Dim lBufferState As Long
    
    ' Call StatusOfWrite() to make sure that the target application has
    ' requested data. This is needed for host to target synchronization.
    If (toDSP.StatusOfWrite(lBufferState) <> SUCCESS) Then
        Exit Sub
    End If
    If (lBufferState >= 0) Then
        Exit Sub
    End If
    
    func_status = Transmit_Signal ' attempt to transmit signal to target
    If (func_status <> SUCCESS) Then ' if attempt was not successful
        response = MsgBox("Error: Signal not transmitted to target, " + _
                          "Do you wish to continue?", _
                          vbcrtical + vbYesNo)
        If (response <> vbYes) Then
            Test_OFF                 ' stop test
        End If
    Else
        func_status = Receive_Signal ' attempt to read signal from target
        Select Case (func_status)
            Case SUCCESS             ' Success full read, continue
                                     '  execution
            Case EEndOfLogFile       ' No more data will be available
                response = MsgBox("End Of Log File has been reached", _
                                   vbInformation)
                Test_OFF
            Case ENoDataAvailable    ' No data is currently available,
                                     '  data may be available in the
                                     '  future
                response = MsgBox("No data is currently available " + _
                                  "Do you wish to continue program?", _
                                   vbInformation + vbYesNo)
                If (response <> vbYes) Then
                    Test_OFF
                End If
            Case FAIL                ' Read failure
                response = MsgBox("Error: Signal not received from target, " + _
                                  "Do you wish to continue?", _
                                  vbCritical + vbYesNo)
                If (response <> vbYes) Then
                    Test_OFF
                End If
            Case Else                ' Unknown return from debugger
                response = MsgBox("Error: Unexpected return from debugger, " + _
                                  "Application is terminated", vbCritical)
        End Select
    End If

End Sub

Private Sub TransmittedSignal_ChartSelected(MouseFlags As Integer, Cancel As Integer)
    ' No handler is required
    ' The program is not configured to accept user input from the charts
End Sub

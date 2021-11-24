VERSION 5.00
Begin VB.Form BoardProc_frm 
   Caption         =   "Select Board And Processor"
   ClientHeight    =   1620
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5880
   LinkTopic       =   "Form1"
   ScaleHeight     =   1620
   ScaleWidth      =   5880
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cmd_OK 
      Caption         =   "OK"
      Height          =   495
      Left            =   4440
      TabIndex        =   4
      Top             =   1080
      Width           =   1335
   End
   Begin VB.ListBox list_Processors 
      Height          =   540
      IntegralHeight  =   0   'False
      Left            =   3480
      TabIndex        =   1
      Top             =   480
      Width           =   2295
   End
   Begin VB.ListBox list_Boards 
      Height          =   540
      IntegralHeight  =   0   'False
      Left            =   0
      TabIndex        =   0
      Top             =   480
      Width           =   3375
   End
   Begin VB.Label Label_Processor 
      Caption         =   "Processor:"
      Height          =   255
      Left            =   3480
      TabIndex        =   3
      Top             =   120
      Width           =   2295
   End
   Begin VB.Label label_Board 
      Caption         =   "Board:"
      Height          =   255
      Left            =   0
      TabIndex        =   2
      Top             =   120
      Width           =   3375
   End
End
Attribute VB_Name = "BoardProc_frm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private CCSetup As Object
Private Boards As Object
Private Board As Object
Private Processors As Object
Private Processor As Object
Public CurrentSelectedBoard As String
Public CurrentSelectedProcessor As String

    
Private Function GetAvailableBoards() As Boolean
    Dim status As Long
    Dim BoardName As String
    
    ' Initialize Lists
    list_Boards.Clear
    list_Processors.Clear
    
    ' Instantiate the Code Composer Setup SystemSetup coclass and obtain a
    ' pointer to the ISystemSetup interface
    Set CCSetup = CreateObject("CodeComposerSetup.SystemSetup")
    
    ' Get a pointer to the IBoards interface
    status = CCSetup.GetBoards(Boards)
    
    ' Loop through the available boards, get the names of the boards,
    ' and add the board names to the boards list control
    For Each Board In Boards
        ' Get the board name
        status = Board.GetName(BoardName)
        
        ' Append board name to the board list
        list_Boards.AddItem (BoardName)
    Next
    
    ' return True
    GetAvailableBoards = True

End Function

Private Function GetAvaiableProcessors(SelectedBoardName As String) As Boolean

    Dim status As Long
    Dim ProcessorName As String
    
    ' Get a pointer to the IBoard interface for the selected
    ' board
    status = CCSetup.GetBoardByName(SelectedBoardName, Board)
    
    
    ' Get a pointer to the IProcessors interface
    status = Board.GetProcessors(Processors)
    
    ' Loop through the available processors, get the names of the
    ' processors, and add the processors to the processors list
    ' control
    For Each Processor In Processors
        ' Get the processor name
        status = Processor.GetName(ProcessorName)
        
        ' Append processor name to the processor list
        list_Processors.AddItem (ProcessorName)
    Next
    
    ' Return True
    GetAvaiableProcessors = True

End Function

Private Sub cmd_OK_Click()

    BoardProc_frm.Hide
    
End Sub

Private Sub Form_Load()

    Dim status As Long
    Dim BoardName As String
    Dim ProcessorName As String
    
    Left = (Screen.Width - Width) / 2
    Top = (Screen.Height - Height) / 2
    
    ' Get Available Boards and Processors
    If (GetAvailableBoards) Then
        ' Set the selected board to 0
        list_Boards.Selected(0) = True
    End If
    
End Sub


Private Sub Form_Unload(Cancel As Integer)
    Set CCSetup = Nothing
    Set Boards = Nothing
    Set Board = Nothing
    Set Processors = Nothing
    Set Processor = Nothing
End Sub

Private Sub list_Boards_Click()

    ' Clear processor list
    list_Processors.Clear
    
    ' Get current selected board
    CurrentSelectedBoard = list_Boards.List(list_Boards.ListIndex)
    
    ' Get available processors for that board
    If (GetAvaiableProcessors(CurrentSelectedBoard)) Then
        ' Set the selected processor to 0
        list_Processors.Selected(0) = True
    End If
    
End Sub

Private Sub list_Processors_Click()

    ' Get current selected processor
    CurrentSelectedProcessor = list_Processors.List(list_Processors.ListIndex)
    
End Sub



Imports System.Console
Imports System.Threading.Thread
Imports System.Threading

Module Module1

    'Class Part
    'Public Length As Long
    'Public Width As Long
    'Public Ammount As Long
    'Public Rotate As Boolean
    'End Class

    'Class Sheet
    '    Public Length As Long
    '    Public Width As Long
    'End Class

    Dim CutWidth As Double

    Class Routine
        Public Server As String
        Public Parts As New COMRASKROYLib.SheetsClass()
        Public Sheets As New COMRASKROYLib.SheetsClass()
        Public Results() As COMRASKROYLib.Result
        Public Rashod As Long
        Public Color As String
        Public dsp As Boolean

        Sub Run()
            Dim x As COMRASKROYLib.IRaskroy
            x = CreateObject("COMRASKROYLib.Raskroy", Server)
            Dim res As COMRASKROYLib.Result
            If x.First(Parts, Sheets, res) Then
                Do
                    Results(Results.Length) = res
                    Rashod = Rashod + res.Amount
                Loop While x.Next(res)
            End If
        End Sub
    End Class

    Function SelectServer() As String
        Static servers(6) As String
        Static cntr As Byte
        servers(0) = "Computer"
        servers(1) = "SERVER"
        servers(2) = "Tanya"
        servers(3) = "Sveta"
        servers(4) = "Popova"
        servers(5) = "Black"
        SelectServer = servers(cntr)
        'cntr = cntr + 1
        'If cntr > 5 Then cntr = 0
    End Function

    Sub Main()
        Dim x1 As COMRASKROYLib.IRaskroy
        x1 = CreateObject("COMRaskroy.Raskroy")

        Dim col As New Collection()
        ' Загрузка данных из базы и выборка данных по материалам и цветам
        Dim acc As Object
        acc = GetObject("\\server\pubs\раскрой\Полторашка.mdb")
        'acc.OpenCurrentDatabase("\\server\pubs\db1.mdb")

        ' запрос списка материалов и цветов rs(0) - материал (дсп/фанера)
        ' rs(1) - цвет
        Dim rs As DAO.Recordset
        Dim rs1 As DAO.Recordset
        rs = acc.CurrentDb.OpenRecordset("SELECT ДСП, Цвет FROM Заказы INNER JOIN Детали ON Заказы.Код=Детали.КодЗаказа WHERE ДСП=True GROUP BY ДСП, Цвет")
        Dim Партия = 4

        ' Для каждой пары (материал,цвет) создается рутина
        While Not rs.EOF
            Dim x As New Routine()
            col.Add(x)
            x.dsp = rs(0).Value
            'If x.dsp Then
            '    x.Sheets.Add2(1810, 1210, 1000, False)
            'End If
            x.Sheets.Add2(1810, 1210, 1000, False)
            'x.Sheets.Add2(2440, 1210, 1000, False)
            x.Color = rs(1).Value
            x.Server = SelectServer()

            ' Запрашиваем детали для материала,цвета
            ' rs1(0) - длина, rs1(1) - ширина, rs1(2) - кол-во,
            ' rs1(3) - поворот
            rs1 = acc.CurrentDb.OpenRecordset("SELECT Длина, Ширина, Количество, Поворот FROM (Детали INNER JOIN Заказы ON Детали.КодЗаказа=Заказы.Код) LEFT JOIN Цвета ON Заказы.Цвет=Цвета.Наименование WHERE ДСП=" & x.dsp & " AND Цвет=""" & x.Color & """")
            Dim count As Integer
            count = 0
            While Not rs1.EOF
                x.Parts.Add2(rs1(0).Value, rs1(1).Value, rs1(2).Value * Партия, rs1(3).Value)
                rs1.MoveNext()
                'count = count + 1
                'If count = 10 Then Exit While
            End While
            Console.WriteLine("Loaded parts for color " & x.Color & ", dsp " & x.dsp & ", amount " & rs1.RecordCount)
            rs.MoveNext()
        End While

        ' Запуск асинхронных раскроев
        Dim element As Routine
        Dim r As New COMRASKROYLib.Raskroy()
        r.RecursionDepth = 1000
        rs = acc.CurrentDb.OpenRecordset("SELECT Код, Время FROM Раскрои")
        rs.AddNew()
        Dim КодРаскроя As Integer
        КодРаскроя = acc.CurrentDb.OpenRecordset("SELECT Nz(LAST(Код))+1 FROM (SELECT * FROM Раскрои ORDER BY Код)")(0).Value
        rs.Fields(0).Value = КодРаскроя
        rs.Fields(1).Value = Now()
        rs.Update()
        rs = acc.CurrentDb.OpenRecordset("SELECT Код, КодРаскроя, Цвет FROM РаскройПоЦветам")
        rs1 = acc.CurrentDb.OpenRecordset("SELECT КодРаскрояПоЦветам, Value, Количество, Отход FROM ЛистыРаскроевПоЦветам")
        For Each element In col
            rs.AddNew()
            Dim КодРаскрояПоЦвету As Integer
            КодРаскрояПоЦвету = acc.CurrentDb.OpenRecordset("SELECT Nz(LAST(Код))+1 FROM (SELECT * FROM РаскройПоЦветам ORDER BY Код)")(0).Value
            rs.Fields(0).Value = КодРаскрояПоЦвету
            rs.Fields(1).Value = КодРаскроя
            rs.Fields(2).Value = element.Color
            rs.Update()
            Dim SumScrap = 0
            Dim res As COMRASKROYLib.Result
            If r.First(element.Parts, element.Sheets, res) Then
                Do
                    r.RecursionDepth = r.RecursionDepth + 2
                    rs1.AddNew()
                    rs1.Fields(0).Value = КодРаскрояПоЦвету
                    rs1.Fields(1).Value = res.String
                    rs1.Fields(2).Value = res.Amount
                    Dim Scrap = res.UsefulScrap + res.Opilki + res.UnUsefulScrap
                    rs1.Fields(3).Value = Scrap
                    SumScrap = SumScrap + Scrap * res.Amount
                    rs1.Update()
                    element.Rashod = element.Rashod + res.Amount
                    Console.Write(".")
                Loop While r.Next(res)
            End If
            'Dim y As New System.Threading.Thread(AddressOf element.Run)
            'y.Start()
            Console.WriteLine("Finished raskroy for " & element.Color & ", dsp " & element.dsp & " кол-во листов = " & element.Rashod & " sum(scrap) = " & SumScrap / 1000000)
        Next
        Console.WriteLine("Press enter to exit...")
        Console.ReadLine()
    End Sub

End Module

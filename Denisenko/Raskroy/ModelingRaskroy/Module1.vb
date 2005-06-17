Imports System.Console
Imports System.Threading.Thread
Imports System.Threading

Module Module1

	Class Package
		Public Server As String
		Public Parts As New COMRASKROYLib.SheetsClass
		Public Sheets As New COMRASKROYLib.SheetsClass
		Public Results As Collection
		Public Rashod As Long
		Public Color As String
		Public Dsp As Boolean

		Sub Run()
			Dim x As COMRASKROYLib.IRaskroy
			x = CreateObject("COMRASKROYLib.Raskroy", Server)
			Dim res As COMRASKROYLib.Result
			If x.First(Parts, Sheets, res) Then
				Do
					Results.Add(res)
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

	Function LoadPackages(ByVal db As DAO.Database) As Collection
		Dim materials As DAO.Recordset = db.OpenRecordset("SELECT ДСП, Цвет FROM Заказы INNER JOIN Детали ON Заказы.Код=Детали.КодЗаказа WHERE ДСП=True GROUP BY ДСП, Цвет")
		Dim packages As New Collection
		Dim партия = 4
		' Для каждой пары (материал,цвет) создается пакет
		While Not materials.EOF
			Dim package As New Package
			package.Dsp = materials("ДСП").Value
			package.Sheets.Add2(1810, 1210, 1000, False)
			package.Color = materials("Цвет").Value
			package.Server = SelectServer()
			Dim details As DAO.Recordset = db.OpenRecordset("SELECT Длина, Ширина, Количество, Поворот FROM (Детали INNER JOIN Заказы ON Детали.КодЗаказа=Заказы.Код) LEFT JOIN Цвета ON Заказы.Цвет=Цвета.Наименование WHERE ДСП=" & package.Dsp & " AND Цвет='" & package.Color & "'")
			While Not details.EOF
				package.Parts.Add2(details("Длина").Value, details("Ширина").Value, _
				   details("Количество").Value * партия, details("Поворот").Value)
				details.MoveNext()
			End While
			Console.WriteLine("Loaded parts for color " & package.Color & ", dsp " & package.Dsp & ", amount " & details.RecordCount)
			packages.Add(package)
			materials.MoveNext()
		End While
		LoadPackages = packages
	End Function

	Sub SavePackages(ByRef db As DAO.Database, ByVal packages As Collection)
		Dim newRaskroy As DAO.Recordset = db.OpenRecordset("SELECT Код, Время FROM Раскрои")
		newRaskroy.AddNew()
		Dim КодРаскроя As Integer
		КодРаскроя = db.OpenRecordset("SELECT Nz(LAST(Код))+1 FROM (SELECT * FROM Раскрои ORDER BY Код)")(0).Value
		newRaskroy.Fields(0).Value = КодРаскроя
		newRaskroy.Fields(1).Value = Now()
		newRaskroy.Update()
		Dim raskroys As DAO.Recordset = db.OpenRecordset("SELECT Код, КодРаскроя, Цвет FROM РаскройПоЦветам")
		Dim sheets As DAO.Recordset = db.OpenRecordset("SELECT КодРаскрояПоЦветам, Value, Количество, Отход FROM ЛистыРаскроевПоЦветам")
		For Each package As Package In packages
			raskroys.AddNew()
			Dim КодРаскрояПоЦветам As Integer
			КодРаскрояПоЦветам = db.OpenRecordset("SELECT Nz(LAST(Код))+1 FROM (SELECT * FROM РаскройПоЦветам ORDER BY Код)")(0).Value
			raskroys.Fields("Код").Value = КодРаскрояПоЦветам
			raskroys.Fields("КодРаскроя").Value = КодРаскроя
			raskroys.Fields("Цвет").Value = package.Color
			raskroys.Update()
			Dim SumScrap = 0
			For Each result As COMRASKROYLib.Result In package.Results
				sheets.AddNew()
				sheets.Fields("КодРаскрояПоЦветам").Value = КодРаскрояПоЦветам
				sheets.Fields("Value").Value = result.String
				sheets.Fields("Количество").Value = result.Amount
				sheets.Fields("Отход").Value = result.UsefulScrap + result.Opilki + result.UnUsefulScrap
				sheets.Update()
				package.Rashod = package.Rashod + result.Amount
				Console.Write(".")
			Next
		Next
	End Sub

	Sub Main()
		Dim dbEngine As New DAO.DBEngineClass
		Dim db As DAO.Database = dbEngine.OpenDatabase("Полторашка.mdb")
		Dim packages As Collection = LoadPackages(db)
		Dim raskroy As New COMRASKROYLib.Raskroy
		For Each package As Package In packages
			Dim sumScrap = 0			 ' в кв. мм.
			Dim sumRashod = 0
			Dim result As COMRASKROYLib.Result
			'Dim y As New System.Threading.Thread(AddressOf element.Run)
			'y.Start()
			raskroy.Begin(package.Parts, package.Sheets)
			While raskroy.NextResult(result)
				package.Results.Add(result)
				sumScrap = sumScrap + (result.UsefulScrap + result.Opilki + result.UnUsefulScrap) * result.Amount
				sumRashod = sumRashod + result.Amount
				Console.Write(".")
			End While
			package.Rashod = sumRashod
			Console.WriteLine("Finished raskroy for " & package.Color & ", dsp " & package.Dsp & " кол-во листов = " & sumRashod & " сумарный отход (кв.м.) = " & sumScrap / 1000000)
		Next
		SavePackages(db, packages)
		Console.WriteLine("Press enter to exit...")
		Console.ReadLine()
	End Sub

End Module

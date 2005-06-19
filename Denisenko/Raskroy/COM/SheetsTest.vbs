dim col
set col = CreateObject("COMRaskroy.Sheets.1")
dim x
x = 10
col.Add(1)
col.Item(-1) = 2
for each i in col
	WScript.Echo(i)
next
dim y
y = WScript.StdIn.ReadLine
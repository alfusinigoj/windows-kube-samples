<!DOCTYPE html>
<html>
<body>

<%
Dim objConn
Set objConn = Server.CreateObject("ADODB.Connection")
objConn.Open("PROVIDER=SQLOLEDB;DATA SOURCE=hostname-or-ip;UID=user-id;PWD=password;DATABASE=database-name")

Set objCmd = Server.CreateObject("ADODB.Command")
objCmd.CommandText = "SELECT * FROM master.sys.tables"
objCmd.ActiveConnection = objConn

Set objRS = objCmd.Execute

Do While Not objRS.EOF
  %><%= objRS("name") %><br><%
  objRS.MoveNext()
Loop
%>

</body>
</html>
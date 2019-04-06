# ASP with OLEDB

This project demonstrates a classic ASP application connecting to a SQL Server database via ODBC.

## Dockerfile

During the build process this Dockerfile installs the ODBC Driver for SQL Server and configures a system-level DNS.

```
# Install the ODBC Driver for SQL Server
RUN md c:/msi;
RUN Invoke-WebRequest 'https://download.microsoft.com/download/1/E/7/1E7B1181-3974-4B29-9A47-CC857B271AA2/English/X64/msodbcsql.msi' -OutFile c:/msi/msodbcsql.msi; 
RUN ["cmd", "/S", "/C", "c:\\windows\\syswow64\\msiexec", "/i", "c:\\msi\\msodbcsql.msi", "IACCEPTMSODBCSQLLICENSETERMS=YES", "ADDLOCAL=ALL", "/qn"];

# Add the DSN
RUN Add-OdbcDsn -Name "your-dsn" -DriverName "\"ODBC Driver 13 For SQL Server\""  -DsnType "System"  -SetPropertyValue @("\"Server=hostname-or-ip\"", "\"Trusted_Connection=No\"");
```

In the Dockerfile You'll have to replace `hostname-or-ip` with the correct address in your environment and `your-dsn` with the DSN your application expects. 

# default.asp 
In `default.asp` you'll have to specify the DSN, username, and password relevant to your environment. 

While specifying such information directly in code is not desirable, it's a pattern often found in legacy ASP applications. In the future content will be added demonstrating config externalization.

## TODO
* Config externalization
* K8s YAML spec

## Notes

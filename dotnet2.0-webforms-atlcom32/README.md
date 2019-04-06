# Dotnet 2.0 32-bit ATL/COM

Here lies a simple ASP.NET 2.0 WebForms application that depends on a 32-bit COM library. This sample demonstrates dockerizing the applications by adding a simple, hand-rolled `Dockerfile` which requires no modifications to the enclosed project.

A VS 2010 VC++ ATL project is present in the ATLPKS directory, but the 32-bit .DLL (`ATLPKS.dll`) is included in this directory for convenience.

## Dockerfile

The `Dockerfile` assumes that your solution is named COMClient and is placed at the same level as the `Dockerfile`. The `Dockerfile` also assume that you've published the application to the `bin\Release\Publish` folder.

The `Dockerfile` downloads and installs the VC++ redistributable in a rather special way due to the fact that the installer is asynchronous. The powershell `Start-Process` and `Wait-Process` Cmdlets synchronize the operation so the docker build doesn't terminate prematurely.

The `Dockerfile` then registers the ATL/COM dll that the .NET 2.0 project depends on. Care is taken to use the 32-bit `regsvr.exe` which is located in `c:\Windows\SysWOW64`.

Just before putting the published artifacts into `c:\inetpub\wwwroot` 32-bit execution is enabled in IIS.
FROM mcr.microsoft.com/dotnet/framework/aspnet:3.5
SHELL ["powershell", "-Command", "$ErrorActionPreference = 'SilentlyContinue'; $ProgressPreference = 'SilentlyContinue';"]

EXPOSE 80

# Download vc++ redist
ADD https://download.microsoft.com/download/C/6/D/C6D0FD4E-9E53-4897-9B91-836EBA2AACD3/vcredist_x86.exe /vcredist_x86.exe
# SYNCHRONOUSLY install the vc++ redist
RUN Start-Process -filepath C:\vcredist_x86.exe -ArgumentList "/install", "/passive", "/norestart", "'/log a.txt'" -PassThru | wait-process

# Register the ATL/COM dll
COPY ./ATLPKS.dll c:/ATLPKS/
RUN c:/Windows/SysWOW64/regsvr32.exe /s c:/ATLPKS/ATLPKS.dll

# Let IIS run 32-bit apps 
RUN "c:\\Windows\\System32\\inetsrv\\appcmd.exe set apppool /apppool.name:DefaultAppPool /enable32BitAppOnWin64:true"

WORKDIR /inetpub/wwwroot
COPY COMClient/COMClient/bin/Release/Publish/bin/* ./bin/
COPY COMClient/COMClient/bin/Release/Publish/* ./

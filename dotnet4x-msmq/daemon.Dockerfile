FROM mcr.microsoft.com/windows/servercore:ltsc2019
SHELL [ "powershell" ]

RUN Add-WindowsFeature MSMQ

RUN Dism /online /Enable-Feature /FeatureName:NetFx4 /All 

WORKDIR /app
COPY Qbert/Daemon/. .
RUN New-LocalUser -Name "pksuser" -Password (ConvertTo-SecureString -AsPlainText "Pk$w0rd189PVTL!" -Force) -FullName "PKS.User" -Description "LocalAdministrator"
RUN Add-LocalGroupMember -Group administrators -Member pksuser -Verbose

WORKDIR /app/bin/Release .
RUN C:\Windows\Microsoft.NET\Framework\v4.0.30319\InstallUtil.exe /username=.\pksuser /password=Pk$w0rd189PVTL! /LogToConsole=true .\Daemon.exe

CMD ["powershell", "while", \
    "((Get-Process | ? { $_.ProcessName -like 'Daemon'} | Measure).Count -gt 0)", \
    "{Start-Sleep -Seconds 1}"]
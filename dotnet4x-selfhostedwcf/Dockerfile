FROM mcr.microsoft.com/dotnet/framework/runtime:4.7.2 AS runtime
SHELL [ "powershell" ]

WORKDIR /app
COPY SelfHostedWCFService/SelfHostedWCFService/. .
RUN New-LocalUser -Name "pksuser" -Password (ConvertTo-SecureString -AsPlainText "Pk$w0rd189PVTL!" -Force) \
    -FullName "PKS.User" -Description "LocalAdministrator"
RUN Add-LocalGroupMember -Group administrators -Member pksuser -Verbose

WORKDIR /app/bin/Release .
RUN C:\Windows\Microsoft.NET\Framework\v4.0.30319\InstallUtil.exe /username=.\pksuser /password=Pk$w0rd189PVTL! \
    /LogToConsole=true .\SelfHostedWCFService.exe

EXPOSE 8080

CMD ["powershell", "while", \
    "((Get-Process | ? { $_.ProcessName -like 'SelfHostedWCFService'} | Measure).Count -gt 0)", \
    "{Start-Sleep -Seconds 1}"]
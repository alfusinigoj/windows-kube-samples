FROM microsoft/iis
SHELL [ "powershell" ]

# Install MSMQ
RUN Add-WindowsFeature MSMQ
# Install ASP.NET
RUN Add-WindowsFeature Web-Asp-Net45

# Pull in the front-end WebAPI
RUN powershell -NoProfile -Command Remove-Item -Recurse C:\inetpub\wwwroot\*
COPY Qbert/API/ /inetpub/wwwroot/

# Install the .NET Framework (neede for backend services)
RUN Dism /online /Enable-Feature /FeatureName:NetFx4 /All 

WORKDIR /app
COPY Qbert/Daemon/. .

# Create a user for the service to run as
RUN New-LocalUser -Name "pksuser" -Password (ConvertTo-SecureString -AsPlainText "Pk$w0rd189PVTL!" -Force) -FullName "PKS.User" -Description "LocalAdministrator"
RUN Add-LocalGroupMember -Group administrators -Member pksuser -Verbose

WORKDIR /app/bin/Release .

# Install the backend Windows Service
RUN C:\Windows\Microsoft.NET\Framework\v4.0.30319\InstallUtil.exe /username=.\pksuser /password=Pk$w0rd189PVTL! /LogToConsole=true .\Daemon.exe

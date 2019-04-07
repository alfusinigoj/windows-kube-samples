FROM mcr.microsoft.com/dotnet/framework/runtime:4.7.2 AS runtime
SHELL [ "powershell" ]

WORKDIR /app
COPY SelfHostedWCFService/SelfHostedWCFService/. .

# Windows services need to run as some kind of user so we'll create one. This is just a legacy artifact 
# of how Windows Services work and the identity of this user isn't important to us so the creds aren't
# perticularly sensitive. I'm not even sure it makes sense to dial back the group the user is being put
# in to.
RUN New-LocalUser -Name "pksuser" -Password (ConvertTo-SecureString -AsPlainText "Pk$w0rd189PVTL!" -Force) \
    -FullName "PKS.User" -Description "LocalAdministrator"
RUN Add-LocalGroupMember -Group administrators -Member pksuser -Verbose

# Install the service into Windows
WORKDIR /app/bin/Release .
RUN C:\Windows\Microsoft.NET\Framework\v4.0.30319\InstallUtil.exe /username=.\pksuser /password=Pk$w0rd189PVTL! \
    /LogToConsole=true .\SelfHostedWCFService.exe

EXPOSE 8080

# The real business of the app lifecycle is managed by Windows due to this app being a server so there isnt'
# really a need for us to worry about it in Docker. However, we do need some process to run that docker can
# watch so it knows we're still alive. This command let's Windows manage that lifecycle while we just watch
# the state of the service, exiting if the process dissapears thus destroying the container. 
# I'm open to better ideas.
CMD ["powershell", "while", \
    "((Get-Process | ? { $_.ProcessName -like 'SelfHostedWCFService'} | Measure).Count -gt 0)", \
    "{Start-Sleep -Seconds 1}"]
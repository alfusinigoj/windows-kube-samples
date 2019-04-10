FROM microsoft/iis
SHELL [ "powershell" ]

RUN Add-WindowsFeature MSMQ
RUN Add-WindowsFeature Web-Asp-Net45

RUN powershell -NoProfile -Command Remove-Item -Recurse C:\inetpub\wwwroot\*
COPY Qbert/API/bin/Release/publish/ /inetpub/wwwroot/

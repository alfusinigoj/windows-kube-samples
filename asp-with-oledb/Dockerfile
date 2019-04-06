FROM microsoft/iis
SHELL ["powershell", "-command"]
EXPOSE 80

RUN Install-WindowsFeature Web-ASP; 
RUN powershell -NoProfile -Command Remove-Item -Recurse C:\inetpub\wwwroot\*

WORKDIR /inetpub/wwwroot
COPY wwwroot/* .
